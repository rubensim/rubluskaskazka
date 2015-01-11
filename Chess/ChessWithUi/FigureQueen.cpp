#include "stdafx.h"

#include "FigureQueen.h"
#include "Constants.h"

Queen::Queen(PieceColor color, string image) :Piece(color, image){}
Queen::~Queen(){}

bool Queen::CheckMove(Coordinate currentPosition, Coordinate movePosition){
	
	if (currentPosition.GetX() == movePosition.GetX() || currentPosition.GetY() == movePosition.GetY() ||
		abs(currentPosition.GetX() - movePosition.GetX()) == abs(currentPosition.GetY() - movePosition.GetY()))
		return true;


	return false;
}



