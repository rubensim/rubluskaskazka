#ifndef SQUARE_H
#define SQUARE_H

#include "stdafx.h"

#include "Piece.h"
#include "Coortdinate.h"

class Square {
public:
	Square(Coordinate coordinate, PieceColor color,Piece* piece = nullptr);
	~Square();

	Piece* GetPiece();
	void SetPiece(Piece* piece);
	
	Coordinate GetCoordinate();
	void SetCoordinate(Coordinate coordinate); 
	bool MovePiece(Square* square);
	PieceColor GetColor();

	static PieceColor LastStepColor;
private:
	Piece* currentPiece;
	PieceColor color;
	Coordinate coordinate;
};

#endif