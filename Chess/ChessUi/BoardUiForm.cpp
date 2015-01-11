#include "qcolor.h"

#include "BoardUiForm.h"
#include "Enums.h"
#include "ImagePiece.h"
#include "Piece.h"
#include "King.h"
#include "Pown.h"


SquareUiForm* BoardUiForm::currrentSquare = nullptr;
map<Coordinate, SquareUiForm*> BoardUiForm::coordinateSystem = BoardUiForm::Init();

//need to refactor , in c++ 11 we can change it!
map<Coordinate, SquareUiForm*> BoardUiForm::Init(){

	map<Coordinate, SquareUiForm*> cords;
	cords[Coordinate(0, 0)] = new SquareUiForm();
	return cords;
}

BoardUiForm::BoardUiForm(int width, int height) {

	this->width = width;
	this->height = height;

	board = new Board();
	
}

BoardUiForm::~BoardUiForm(){}

void BoardUiForm::drowBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			squares[i][j] = new SquareUiForm(board->GetSquare(i, j));
			squares[i][j]->setParentItem(this);
			coordinateSystem[board->GetSquare(i, j)->GetCoordinate()] = squares[i][j];
		}
}

void BoardUiForm::NewGame(int startX, int startY)
{
	board->NewGame(startX, height - startY  );

	drowBoard();
}

QRectF BoardUiForm::boundingRect() const{
	// outer most edges
	return QRectF(0, 0, this->width, this->height);
}

void BoardUiForm::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	QRectF rect1 = boundingRect();

	painter->drawRect(rect1);
}



