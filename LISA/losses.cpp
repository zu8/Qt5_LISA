
#include "losses.h"


losses::losses(QGraphicsPathItem *parent): QObject(), QGraphicsPathItem(parent)
{    
    LosDiameter = 0;
    LosRole = -1; // 0 - mainLine , 1 - lateral
    rectArea = QRectF (0,0,5000,5000);
    StartDrawing = false;
    endDrawing = false;
    PipeLos = 0.00;
    this->setFlag( QGraphicsItem::ItemIsSelectable,true);

}
losses::~losses(){deleteLater();}

QRectF losses::boundingRect() const
{
    return rectArea;
}

void losses::paint(QPainter *painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/)
{

    curPath.clear();
    painter->setPen(QPen(QColorConstants::Svg::orangered,10,Qt::SolidLine));
    curPath.moveTo(points[0]);
    for(auto i = 0; i < points.size(); i++){
        curPath.lineTo(points[i]);
    }
    if(!endDrawing) curPath.lineTo(curPoint);
    painter->drawPath(curPath);
}

QPainterPath losses::shape() const
{
   QPainterPathStroker stroker;// = new QPainterPathStroker;
   stroker.setWidth(10);
   return stroker.createStroke(curPath);
}

void losses::setStartPos(QPointF pos)
{
    startPos = pos;
    points.push_back(startPos);
}

void losses::setCurPos(QPointF pos)
{
    curPoint = pos;
}

void losses::setRole(int Role)
{
    LosRole = Role;
}

void losses::setDiam(int Diam)
{
    LosDiameter = Diam;
}

void losses::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "click lose";
    StartDrawing = true;
    curPoint = event->scenePos();
    if (qFabs(curPoint.x() - previousPos.x()) < 25 && qFabs(curPoint.y() - previousPos.y()) < 25)
    {
        endDrawing = true;

        switch (LosDiameter) {
            case 25:
            {
             PipeLos = (curPath.length()*0.01)*0.018;
            }
                break;
            case 32:
            {
            PipeLos = (curPath.length()*0.01)*0.0055;
            }
                break;
            case 40:
            {
            PipeLos = (curPath.length()*0.01)*0.0026;
            }
                break;
            default:
                break;
        }
        qDebug()<< "len "<< curPath.length();
        qDebug()<< "PipeLos "<< PipeLos;
         emit CalcLos(LosRole,PipeLos);        
    }
    else
    {
        previousPos = curPoint;
        points.push_back(curPoint);

    }
    qDebug() << endDrawing;
    QGraphicsItem::mousePressEvent(event);
}

void losses::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
      if(StartDrawing == false) points[0] = startPos;
    qDebug() << "LOS move";
     if (endDrawing) emit EDrawingLos();
     if (endDrawing == false) curPoint = event->scenePos();


     QGraphicsItem::mouseMoveEvent(event);
}

void losses::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}

void losses::LsrectScene(QRectF scR)
{
    rectArea = scR;
}

