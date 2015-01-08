#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "stdafx.h"
#include "Board.h"

class ChessGame{
public:
	ChessGame();
	~ChessGame(){};

	void StartGame();
	void Pause();
private:
	Board* board;

};
#endif