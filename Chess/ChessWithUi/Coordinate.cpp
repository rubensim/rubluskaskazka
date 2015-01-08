#include "stdafx.h"
#include "Coortdinate.h"
#include "Constants.h"

Coordinate::Coordinate(int a, int b) 
{
	this->X = a;
	this->Y = b;
	/*assert(a >= 0 || a == -1);
	assert(b >= 0 || a == -1);
	assert(a<8);
	assert(b<8);
*/
}
Coordinate::Coordinate() : X(-1), Y(-1)
{}

Coordinate::Coordinate(const Coordinate& copy){
   Copy(copy);
}

Coordinate & Coordinate::operator = (const Coordinate & other)
{
	if (&other == this)
		return *this;

	 Copy(other);

	return *this;
}

bool Coordinate::operator== (const Coordinate & other){
	return this->X == other.X &&  this->Y == other.Y;
}


Coordinate Coordinate::MoveUp(int step)
{
	return Coordinate(this->X, this->Y - step * SQUARESIZE);
}

void Coordinate::Copy(const Coordinate & other){
	this->X = other.X;
	this->Y = other.Y;
}

Coordinate operator+ (Coordinate& coordinate, pair<int, int> numbers){

	return Coordinate(coordinate.GetX() + numbers.first * SQUARESIZE, coordinate.GetY() + numbers.second * SQUARESIZE);
}

Coordinate operator+ (Coordinate& coordinate, int number){
	return Coordinate(coordinate.GetX() + number * SQUARESIZE, coordinate.GetY() + number * SQUARESIZE);
}

Coordinate operator- (Coordinate& coordinate, int number){
	return Coordinate(coordinate.GetX() - number * SQUARESIZE, coordinate.GetY() - number * SQUARESIZE);
}


