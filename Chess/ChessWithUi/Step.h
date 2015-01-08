#ifndef STEP_H
#define STEP_H


#include <iostream>


#include <map>
#include <utility>

#include "Constants.h"
#include "Coortdinate.h"

using namespace::std;

class Step{
public:
	Step();
	~Step();
	pair<char, int> GetCurrentStep(Coordinate coordinate);
	Coordinate GetCoordinate(pair<char, int> step);
	void RegisterStep(pair<char, int> key, Coordinate coordinate);

private:
	map<pair<char, int>, Coordinate> steps;
	pair<char, int> currentStep;
	
};
#endif // !STEP_H
