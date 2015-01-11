#include "stdafx.h"

#include "FigureKnight.h"
#include "Constants.h"

Knight::Knight(PieceColor color, string image) :Piece(color, image){}
Knight::~Knight(){}

bool Knight::CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep){
	
	if (abs(currentPosition.GetX() - movePosition.GetX()) == SQUARESIZE && abs(currentPosition.GetY() - movePosition.GetY()) == 2 * SQUARESIZE ||
		abs(currentPosition.GetX() - movePosition.GetX()) == 2 * SQUARESIZE && abs(currentPosition.GetY() - movePosition.GetY()) == SQUARESIZE)
		return true;


	return false;
}
