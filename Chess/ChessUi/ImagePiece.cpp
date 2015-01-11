#include <qtransform.h>
#include <qdrag.h>

#include "ImagePiece.h"
#include "Constants.h"
#include "BoardUiForm.h"
#include "WorkWithCoordinateSystem.h"

ImagePiece::ImagePiece(Coordinate coordiate, Piece* piece)
{
	this->piece = piece;
	this->coordinate = coordiate;

    setFlag(ItemIsMovable);
}

QRectF ImagePiece::boundingRect() const
{
	// outer most edges
	return QRectF(coordinate.GetX(), coordinate.GetY(), IMAGESIZE, IMAGESIZE);
}

void ImagePiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QRectF rect = boundingRect();

	QImage image = QImage(QString::fromStdString(this->piece->GetImage()));

	QPoint point(coordinate.GetX(), coordinate.GetY());

	painter->drawImage(rect, image);
}

void ImagePiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	BoardUiForm::currrentSquare = BoardUiForm::coordinateSystem[WorkWithCoordinateSystem::GetSquareCoordinate(this->coordinate)];

	update();

	QGraphicsItem::mousePressEvent(event);
}

void ImagePiece::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

	QDrag *drag = new QDrag(event->widget());
	QMimeData *mime = new QMimeData;

	mime->setImageData(boundingRect());
	drag->setMimeData(mime);
	drag->exec();

}

void ImagePiece::SetCoordinate(Coordinate coordinate){ 
	this->coordinate = coordinate; 
}

Coordinate ImagePiece::GetCoordinate(){ 
	return this->coordinate; 
}

Piece* ImagePiece::GetPiece(){ 
	return this->piece; 
}
