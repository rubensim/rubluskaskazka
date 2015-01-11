#ifndef STEP_H
#define STEP_H


#include <iostream>
#include<fstream>

#include <map>
#include <utility>
#include "string"
#include<vector>

#include "Constants.h"
#include "Coortdinate.h"
#include "Enums.h"

using namespace::std;

class Step{
public:
	Step();
	~Step();
	pair<char, int> GetStep(Coordinate coordinate);
	string GetCurrentStep(PieceColor);
	Coordinate GetCoordinate(pair<char, int> step);
	void RegisterStep(pair<char, int> key, Coordinate coordinate);
	void WriteStep(Coordinate prev, Coordinate current, PieceColor color);
	void ClearData();
private:
	vector<string> &split(string &s, char delim, vector<string> &elems);
	void Write(ostream& out, pair<char, int> prev, pair<char, int> current, PieceColor color);
	map<pair<char, int>, Coordinate> steps;
	
};
#endif // !STEP_H
