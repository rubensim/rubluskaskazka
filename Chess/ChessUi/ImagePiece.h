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
	ImagePiece(QString imageFile, int x, int y, Piece* piece);
	ImagePiece(QString imageFile, Coordinate coordiate, Piece* piece);

	//ovveride QGraphicsItem functions
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

	static ImagePiece *currrentPiece;
	// item state
	bool Pressed;

	//Get set methods
	void SetCoordinate(Coordinate coordinate);
	Coordinate GetCoordinate();
	Piece* GetPiece();
	Coordinate GetSquareCoordinate();
protected:
	// overriding mouse events
	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
	Piece *piece;
	QString imageFile;
	Coordinate coordinate;
};

#endif 