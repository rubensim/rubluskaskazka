#ifndef PIECE_H
#define PIECE_H


#include "Enums.h"
#include "Coortdinate.h"


using namespace std;

class Piece {
public:
	Piece(PieceColor color, string image) :pieceColor(color), image(image){ this->isMoved = false; };
	virtual ~Piece(){}

	virtual bool CheckMove(Coordinate currentPosition, Coordinate movePosition) = 0;

	void DoMove(){ this->isMoved = true; }

	//get set methods
	void SetImage(string piecePath) { this->image = piecePath; }
	string GetImage(){ return this->image; }
	PieceColor GetColor(){
		return this->pieceColor;
	}

	bool HaseMoved(){ return this->isMoved; }

protected:
	bool isMoved;
	PieceColor pieceColor;
	string image;
};

#endif
