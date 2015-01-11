#ifndef IMAGEPIECE_H
#define IMAGEPIECE_H

#include <QGraphicsSceneDragDropEvent>
#include <QPainter>
#include <QGraphicsItem>
#include "Coortdinate.h"
#include "Piece.h"

// class for customization
class ImagePiece :public QGraphicsItem
{
public:
	ImagePiece(Coordinate coordiate, Piece* piece);

	//ovveride QGraphicsItem functions
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

	//Get set methods
	void SetCoordinate(Coordinate coordinate);
	Coordinate GetCoordinate();
	Piece* GetPiece();

protected:
	// overriding mouse events
	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
	Piece *piece;
	Coordinate coordinate;
};

#endif 