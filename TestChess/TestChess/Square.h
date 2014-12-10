#ifndef SQUARE_H
#define SQUARE_H

#include "stdafx.h"
#include "Piece.h"

#include <utility>
#include <vector>

#include <iostream>

class Square{
public:
	 Square();
	~ Square();
	Piece* GetPiece();
	void SetPiece(Piece* piece);
    void RemovePiece ();	
	
private:
	Piece* currentPiece;
};

#endif


