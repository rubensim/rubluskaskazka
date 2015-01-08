#include <qtransform.h>
#include <qdrag.h>
#include "ImagePiece.h"
#include "Constants.h"
#include "SquareUiForm.h"

ImagePiece* ImagePiece:: currrentPiece = NULL;


ImagePiece::ImagePiece(QString imageFile, int x, int y, Piece* piece) 
{
	this->piece = piece;
	this->imageFile = imageFile;
	this->coordinate.SetX(x);
	this->coordinate.SetY(y);

	setFlag(ItemIsMovable);

}

ImagePiece::ImagePiece(QString imageFile, Coordinate coordiate, Piece* piece)
{
	this->piece = piece;
	this->imageFile = imageFile;
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

	QImage image = QImage(imageFile);

	QPoint point(coordinate.GetX(), coordinate.GetY());

	painter->drawImage(rect, image);
}

void ImagePiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	currrentPiece = this;
	SquareUiForm::lastSquere = dynamic_cast<SquareUiForm*>(SquareUiForm::Scene->itemAt(this->coordinate.GetX() - IMAGESIZE / 2, this->coordinate.GetY() + IMAGESIZE / 2, QTransform()));;
	
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

Coordinate ImagePiece::GetSquareCoordinate(){
	return Coordinate(this->coordinate.GetX() - IMAGESIZE / 2, this->coordinate.GetY() - IMAGESIZE / 2);
}