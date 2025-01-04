#include <iostream>
#include <math.h>
#include "game.h"

Game::Game(){
    this->playGame(2);
}

void Game::playGame(int depth){
    if(!this->board.colorToPlay){
        u_int8_t move = this->brain.getBestMove(this->board, depth);
        this->board = this->board.movesToBoards({{move}})[0];
        this->board.prettyPrint();
        std::string responseFen = "";
        std::cin >> responseFen;
        std::cout << responseFen << '\n';
    }
}

int main(){
    Game game = Game();
}