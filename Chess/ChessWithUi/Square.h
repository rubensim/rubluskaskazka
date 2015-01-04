#ifndef SQUARE_H
#define SQUARE_H

#include "stdafx.h"

#include "Piece.h"
#include "Coortdinate.h"

class Square {
public:
	Square(){ this->cordinate = new Coordinate(); }
	Square(Piece* piece);
	~Square(){};
	Piece* GetPiece();
	void SetPiece(Piece* piece);
	void CreatePiece(PieceType type, PieceColor color, string image);
	Coordinate* cordinate;
private:
	Piece* currentPiece;
	PieceColor color;
};

#endif