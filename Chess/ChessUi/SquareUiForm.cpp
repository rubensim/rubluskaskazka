#include <qdrag.h>
#include <QLabel>

#include "SquareUiForm.h"
#include "Constants.h"
#include "Enums.h"
#include "Square.h"
#include "BoardUiForm.h"
#include "WorkWithCoordinateSystem.h"

QFormLayout* SquareUiForm::box[] = {};

SquareUiForm::SquareUiForm(){}

SquareUiForm::SquareUiForm(Square* square){
	setAcceptDrops(true);

	this->cSquare = square;

	this->color = GetColorBySquareColor(square->GetColor());
	this->image = NULL;

	if (square->GetPiece() != nullptr)
	{ 
		this->SetImage(new ImagePiece(WorkWithCoordinateSystem::GetPieceCoordinate(this->GetCoordinate()), square->GetPiece()));
	}
}

SquareUiForm::~SquareUiForm(){
//	delete image;
	//delete cSquare;
}

QRectF SquareUiForm::boundingRect() const{
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

	if (BoardUiForm::currrentSquare != nullptr)
	{
		
		if (BoardUiForm::currrentSquare->cSquare->MovePiece(cSquare))
		{
			SetImage(BoardUiForm::currrentSquare->GetImage());
			WriteSteps(BoardUiForm::currrentSquare->GetCoordinate());
			BoardUiForm::currrentSquare = nullptr;
		}

		scene()->update();
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
	if (this->image != NULL)
	{
		this->image->setParentItem(NULL);
		scene()->removeItem(this->image);
	}

	this->image = image;

	this->image->setParentItem(this);

	this->cSquare->SetPiece(image->GetPiece());

	this->image->SetCoordinate(WorkWithCoordinateSystem::GetPieceCoordinate(GetCoordinate()));

}


void SquareUiForm::WriteSteps(Coordinate previewsCoordinate){
	QString step = QString::fromStdString(Board::Steps->GetCurrentStep(this->cSquare->GetPiece()->GetColor()));
	
	if (!step.isEmpty())
	{
		QLabel *label = new QLabel(step);
		SquareUiForm::box[this->cSquare->GetPiece()->GetColor()]->addRow(label);
	}
}

QColor SquareUiForm::GetColorBySquareColor(PieceColor color){

	if (color == PieceColor::White)
		return Qt::white;

	return Qt::black;

}






