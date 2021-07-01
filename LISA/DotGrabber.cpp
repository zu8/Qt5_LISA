#include "DotGrabber.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

DotGrabber::DotGrabber(QGraphicsItem *parentItem, QObject *parent) :
    QObject(parent)
{
    setParentItem(parentItem);
    setAcceptHoverEvents(true);
    setBrush(QBrush(Qt::black));
    setRect(-8,-8,16,16);
    setDotFlags(0);
    this->setFlag(QGraphicsItem::ItemIsMovable,false ); // QGraphicsItem::ItemIsSelectable
    setZValue(0.8);
}

DotGrabber::DotGrabber(QPointF pos, QGraphicsItem *parentItem, QObject *parent) :
    QObject(parent)
{
    setParentItem(parentItem);
    setAcceptHoverEvents(true);
    setBrush(QBrush(Qt::black));
    setRect(-8,-8,16,16);
    setPos(pos);
    setPreviousPosition(pos);
    setDotFlags(1);
    setVisible(false);

}

DotGrabber::DotGrabber(const DotGrabber &other)
{
   // m_flags = other.m_flags;
    m_previousPosition = other.m_previousPosition;
    setBrush(QBrush(Qt::black));
    setRect(-8,-8,16,16);
    setDotFlags(0);
    setZValue(0.8);
}

DotGrabber::~DotGrabber(){ deleteLater();}

QRectF DotGrabber::boundingRect() const
{
     return QRectF(-20,-20,40,40);
}

QPainterPath DotGrabber::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(boundingRect()));  // boundingRect()
    return path;

}

QPointF DotGrabber::previousPosition() const
{
    return m_previousPosition;
}

void DotGrabber::setPreviousPosition(const QPointF previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
    emit previousPositionChanged();
}

void DotGrabber::setDotFlags(unsigned int flags)
{
    m_flags = flags;
}

void DotGrabber::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_flags & Movable){
        auto dx = event->scenePos().x() - m_previousPosition.x();
        auto dy = event->scenePos().y() - m_previousPosition.y();
        moveBy(dx,dy);
        setPreviousPosition(event->scenePos());
        qDebug() << "DotMove!";
       // emit signalMove(this, dx, dy);
    } else {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void DotGrabber::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_flags & Movable){
        setPreviousPosition(event->scenePos());
    } else {
        QGraphicsItem::mousePressEvent(event);
    }
}

void DotGrabber::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMouseRelease();
    QGraphicsItem::mouseReleaseEvent(event);
}

