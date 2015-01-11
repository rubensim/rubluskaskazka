#include "stdafx.h"

#include "FigurePown.h"
#include "Constants.h"

Pown::Pown(PieceColor color, string image) :Piece(color, image){}

bool Pown::CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep){
	
	if (allowDoCornerStep)
	{
		if (abs(currentPosition.GetY() - movePosition.GetY()) == SQUARESIZE && abs(currentPosition.GetX() - movePosition.GetX()) == SQUARESIZE)
			return true;
	}
	if (currentPosition.GetX() == movePosition.GetX())
	{
		return isMoved ? (abs(currentPosition.GetY() - movePosition.GetY()) == SQUARESIZE) : (abs(currentPosition.GetY() - movePosition.GetY()) <= 2 * SQUARESIZE);
	}

	return false;
}



