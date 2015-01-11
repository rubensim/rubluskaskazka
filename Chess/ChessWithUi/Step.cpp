#include "stdafx.h"
#include "Step.h"

#include <iostream>

#include <sstream>
using namespace::std;

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

pair<char, int> Step::GetStep(Coordinate coordinate){

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

void Step::WriteStep(Coordinate prev, Coordinate current, PieceColor color)
{
	ofstream stepFile;
	stepFile.open("StepsFile.txt", ios::trunc);
	Write(stepFile, GetStep(prev), GetStep(current), color);
}

void Step::Write(ostream& out, pair<char, int> prev, pair<char, int> current, PieceColor color){
	if (color == PieceColor::White)
		out << "\n";

	out << prev.first + std::to_string(prev.second) << "->" << current.first + std::to_string(current.second) << ":";
}

string Step::GetCurrentStep(PieceColor color){
	ifstream in;
	string line;
	in.open("StepsFile.txt", ios::in);
	
	if (in.is_open())
		while (!in.eof())
		{
			getline(in, line);
		}

	if (!line.empty()){
		vector<string> elems;
		elems = this->split(line, ':', elems);

		if (!elems[color].empty())
		   return elems[color];
	}

	return "";
}

vector<string> & Step::split(string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;

	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}

	return elems;
}