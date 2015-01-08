#ifndef SQUARE_H
#define SQUARE_H

#include "stdafx.h"

#include "Piece.h"
#include "Coortdinate.h"

class Square {
public:
	Square(Coordinate coordinate);
	Square(Piece* piece);
	~Square(){};

	Piece* GetPiece();
	void SetPiece(Piece* piece);
	void CreatePiece(PieceType type, PieceColor color, string image);
	Coordinate GetCoordinate();
	void SetCoordinate(Coordinate coordinate); 
private:
	Piece* currentPiece;
	PieceColor color;
	Coordinate coordinate;
};

#endif