#include <iostream>
#include "chessboard.h"

Chessboard::Chessboard(){
  this->configureBoards("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  this->prettyPrint();
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
int main(){
Chessboard board = Chessboard();
std::cout << "done" << "\n";

}