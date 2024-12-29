#include <iostream>
#include "chessboard.h"

Chessboard::Chessboard(){
  this->configureBoards("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
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
  for(int i = 0; i<64; i++){
    
  }

}