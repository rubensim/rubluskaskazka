#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Board.h"
class ChessGame{
public:
	ChessGame();
	~ChessGame();
	void NewGame();
private:
	Board* board;

#endif
