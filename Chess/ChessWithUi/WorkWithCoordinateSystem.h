#ifndef WORKWITHCOORDINATESYSTEM
#define WORKWITHCOORDINATESYSTEM

#include "stdafx.h"

#include "Coortdinate.h"
#include "Constants.h"

class WorkWithCoordinateSystem{
public:
	static Coordinate GetSquareCoordinate(Coordinate co){
		return Coordinate(co.GetX() - IMAGESIZE / 2, co.GetY() - IMAGESIZE / 2);
	}

	static Coordinate GetPieceCoordinate(Coordinate co){
		return Coordinate(co.GetX() + IMAGESIZE / 2, co.GetY() + IMAGESIZE / 2);
	}
};
#endif // !WORKWITHCOORDINATSYSTEM
