#include <iostream>
class Chessboard {
    public:
        u_int64_t board;

        //0x00 Pawn
        //0x01 Knight
        //0x02 Bishop
        //0x03 Rook
        //0x04 Queen
        //0x05 King
        u_int8_t peice;

        //0x00 Black
        //0x01 White
        bool color;

        void setup(u_int8_t type, bool color);
        void prettyPrint();
};