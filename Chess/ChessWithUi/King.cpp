#include "stdafx.h"

#include "King.h"
#include "Piece.h"
#include "Constants.h"

King::King(PieceColor color) :Piece(color){}

King:: King(PieceColor color, string image):Piece(color, image){
}

bool King::CheckMove(Coordinate currentPosition, Coordinate movePosition){
	int x = currentPosition.GetX() > 0 ? currentPosition.GetX() - IMAGESIZE / 2 : currentPosition.GetX() + IMAGESIZE / 2;
	int y = currentPosition.GetY() > 0 ? currentPosition.GetY() + IMAGESIZE / 2 : currentPosition.GetY() - IMAGESIZE / 2 ;

	Coordinate current(x, y);
	if (((current.GetY() == movePosition.GetY() || current.GetY() + SQUARESIZE == movePosition.GetY() || current.GetY() - SQUARESIZE == movePosition.GetY()) && (current.GetX() - SQUARESIZE == movePosition.GetX() || current.GetX() + SQUARESIZE == movePosition.GetX())) ||
		(current.GetX() == movePosition.GetX() && (current.GetY() + SQUARESIZE == movePosition.GetY() || current.GetY() - SQUARESIZE == movePosition.GetY())))
		return true;
	
	return false;
}



