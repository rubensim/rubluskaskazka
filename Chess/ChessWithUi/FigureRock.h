#ifndef FIGUREROCK_H_
#define FIGUREROCK_H_

#include "stdafx.h"
#include "Piece.h"
#include "Coortdinate.h"

class Rock : public Piece {
public:
	Rock(PieceColor color, string image = "");
	~Rock();
	virtual bool CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep = false);
};

#endif
