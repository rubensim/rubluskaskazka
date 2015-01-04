#include <qdrag.h>
#include "SquareUiForm.h"
#include <QLabel>
#include "Constants.h"
#include "Enums.h"

QGraphicsScene* SquareUiForm:: Scene = NULL;
SquareUiForm * SquareUiForm::lastSquere = NULL;

SquareUiForm:: SquareUiForm(){
}

SquareUiForm::SquareUiForm(QColor color, int x, int y){

	setAcceptDrops(true);

	this->coordinat.SetX(x);
	this->coordinat.SetY(y);

	this->color = color;
	this->image = NULL;
}

SquareUiForm::~SquareUiForm()
{

}

QRectF SquareUiForm::boundingRect() const
{
	// outer most edges
	return QRectF(coordinat.GetX(), coordinat.GetY(), SQUARESIZE, SQUARESIZE);
}


void SquareUiForm::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

	QRectF rect1 = boundingRect();

	QBrush brush(color, Qt::SolidPattern);

	painter->fillRect(rect1, brush);
	painter->drawRect(rect1);
}


void SquareUiForm::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (ImagePiece::currrentPiece != NULL)

		if (ImagePiece::currrentPiece->GetPiece()->CheckMove(ImagePiece::currrentPiece->GetCoordinate(), this->coordinat))
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


			lastSquere->image =  NULL;
			image = ImagePiece::currrentPiece;
			
			ImagePiece::currrentPiece->coordinate.SetX(this->coordinat.GetX() + IMAGESIZE / 2);
			ImagePiece::currrentPiece->coordinate.SetY(this->coordinat.GetY() + IMAGESIZE / 2);

			ImagePiece::currrentPiece = NULL;
			image->update();

			Scene->update();

		}

	update();
	QGraphicsItem::mousePressEvent(event);
}

void SquareUiForm::dragEnterEvent(QGraphicsSceneDragDropEvent * event){

	if (!(event->mimeData()->imageData().toRectF().x() == this->coordinat.GetX() + IMAGESIZE / 2 && event->mimeData()->imageData().toRectF().y() == this->coordinat.GetY() + IMAGESIZE / 2))
	{
		event->setAccepted(true);
		update();
	}
}

void SquareUiForm::dragMoveEvent(QGraphicsSceneDragDropEvent * event)
{
	if (!(event->mimeData()->imageData().toRectF().x() == this->coordinat.GetX() + IMAGESIZE / 2 && event->mimeData()->imageData().toRectF().y() == this->coordinat.GetY() + IMAGESIZE / 2))
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
	if (!(event->mimeData()->imageData().toRectF().x() == this->coordinat.GetX() + IMAGESIZE / 2 && event->mimeData()->imageData().toRectF().y() == this->coordinat.GetY() + IMAGESIZE / 2))
	{
		QGraphicsItem::dropEvent(event);
	}
	
}





