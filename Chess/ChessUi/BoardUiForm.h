#ifndef BOARDUIFORM_H
#define BOARDUIFORM_H

#include <QtWidgets/QMainWindow>

#include <SquareUiForm.h>

#include <Constants.h>

const QString kingPathBlack = ":/ChessUi/Resources/King-Black.png";
const QString kingPathWhite= ":/ChessUi/Resources/King-White.png";

const QString rookPathBlack = ":/ChessUi/Resources/Castle-Black.png";
const QString rookPathWhite = ":/ChessUi/Resources/Castle-White.png";

const QString knightPathBlack = ":/ChessUi/Resources/Knight-Black.png";
const QString knightPathWhite = ":/ChessUi/Resources/Knight-White.png";

const QString bishopPathBlack = ":/ChessUi/Resources/Bishop-Black.png";
const QString bishopPathWhite = ":/ChessUi/Resources/Bishop-White.png";

const QString queenPathBlack = ":/ChessUi/Resources/Queen-Black.png";
const QString queenPathWhite = ":/ChessUi/Resources/Queen-White.png";

const QString ponePathBlack = ":/ChessUi/Resources/Pone-Black.png";
const QString ponePathWhite = ":/ChessUi/Resources/Pone-White.png";

class BoardUiForm : public QGraphicsItem{

public:
	BoardUiForm(int x, int y);
	~BoardUiForm();
	QRectF boundingRect() const;
	void drowBoard(int startX, int startY, QPainter* painter);
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
	void NewGame(int startX, int startY, QPainter* painter);
	//void CreatePieces();
	/*void CreateWhitePieces(QPainter* painter);
	void CreateBlackPieces(QPainter* painter);*/
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
	SquareUiForm *squares[BOARD_SIZE][BOARD_SIZE];

};

#endif
