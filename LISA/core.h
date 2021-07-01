#ifndef CORE_H
#define CORE_H
#include <QWidget>
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QDebug>

class QGraphicsSceneMouseEvent;
class Sprinkler;

class Core : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
   Core(QGraphicsEllipseItem* parent = 0);
   ~Core();
   Core(const Core &other);
   enum { Type = UserType + 4 };
   int type() const override { return Type;}
   enum bodyType {
       ghost = 0,
       rotor,
       rotator,
       spray,
       tap       
   };
   QPointF scPos;
   QPointF centrPos;
   qreal getCoreFlow();
   bodyType Bodytype ();
   Sprinkler* getAreal();
   void setAreal(Sprinkler*);
   void setCentrl(QPointF Scpos);
   void setBodyType(bodyType Type);
   void setBodyType(int Type);
   QColor getColor();
   void setColorBody(QColor);
   QPointF previousPosition();
   void setPreviousPosition(QPointF);
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
   QPainterPath shape() const override;
   void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
   void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
   friend QDataStream& operator>>( QDataStream& in,  Core & body );
   friend QDataStream& operator<<(QDataStream & out, const   Core & body);
private:
   bodyType BType;
   QColor BodyColor;
   QBrush BBrush;
   QPointF m_previousPosition;
   Sprinkler* areal;
   qreal coreFlow;

signals:
    void SprinklerClicked(Sprinkler*);
    void coremoving(bool);
friend class Sprinkler;
friend class SprinklerWgt;

};


//Перегрузка операций << и >> для Core и QDataStream:
QDataStream & operator<<(QDataStream & out, const  Core & body);
QDataStream & operator>>(QDataStream & in,  Core & body);
#endif // CORE_H
