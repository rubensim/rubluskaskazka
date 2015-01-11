#ifndef FIGUREKING_H
#define FIGUREKING_H

#include "stdafx.h"
#include "Piece.h"
#include "Coortdinate.h"

class King: public Piece {
public:
	King(PieceColor color, string image);
	~King();

	virtual bool CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep = false);
};

#endif
