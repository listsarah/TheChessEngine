#include <iostream>
#include <math.h>
#include "game.h"

Game::Game(){
    this->playGame(2);
}

void Game::playGame(int depth){
    if(!this->board.colorToPlay){
        u_int16_t move = this->brain.getBestMove(this->board, depth);
        std::cout<< move <<"\n";
        this->board = this->board.moveToBoard(move);
        this->board.prettyPrint();
        std::string responseFen = "";
        std::cin >> responseFen;
        std::cout << responseFen << '\n';
    }
}

int main(){
    Game game = Game();
    // Chessboard board = Chessboard(false);
    // board.getLegalMoves();
}