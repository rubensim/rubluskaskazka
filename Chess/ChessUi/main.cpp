#include "chessui.h"
#include <QtWidgets/QApplication>
#include "Board.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChessUi w;
	w.show();
	return a.exec();
}
