#include "stdafx.h"

#include "Board.h"
#include "Piece.h"
#include "Pown.h"
#include "King.h"


Step* Board::Steps = new Step();

Board::Board(){}
Board::~Board(){}

Square * Board::CreateSquare(Coordinate co, PieceColor color, int i , int j ){
	
	this->Squares[i][j] = new Square(co, color);
	Steps->RegisterStep(pair<char, int>('A' - 1 + (j + 1), i + 1), co);

	return this->Squares[i][j];
}

void  Board::SetPawns()
{
	for (int j = 0; j < BOARD_SIZE; j++)
	{
		// Place white pawn
		CreatePiece(BOARD_SIZE - 2, j, new Pown(PieceColor::Black, PONEPATHBLACK));

		// Place black pawn
		CreatePiece(1, j, new Pown(PieceColor::White, PONEPATHWHITE));
	}
}

void  Board::SetPieces(){
	//white pieces
	CreatePiece(BOARD_SIZE - 1, 0, new King(PieceColor::Black, ROOKPATHBLACK));
	CreatePiece(BOARD_SIZE - 1, BOARD_SIZE - 1, new King(PieceColor::Black, ROOKPATHBLACK));

	CreatePiece(BOARD_SIZE - 1, 1, new King(PieceColor::Black, KNIGHTPATHBLACK));
	CreatePiece(BOARD_SIZE - 1, BOARD_SIZE - 2, new King(PieceColor::Black, KNIGHTPATHBLACK));

	CreatePiece(BOARD_SIZE - 1, 2, new King(PieceColor::Black, BISHOPPATHBLACK));
	CreatePiece(BOARD_SIZE - 1, BOARD_SIZE - 3, new King(PieceColor::Black, BISHOPPATHBLACK));

	CreatePiece(BOARD_SIZE - 1, 3, new King(PieceColor::Black, QUEENPATHBLACK));
	CreatePiece(BOARD_SIZE - 1, BOARD_SIZE - 4, new King(PieceColor::Black, KINGPATHBLACK));

	//black pieces

	CreatePiece(0, 0, new King(PieceColor::White, ROOKPATHWHITE));
	CreatePiece(0, BOARD_SIZE - 1, new King(PieceColor::White, ROOKPATHWHITE));

	CreatePiece(0, 1, new King(PieceColor::White, KNIGHTPATHWHITE));
	CreatePiece(0, BOARD_SIZE - 2, new King(PieceColor::White, KNIGHTPATHWHITE));

	CreatePiece(0, 2, new King(PieceColor::White, BISHOPPATHWHITE));
	CreatePiece(0, BOARD_SIZE - 3, new King(PieceColor::White, BISHOPPATHWHITE));

	CreatePiece(0, 3, new King(PieceColor::White, QUEENPATHWHITE));
	CreatePiece(0, BOARD_SIZE - 4, new King(PieceColor::White, KINGPATHWHITE));

}

Square *Board::GetSquare(int i, int j){
	return Squares[i][j];
}

void Board::NewGame(int x, int y){

	int startX = x;
	int startY = y;

	PieceColor startColor = PieceColor::Black;
	PieceColor endColor = PieceColor::White;

	for (int i = 0; i < BOARD_SIZE; i++){

		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Coordinate coordinate = Coordinate(startX, startY);
			PieceColor color = j % 2 == 0 ? startColor : endColor;

			Squares[i][j] = this->Squares[i][j] = new Square(coordinate, color);

			Steps->RegisterStep(pair<char, int>('A' - 1 + (j + 1), i + 1), coordinate);


			startX += SQUARESIZE;

			//coordinateSystem[coordinate] = squares[i][j];

		}

		startY -= SQUARESIZE;
		startX = x;
		startColor = i % 2 == 0 ? PieceColor::White : PieceColor::Black;
		endColor = i % 2 == 0 ? PieceColor::Black : PieceColor::White;

	}

	SetPieces();
	SetPawns();
}

void Board::CreatePiece(int i, int j, Piece *piece)
{
	this->Squares[i][j]->SetPiece(piece);
}



