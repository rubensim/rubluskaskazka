#ifndef FIGUREQUEEN_H_
#define FIGUREQUEEN_H_

#include "stdafx.h"
#include "Piece.h"
#include "Coortdinate.h"

class Queen : public Piece {
public:
	Queen(PieceColor color, string image = "");
	~Queen();
	virtual bool CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep = false);
};

#endif
