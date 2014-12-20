#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate{ 
	Coordinate(){};
    Coordinate(int x, int y);
    Coordinate & operator = (const Coordinate & Other);	
    bool operator < (const Coordinate & Other) const;	
    bool operator ==(const Coordinate & Other) const;
    int GetX() const;	
    int GetY() const;	
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