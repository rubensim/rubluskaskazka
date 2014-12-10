#ifndef PIECE_H
#define PIECE_H

#include "stdafx.h"
#include "Enums.h"
#include <iostream>

using namespace std;

class Piece {
public:
	Piece();
	Piece(PieceColor color);
	~Piece();
	 void SetImage();
	 PieceColor GetColor();
	 bool CheckMove();
	 void DoMove();
private:
	PieceColor color;
	string image;
	
};

#endif
