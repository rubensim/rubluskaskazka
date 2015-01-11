#include "stdafx.h"

#include "Square.h"
#include "Board.h"

PieceColor Square::LastStepColor = PieceColor::Black;

Square::Square(Coordinate coordinate, PieceColor color, Piece* piece){

	SetPiece(piece);
	SetCoordinate(coordinate);
	this->color = color;
}


Square::~Square(){
//	delete currentPiece;
}

Coordinate Square::GetCoordinate() {
	return this->coordinate; 
}

void Square::SetCoordinate(Coordinate coordinate){
	this->coordinate = coordinate;
}

Piece* Square::GetPiece(){
	return this->currentPiece;
}

void Square::SetPiece(Piece* piece){
	this->currentPiece = piece;
}

bool  Square::MovePiece(Square* square){
	if (LastStepColor != this->currentPiece->GetColor())
	{
		if (this->currentPiece->CheckMove(this->coordinate, square->GetCoordinate()))	{
			if (square->GetPiece() != nullptr)
			{
				if (square->GetPiece()->GetColor() != this->currentPiece->GetColor())
				{
					square->SetPiece(nullptr);
				}
				else
				{
					return false;
				}
			}

			Board::Steps->WriteStep(this->GetCoordinate(), square->GetCoordinate(), this->GetPiece()->GetColor());

			this->currentPiece->DoMove();
			square->SetPiece(this->currentPiece);

			LastStepColor = this->currentPiece->GetColor();

			return true;
		}
	}

	return false;
}

PieceColor Square::GetColor(){
	return this->color;
}



