// TestChess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#include "ChessGame.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ChessGame* chGame = new ChessGame();

	char color  = 'w';
	cout << "Please select a color w/b ? ";
	cin >> color;
	return 0;
}

