#include "stdafx.h"

#include "Square.h"
#include "King.h"


Square::Square(Piece* piece){
	currentPiece  = new King(PieceColor::White);
}

Piece* Square::GetPiece(){
	return this->currentPiece;
}

void Square::SetPiece(Piece* piece){
	this->currentPiece = piece;
}


