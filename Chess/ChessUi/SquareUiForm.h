#ifndef SQUAREUIFORM_H
#define SQUAREUIFORM_H

#include <QGraphicsSceneDragDropEvent>
#include <QtWidgets/QFormLayout>
#include <QtCore>
#include <QGraphicsItem>
#include <qgraphicsview.h>
#include "Square.h"
#include "ImagePiece.h"


class SquareUiForm : public QGraphicsObject
{

public:
	SquareUiForm(QColor color, Coordinate coordinate);
	~SquareUiForm();

	static QGraphicsScene *Scene;
	static SquareUiForm *lastSquere;
	static QFormLayout *box;

	//ovveride QGraphicsItem functions
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
	
	//drow square and image;
	void drawSqaure(int x, int y, QPainter* painter, QColor color);
	

	//get set methods

	Coordinate GetCoordinate() const;
	ImagePiece* GetImage();
	void SetImage(ImagePiece* image);
	Coordinate GetPieceCoordinate();
	
protected:
	// overriding mouse events
	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	void dragEnterEvent(QGraphicsSceneDragDropEvent * event) override;
	void dropEvent(QGraphicsSceneDragDropEvent * event) override;
	void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
	void dragMoveEvent(QGraphicsSceneDragDropEvent * event) override;
private:
	void MovePiece();
	void WriteSteps(Coordinate previewsCoordinate);
	
	ImagePiece *image;
	QRectF rect;
	QColor color;
	
	Square *cSquare;
};
#endif