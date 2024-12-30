#include <iostream>
#include "chessboard.h"

Chessboard::Chessboard(){
  this->configureBoards("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  this->prettyPrint();
  this->colorToPlay = false;
}

void Chessboard::configureBoards(std::string fen){
  std::string currChar = "";
  u_int8_t currBoardIndex = 0;
  this->whiteKingBoard = 0;
  this->whiteQueenBoard = 0;
  this->whiteRookBoard = 0;
  this->whiteBishopBoard = 0;
  this->whiteKnightBoard = 0;
  this->whitePawnBoard = 0;
  this->blackKingBoard = 0;
  this->blackQueenBoard = 0;
  this->blackRookBoard = 0;
  this->blackBishopBoard = 0;
  this->blackKnightBoard = 0;
  this->blackPawnBoard = 0;
  for(int i = 0; i<fen.length(); i++){
    currChar = fen.at(i);
    if(currChar == "K"){
      this->whiteKingBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White King" << "\n";
      #endif
    }
    else if (currChar == "Q"){
      this->whiteQueenBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Queen" << "\n";
      #endif
    }
    else if (currChar == "R"){
      this->whiteRookBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Rook" << "\n";
      #endif
    }
    else if (currChar == "B"){
      this->whiteBishopBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Bishop" << "\n";
      #endif
    }
    else if (currChar == "N"){
      this->whiteKnightBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Knight" << "\n";
      #endif
    }
    else if (currChar == "P"){
      this->whitePawnBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Pawn" << "\n";
      #endif
    }
    else if(currChar == "k"){
      this->blackKingBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black King" << "\n";
      #endif
    }
    else if (currChar == "q"){
      this->blackQueenBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
      std::cout << "Black Queen" << "\n";
      #endif
    }
    else if (currChar == "r"){
      this->blackRookBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black Rook" << "\n";
      #endif
    }
    else if (currChar == "b"){
      this->blackBishopBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black Bishop" << "\n";
      #endif
    }
    else if (currChar == "n"){
      this->blackKnightBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black Knight" << "\n";
      #endif
    }
    else if (currChar == "p"){
      this->blackPawnBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black Pawn" << "\n";
      #endif
    }
    else if(currChar != "/"){
      try
      {
        int emptySquares = std::stoi(currChar.c_str());
        currBoardIndex += emptySquares;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
  }
}
void Chessboard::prettyPrint(){
  std::string board[64] = {};
  for(u_int64_t i = 0; i<64; i++){
    if(this->whiteKingBoard & u_int64_t(1)<<i) board[i] = "K";
    else if(this->whiteQueenBoard & u_int64_t(1)<<i) board[i] = "Q";
    else if(this->whiteRookBoard & u_int64_t(1)<<i) board[i] = "R";
    else if(this->whiteBishopBoard & u_int64_t(1)<<i) board[i] = "B";
    else if(this->whiteKnightBoard & u_int64_t(1)<<i) board[i] = "N";
    else if(this->whitePawnBoard & u_int64_t(1)<<i) board[i] = "P";
    else if(this->blackKingBoard & u_int64_t(1)<<i) board[i] = "k";
    else if(this->blackQueenBoard & u_int64_t(1)<<i) board[i] = "q";
    else if(this->blackRookBoard & u_int64_t(1)<<i) board[i] = "r";
    else if(this->blackBishopBoard & u_int64_t(1)<<i) board[i] = "b";
    else if(this->blackKnightBoard & u_int64_t(1)<<i) board[i] = "n";
    else if(this->blackPawnBoard & u_int64_t(1)<<i) board[i] = "p";
    else board[i] = " ";
    if(i%8==7){
      std::cout << board[i] << "\n";
    }
    else{
      std::cout << board[i] << " ";
    }
  }
}

std::list<u_int16_t> Chessboard::getLegalMoves(){
  u_int64_t enemyPeices = 0;
  u_int64_t yourPeices = 0;

  u_int64_t yourKing = 0;
  u_int64_t yourQueen = 0;
  u_int64_t yourRooks = 0;
  u_int64_t yourBishops = 0;
  u_int64_t yourKnights = 0;
  u_int64_t yourPawns = 0;

  // bits 10-15 from, bits 4-9 to, bits 0-3 flags as follows
  // 0000: quiet move
  // 0001: double pawn at beginning
  // 0010: king castle
  // 0011: queen castle
  // 0100: captures 
  // 0101: captures en passant (weird pawn capture thingy)
  // 0110: knight-promotion
  // 0111: bishop-promotion
  // 1000:rook-promotion
  // 1001: queen-promotion
  // 1010: knight-promotion and capture
  // 1011: bishop promotion and capture
  // 1100: rook protiomtion and capture
  // 1101: queen promotion and caputure
  std::list<u_int16_t> possibleKingMoves = {};
  std::list<u_int16_t> possibleQueenMoves = {};
  std::list<u_int16_t> possibleRookMoves = {};
  std::list<u_int16_t> possibleBishopMoves = {};
  std::list<u_int16_t> possibleKnightMoves = {};
  std::list<u_int16_t> possiblePawnMoves = {};

  int kingMoves[8] = {-9, -8, -7, -1, 1, 7, 8, 9};
  int queenMoves[56] = {8, 16, 24, 32, 40, 48, 56, 
                        -8, -16, -24, -32, -40, -48, -56, 
                        -1, -2, -3, -4, -5, -6, -7, 
                        1, 2, 3, 4, 5, 6, 7
                        -9, -18, -27, -36, -45, -54, -63, 
                        -7, -14, -21, -28, -35, -42, -49,
                        9, 18, 27, 36, 45, 54, 63,
                        7, 14, 21, 28, 35, 42, 49};
  int rookMoves[28] = {8, 16, 24, 32, 40, 48, 56, 
                        -8, -16, -24, -32, -40, -48, -56, 
                        -1, -2, -3, -4, -5, -6, -7, 
                        1, 2, 3, 4, 5, 6, 7};
  int bishopMoves[28] = {-9, -18, -27, -36, -45, -54, -63, 
                        -7, -14, -21, -28, -35, -42, -49,
                        9, 18, 27, 36, 45, 54, 63,
                        7, 14, 21, 28, 35, 42, 49};
  int knightMoves[8] = {15, 17, 6, 10, -15, -17, -6, -10};

  if(colorToPlay){
    yourKing = this->blackKingBoard;
    yourQueen = this->blackQueenBoard;
    yourRooks = this->blackRookBoard;
    yourBishops = this->blackBishopBoard;
    yourKnights = this->blackKnightBoard;
    yourPawns = this->blackPawnBoard;

    enemyPeices = this->whiteKingBoard | this->whiteQueenBoard | this->whiteRookBoard | this->whiteBishopBoard | this->whiteKnightBoard | this->whitePawnBoard;
    yourPeices = this->blackKingBoard | this->blackQueenBoard | this->blackRookBoard | this->blackBishopBoard | this->blackKnightBoard | this->blackPawnBoard;
  }
  else{
    yourKing = this->whiteKingBoard;
    yourQueen = this->whiteQueenBoard;
    yourRooks = this->whiteRookBoard;
    yourBishops = this->whiteBishopBoard;
    yourKnights = this->whiteKnightBoard;
    yourPawns = this->whitePawnBoard;

    enemyPeices = this->blackKingBoard | this->blackQueenBoard | this->blackRookBoard | this->blackBishopBoard | this->blackKnightBoard | this->blackPawnBoard;
    yourPeices = this->whiteKingBoard | this->whiteQueenBoard | this->whiteRookBoard | this->whiteBishopBoard | this->whiteKnightBoard | this->whitePawnBoard;
  }

  for(u_int64_t i = 0; i<64; i++){
    if(yourKing & u_int64_t(1)<<i){
      for(int j=0; j<8; j++){
        int movingToIndex = i+kingMoves[j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t captureHuh = 0;
          if(enemyPeices & u_int64_t(1)<<movingToIndex) captureHuh = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | captureHuh;
          possibleKingMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "King Move Found: " << move << " ";
            if(captureHuh) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
      }
    }

    else if(yourQueen & u_int64_t(1)<<i){
      for(int j=0; j<56; j++){
        int movingToIndex = i+queenMoves[j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t captureHuh = 0;
          if(enemyPeices & u_int64_t(1)<<movingToIndex) captureHuh = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | captureHuh;
          possibleQueenMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Queen Move Found: " << move << " ";
            if(captureHuh) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
      }
    }
    else if(yourRooks & u_int64_t(1)<<i){
      for(int j=0; j<28; j++){
        int movingToIndex = i+rookMoves[j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t captureHuh = 0;
          if(enemyPeices & u_int64_t(1)<<movingToIndex) captureHuh = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | captureHuh;
          possibleRookMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Rook Move Found: " << move << " ";
            if(captureHuh) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
      }
    }
    else if(yourBishops & u_int64_t(1)<<i){
      for(int j=0; j<28; j++){
        int movingToIndex = i+bishopMoves[j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t captureHuh = 0;
          if(enemyPeices & u_int64_t(1)<<movingToIndex) captureHuh = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | captureHuh;
          possibleBishopMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Bishop Move Found: " << move << " ";
            if(captureHuh) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
      }
      
    }
    else if(yourKnights & u_int64_t(1)<<i){
      for(int j=0; j<8; j++){
        int movingToIndex = i+knightMoves[j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t captureHuh = 0;
          if(enemyPeices & u_int64_t(1)<<movingToIndex) captureHuh = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | captureHuh;
          possibleKnightMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Knight Move Found: " << move << " ";
            if(captureHuh) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
      }
    }
    else if(yourPawns & u_int64_t(1)<<i){
      
    }
} 
    return possibleKingMoves;
}


int main(){
Chessboard board = Chessboard();
board.configureBoards("4k3/3q4/3N4/B7/8/8/3Q4/4K3");
board.prettyPrint();
board.getLegalMoves();
std::cout << "done" << "\n";

}