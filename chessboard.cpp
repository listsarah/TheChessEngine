#include <iostream>
#include "chessboard.h"

Chessboard::Chessboard(){
  this->configureBoards("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  this->prettyPrint();
}

void Chessboard::configureBoards(std::string fen){
  std::string currChar = "";
  u_int8_t currBoardIndex = 0;
  static u_int64_t theIndexinator = 1;
  for(int i = 0; i<fen.length(); i++){
    currChar = fen.at(i);
    if(currChar == "K"){
      this->whiteKingBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "Q"){
      this->whiteQueenBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "R"){
      this->whiteRookBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "B"){
      this->whiteBishopBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "N"){
      this->whiteKnightBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "P"){
      this->whitePawnBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if(currChar == "k"){
      this->blackKingBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "q"){
      this->blackQueenBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "r"){
      this->blackRookBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "b"){
      this->blackBishopBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "n"){
      this->blackKnightBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if (currChar == "p"){
      this->blackPawnBoard |= theIndexinator << currBoardIndex;
      currBoardIndex++;
    }
    else if(currChar != "/"){
      try
      {
        currBoardIndex += std::stoi(currChar.c_str());
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
  }
}
void Chessboard::prettyPrint(){
  std::string board[] = {};
  for(int i = 0; i<64; i++){
    if(this->whiteKingBoard && 1) board[i] = "K";
    else if(this->whiteQueenBoard && 1) board[i] = "Q";
    else if(this->whiteRookBoard && 1) board[i] = "R";
    else if(this->whiteBishopBoard && 1) board[i] = "B";
    else if(this->whiteKnightBoard && 1) board[i] = "N";
    else if(this->whitePawnBoard && 1) board[i] = "P";
    else if(this->blackKingBoard && 1) board[i] = "k";
    else if(this->blackQueenBoard && 1) board[i] = "q";
    else if(this->blackRookBoard && 1) board[i] = "r";
    else if(this->blackBishopBoard && 1) board[i] = "b";
    else if(this->blackKnightBoard && 1) board[i] = "n";
    else if(this->blackPawnBoard && 1) board[i] = "p";
    else board[i] = " ";
    if(i%8==7){
      std::cout << board[i] << "\n";
    }
    else{
      std::cout << board[i] << " ";
    }
  }
}

Chessboard board = Chessboard();