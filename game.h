#pragma once
#include <iostream>
#include <vector>
#include "chessboard.h"
#include "brain.h"
class Game {
    public:
        Chessboard board = Chessboard(false);
        Brain brain = Brain();
        Game();
        void playGameCLI(int depth);
        void playGameUCI(int depth);
        int main();
};