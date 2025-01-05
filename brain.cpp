#include <iostream>
#include "brain.h"
#include <math.h>

Brain::Brain(){
    this->setupPSQT();
}

float Brain::minimax(Chessboard board, int depth){
    if(depth == 0 || board.gameOver){
      #ifdef DEBUG_PRINT_ENABLED
        std::cout<<"eval: "<<this->evaluate(board)<<"\n";
      #endif
        return this->evaluate(board);

    }
    if(!board.colorToPlay){
        float maxEval = -10000;
        std::vector<std::vector<u_int16_t>> moves = board.removeCheckMoves(board.getLegalMoves());
        for(int i = 0; i<size(moves); i++){
            for(int j = 0; j<size(moves[i]); j++){
                Chessboard childBoard = board.moveToBoard(moves[i][j]);
                childBoard.switchColor();
                float eval = this->minimax(childBoard, depth-1);
                maxEval = std::max(maxEval, eval);
            }
        }
        return maxEval;
    }
    else{
        float minEval = 10000;
        std::vector<std::vector<u_int16_t>> moves = board.removeCheckMoves(board.getLegalMoves());
        for(int i = 0; i<size(moves); i++){
            for(int j = 0; j<size(moves[i]); j++){
                Chessboard childBoard = board.moveToBoard(moves[i][j]);
                childBoard.switchColor();
                float eval = this->minimax(childBoard, depth-1);
                minEval = std::min(minEval, eval);
            }
        }
        return minEval;
    }
    
}

float Brain::evaluate(Chessboard board){
    float score = 0;
    for(u_int64_t i = 0; i<64; i++){
      if(board.enemyKing & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->whiteKingWeight + this->whiteKingPSQT[i];
        else score += this->blackKingWeight + this->blackKingPSQT[i];
      }
      else if(board.enemyQueen & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->whiteQueenWeight + this->whiteQueenPSQT[i];
        else score += this->blackQueenWeight + this->blackQueenPSQT[i];
      }
      else if(board.enemyRooks & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->whiteRookWeight + this->whiteRookPSQT[i];
        else score += this->blackRookWeight + this->blackRookPSQT[i];
      }
      else if(board.enemyBishops & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->whiteBishopWeight + this->whiteBishopPSQT[i];
        else score += this->blackBishopWeight + this->blackBishopPSQT[i];
      }
      else if(board.enemyKnights & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->whiteKnightWeight + this->whiteKnightPSQT[i];
        else score += this->blackKnightWeight + this->blackKnightPSQT[i];
      }
      else if(board.enemyPawns & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->whitePawnWeight + this->whitePawnPSQT[i];
        else score += this->blackPawnWeight + this->blackPawnPSQT[i];
      }
      else if(board.yourKing & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->blackKingWeight + this->blackKingPSQT[i];
        else score += this->whiteKingWeight + this->whiteKingPSQT[i];
      }
      else if(board.yourQueen & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->blackQueenWeight + this->blackQueenPSQT[i];
        else score += this->whiteQueenWeight + this->whiteQueenPSQT[i];
      }
      else if(board.yourRooks & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->blackRookWeight + this->blackRookPSQT[i];
        else score += this->whiteRookWeight + this->whiteRookPSQT[i];
      }
      else if(board.yourBishops & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->blackBishopWeight + this->blackBishopPSQT[i];
        else score += this->whiteBishopWeight + this->whiteBishopPSQT[i];
      }
      else if(board.yourKnights & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->blackKnightWeight + this->blackKnightPSQT[i];
        else score += this->whiteKnightWeight + this->whiteKnightPSQT[i];
      }
      else if(board.yourPawns & u_int64_t(1)<<i){
        if(board.colorToPlay) score += this->blackPawnWeight + this->blackPawnPSQT[i];
        else score += this->whitePawnWeight + this->whitePawnPSQT[i];
      }
    }
    return float(score);
}

u_int16_t Brain::getBestMove(Chessboard board, int depth){
    std::vector<std::vector<u_int16_t>> legalMoves = board.getLegalMoves();
    std::vector<std::vector<u_int16_t>> moves = board.removeCheckMoves(legalMoves);
    std::vector<std::vector<float>> scores = {{},{},{},{},{},{}};
    for(int i = 0; i<size(moves); i++){
      for(int j = 0; j<size(moves[i]); j++){
        Chessboard currBoard = board.moveToBoard(moves[i][j]);
        currBoard.switchColor();
        scores[i].push_back(minimax(currBoard, depth));
      }
    }
    int bestIndexI = -2;
    int bestIndexJ = -2;
    int bestScore = 0;
    if(board.colorToPlay){
      bestScore = 10000;
    }
    else{
      bestScore = -10000;
    }
    for(int i = 0; i<size(scores); i++){
      for(int j = 0; j<size(scores[i]); j++){
        if(board.colorToPlay){
          if(scores[i][j] < bestScore){
            bestScore = scores[i][j];
            bestIndexI = i;
            bestIndexJ = j;
          }
        }
        else{
          if(scores[i][j] > bestScore){
            bestScore = scores[i][j];
            bestIndexI = i;
            bestIndexJ = j;
        }
      }
    }
  }
  return moves[bestIndexI][bestIndexJ];
}