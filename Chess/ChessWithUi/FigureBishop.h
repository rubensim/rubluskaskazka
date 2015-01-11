#ifndef FIGUREBISHOP_H_
#define FIGUREBISHOP_H_

#include "stdafx.h"
#include "Piece.h"
#include "Coortdinate.h"

class Bishop : public Piece {
public:
	Bishop(PieceColor color, string image = "");
	~Bishop();
	virtual bool CheckMove(Coordinate currentPosition, Coordinate movePosition);
};

#endif
