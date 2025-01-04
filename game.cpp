#include <iostream>
#include <math.h>
#include "game.h"

Game::Game(){
    this->playGame(3);
}

void Game::playGame(int depth){
    if(!this->board.colorToPlay){
        while(true){
            u_int16_t move = this->brain.getBestMove(this->board, depth);
            std::cout<< move <<"\n";
            this->board = this->board.moveToBoard(move);
            this->board.prettyPrint();
            std::string responseFen = "";
            std::cin >> responseFen;
            this->board.configureBoards(responseFen);
            this->board.prettyPrint();
        }
    }
    else{
        while(true){
            this->board.prettyPrint();
            std::string responseFen = "";
            std::cin >> responseFen;
            this->board.configureBoards(responseFen);
            this->board.prettyPrint();
            u_int16_t move = this->brain.getBestMove(this->board, depth);
            std::cout<< move <<"\n";
            this->board = this->board.moveToBoard(move);
        }
    }
}

// first move: rnbqkbnr/pppp1ppp/8/4p3/8/2N5/PPPPPPPP/R1BQKBNR
//second move: r1bqkbnr/pppp1ppp/2n5/4p3/8/2N2N2/PPPPPPPP/R1BQKB1R
//third move: r1bqkb1r/pppp1ppp/2n2n2/4p3/4P3/2N2N2/PPPP1PPP/R1BQKB1R

int main(){
    Game game = Game();
    // Chessboard board = Chessboard(false);
    // Brain brain = Brain();
    // std::cout<<brain.evaluate(board)<<"\n";
    // board.getLegalMoves();
}