#ifndef KING_H
#define KING_H

#include "stdafx.h"
#include "Piece.h"

class King: public Piece {
public:
	King(){};
	King(PieceColor color);
	~King(){};
	virtual bool CheckMove();
	virtual void DoMove();
};

#endif
