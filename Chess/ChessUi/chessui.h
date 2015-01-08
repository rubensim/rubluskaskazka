#ifndef CHESSUI_H
#define CHESSUI_H

#include <QtWidgets/QMainWindow>
#include <QtGui>
#include <QtCore>
#include "ui_chessui.h"
#include "Constants.h"
#include "SquareUiForm.h"
#include "Step.h"

const QString kingPathBlack = ":/ChessUi/Resources/black_king.png";
const QString kingPathWhite = ":/ChessUi/Resources/white_king.png";

const QString rookPathBlack = ":/ChessUi/Resources/black_rock.png";
const QString rookPathWhite = ":/ChessUi/Resources/white_rock.png";

const QString knightPathBlack = ":/ChessUi/Resources/black_horse.png";
const QString knightPathWhite = ":/ChessUi/Resources/white_horse.png";

const QString bishopPathBlack = ":/ChessUi/Resources/black_bishop.png";
const QString bishopPathWhite = ":/ChessUi/Resources/white_bishop.png";

const QString queenPathBlack = ":/ChessUi/Resources/black_queen.png";
const QString queenPathWhite = ":/ChessUi/Resources/white_queen.png";

const QString ponePathBlack = ":/ChessUi/Resources/black_pown.png";
const QString ponePathWhite = ":/ChessUi/Resources/white_pown.png";

class ChessUi : public QMainWindow
{
	Q_OBJECT

public:
	ChessUi(QWidget *parent = 0);
	~ChessUi();

	static Step *steps;

public slots:
	void NewGameClick();

private:
	void NewGame();
	void CreatePawns();
	void SetPieces();
	void SetPawns();
	void CreatePiece(int i, int j, Piece *piece, QColor color, QString imageFile);
	void InitBoardNumbers();

	Ui::ChessUiClass ui;
	QGraphicsScene *scene;
	SquareUiForm *squares[BOARD_SIZE][BOARD_SIZE];

	int initialX; 
	int initialY;
};

#endif // CHESSUI_H
