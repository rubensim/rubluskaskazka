#ifndef CHESSUI_H
#define CHESSUI_H

#include <QtWidgets/QMainWindow>
#include <QtGui>
#include <QtCore>
#include "ui_chessui.h"

#include "BoardUiForm.h"


class ChessUi : public QMainWindow
{
	Q_OBJECT

public:
	ChessUi(QWidget *parent = 0);
	~ChessUi();

public slots:
	void NewGameClick();

private:

	void InitBoardNumbers();

	BoardUiForm *board;
	Ui::ChessUiClass ui;
	QGraphicsScene *scene;

	int initialX; 
	int initialY;
};

#endif // CHESSUI_H
