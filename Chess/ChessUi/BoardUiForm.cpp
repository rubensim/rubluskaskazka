#include "BoardUiForm.h"
#include "Piece.h"
#include "King.h"
#include "Enums.h"


BoardUiForm::BoardUiForm(int startX, int startY) {
	int x = startX;
	int y = startY;

	QColor startColor = Qt::black;
	QColor endColor = Qt::white;

	for (int i = 0; i < BOARD_SIZE; i++){
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			QColor color = j % 2 == 0 ? startColor : endColor;
			squares[i][j] = new SquareUiForm(color, Coordinate(x, y));
			x += SQUARESIZE;
		}

		y -= SQUARESIZE;
		x = 60;
		startColor = i % 2 == 0 ? Qt::white : Qt::black;
		endColor = i % 2 == 0 ? Qt::black : Qt::white;
	}
}

BoardUiForm::~BoardUiForm()
{

}


void BoardUiForm::drowBoard(int startX, int startY, QPainter* painter)
{
	//int x = startX; 
	//int y = startY;

	//QColor startColor = Qt::black;
	//QColor endColor = Qt::white;

	//for (int i = 0; i < BOARD_SIZE; i++)
	//{
	//	for (int j = 0; j < BOARD_SIZE; j++)
	//	{
	//		QColor color = j % 2 == 0 ? startColor : endColor;

	//		squares[i][j].drawSqaure(x, y, painter, color);
	//		x += SQUARESIZE;
	//	}

	//	y -= SQUARESIZE;
	//	x = 60;
	//	startColor = i % 2 == 0 ? Qt::white : Qt::black;
	//	endColor = i % 2 == 0 ? Qt::black : Qt::white;
	//}

	//// Create White Pieces
	//CreateWhitePieces(painter);

 //   //Create black pieces
	//CreateBlackPieces(painter);
}

void BoardUiForm::NewGame(int startX, int startY, QPainter* painter)
{
	drowBoard(startX, startY, painter);
	// Create White Pieces
	//CreateWhitePieces(painter);

	////Create black pieces
	//CreateBlackPieces(painter);
}

QRectF BoardUiForm::boundingRect() const{
	// outer most edges
	return QRectF(0, 0, 100, 100);
}
void BoardUiForm::mousePressEvent(QGraphicsSceneMouseEvent *event){
	
	QGraphicsItem::mousePressEvent(event);
}

void BoardUiForm::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	squares[0][0]->paint(painter, option, widget);
}


//void  BoardUiForm::CreateWhitePieces(QPainter* painter)
//{
//	//squares[BOARD_SIZE - 1][0].square->CreatePiece(PieceType::_ROOK, PieceColor::White, rookPathWhite.toStdString());
//	//squares[BOARD_SIZE - 1][0].drawImage(painter);
//
//	//squares[BOARD_SIZE - 1][BOARD_SIZE - 1].square->CreatePiece(PieceType::_ROOK, PieceColor::White, rookPathWhite.toStdString());
//	//squares[BOARD_SIZE - 1][BOARD_SIZE - 1].drawImage(painter);
//
//	//squares[BOARD_SIZE - 1][1].square->CreatePiece(PieceType::_KNIGHT, PieceColor::White, knightPathWhite.toStdString());
//	//squares[BOARD_SIZE - 1][1].drawImage(painter);
//
//	//squares[BOARD_SIZE - 1][BOARD_SIZE - 2].square->CreatePiece(PieceType::_KNIGHT, PieceColor::White, knightPathWhite.toStdString());
//	//squares[BOARD_SIZE - 1][BOARD_SIZE - 2].drawImage(painter);
//
//	//squares[BOARD_SIZE - 1][BOARD_SIZE - 3].square->CreatePiece(PieceType::_BISHOP, PieceColor::White, bishopPathWhite.toStdString());
//	//squares[BOARD_SIZE - 1][BOARD_SIZE - 3].drawImage(painter);
//
//	//squares[BOARD_SIZE - 1][2].square->CreatePiece(PieceType::_BISHOP, PieceColor::White, bishopPathWhite.toStdString());
//	//squares[BOARD_SIZE - 1][2].drawImage(painter);
//
//	//squares[BOARD_SIZE - 1][3].square->CreatePiece(PieceType::_QUEEN, PieceColor::White, queenPathWhite.toStdString());
//	//squares[BOARD_SIZE - 1][3].drawImage(painter);
//
//	//squares[BOARD_SIZE - 1][BOARD_SIZE - 4].square->CreatePiece(PieceType::_KING, PieceColor::White, kingPathWhite.toStdString());
//	//squares[BOARD_SIZE - 1][BOARD_SIZE - 4].drawImage(painter);
//
//	//// Place white pawns
//	//for (int j = 0; j < BOARD_SIZE; j++)
//	//{
//	//	squares[BOARD_SIZE - 2][j].square->CreatePiece(PieceType::_PAWN, PieceColor::White, ponePathWhite.toStdString());
//	//	squares[BOARD_SIZE - 2][j].drawImage(painter);
//	//}
//}
//void  BoardUiForm::CreateBlackPieces(QPainter* painter)
//{
//	//squares[0][0].square->CreatePiece(PieceType::_ROOK, PieceColor::Black, rookPathBlack.toStdString());
//	//squares[0][0].drawImage(painter);
//
//	//squares[0][BOARD_SIZE - 1].square->CreatePiece(PieceType::_ROOK, PieceColor::Black, rookPathBlack.toStdString());
//	//squares[0][BOARD_SIZE - 1].drawImage(painter);
//
//	//squares[0][1].square->CreatePiece(PieceType::_KNIGHT, PieceColor::Black, knightPathBlack.toStdString());
//	//squares[0][1].drawImage(painter);
//
//	//squares[0][BOARD_SIZE - 2].square->CreatePiece(PieceType::_KNIGHT, PieceColor::Black, knightPathBlack.toStdString());
//	//squares[0][BOARD_SIZE - 2].drawImage(painter);
//
//	//squares[0][BOARD_SIZE - 3].square->CreatePiece(PieceType::_BISHOP, PieceColor::Black, bishopPathBlack.toStdString());
//	//squares[0][BOARD_SIZE - 3].drawImage(painter);
//
//	//squares[0][2].square->CreatePiece(PieceType::_BISHOP, PieceColor::Black, bishopPathBlack.toStdString());
//	//squares[0][2].drawImage(painter);
//
//	//squares[0][3].square->CreatePiece(PieceType::_QUEEN, PieceColor::Black, queenPathBlack.toStdString());
//	//squares[0][3].drawImage(painter);
//
//	//squares[0][BOARD_SIZE - 4].square->CreatePiece(PieceType::_KING, PieceColor::Black, kingPathBlack.toStdString());
//	//squares[0][BOARD_SIZE - 4].drawImage(painter);
//
//	//// Place black pawns
//	//for (int j = 0; j < BOARD_SIZE; j++)
//	//{
//	//	squares[1][j].square->CreatePiece(PieceType::_PAWN, PieceColor::Black, ponePathBlack.toStdString());
//	//	squares[1][j].drawImage(painter);
//	//}
//}
//
//
