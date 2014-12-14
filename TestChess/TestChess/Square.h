#ifndef SQUARE_H
#define SQUARE_H

#include "stdafx.h"

#include "Piece.h"

class Square {
public:
	Square(){};
	Square(Piece* piece);
	~Square(){};
	Piece* GetPiece();
	void SetPiece(Piece* piece);
private:
	Piece* currentPiece;
	
};

#endif