#ifndef COORDINATE_H
#define COORDINATE_H

#include "stdafx.h"

class Coordinate{ 
public:
	Coordinate();
    Coordinate(int x, int y);
    Coordinate & operator = (const Coordinate & Other);	
    bool operator < (const Coordinate & Other) const;	
    bool operator ==(const Coordinate & Other) const;
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
    int X;	
    int Y;
};
#endif