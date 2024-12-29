#include <iostream>
#include <string>
class Chessboard {
    public:
        u_int64_t whiteKingBoard;
        u_int64_t whiteQueenBoard;
        u_int64_t whiteRookBoard;   
        u_int64_t whiteBishopBoard;
        u_int64_t whiteKnightBoard;
        u_int64_t whitePawnBoard;
        u_int64_t blackKingBoard;
        u_int64_t blackQueenBoard;
        u_int64_t blackRookBoard;   
        u_int64_t blackBishopBoard;
        u_int64_t blackKnightBoard;
        u_int64_t blackPawnBoard;

        void configureBoards(std::string fen);
        void prettyPrint();
        Chessboard();
};