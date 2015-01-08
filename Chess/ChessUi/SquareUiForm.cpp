#include <qdrag.h>
#include "SquareUiForm.h"
#include <QLabel>
#include "Constants.h"
#include "Enums.h"
#include "Square.h"
#include "chessui.h"


QGraphicsScene* SquareUiForm:: Scene = NULL;
QFormLayout* SquareUiForm::box = NULL;
SquareUiForm * SquareUiForm::lastSquere = NULL;

SquareUiForm::SquareUiForm(QColor color, Coordinate coordinate){

	setAcceptDrops(true);

	this->cSquare = new Square(coordinate);

	this->color = color;
	this->image = NULL;
}

SquareUiForm::~SquareUiForm(){
	delete image;
	delete cSquare;
}

QRectF SquareUiForm::boundingRect() const
{
	// outer most edges
	return QRectF(GetCoordinate().GetX(), GetCoordinate().GetY(), SQUARESIZE, SQUARESIZE);
}

void SquareUiForm::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

	QRectF rect1 = boundingRect();

	QBrush brush(color, Qt::SolidPattern);

	painter->fillRect(rect1, brush);
	painter->drawRect(rect1);
}

void SquareUiForm::MovePiece(){

	if (ImagePiece::currrentPiece != NULL)

		if (ImagePiece::currrentPiece->GetPiece()->CheckMove(ImagePiece::currrentPiece->GetSquareCoordinate(), GetCoordinate()))
		{
			if (image != NULL)
			{
				if (image->GetPiece()->GetColor() != ImagePiece::currrentPiece->GetPiece()->GetColor())
				{
					Scene->removeItem(image);
				}
				else
				{
					return;
				}
			}

			lastSquere->image = NULL;
			image = ImagePiece::currrentPiece;

			ImagePiece::currrentPiece->GetPiece()->DoMove();
			Coordinate previewsCoordinate(ImagePiece::currrentPiece->GetSquareCoordinate());
			ImagePiece::currrentPiece->SetCoordinate(GetPieceCoordinate());

			ImagePiece::currrentPiece = NULL;
			image->update();

			WriteSteps(previewsCoordinate);

			Scene->update();
		}
}

void SquareUiForm::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	MovePiece();
	
	update();

	QGraphicsItem::mousePressEvent(event);
}

void SquareUiForm::dragEnterEvent(QGraphicsSceneDragDropEvent * event){

	if (!(event->mimeData()->imageData().toRectF().x() == GetCoordinate().GetX() + IMAGESIZE / 2 && event->mimeData()->imageData().toRectF().y() == GetCoordinate().GetY() + IMAGESIZE / 2))
	{
		event->setAccepted(true);
		update();
	}
}

void SquareUiForm::dragMoveEvent(QGraphicsSceneDragDropEvent * event)
{
	if (!(event->mimeData()->imageData().toRectF().x() == GetCoordinate().GetX() + IMAGESIZE / 2 && event->mimeData()->imageData().toRectF().y() == GetCoordinate().GetY() + IMAGESIZE / 2))
	{
		event->setAccepted(true);
		update();
	}
}

void SquareUiForm::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
	Q_UNUSED(event);
	update();
}

void SquareUiForm::dropEvent(QGraphicsSceneDragDropEvent * event)
{ 
	if (!(event->mimeData()->imageData().toRectF().x() == GetCoordinate().GetX() + IMAGESIZE / 2 && event->mimeData()->imageData().toRectF().y() == GetCoordinate().GetY() + IMAGESIZE / 2))
	{
		MovePiece();
		update();
	}
	
}

Coordinate SquareUiForm::GetCoordinate() const{
	return cSquare->GetCoordinate();
}

ImagePiece* SquareUiForm:: GetImage(){ 
	return this->image; 
}

void SquareUiForm::SetImage(ImagePiece* image)
{
	this->image = image;
	this->cSquare->SetPiece(image->GetPiece());
}

Coordinate SquareUiForm::GetPieceCoordinate(){ 
	return Coordinate(this->GetCoordinate().GetX() + IMAGESIZE / 2, this->GetCoordinate().GetY() + IMAGESIZE / 2); 
}

void SquareUiForm::WriteSteps(Coordinate previewsCoordinate){
	pair<char, int> current = ChessUi::steps->GetCurrentStep(this->GetCoordinate());
	pair<char, int> last = ChessUi::steps->GetCurrentStep(previewsCoordinate);

	QLabel *label = new QLabel(last.first + QString::number(last.second) + " -> " + current.first + QString::number(current.second));

	SquareUiForm::box->addRow(label);
}





