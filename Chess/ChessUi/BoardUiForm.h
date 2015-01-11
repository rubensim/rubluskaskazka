#ifndef BOARDUIFORM_H
#define BOARDUIFORM_H

#include <QtWidgets/QMainWindow>

#include <SquareUiForm.h>

#include <Constants.h>
#include "Board.h"
#include "Step.h"


class BoardUiForm : public QGraphicsItem{

public:
	BoardUiForm(int width, int height);
	~BoardUiForm();

	QRectF boundingRect() const;
	void drowBoard();
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
	void NewGame(int startX, int startY);

	SquareUiForm* GetSquareByCoordinate(Coordinate coordinate);

	static map<Coordinate, SquareUiForm*> coordinateSystem;
	static SquareUiForm *currrentSquare;
	static map<Coordinate, SquareUiForm*> Init();

private:
	int width;
	int height;

	Board *board;

	SquareUiForm *squares[BOARD_SIZE][BOARD_SIZE];
	
};

#endif
