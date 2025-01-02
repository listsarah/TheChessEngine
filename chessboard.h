#include <iostream>
#include <string>
#include <list>
#include <vector>
class Chessboard {
    public:

        u_int64_t enemyPeices;
        u_int64_t yourPeices;
        u_int64_t allPeices;

        u_int64_t yourKing;
        u_int64_t yourQueen;
        u_int64_t yourRooks;
        u_int64_t yourBishops;
        u_int64_t yourKnights;
        u_int64_t yourPawns;

        u_int64_t enemyKing;
        u_int64_t enemyQueen;
        u_int64_t enemyRooks;
        u_int64_t enemyBishops;
        u_int64_t enemyKnights;
        u_int64_t enemyPawns;

        u_int8_t yourKingIndex;
        u_int8_t enemyKingIndex;

        bool colorToPlay;

        u_int8_t pawnsElegibleForDoubleMove;
        int enemyRank;

        std::vector<int> straightLeftMoves = {-1, -2, -3, -4, -5, -6, -7};
        std::vector<int> straightRightMoves = {1, 2, 3, 4, 5, 6, 7};
        std::vector<int> straightUpMoves = {-8, -16, -24, -32, -40, -48, -56};
        std::vector<int> straighDownMoves = {8, 16, 24, 32, 40, 48, 56};
        std::vector<int> diagonalLeftDownMoves = {7, 14, 21, 28, 35, 42, 49};
        std::vector<int> diagonalRightDownMoves = {9, 18, 27, 36, 45, 54, 63};
        std::vector<int> diagonalLeftUpMoves = {7, 14, 21, 28, 35, 42, 49};
        std::vector<int> diagonalRightUpMoves = {9, 18, 27, 36, 45, 54, 63};

        std::vector<std::vector<int>> pawnMovesWhite = {{-16}, {-8}, {-7, -9}};
        std::vector<std::vector<int>> pawnMovesBlack = {{-16}, {-8}, {-7, -9}};

        std::vector<std::vector<int>> kingMoves = {{-9, -8, -7, -1, 1, 7, 8, 9}};
        std::vector<std::vector<int>> queenMoves = {straightLeftMoves, straightRightMoves, straightUpMoves, straighDownMoves, diagonalLeftDownMoves, diagonalRightDownMoves, diagonalLeftUpMoves, diagonalRightUpMoves};
        std::vector<std::vector<int>> rookMoves = {straightLeftMoves, straightRightMoves, straightUpMoves, straighDownMoves};
        std::vector<std::vector<int>> bishopMoves = {diagonalLeftDownMoves, diagonalRightDownMoves, diagonalLeftUpMoves, diagonalRightUpMoves};
        std::vector<std::vector<int>> knightMoves = {{15, 17, 6, 10, -15, -17, -6, -10}};
        std::vector<std::vector<int>> pawnMoves;
        

        void configureBoards(std::string fen);
        void prettyPrint();
        
        std::vector<std::vector<u_int16_t>> getLegalMoves();
        std::vector<u_int16_t> getLegalMovesKing(int currIndex);
        std::vector<u_int16_t> getLegalMovesQueen(int currIndex);
        std::vector<u_int16_t> getLegalMovesRook(int currIndex);
        std::vector<u_int16_t> getLegalMovesBishop(int currIndex);
        std::vector<u_int16_t> getLegalMovesKnight(int currIndex);
        std::vector<u_int16_t> getLegalMovesPawn(int currIndex);

        std::vector<std::vector<u_int16_t>> removeCheckMoves(std::vector<std::vector<u_int16_t>> fullMoveList);
        std::vector<Chessboard> movesToBoards(std::vector<std::vector<u_int16_t>> moves);

        int main();
        Chessboard(bool blackPeicesHuh);

        Chessboard(const Chessboard& other) {
            this->colorToPlay = other.colorToPlay;
            this->enemyRank = other.enemyRank;
            this->pawnsElegibleForDoubleMove = other.pawnsElegibleForDoubleMove;
            this->pawnMoves = other.pawnMoves;
            this->yourKingIndex = other.yourKingIndex;
            this->enemyKingIndex = other.enemyKingIndex;

            this->yourKing = other.yourKing;
            this->yourQueen = other.yourQueen;
            this->yourRooks = other.yourRooks;
            this->yourBishops = other.yourBishops;
            this->yourKnights = other.yourKnights;
            this->yourPawns = other.yourPawns;
            this->enemyKing = other.enemyKing;
            this->enemyQueen = other.enemyQueen;
            this->enemyRooks = other.enemyRooks;
            this->enemyBishops = other.enemyBishops;
            this->enemyKnights = other.enemyKnights;
            this->enemyPawns = other.enemyPawns;

            this->allPeices = other.allPeices;
            this->yourPeices = other.yourPeices;
            this->enemyPeices = other.enemyPeices;

            this->straightLeftMoves = other.straightLeftMoves;
            this->straightRightMoves = other.straightRightMoves;
            this->straightUpMoves = other.straightUpMoves;
            this->straighDownMoves = other.straighDownMoves;
            this->diagonalLeftDownMoves = other.diagonalLeftDownMoves;
            this->diagonalLeftUpMoves = other.diagonalLeftUpMoves;
            this->diagonalRightDownMoves = other.diagonalRightDownMoves;
            this->diagonalRightUpMoves = other.diagonalRightUpMoves;

            this->pawnMovesBlack = other.pawnMovesBlack;
            this->pawnMovesWhite = other.pawnMovesWhite;

            this->kingMoves = other.kingMoves;
            this->queenMoves = other.queenMoves;
            this->rookMoves = other.rookMoves;
            this->bishopMoves = other.bishopMoves;
            this->knightMoves = other.knightMoves;
        }

};