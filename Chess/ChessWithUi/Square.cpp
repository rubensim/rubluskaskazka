#include "stdafx.h"

#include "Square.h"
#include "King.h"

Square::Square(Piece* piece){
	this->currentPiece = piece;
}

Piece* Square::GetPiece(){
	return this->currentPiece;
}

void Square::SetPiece(Piece* piece){
	this->currentPiece = piece;
}

void Square::CreatePiece(PieceType type, PieceColor color, string image){
	switch (type)
	{
	case _PAWN:
		this->currentPiece = new King(color, image);
		break;
	case _BISHOP:
		this->currentPiece = new King(color, image);
		break;
	case _ROOK:
		this->currentPiece = new King(color, image);
		break;
	case _KING:
		this->currentPiece = new King(color, image);
		break;
	case _KNIGHT:
		this->currentPiece = new King(color, image);
		break;
	case _QUEEN:
		this->currentPiece = new King(color, image);
		break;
	default:
		this->currentPiece = NULL;
		break;

	}
}

