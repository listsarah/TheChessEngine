#pragma once
#include <iostream>
#include <vector>
#include "chessboard.h"
class Brain {
    public:
        int whiteKingWeight = 900;
        int whiteQueenWeight = 90;
        int whiteRookWeight = 50;
        int whiteBishopWeight = 30;
        int whiteKnightWeight = 30;
        int whitePawnWeight = 10;
        int blackKingWeight = -900;
        int blackQueenWeight = -90;
        int blackRookWeight = -50;
        int blackBishopWeight = -30;
        int blackKnightWeight = -30;
        int blackPawnWeight = -10;

        std::vector<double> whiteKingPSQT =  {-3, -4, -4, -5, -5, -4, -4, -3,
                                              -3, -4, -4, -5, -5, -4, -4, -3,
                                              -3, -4, -4, -5, -5, -4, -4, -3,
                                              -3, -4, -4, -5, -5, -4, -4, -3,
                                              -2, -3, -3, -4, -4, -3, -3, -2,
                                              -1, -2, -2, -2, -2, -2, -2, -1,
                                               2,  2,  0,  0,  0,  0,  2,  2,
                                               2,  3,  1,  0,  0,  1,  3,  2};

        std::vector<double> whiteQueenPSQT = {-2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0,
                                              -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0,
                                              -1.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -1.0,
                                              -0.5,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5,
                                               0.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5,
                                              -1.0,  0.5,  0.5,  0.5,  0.5,  0.5,  0.0, -1.0,
                                              -1.0,  0.0,  0.5,  0.0,  0.0,  0.0,  0.0, -1.0,
                                              -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0};
        
        std::vector<double> whiteRookPSQT = { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
                                              0.5,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  0.5,
                                             -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5,
                                             -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5,
                                             -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5,
                                             -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5,
                                             -0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5,
                                              0.0,  0.0,  0.0,  0.5,  0.5,  0.0,  0.0,  0.0};

        std::vector<double> whiteBishopPSQT = {-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0,
                                               -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0,
                                               -1.0,  0.0,  0.5,  1.0,  1.0,  0.5,  0.0, -1.0,
                                               -1.0,  0.5,  0.5,  1.0,  1.0,  0.5,  0.5, -1.0,
                                               -1.0,  0.0,  1.0,  1.0,  1.0,  1.0,  0.0, -1.0,
                                               -1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, -1.0,
                                               -1.0,  0.5,  0.0,  0.0,  0.0,  0.0,  0.5, -1.0,
                                               -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0};

        std::vector<double> whiteKnightPSQT = {-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0,
                                               -4.0, -2.0,  0.0,  0.0,  0.0,  0.0, -2.0, -4.0,
                                               -3.0,  0.0,  1.0,  1.5,  1.5,  1.0,  0.0, -3.0, 
                                               -3.0,  0.5,  1.5,  2.0,  2.0,  1.5,  0.5, -3.0,
                                               -3.0,  0.0,  1.5,  2.0,  2.0,  1.5,  0.0, -3.0,
                                               -3.0,  0.5,  1.0,  1.5,  1.5,  1.0,  0.5, -3.0,
                                               -4.0, -2.0,  0.0,  0.5,  0.5,  0.0, -2.0, -4.0,
                                               -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0};

        std::vector<double> whitePawnPSQT = { 0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
                                              5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0,
                                              1.0,  1.0,  2.0,  3.0,  3.0,  2.0,  1.0,  1.0,
                                              0.5,  0.5,  1.0,  2.5,  2.5,  1.0,  0.5,  0.5,
                                              0.0,  0.0,  0.0,  2.0,  2.0,  0.0,  0.0,  0.0,
                                              0.5, -0.5, -1.0,  0.0,  0.0, -1.0, -0.5,  0.5,
                                              0.5,  1.0,  1.0, -2.0, -2.0,  1.0,  1.0,  0.5,
                                              0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0};

        std::vector<double> blackKingPSQT = {};
        std::vector<double> blackQueenPSQT = {};
        std::vector<double> blackRookPSQT = {};
        std::vector<double> blackBishopPSQT = {};
        std::vector<double> blackKnightPSQT = {};
        std::vector<double> blackPawnPSQT = {};

        void setupPSQT(){
            int vectorLength = size(whiteKingPSQT);
            for(int i = 0; i<vectorLength; i++){
                blackKingPSQT.push_back(whiteKingPSQT[vectorLength-1-i]);
                blackQueenPSQT.push_back(whiteQueenPSQT[vectorLength-1-i]);
                blackRookPSQT.push_back(whiteRookPSQT[vectorLength-1-i]);
                blackBishopPSQT.push_back(whiteBishopPSQT[vectorLength-1-i]);
                blackKnightPSQT.push_back(whiteKnightPSQT[vectorLength-1-i]);
                blackPawnPSQT.push_back(whitePawnPSQT[vectorLength-1-i]);
            }
        }

        Brain();

        float minimax(Chessboard board, int depth);

        int evaluate(Chessboard board);

        u_int8_t getBestMove(Chessboard board, int depth);
};