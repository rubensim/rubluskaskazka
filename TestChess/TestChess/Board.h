#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include <iostream>

int const BOARD_SIZE = 8;

class Board{
public:
	Board();
	~Board();
    void Init();
private:
	Square Squares[BOARD_SIZE][BOARD_SIZE];
};
#endif