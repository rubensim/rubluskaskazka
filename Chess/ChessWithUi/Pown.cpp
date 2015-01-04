#include "stdafx.h"

#include "Pown.h"
#include "Constants.h"

Pown::Pown(PieceColor color) :Piece(color){}

Pown::Pown(PieceColor color, string image) : Piece(color, image){
}

bool Pown::CheckMove(Coordinate currentPosition, Coordinate movePosition){
	int x = currentPosition.GetX() > 0 ? currentPosition.GetX() - IMAGESIZE / 2 : currentPosition.GetX() + IMAGESIZE / 2;
	int y = currentPosition.GetY() > 0 ? currentPosition.GetY() + IMAGESIZE / 2 : currentPosition.GetY() - IMAGESIZE / 2;

	Coordinate current(x, y);

	//check pawn's move in a first move
	if (!HaseMoved())
	{
		if (current.GetX() == movePosition.GetX() && (current.GetY() - SQUARESIZE == movePosition.GetY() || current.GetY() - 2 * SQUARESIZE == movePosition.GetY()))
		   return true;
	}
	else
	{
		if (current.GetX() == movePosition.GetX() && current.GetY() - SQUARESIZE == movePosition.GetY())
			return true;
	}

	return false;
}



