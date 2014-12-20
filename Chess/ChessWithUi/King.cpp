#include "stdafx.h"

#include "King.h"
#include "Piece.h"


King:: King(PieceColor color){
	this->color = color;
}

bool King::CheckMove(){
	return true;
}
void King::DoMove(){}


