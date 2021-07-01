#include <QPainter>
#include <QDebug>
#include "Pump.h"

Pump::Pump(QGraphicsRectItem *parent): QObject(),QGraphicsRectItem (parent){
    scPos = QPointF(0,0);
    m_previousPosition = scPos;
    DesCapValue = 0;
    PressValue = 0;
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    this->setFlag(QGraphicsItem::ItemIsMovable,true);
}

Pump::Pump(const Pump &other)
{
   m_previousPosition = other.m_previousPosition;
   DesCapValue = other.DesCapValue;
   PressValue = other.PressValue;
   scPos = other.scPos;
   this->setFlag(QGraphicsItem::ItemIsSelectable,true);
   this->setFlag(QGraphicsItem::ItemIsMovable,true);
}

Pump::~Pump(){ deleteLater();}

void Pump::paint(QPainter *painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/)
{
    //qDebug() << "в пэинтере насоса";
    painter->setPen(QPen(Qt::black,8,Qt::SolidLine));
    painter->setBrush(QBrush(QColor(255,255,255)));
    painter->drawRect(-35,-35,70,70);
    painter->setFont(QFont("Roboto",36,QFont::Bold));
    painter->drawText(-14,18,"P");
}

void Pump::setDesignCapacity(double dc)
{
    DesCapValue = dc;
}

void Pump::setWorkingPressure(double wp)
{
    PressValue = wp;
}

double Pump::getDesignCapacity()
{
    return DesCapValue;
}

double Pump::getWorkingPressure()
{
    if (PressValue) return PressValue;
    else return 0;
}

void Pump::setPreviousPosition(QPointF pos)
{
    m_previousPosition = pos;
}

void Pump::setScPos(QPointF sp)
{
    scPos = sp;
}

QRectF Pump::boundingRect() const
{
    return QRectF(-35,-35,70,70);
}

QPainterPath Pump::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Pump::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton ){
        setPreviousPosition(event->scenePos());
        emit PumpClicked(true);
    }
    QGraphicsItem::mousePressEvent(event);
}

void Pump::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    auto dx = event->scenePos().x() - m_previousPosition.x();
    auto dy = event->scenePos().y() - m_previousPosition.y();
    moveBy(dx,dy);
    setPreviousPosition(event->scenePos());
    emit PumpMove(true);

    QGraphicsItem::mouseMoveEvent(event);
}

void Pump::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    emit PumpMove(false);
    QGraphicsItem::mouseReleaseEvent(event);
}

QDataStream & operator<<(QDataStream & out,const Pump & pump1)
{
    out<< pump1.m_previousPosition;
    out<< pump1.DesCapValue;
    out<< pump1.PressValue;
    out<< pump1.scPos;
    return out;
}
QDataStream & operator>>(QDataStream & in,Pump & pump1)
{
    in>>pump1.m_previousPosition;
    in>> pump1.DesCapValue;
    in>> pump1.PressValue;
    in>> pump1.scPos;
    return in;
}
