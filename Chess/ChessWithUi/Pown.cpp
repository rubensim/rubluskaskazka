#include "stdafx.h"

#include "Pown.h"
#include "Constants.h"

Pown::Pown(PieceColor color, string image) :Piece(color, image){}

bool Pown::CheckMove(Coordinate currentPosition, Coordinate movePosition){
	
	if (currentPosition.GetX() == movePosition.GetX())
	{
		return isMoved ? (currentPosition.GetY() - movePosition.GetY() == SQUARESIZE) : (currentPosition.GetY() - movePosition.GetY() <= 2 * SQUARESIZE);
	}

	return false;
}



