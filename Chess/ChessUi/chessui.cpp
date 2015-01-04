#include <QLabel>
#include <QFont>
#include "chessui.h"
#include "ImagePiece.h"
#include "Piece.h"
#include "King.h"
#include "Pown.h"

ChessUi::ChessUi(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// create our object and add it to the scene

	scene = new QGraphicsScene(this);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	SquareUiForm::Scene = scene;
	ui.graphicsView->setScene(scene);
	initialX = ui.graphicsView->x();
	initialY = ui.graphicsView->y();


	ui.steps_Box->hide();

	
	//set slots

	QObject::connect(ui.actionNew_Game_2, SIGNAL(triggered()), this, SLOT(NewGameClick()));
}

ChessUi::~ChessUi()
{

}



void ChessUi::NewGameClick()
{
	ui.steps_Box->show();

	InitBoardNumbers();
	NewGame();
}

void ChessUi::InitBoardNumbers()
{
	int horizontalX = initialX;
	int VerticalY = initialY;

	QFont font;
	font.setPointSize(16);

	for (int i = BOARD_SIZE; i >= 1; i--)
	{
		QLabel *verticalLeftlabel = new QLabel(QString::number(i), ui.centralWidget);
		verticalLeftlabel->setGeometry(initialX - 32, VerticalY + SQUARESIZE / 2, 16, 16);
		verticalLeftlabel->setFont(font);
		verticalLeftlabel->show();

		VerticalY += SQUARESIZE;
		
		QLabel *HorizontalDownlabel = new QLabel(QString('A' - 1 + i), ui.centralWidget);
		HorizontalDownlabel->setGeometry(horizontalX + ui.graphicsView->width() - SQUARESIZE / 2, initialY + ui.graphicsView->height() + 16, 16, 16);
		HorizontalDownlabel->setFont(font);
		HorizontalDownlabel->show();

		horizontalX -= SQUARESIZE;
	}
}

void ChessUi::NewGame()
{

	int x = initialX;
	int y = initialY- SQUARESIZE;

	QColor startColor = Qt::black;
	QColor endColor = Qt::white;

	for (int i = 0; i < BOARD_SIZE; i++){
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			QColor color = j % 2 == 0 ? startColor : endColor;
			squares[i][j] = new SquareUiForm(color, x, y);
			x += SQUARESIZE;
			scene->addItem(squares[i][j]);
		}

		y -= SQUARESIZE;
		x = ui.graphicsView->x();
		startColor = i % 2 == 0 ? Qt::white : Qt::black;
		endColor = i % 2 == 0 ? Qt::black : Qt::white;
	}

	SetPieces();
	SetPawns();
}

void ChessUi::CreatePiece(int i, int j, Piece *piece, QColor color, QString imageFile)
{
	ImagePiece *image = new ImagePiece(imageFile, squares[i][j]->GetCoordinate().GetX() + IMAGESIZE / 2, squares[i][j]->GetCoordinate().GetY() + IMAGESIZE / 2, piece);
	squares[i][j]->SetImage(image);
	scene->addItem(squares[i][j]->GetImage());
}

void  ChessUi::SetPieces(){
	//white pieces
	CreatePiece(BOARD_SIZE - 1, 0, new King(PieceColor::Black), PieceColor::Black, rookPathBlack);
	CreatePiece(BOARD_SIZE - 1, BOARD_SIZE - 1, new King(PieceColor::Black), PieceColor::Black, rookPathBlack);

	CreatePiece(BOARD_SIZE - 1, 1, new King(PieceColor::Black), PieceColor::Black, knightPathBlack);
	CreatePiece(BOARD_SIZE - 1, BOARD_SIZE - 2, new King(PieceColor::Black), PieceColor::Black, knightPathBlack);

	CreatePiece(BOARD_SIZE - 1, 2 , new King(PieceColor::Black), PieceColor::White, bishopPathBlack);
	CreatePiece(BOARD_SIZE - 1, BOARD_SIZE - 3, new King(PieceColor::Black), PieceColor::Black , bishopPathBlack);

	CreatePiece(BOARD_SIZE - 1, 3, new King(PieceColor::Black), PieceColor::White, queenPathBlack);
	CreatePiece(BOARD_SIZE - 1, BOARD_SIZE - 4, new King(PieceColor::Black), PieceColor::Black, kingPathBlack);

	//black pieces

	CreatePiece(0, 0, new King(PieceColor::White), PieceColor::White, rookPathWhite);
	CreatePiece(0, BOARD_SIZE - 1, new King(PieceColor::White), PieceColor::White, rookPathWhite);

	CreatePiece(0, 1, new King(PieceColor::White), PieceColor::White, knightPathWhite);
	CreatePiece(0, BOARD_SIZE - 2, new King(PieceColor::White), PieceColor::White, knightPathWhite);

	CreatePiece(0, 2, new King(PieceColor::White), PieceColor::White, bishopPathWhite);
	CreatePiece(0, BOARD_SIZE - 3, new King(PieceColor::White), PieceColor::White, bishopPathWhite);

	CreatePiece(0, 3, new King(PieceColor::White), PieceColor::White, queenPathWhite);
	CreatePiece(0, BOARD_SIZE - 4, new King(PieceColor::White), PieceColor::White, kingPathWhite);

}
void  ChessUi::SetPawns()
{
	for (int j = 0; j < BOARD_SIZE; j++)
	{
		// Place white pawn
		CreatePiece(BOARD_SIZE - 2, j, new Pown(PieceColor::Black), PieceColor::Black, ponePathBlack);

		// Place black pawn
		CreatePiece(1, j, new Pown(PieceColor::White), PieceColor::White, ponePathWhite);
	}

}