#include <iostream>
#include <math.h>
#include "game.h"
#include <algorithm>
#include <cctype>
#include <fstream>

Game::Game(){
    this->playGameUCI(2);
}

std::ofstream logFile("debug.log");

void logMessage(const std::string &direction, const std::string &message) {
    if (logFile.is_open()) {
        logFile << direction << ": " << message << std::endl;
    }
}

void Game::playGameCLI(int depth){
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

void Game::playGameUCI(int depth){
    while(true){
        std::string command;
        if (!std::getline(std::cin, command)) {
            break;
        }
        logMessage("Received", command);
        if (command == "uci") {
            std::cout << "id name Pringles\n";
            logMessage("Sent", "id name Pringles\n");
            std::cout << "id author Sarah\n";
            logMessage("Sent", "id author Sarah\n");
            std::cout << "uciok\n";
            logMessage("Sent", "uciok\n");
        }
        else if(command == "isready") {
            std::cout << "readyok\n";
            logMessage("Sent", "readyok\n");
        }
        else if(command == "ucinewgame") {
            this->board.configureBoards("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
        }
        else if(command.rfind("position", 0) == 0) {
            bool color = this->board.colorToPlay;
            command.erase(std::remove_if(command.begin(), command.end(), ::isspace),command.end());
            int movesIndex = command.rfind("moves");
            int fenIndex = command.rfind("fen"); 

            if(command.rfind("startpos") < command.length()){
                // this->board.configureBoards("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

                }
            else if(fenIndex < command.length()){
                std::string intermediate = command.substr(fenIndex + 3);
                this->board.configureBoards(intermediate);
            }
            std::string moves = command.substr(movesIndex+5);
            this->board.switchColor();
            for(int i = 0; i<moves.length()/4;i++){
                this->board = this->board.configureBoardFromAlgMove(moves.substr(4*i, 4));
                this->board.switchColor();
                }
            this->board.switchColor(color);
            #ifdef DEBUG_PRINT_ENABLED
                this->board.prettyPrint();
            #endif
        }
        else if(command.rfind("go", 0) == 0) {
            u_int16_t move = this->brain.getBestMove(this->board, depth);
            std::string moveStr = this->board.moveToLongAlgebraic(move);
            std::cout<<"bestmove " + moveStr << "\n";
            std::cout<<"bestmove " + moveStr << "\n";
            std::cout<<"bestmove " + moveStr << "\n";
            std::cout<<"bestmove " + moveStr << "\n";
            std::cout<<"bestmove " + moveStr << "\n";
            logMessage("Sent", "bestmove " + moveStr);
            #ifdef DEBUG_PRINT_ENABLED
                this->board.prettyPrint();
            #endif
        }
        else if (command == "quit") {
            break;
        }
    } 
}

// first move: rnbqkbnr/pppp1ppp/8/4p3/8/2N5/PPPPPPPP/R1BQKBNR
//second move: r1bqkbnr/pppp1ppp/2n5/4p3/8/2N2N2/PPPPPPPP/R1BQKB1R
//third move: r1bqkb1r/pppp1ppp/2n2n2/4p3/4P3/2N2N2/PPPP1PPP/R1BQKB1R
//

int main(){
    Game game = Game();
    // Chessboard board = Chessboard(false);
    // Brain brain = Brain();
    // std::cout<<brain.evaluate(board)<<"\n";
    // board.getLegalMoves();
}