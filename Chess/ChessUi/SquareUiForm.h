#ifndef SQUAREUIFORM_H
#define SQUAREUIFORM_H

#include <QGraphicsSceneDragDropEvent>

#include <QtCore>
#include <QGraphicsItem>
#include <qgraphicsview.h>
#include "Square.h"
#include "ImagePiece.h"


class SquareUiForm : public QGraphicsObject
{

public:
	SquareUiForm();
	SquareUiForm(QColor color, int x, int y);
	~SquareUiForm();

	static QGraphicsScene *Scene;
	static SquareUiForm *lastSquere;

	//ovveride QGraphicsItem functions
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
	
	//drow square and image;
	void drawSqaure(int x, int y, QPainter* painter, QColor color);
	

	//get set methods

	Coordinate GetCoordinate(){ return this->coordinat; }
	ImagePiece* GetImage(){ return this->image; }
	void SetImage(ImagePiece* image){ this->image = image; }
	
protected:
	// overriding mouse events
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent * event) override;
	void dropEvent(QGraphicsSceneDragDropEvent * event) override;
	void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
	void dragMoveEvent(QGraphicsSceneDragDropEvent * event) override;
private:
	Coordinate coordinat;
	ImagePiece *image;
	QRectF rect;
	QColor color;
};
#endif