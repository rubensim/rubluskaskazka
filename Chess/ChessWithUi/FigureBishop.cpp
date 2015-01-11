#include "stdafx.h"

#include "FigureBishop.h"
#include "Constants.h"

Bishop::Bishop(PieceColor color, string image) :Piece(color, image){}
Bishop::~Bishop(){}

bool Bishop::CheckMove(Coordinate currentPosition, Coordinate movePosition, bool allowDoCornerStep){
	
	if (abs(currentPosition.GetX() - movePosition.GetX()) == abs(currentPosition.GetY() - movePosition.GetY()))
		return true;


	return false;
}
