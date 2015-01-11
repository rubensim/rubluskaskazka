#include <QLabel>
#include <QFont>
#include "chessui.h"

#include "Constants.h"

using namespace::std;


ChessUi::ChessUi(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// create our object and add it to the scene

	scene = new QGraphicsScene(this);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);

	SquareUiForm::box[0] = ui.your_steps;
	SquareUiForm::box[1] = ui.opponent_steps;

	ui.graphicsView->setScene(scene);
	
	initialX = ui.graphicsView->x();
	initialY = ui.graphicsView->y();

	this->board = new BoardUiForm(ui.graphicsView->width(), ui.graphicsView->height());

	ui.steps_box->hide();

	
	//set slots

	QObject::connect(ui.actionNew_Game_2, SIGNAL(triggered()), this, SLOT(NewGameClick()));
}

ChessUi::~ChessUi()
{

}

void ChessUi::NewGameClick()
{
	ui.steps_box->show();

	InitBoardNumbers();

	board->NewGame(0, initialY);

	scene->addItem(board);
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
