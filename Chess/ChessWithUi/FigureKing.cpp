#include "stdafx.h"

#include "FigureKing.h"
#include "Constants.h"

King::King(PieceColor color, string image) :Piece(color, image){}

King::~King(){}

bool King::CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep){

	if (abs(currentPosition.GetX() - movePosition.GetX()) <= SQUARESIZE &&
		abs(currentPosition.GetY() - movePosition.GetY()) <= SQUARESIZE)
		return true;

	/*if (current == movePosition + 1 || current == movePosition - 1 
		|| current == movePosition + pair<int, int>(0, 1) || current == movePosition + pair<int, int>(0, -1)
		|| current == movePosition + pair<int, int>(1, 0) || current == movePosition + pair<int, int>(-1, 0)
		|| current == movePosition + pair<int, int>(1, -1) || current == movePosition + pair<int, int>(-1, 1))
	
		return true;
	*/
	return false;
}



