#ifndef FIGUREKNIGHT_H_
#define FIGUREKNIGHT_H_

#include "stdafx.h"
#include "Piece.h"
#include "Coortdinate.h"

class Knight : public Piece {
public:
	Knight(PieceColor color, string image = "");
	~Knight();
	virtual bool CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep = false);
};

#endif
