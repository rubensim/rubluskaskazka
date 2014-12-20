#ifndef CHESSUI_H
#define CHESSUI_H

#include <QtWidgets/QMainWindow>
#include "ui_chessui.h"

class ChessUi : public QMainWindow
{
	Q_OBJECT

public:
	ChessUi(QWidget *parent = 0);
	~ChessUi();

private:
	Ui::ChessUiClass ui;
};

#endif // CHESSUI_H
