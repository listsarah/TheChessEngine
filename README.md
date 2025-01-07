# The Chess Engine V1.0
## Overview
This chess engine using the minimax algorithm with a combination of hueristics to allow the engine to determine the best move. The minimax algorithm searches with a depth of 3. 
It also has a UCI interface that allows it to be used on any Chess GUI that supports the UCI protocol. It is a chessbot for a beginner or intermediate player.

## Hueristics
The bot uses two heuristics, the total weight of peices on the board, as well as the location of each peice. Peice square boards were hardcoded into the bot to "guide" peices towards
the squares where it is traditionally known they are stronger. The total weight of the board is determined by giving each peice a weight. The black and white peices have opposite
signs, and the totals of the peices left on the board, as well as their constant for their location on the board is summed. This value is used for evaluating the best next move.

## Chess Mechanics
### Board State
The board is stored using 12 64-bit unsigned integers. Each peice has its own 64-bit integer, where the bit at the index of the peice is a 1, and all empty places are 0s. These can be used together to determine the state of the board
at any time. This representation was choosen because it is more memory and time efficient to do computations via bit-shifting, rather then having to create and look-up values from custom objects.

### Moves
The moves were stored using a 16-bit unsigned integer. The most significant 6 bits represent the index the peice is comming from, the next 6 bits represent the index the peice is going
to, and the last four bits represent a flag used for capturing, promotions, and other special moves. This approach was choosen because it is memory efficient, and all information 
about the move can be gathered via bit-shifting, which is a fast operation. For each peice the legal moves were generated, without considering if they put the king in check. 
After the legal moves were generated, the moves were evaluated to ensure the king is not put in check by the move. This is determined by generating the legal moves from the other
players perspective for each of your legal moves. If any of the resulting boards do not contain a king (ie king was captured), then that move is not legal, as it puts the king in check.

## Shortcomings
- Does not handle castling. Neither the Chessbot, nor the user can castle during the game
- Pawns do not capture En Passant. The player can capture En Passant, but the Chessbot will not.
- Has only one set of piece square tables for each piece. Piece square tables for both the opening game, as well as the end game will be added in the future.
- The search depth is not adaptive. When both of the players have few peices during the end game, the bot has a hard time looking forward far enough to checkmate. This will be fixed by increasing the search depth based on the number of legal moves avaliable
