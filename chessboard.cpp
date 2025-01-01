#include <iostream>
#include "chessboard.h"


Chessboard::Chessboard(bool blackPeicesHuh){
  this->colorToPlay = blackPeicesHuh;
  this->configureBoards("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  this->prettyPrint();
  if(blackPeicesHuh){
    this->pawnMoves = this->pawnMovesBlack;
    this->enemyRank = 7;
  }
  else{
    this->enemyRank = 0;
    this->pawnMoves = this->pawnMovesWhite;
  } 
}

void Chessboard::configureBoards(std::string fen){
  std::string currChar = "";
  u_int8_t currBoardIndex = 0;
  u_int8_t whiteKingIndex = 100;
  u_int8_t blackKingIndex = 100;
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

  if(fen == "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR") this->pawnsElegibleForDoubleMove = 0b11111111;

  for(int i = 0; i<fen.length(); i++){
    currChar = fen.at(i);
    if(currChar == "K"){
      this->whiteKingBoard |= u_int64_t(1) << currBoardIndex;
      whiteKingIndex = currBoardIndex;
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
      blackKingIndex = currBoardIndex;
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
  if(this->colorToPlay){
    this->yourKing = this->blackKingBoard;
    this->yourQueen = this->blackQueenBoard;
    this->yourRooks = this->blackRookBoard;
    this->yourBishops = this->blackBishopBoard;
    this->yourKnights = this->blackKnightBoard;
    this->yourPawns = this->blackPawnBoard;
    this->yourKingIndex = blackKingIndex;

    this->enemyPeices = this->whiteKingBoard | this->whiteQueenBoard | this->whiteRookBoard | this->whiteBishopBoard | this->whiteKnightBoard | this->whitePawnBoard;
    this->yourPeices = this->blackKingBoard | this->blackQueenBoard | this->blackRookBoard | this->blackBishopBoard | this->blackKnightBoard | this->blackPawnBoard;
  }
  else{
    this->yourKing = this->whiteKingBoard;
    this->yourQueen = this->whiteQueenBoard;
    this->yourRooks = this->whiteRookBoard;
    this->yourBishops = this->whiteBishopBoard;
    this->yourKnights = this->whiteKnightBoard;
    this->yourPawns = this->whitePawnBoard;
    this->yourKingIndex = whiteKingIndex;

    this->enemyPeices = this->blackKingBoard | this->blackQueenBoard | this->blackRookBoard | this->blackBishopBoard | this->blackKnightBoard | this->blackPawnBoard;
    this->yourPeices = this->whiteKingBoard | this->whiteQueenBoard | this->whiteRookBoard | this->whiteBishopBoard | this->whiteKnightBoard | this->whitePawnBoard;
  }
  this->allPeices = this->enemyPeices | this->yourPeices;
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

std::vector<std::vector<u_int16_t>> Chessboard::getLegalMoves(){


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
  std::vector<u_int16_t> possibleKingMoves = {};
  std::vector<u_int16_t> possibleQueenMoves = {};
  std::vector<u_int16_t> possibleRookMoves = {};
  std::vector<u_int16_t> possibleBishopMoves = {};
  std::vector<u_int16_t> possibleKnightMoves = {};
  std::vector<u_int16_t> possiblePawnMoves = {};


  for(u_int64_t i = 0; i<64; i++){
    if(yourKing & u_int64_t(1)<<i){
      possibleKingMoves = this->getLegalMovesKing(i);
    }

    else if(yourQueen & u_int64_t(1)<<i){
      possibleQueenMoves = this->getLegalMovesQueen(i);
    }
    else if(yourRooks & u_int64_t(1)<<i){
      possibleRookMoves = this->getLegalMovesRook(i);
    }
    else if(yourBishops & u_int64_t(1)<<i){
      possibleBishopMoves = this->getLegalMovesBishop(i);
    }
    else if(yourKnights & u_int64_t(1)<<i){
      possibleKnightMoves = this->getLegalMovesKnight(i);
    }
    else if(yourPawns & u_int64_t(1)<<i){
      possiblePawnMoves = this->getLegalMovesPawn(i);
    }
} 
    std::vector<std::vector<u_int16_t>> retval = {possibleKingMoves, possibleQueenMoves, possibleRookMoves, possibleBishopMoves, possibleKnightMoves, possiblePawnMoves};
    return retval;
}

std::vector<u_int16_t> Chessboard::getLegalMovesKing(int currIndex){
  std::vector<u_int16_t> possibleKingMoves = {};
  for(int i = 0; i<size(this->kingMoves); i++){
    for(int j = 0; j<size(this->kingMoves[i]); j++){
      int movingToIndex = currIndex+this->kingMoves[i][j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(this->yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t flag = 0;
          if(this->enemyPeices & u_int64_t(1)<<movingToIndex) flag = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | flag;
          possibleKingMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "King Move Found: " << move << " ";
            if(flag) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
    }
  }
  return possibleKingMoves;
}

std::vector<u_int16_t> Chessboard::getLegalMovesQueen(int currIndex){
  std::vector<u_int16_t> possibleQueenMoves = {};
  for(int i = 0; i<size(this->queenMoves); i++){
    for(int j = 0; j<size(this->queenMoves[i]); j++){
      int movingToIndex = currIndex+this->queenMoves[i][j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(this->yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t flag = 0;
          if(this->enemyPeices & u_int64_t(1)<<movingToIndex) flag = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | flag;
          possibleQueenMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Queen Move Found: " << move << " ";
            if(flag) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
        if(int(this->allPeices & (u_int64_t(1) << movingToIndex))) break;
    }
  }
  return possibleQueenMoves;
}

std::vector<u_int16_t> Chessboard::getLegalMovesRook(int currIndex){
  std::vector<u_int16_t> possibleRookMoves = {};
  for(int i = 0; i<size(this->rookMoves); i++){
    for(int j = 0; j<size(this->rookMoves[i]); j++){
      int movingToIndex = currIndex+this->rookMoves[i][j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(this->yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t flag = 0;
          if(this->enemyPeices & u_int64_t(1)<<movingToIndex) flag = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | flag;
          possibleRookMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Rook Move Found: " << move << " ";
            if(flag) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
        if(int(this->allPeices & (u_int64_t(1) << movingToIndex))) break;
    }
  }
  return possibleRookMoves;
}

std::vector<u_int16_t> Chessboard::getLegalMovesBishop(int currIndex){
  std::vector<u_int16_t> possibleBishopMoves = {};
  for(int i = 0; i<size(this->bishopMoves); i++){
    for(int j = 0; j<size(this->bishopMoves[i]); j++){
      int movingToIndex = currIndex+this->bishopMoves[i][j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(this->yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t flag = 0;
          if(this->enemyPeices & u_int64_t(1)<<movingToIndex) flag = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | flag;
          possibleBishopMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Bishop Move Found: " << move << " ";
            if(flag) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
        if(int(this->allPeices & (u_int64_t(1) << movingToIndex))) break;
    }
  }
  return possibleBishopMoves;
}

std::vector<u_int16_t> Chessboard::getLegalMovesKnight(int currIndex){
  std::vector<u_int16_t> possibleKnightMoves = {};
  for(int i = 0; i<size(this->knightMoves); i++){
    for(int j = 0; j<size(this->knightMoves[i]); j++){
      int movingToIndex = currIndex+this->knightMoves[i][j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(this->yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          u_int8_t flag = 0;
          if(this->enemyPeices & u_int64_t(1)<<movingToIndex) flag = 4;
          move = ((((move | i) << 10) | movingToIndex) << 4) | flag;
          possibleKnightMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Knight Move Found: " << move << " ";
            if(flag) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
    }
  }
  return possibleKnightMoves;
}

int getRank(int index){
  return int(index/8);
}

std::vector<u_int16_t> Chessboard::getLegalMovesPawn(int currIndex){
  std::vector<u_int16_t> possiblePawnMoves = {};
  int startingIndex = 0;
  if((this->yourPawns & u_int64_t(1)<<currIndex) & (this->pawnsElegibleForDoubleMove & (u_int8_t(1)<<(currIndex%8)))) startingIndex = 1;
  for(int i = startingIndex; i<size(this->pawnMoves); i++){
    for(int j = 0; j<size(this->pawnMoves[i]); j++){
      int movingToIndex = currIndex+this->pawnMoves[i][j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(this->yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          std::vector<u_int8_t> flag = {};
          switch(i)
          {
          case 0:
            if((this->enemyPeices & u_int64_t(1)<<movingToIndex) == 0) flag.push_back(1);
            break;
          case 1:
            if((this->enemyPeices & u_int64_t(1)<<movingToIndex) == 0){
              if(getRank(movingToIndex) ==  this->enemyRank){
                flag.push_back(u_int8_t(0b0110));
                flag.push_back(u_int8_t(0b0111));
                flag.push_back(u_int8_t(0b1000));
                flag.push_back(u_int8_t(0b1001));
              }
              else{
                flag.push_back(0);
              }
            }
            break;
          case 2:
            if(this->enemyPeices & u_int64_t(1)<<movingToIndex){
              if(getRank(movingToIndex) ==  this->enemyRank){
                flag.push_back(u_int8_t(0b1010));
                flag.push_back(u_int8_t(0b1011));
                flag.push_back(u_int8_t(0b1100));
                flag.push_back(u_int8_t(0b1101));
              }
              else{
                flag.push_back(4);
              }
            }
            break;
          default:
            std::cerr << "Get Legal Pawn Moves is Broken" << "\n";
            break;
          }

          for(int k = 0; k<size(flag); k++){
            move = ((((move | i) << 10) | movingToIndex) << 4) | flag[k];
            possiblePawnMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Pawn Move Found: " << move << " ";
            switch(flag[k]){
              case 0:
                std::cout<<"Quiet Move";
                break;
              case 1:
                std::cout<<"Double Pawn";
                break;
              case 4:
                std::cout<<"Capture";
                break;
              case 5:
                std::cout<<"Capture En Passant";
                break;
              case 6:
                std::cout<<"Knight Promotion";
                break;
              case 7:
                std::cout<<"Bishop Promotion";
                break;
              case 8:
                std::cout<<"Rook Promotion";
                break;
              case 9:
                std::cout<<"Queen Promtion";
                break;
              case 10:
                std::cout<<"Knight Promotion and Capture";
                break;
              case 11:
                std::cout<<"Bishop Promotion and Capture";
                break;
              case 12:
                std::cout<<"Rook Promotion and Capture";
                break;
              case 13:
                std::cout<<"Queen Promotion and Capture";
                break;
            }
            std::cout << "\n";
          #endif
          }

        }
    }
  }
  return possiblePawnMoves;
}

std::vector<std::vector<u_int16_t>> Chessboard::removeCheckMoves(std::vector<std::vector<u_int16_t>> fullMoveList){
  for(int i=0; i<size(fullMoveList); i++){

  }
}
//possibleKingMoves, possibleQueenMoves, possibleRookMoves, possibleBishopMoves, possibleKnightMoves, possiblePawnMoves
std::vector<Chessboard> Chessboard::movesToBoards(Chessboard oldBoard, std::vector<std::vector<u_int16_t>> moves){
  std::vector<Chessboard> retList = {};
  for(int i = 0; i<size(moves); i++){
    for(int j=0; j<size(moves[i]); j++){
      Chessboard currentBoard = oldBoard;
      u_int16_t flag = moves[i][j] & u_int16_t(15);
      u_int16_t fromIndex = (moves[i][j] & 0b1111110000000000) >> 10;
      u_int16_t toIndex = (moves[i][j] & 0b0000001111110000) >> 4;
      switch (i)
      {
      case 0:
        if(flag == 4){
          currentBoard.yourKing &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourKing |= u_int64_t(1) << toIndex;

          currentBoard.
        }
        else{

        }
        break;
      
      default:
        break;
      }
    }
  }
}

int main(){
Chessboard board = Chessboard(false);
board.configureBoards("4k3/3q4/3N4/B7/8/8/3Q4/4K1P1");
board.prettyPrint();
board.getLegalMoves();
std::cout << "done" << "\n";

}