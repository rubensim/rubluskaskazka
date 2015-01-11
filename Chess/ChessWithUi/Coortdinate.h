#ifndef COORDINATE_H
#define COORDINATE_H

#include "stdafx.h"

#include <iostream>
using namespace std;

class Coordinate{ 
public:
	Coordinate();
    Coordinate(int x, int y);
	Coordinate(const Coordinate& copy);
    Coordinate & operator = (const Coordinate & other);	
    bool operator== (const Coordinate & other);
	bool operator<(const Coordinate& other) const;
	bool operator>(const Coordinate & other);
	Coordinate MoveUp(int step);
	
	int GetX() const{ return this->X; }
	int GetY() const{ return this->Y; }
    void SetX(int a)
    {
        X = a;    
    }
    void SetY(int a)
    {
        Y = a;   
    }
private:
	void Copy(const Coordinate & other);
    int X;	
    int Y;
};

Coordinate operator+(Coordinate & coordinate, pair<int, int> numbers);
Coordinate operator +(Coordinate & coordinate, int number);
Coordinate operator -(Coordinate & coordinate, int number);
#endif