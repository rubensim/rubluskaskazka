#ifndef PIECE_H
#define PIECE_H

#include "stdafx.h"

#include "Enums.h"
#include <iostream>

using namespace std;

class Piece {
public:
	Piece(){};
	Piece(PieceColor color){};
	virtual ~Piece(){};
	virtual bool CheckMove()= 0;
	virtual void DoMove() = 0;
	void SetImage(string piecePath) {this->image = piecePath;}
    PieceColor GetColor(){return this->color;}
protected:
	PieceColor color;
	string image;
};

#endif
