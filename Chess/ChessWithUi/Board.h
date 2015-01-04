#ifndef BOARD_H
#define BOARD_H

#include "stdafx.h"

#include "Square.h"
#include "Constants.h"


class Board{
public:
	Board();
	~Board(){};
private:
	  Square* Squares[BOARD_SIZE][BOARD_SIZE] ;
};

#endif