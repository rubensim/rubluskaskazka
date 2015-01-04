#ifndef ENUMS_H
#define ENUMS_H

enum PieceColor:char {White = 'w', Black = 'b'};
enum PieceType {_BISHOP, _PAWN, _KNIGHT, _QUEEN, _ROOK, _KING,_BLANK_PIECE };
enum State{New, InProgress, Cancel , None };

#endif
