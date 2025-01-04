#pragma once
#include <iostream>
#include <vector>
#include "chessboard.h"
class Brain {
    public:
        float whiteKingWeight = 900;
        float whiteQueenWeight = 90;
        float whiteRookWeight = 50;
        float whiteBishopWeight = 30;
        float whiteKnightWeight = 30;
        float whitePawnWeight = 10;
        float blackKingWeight = -900;
        float blackQueenWeight = -90;
        float blackRookWeight = -50;
        float blackBishopWeight = -30;
        float blackKnightWeight = -30;
        float blackPawnWeight = -10;

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
                blackKingPSQT.push_back(-1.0*whiteKingPSQT[vectorLength-1-i]);
                blackQueenPSQT.push_back(-1.0*whiteQueenPSQT[vectorLength-1-i]);
                blackRookPSQT.push_back(-1.0*whiteRookPSQT[vectorLength-1-i]);
                blackBishopPSQT.push_back(-1.0*whiteBishopPSQT[vectorLength-1-i]);
                blackKnightPSQT.push_back(-1.0*whiteKnightPSQT[vectorLength-1-i]);
                blackPawnPSQT.push_back(-1.0*whitePawnPSQT[vectorLength-1-i]);
            }
        }

        Brain();

        float minimax(Chessboard board, int depth);

        float evaluate(Chessboard board);

        u_int16_t getBestMove(Chessboard board, int depth);
};