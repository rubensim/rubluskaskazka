#include "stdafx.h"

#include "FigureRock.h"
#include "Constants.h"

Rock::Rock(PieceColor color, string image) :Piece(color, image){}

Rock::~Rock(){}

bool Rock::CheckMove(Coordinate currentPosition, Coordinate movePosition){
	if (currentPosition.GetX() == movePosition.GetX() || currentPosition.GetY() == movePosition.GetY())
		return true;


	return false;
}
