#include <iostream>
#include "brain.h"

Brain::Brain(){
    this->setupPSQT();
}

u_int8_t Brain::minimax(Chessboard board, int depth, bool isMinimizing){
    if(depth == 0){
        return this->currBestMove;
    }
    std::vector<std::vector<u_int16_t>> legalMoves = board.getLegalMoves();
    for(int i=0; i<size(legalMoves); i++){
        for(int j=0; j<size(legalMoves[i]); j++){
            
        }
    }
    
}