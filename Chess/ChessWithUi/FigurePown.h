#ifndef FIGUREPOWN_H
#define FIGUREPOWN_H

#include "stdafx.h"

#include "Piece.h"
#include "Coortdinate.h"

class Pown : public Piece {
public:
	Pown(PieceColor color, string image);
	~Pown(){};

	virtual bool CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep = false);
};

#endif
