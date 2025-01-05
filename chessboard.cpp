#include <iostream>
#include "chessboard.h"
#include <math.h>

Chessboard::Chessboard(bool blackPeicesHuh){
  this->colorToPlay = blackPeicesHuh;
  this->configureBoards("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
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
  u_int64_t whiteKingBoard = 0;
  u_int64_t whiteQueenBoard = 0;
  u_int64_t whiteRookBoard = 0;
  u_int64_t whiteBishopBoard = 0;
  u_int64_t whiteKnightBoard = 0;
  u_int64_t whitePawnBoard = 0;
  u_int64_t blackKingBoard = 0;
  u_int64_t blackQueenBoard = 0;
  u_int64_t blackRookBoard = 0;
  u_int64_t blackBishopBoard = 0;
  u_int64_t blackKnightBoard = 0;
  u_int64_t blackPawnBoard = 0;

  if(fen == "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"){
    this->yourPawnsEligableForDoubleMove = 0b11111111;
    this->enemyPawnsEligableForDoubleMove = 0b11111111;
  }

  for(int i = 0; i<fen.length(); i++){
    currChar = fen.at(i);
    if(currChar == "K"){
      whiteKingBoard |= u_int64_t(1) << currBoardIndex;
      whiteKingIndex = currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White King" << "\n";
      #endif
    }
    else if (currChar == "Q"){
      whiteQueenBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Queen" << "\n";
      #endif
    }
    else if (currChar == "R"){
      whiteRookBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Rook" << "\n";
      #endif
    }
    else if (currChar == "B"){
      whiteBishopBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Bishop" << "\n";
      #endif
    }
    else if (currChar == "N"){
      whiteKnightBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Knight" << "\n";
      #endif
    }
    else if (currChar == "P"){
      whitePawnBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "White Pawn" << "\n";
      #endif
    }
    else if(currChar == "k"){
      blackKingBoard |= u_int64_t(1) << currBoardIndex;
      blackKingIndex = currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black King" << "\n";
      #endif
    }
    else if (currChar == "q"){
      blackQueenBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
      std::cout << "Black Queen" << "\n";
      #endif
    }
    else if (currChar == "r"){
      blackRookBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black Rook" << "\n";
      #endif
    }
    else if (currChar == "b"){
      blackBishopBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black Bishop" << "\n";
      #endif
    }
    else if (currChar == "n"){
      blackKnightBoard |= u_int64_t(1) << currBoardIndex;
      currBoardIndex++;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Black Knight" << "\n";
      #endif
    }
    else if (currChar == "p"){
      blackPawnBoard |= u_int64_t(1) << currBoardIndex;
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
    if(currBoardIndex > 63){
      break;
    }
  }
  if(this->colorToPlay){
    std::cout<<"should not print \n";
    this->yourKing = blackKingBoard;
    this->yourQueen = blackQueenBoard;
    this->yourRooks = blackRookBoard;
    this->yourBishops = blackBishopBoard;
    this->yourKnights = blackKnightBoard;
    this->yourPawns = blackPawnBoard;
    this->yourKingIndex = blackKingIndex;

    this->enemyKing = whiteKingBoard;
    this->enemyQueen = whiteQueenBoard;
    this->enemyRooks = whiteRookBoard;
    this->enemyBishops = whiteBishopBoard;
    this->enemyKnights = whiteKnightBoard;
    this->enemyPawns = whitePawnBoard;
    this->enemyKingIndex = whiteKingIndex;
  }
  else{

    this->yourKing = whiteKingBoard;
    this->yourQueen = whiteQueenBoard;
    this->yourRooks = whiteRookBoard;
    this->yourBishops = whiteBishopBoard;
    this->yourKnights = whiteKnightBoard;
    this->yourPawns = whitePawnBoard;
    this->yourKingIndex = whiteKingIndex;

    this->enemyKing = blackKingBoard;
    this->enemyQueen = blackQueenBoard;
    this->enemyRooks = blackRookBoard;
    this->enemyBishops = blackBishopBoard;
    this->enemyKnights = blackKnightBoard;
    this->enemyPawns = blackPawnBoard;
    this->enemyKingIndex = blackKingIndex;

  }
  this->enemyPeices = this->enemyKing | this->enemyQueen | this->enemyRooks | this->enemyBishops | this->enemyKnights | this->enemyPawns;
  this->yourPeices = this->yourKing | this->yourQueen | this->yourRooks | this->yourBishops | this->yourKnights | this->yourPawns;
  this->allPeices = this->enemyPeices | this->yourPeices;
}


void Chessboard::prettyPrint(){
  std::string board[64] = {};
  if(this->colorToPlay){
    for(u_int64_t i = 0; i<64; i++){
      if(this->enemyKing & u_int64_t(1)<<i) board[i] = "K";
      else if(this->enemyQueen & u_int64_t(1)<<i) board[i] = "Q";
      else if(this->enemyRooks & u_int64_t(1)<<i) board[i] = "R";
      else if(this->enemyBishops & u_int64_t(1)<<i) board[i] = "B";
      else if(this->enemyKnights & u_int64_t(1)<<i) board[i] = "N";
      else if(this->enemyPawns & u_int64_t(1)<<i) board[i] = "P";
      else if(this->yourKing & u_int64_t(1)<<i) board[i] = "k";
      else if(this->yourQueen & u_int64_t(1)<<i) board[i] = "q";
      else if(this->yourRooks & u_int64_t(1)<<i) board[i] = "r";
      else if(this->yourBishops & u_int64_t(1)<<i) board[i] = "b";
      else if(this->yourKnights & u_int64_t(1)<<i) board[i] = "n";
      else if(this->yourPawns & u_int64_t(1)<<i) board[i] = "p";
      else board[i] = " ";
      if(i%8==7){
        std::cout << board[i] << "\n";
      }
      else{
        std::cout << board[i] << " ";
      }
    }
  }
  else{
    for(u_int64_t i = 0; i<64; i++){
      if(this->enemyKing & u_int64_t(1)<<i) board[i] = "k";
      else if(this->enemyQueen & u_int64_t(1)<<i) board[i] = "q";
      else if(this->enemyRooks & u_int64_t(1)<<i) board[i] = "r";
      else if(this->enemyBishops & u_int64_t(1)<<i) board[i] = "b";
      else if(this->enemyKnights & u_int64_t(1)<<i) board[i] = "n";
      else if(this->enemyPawns & u_int64_t(1)<<i) board[i] = "p";
      else if(this->yourKing & u_int64_t(1)<<i) board[i] = "K";
      else if(this->yourQueen & u_int64_t(1)<<i) board[i] = "Q";
      else if(this->yourRooks & u_int64_t(1)<<i) board[i] = "R";
      else if(this->yourBishops & u_int64_t(1)<<i) board[i] = "B";
      else if(this->yourKnights & u_int64_t(1)<<i) board[i] = "N";
      else if(this->yourPawns & u_int64_t(1)<<i) board[i] = "P";
      else board[i] = " ";
      if(i%8==7){
        std::cout << board[i] << "\n";
      }
      else{
        std::cout << board[i] << " ";
      }
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
      std::vector<u_int16_t> legalKingMoves = this->getLegalMovesKing(i);
      possibleKingMoves.insert(possibleKingMoves.end(), legalKingMoves.begin(), legalKingMoves.end());
    }

    else if(yourQueen & u_int64_t(1)<<i){
      std::vector<u_int16_t> legalQueenMoves = this->getLegalMovesQueen(i);
      possibleQueenMoves.insert(possibleQueenMoves.end(), legalQueenMoves.begin(), legalQueenMoves.end());
    }
    else if(yourRooks & u_int64_t(1)<<i){
      std::vector<u_int16_t> legalRookMoves = this->getLegalMovesRook(i);
      possibleRookMoves.insert(possibleRookMoves.end(), legalRookMoves.begin(), legalRookMoves.end());
    }
    else if(yourBishops & u_int64_t(1)<<i){
      std::vector<u_int16_t> legalBishopMoves = this->getLegalMovesBishop(i);
      possibleBishopMoves.insert(possibleBishopMoves.end(), legalBishopMoves.begin(), legalBishopMoves.end());
    }
    else if(yourKnights & u_int64_t(1)<<i){
      std::vector<u_int16_t> legalKnightMoves = this->getLegalMovesKnight(i);
      possibleKnightMoves.insert(possibleKnightMoves.end(), legalKnightMoves.begin(), legalKnightMoves.end());
    }
    else if(yourPawns & u_int64_t(1)<<i){
      std::vector<u_int16_t> legalPawnMoves = this->getLegalMovesPawn(i);
      possiblePawnMoves.insert(possiblePawnMoves.end(), legalPawnMoves.begin(), legalPawnMoves.end());
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
          move = ((((u_int16_t(currIndex) << 6) | movingToIndex) << 4) | flag);
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
          move = ((((u_int16_t(currIndex) << 6) | movingToIndex) << 4) | flag);
          possibleQueenMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Queen Move Found: " << move << " ";
            if(flag) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
        if(this->allPeices & (u_int64_t(1) << movingToIndex)!=0) break;
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
          move = ((((u_int16_t(currIndex) << 6) | movingToIndex) << 4) | flag);
          possibleRookMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Rook Move Found: " << move << " ";
            if(flag) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
        if(this->allPeices & (u_int64_t(1) << movingToIndex)!=0) break;
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
          move = ((((u_int16_t(currIndex) << 6) | movingToIndex) << 4) | flag);
          possibleBishopMoves.push_back(move);
          #ifdef DEBUG_PRINT_ENABLED
            std::cout << "Bishop Move Found: " << move << " ";
            if(flag) std::cout << "Capture";
            std::cout << "\n";
          #endif
        }
        if(this->allPeices & (u_int64_t(1) << movingToIndex)!=0) break;
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
          move = ((((u_int16_t(currIndex) << 6) | movingToIndex) << 4) | flag);
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
  return floor(index/8);
}

std::string getFile(int index){
  std::vector<std::string> files = {"a", "b", "c", "d", "e", "f", "g", "h"};
  return files[index%8];
}

int getIndexFromAlg(std::string algMove){
  std::string currChar = "";
  currChar = algMove.at(1);
  int rank = std::atoi(currChar.c_str());
  rank = (-1*rank + 8)*8;
  currChar = algMove.at(0);
  int file = 0;
  if(currChar == "b") file = 1;
  else if(currChar == "c") file =2;
  else if(currChar == "d") file = 3;
  else if(currChar == "e") file  = 4;
  else if(currChar == "f") file = 5;
  else if(currChar == "g") file = 6;
  else if(currChar == "h") file = 7;
  return rank + file;
}

Chessboard Chessboard::configureBoardFromAlgMove(std::string rankAndFile){
  int fromIndex = getIndexFromAlg(rankAndFile.substr(0, 2));
  int toIndex = getIndexFromAlg(rankAndFile.substr(2, 2));
  Chessboard currentBoard = Chessboard(*this);
  if(rankAndFile.length() == 5){
    if(rankAndFile.at(4) == 'n'){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKnights |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(rankAndFile.at(4) == 'b'){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourBishops |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(rankAndFile.at(4) == 'r'){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourRooks |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(rankAndFile.at(4) == 'q'){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourQueen |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
  }
  else{
    currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
    currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
    currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
    currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
    currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
    currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    
    if((currentBoard.yourKing & (u_int64_t(1) << fromIndex))){
      currentBoard.yourKing &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKing |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(currentBoard.yourQueen & (u_int64_t(1) << fromIndex)){
      currentBoard.yourQueen &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourQueen |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(currentBoard.yourRooks & (u_int64_t(1) << fromIndex)){
      currentBoard.yourRooks &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourRooks |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(currentBoard.yourBishops & (u_int64_t(1) << fromIndex)){
      currentBoard.yourBishops &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourBishops |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if((currentBoard.yourKnights & (u_int64_t(1) << fromIndex))){
      currentBoard.yourKnights &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKnights |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(currentBoard.yourPawns & (u_int64_t(1) << fromIndex)){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourPawns |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
  }
  currentBoard.enemyPeices = currentBoard.enemyKing | currentBoard.enemyQueen | currentBoard.enemyRooks | currentBoard.enemyBishops | currentBoard.enemyKnights | currentBoard.enemyPawns;
  currentBoard.yourPeices = currentBoard.yourKing | currentBoard.yourQueen | currentBoard.yourRooks | currentBoard.yourBishops | currentBoard.yourKnights | currentBoard.yourPawns;
  currentBoard.allPeices = currentBoard.enemyPeices | currentBoard.yourPeices;
  return currentBoard;
}

std::vector<u_int16_t> Chessboard::getLegalMovesPawn(int currIndex){
  std::vector<u_int16_t> possiblePawnMoves = {};
  int startingIndex = 0;
  if((this->yourPawns & u_int64_t(1)<<currIndex) & (this->yourPawnsEligableForDoubleMove & (u_int8_t(1)<<(currIndex%8)))) startingIndex = 1;
  for(int i = startingIndex; i<size(this->pawnMoves); i++){
    for(int j = 0; j<size(this->pawnMoves[i]); j++){
      int movingToIndex = currIndex+this->pawnMoves[i][j];
        if(movingToIndex >= 0 && movingToIndex < 64 && !(this->yourPeices & (u_int64_t(1) << movingToIndex))){
          u_int16_t move = 0;
          std::vector<u_int8_t> flag = {};
          switch(i)
          {
          case 0:
            if((this->enemyPeices & (u_int64_t(1)<<movingToIndex)) == u_int64_t(0)) flag.push_back(1);
            break;
          case 1:
            if((this->enemyPeices & (u_int64_t(1)<<movingToIndex)) == u_int64_t(0)){
              if(getRank(movingToIndex) ==  this->enemyRank){
                flag.push_back(6);
                flag.push_back(7);
                flag.push_back(8);
                flag.push_back(9);
              }
              else{
                flag.push_back(0);
              }
            }
            break;
          case 2:
            if((this->enemyPeices & (u_int64_t(1)<<movingToIndex)) != u_int64_t(0)){
              if(int(getRank(movingToIndex)) ==  int(this->enemyRank)){
                flag.push_back(10);
                flag.push_back(11);
                flag.push_back(12);
                flag.push_back(13);
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
            move = ((((u_int16_t(currIndex) << 6) | movingToIndex) << 4) | flag[k]);
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

Chessboard Chessboard::moveToBoard(u_int16_t move){
  u_int16_t flag = move & u_int16_t(15);
  u_int16_t fromIndex = (move & 0b1111110000000000) >> 10;
  u_int16_t toIndex = (move & 0b0000001111110000) >> 4;
  Chessboard currentBoard = Chessboard(*this);

  if(currentBoard.yourKing & (u_int64_t(1) << fromIndex)){
    if(flag == 4){
      currentBoard.yourKing &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKing |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else{
      currentBoard.yourKing &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKing |= u_int64_t(1) << toIndex;
    }
  }
  else if(currentBoard.yourQueen & (u_int64_t(1) << fromIndex)){
    if(flag == 4){
      currentBoard.yourQueen &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourQueen |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else{
      currentBoard.yourQueen &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourQueen |= u_int64_t(1) << toIndex;
    }
  }
  else if(currentBoard.yourRooks & (u_int64_t(1) << fromIndex)){
    if(flag == 4){
      currentBoard.yourRooks &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourRooks |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else{
      currentBoard.yourRooks &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourRooks |= u_int64_t(1) << toIndex;
    }
  }
  else if(currentBoard.yourBishops & (u_int64_t(1) << fromIndex)){
    if(flag == 4){
      currentBoard.yourBishops &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourBishops |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else{
      currentBoard.yourBishops &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourBishops |= u_int64_t(1) << toIndex;
    }
  }
  else if(currentBoard.yourKnights & (u_int64_t(1) << fromIndex)){
    if(flag == 4){
      currentBoard.yourKnights &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKnights |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else{
      currentBoard.yourKnights &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKnights |= u_int64_t(1) << toIndex;
    }
  }
  else if(currentBoard.yourPawns & (u_int64_t(1) << fromIndex)){
    if(flag == 0 || flag == 1){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourPawns |= u_int64_t(1) << toIndex;
    }
    else if(flag == 4 || flag == 5){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourPawns |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(flag == 6){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKnights |= u_int64_t(1) << toIndex;
    }
    else if(flag == 7){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourBishops |= u_int64_t(1) << toIndex;
    }
    else if(flag == 8){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourRooks |= u_int64_t(1) << toIndex;
    }
    else if(flag == 9){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourQueen |= u_int64_t(1) << toIndex;
    }
    else if(flag == 10){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourKnights |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(flag == 11){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourBishops |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(flag == 12){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourRooks |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
    else if(flag == 13){
      currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
      currentBoard.yourQueen |= u_int64_t(1) << toIndex;

      currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
      currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
    }
  }
  currentBoard.enemyPeices = currentBoard.enemyKing | currentBoard.enemyQueen | currentBoard.enemyRooks | currentBoard.enemyBishops | currentBoard.enemyKnights | currentBoard.enemyPawns;
  currentBoard.yourPeices = currentBoard.yourKing | currentBoard.yourQueen | currentBoard.yourRooks | currentBoard.yourBishops | currentBoard.yourKnights | currentBoard.yourPawns;
  currentBoard.allPeices = currentBoard.enemyPeices | currentBoard.yourPeices;
  return currentBoard;
}

//possibleKingMoves, possibleQueenMoves, possibleRookMoves, possibleBishopMoves, possibleKnightMoves, possiblePawnMoves
std::vector<Chessboard> Chessboard::movesToBoards(std::vector<std::vector<u_int16_t>> moves){
  std::vector<Chessboard> retList = {};
  for(int i = 0; i<size(moves); i++){
    for(int j=0; j<size(moves[i]); j++){
      Chessboard currentBoard = Chessboard(*this);
      u_int16_t flag = moves[i][j] & u_int16_t(15);
      u_int16_t fromIndex = (moves[i][j] & 0b1111110000000000) >> 10;
      u_int16_t toIndex = (moves[i][j] & 0b0000001111110000) >> 4;
      switch (i)
      {
      case 0:
        if(flag == 4){
          currentBoard.yourKing &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourKing |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else{
          currentBoard.yourKing &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourKing |= u_int64_t(1) << toIndex;
        }
        break;
      case 1:
        if(flag == 4){
          currentBoard.yourQueen &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourQueen |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else{
          currentBoard.yourQueen &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourQueen |= u_int64_t(1) << toIndex;
        }
        break;
      case 2:
        if(flag == 4){
          currentBoard.yourRooks &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourRooks |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else{
          currentBoard.yourRooks &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourRooks |= u_int64_t(1) << toIndex;
        }
        break;
      case 3:
        if(flag == 4){
          currentBoard.yourBishops &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourBishops |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else{
          currentBoard.yourBishops &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourBishops |= u_int64_t(1) << toIndex;
        }
        break;
      case 4:
        if(flag == 4){
          currentBoard.yourKnights &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourKnights |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else{
          currentBoard.yourKnights &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourKnights |= u_int64_t(1) << toIndex;
        }
        break;
      case 5:
        if(flag == 0 || flag == 1){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourPawns |= u_int64_t(1) << toIndex;
        }
        else if(flag == 4 || flag == 5){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourPawns |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else if(flag == 6){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourKnights |= u_int64_t(1) << toIndex;
        }
        else if(flag == 7){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourBishops |= u_int64_t(1) << toIndex;
        }
        else if(flag == 8){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourRooks |= u_int64_t(1) << toIndex;
        }
        else if(flag == 9){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourQueen |= u_int64_t(1) << toIndex;
        }
        else if(flag == 10){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourKnights |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else if(flag == 11){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourBishops |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else if(flag == 12){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourRooks |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        else if(flag == 13){
          currentBoard.yourPawns &= ~(u_int64_t(1) << fromIndex);
          currentBoard.yourQueen |= u_int64_t(1) << toIndex;

          currentBoard.enemyKing &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyQueen &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyRooks &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyBishops &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyKnights &= ~(u_int64_t(1) << toIndex);
          currentBoard.enemyPawns &= ~(u_int64_t(1) << toIndex);
        }
        break;
      }
      currentBoard.enemyPeices = currentBoard.enemyKing | currentBoard.enemyQueen | currentBoard.enemyRooks | currentBoard.enemyBishops | currentBoard.enemyKnights | currentBoard.enemyPawns;
      currentBoard.yourPeices = currentBoard.yourKing | currentBoard.yourQueen | currentBoard.yourRooks | currentBoard.yourBishops | currentBoard.yourKnights | currentBoard.yourPawns;
      currentBoard.allPeices = currentBoard.enemyPeices | currentBoard.yourPeices;
      retList.push_back(currentBoard);
    }
  }
  return retList;
}

void Chessboard::switchColor(){
            Chessboard intermediate = Chessboard(*this);
            this->colorToPlay = !this->colorToPlay;
            if(this->colorToPlay){
                this->pawnMoves = this->pawnMovesBlack;
                this->enemyRank = 7;
            }
            else{
                this->pawnMoves = this->pawnMovesWhite;
                this->enemyRank = 0;
            }
            this->yourPawnsEligableForDoubleMove = this->enemyPawnsEligableForDoubleMove;
            this->enemyPawnsEligableForDoubleMove = intermediate.yourPawnsEligableForDoubleMove;
            this->yourKingIndex = this->enemyKingIndex;
            this->enemyKingIndex = intermediate.yourKingIndex;

            this->yourKing = this->enemyKing;
            this->yourQueen = this->enemyQueen;
            this->yourRooks = this->enemyRooks;
            this->yourBishops = this->enemyBishops;
            this->yourKnights = this->enemyKnights;
            this->yourPawns = this->enemyPawns;
            this->enemyKing = intermediate.yourKing;
            this->enemyQueen = intermediate.yourQueen;
            this->enemyRooks = intermediate.yourRooks;
            this->enemyBishops = intermediate.yourBishops;
            this->enemyKnights = intermediate.yourKnights;
            this->enemyPawns = intermediate.yourPawns;

            this->yourPeices = this->enemyPeices;
            this->enemyPeices = intermediate.yourPeices;
        }


std::vector<std::vector<u_int16_t>> Chessboard::removeCheckMoves(std::vector<std::vector<u_int16_t>> yourFullMoveList){
  std::vector<Chessboard> yourPossibleBoards = this->movesToBoards(yourFullMoveList);
  std::vector<std::vector<u_int16_t>> nonCheckMoves = {{},{},{},{},{},{}};
  int boardIndex = 0;
  for(int i=0; i<size(yourFullMoveList); i++){
    for(int j=0; j<size(yourFullMoveList[i]); j++){
      yourPossibleBoards[boardIndex].switchColor();
      std::vector<std::vector<u_int16_t>> enemyMoves = yourPossibleBoards[boardIndex].getLegalMoves();
      std::vector<Chessboard> enemyPossibleBoards = yourPossibleBoards[boardIndex].movesToBoards(enemyMoves);
      bool check = false;
      for(int k=0; k<size(enemyPossibleBoards); k++){
        if(!enemyPossibleBoards[k].enemyKing){
          #ifdef DEBUG_PRINT_ENABLED
            std::cout<<"this move puts kind in check. Move: " << i << "\n"; 
          #endif
          check = true;
          break;
        }
      }
      boardIndex ++;
      if(!check){
        nonCheckMoves[i].push_back(yourFullMoveList[i][j]);
      }
    }
  }
      if(size(nonCheckMoves[0]) == 0 && size(nonCheckMoves[1]) == 0 && size(nonCheckMoves[2]) == 0 && size(nonCheckMoves[3]) == 0 && size(nonCheckMoves[4]) == 0 && size(nonCheckMoves[5]) == 0){
      this->gameOver = true;
      #ifdef DEBUG_PRINT_ENABLED
        std::cout << "Game Over" << "\n";
      #endif
    }
  #ifdef DEBUG_PRINT_ENABLED
    std::cout << "Noncheck moves: " << "\n";
    for(int i=0; i<size(nonCheckMoves); i++){
      for(int j=0; j<size(nonCheckMoves[i]); j++){
        std::cout << "i: " << i<< " move: "<< nonCheckMoves[i][j]<< "\n";
      }
    }
  #endif
  return nonCheckMoves;
}

std::string Chessboard::moveToLongAlgebraic(u_int16_t move){
  u_int16_t flag = move & u_int16_t(15);
  u_int16_t fromIndex = (move & 0b1111110000000000) >> 10;
  u_int16_t toIndex = (move & 0b0000001111110000) >> 4;

  std::string fromIndexString = "";
  std::string toIndexString = "";

  int fromRank = 8-getRank(int(fromIndex));
  int toRank = 8-getRank(int(toIndex));
  std::string fromFile = getFile(int(fromIndex));
  std::string toFile = getFile(int(toIndex));

  std::string promotion = "";
  if(flag == 6 || flag == 10) promotion = "n";
  else if(flag == 7 || flag == 11) promotion = "b";
  else if(flag == 8 || flag == 12) promotion = "r";
  else if(flag == 9 || flag == 13) promotion = "q";

  std::string retStr = fromFile + std::to_string(fromRank) + toFile + std::to_string(toRank) + promotion;
  #ifdef DEBUG_PRINT_ENABLED
    std::cout<< retStr << "\n"; 
  #endif
  return retStr;
}

void Chessboard::switchColor(bool blackPeicesHuh){
  if(this->colorToPlay ^ blackPeicesHuh){
    this->switchColor();
  }
}

u_int16_t longAlgebraicToMove(std::string longAlg);