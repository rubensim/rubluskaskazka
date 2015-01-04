#ifndef PIECE_H
#define PIECE_H

#include "stdafx.h"

#include "Enums.h"
#include "Constants.h"
#include "Coortdinate.h"
#include <iostream>

using namespace std;

class Piece {
public:
	Piece(PieceColor color) :pieceColor(color){ this->isMoved = false; };
	Piece(PieceColor color, string image) : pieceColor(color), image(image){ this->isMoved = false; }
	virtual ~Piece(){};
	virtual bool CheckMove(Coordinate currentPosition, Coordinate movePosition) = 0;
	void DoMove(){ this->isMoved = true; }

	//get set methods
	void SetImage(string piecePath) { this->image = piecePath; }
	string GetImage(){ return this->image; }
	PieceColor GetColor(){
		return this->pieceColor;
	}

	bool HaseMoved(){ return this->isMoved; }

protected:
	bool isMoved;
	PieceColor pieceColor;
	string image;
};

#endif
