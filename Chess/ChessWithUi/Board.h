#ifndef BOARD_H
#define BOARD_H

#include "stdafx.h"

#include "Square.h"
#include "Constants.h"
#include "Step.h"


class Board{
public:
	Board();
	~Board();

	void NewGame(int startX, int startY);

	Square * CreateSquare(Coordinate co, PieceColor color, int i, int j);
	void CreatePiece(int i, int j, Piece *piece);
	void SetPawns();
	void SetPieces();

	Square *GetSquare(int i, int j);

	static Step *Steps;
private:
	  Square* Squares[BOARD_SIZE][BOARD_SIZE] ;
};

#endif