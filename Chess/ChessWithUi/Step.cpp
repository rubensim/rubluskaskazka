#include "stdafx.h"
#include "Step.h"

Step::Step()
{
	/*for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 1; j <= BOARD_SIZE; j++)
		   AllSteps[i] = new pair<char, int>('A' - 1 + j, j);
	}*/
}

Step::~Step(){
	/*map<pair<char, int>, Coordinate*>::iterator it = steps.begin();
	map<pair<char, int>, Coordinate*>::const_iterator end = steps.end();

	for (; it != end; ++it)
		delete it->second;*/
}

pair<char, int> Step::GetCurrentStep(Coordinate coordinate){

	map<pair<char, int>, Coordinate>::iterator it = steps.begin();
	map<pair<char, int>, Coordinate>::const_iterator end = steps.end();

	for (; it != end; ++it)
		if (it->second == coordinate)
			return it->first;
}

Coordinate Step::GetCoordinate(pair<char, int> step){
	return this->steps[step];
}

void Step::RegisterStep(pair<char, int> key, Coordinate coordinate){
	steps[key] = coordinate;
}