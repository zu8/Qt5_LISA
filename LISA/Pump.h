#ifndef PUMP_H
#define PUMP_H
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

class Pump : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Pump( QGraphicsRectItem* parent = 0 );
    Pump(const Pump &other);
    ~Pump();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setDesignCapacity(double);
    void setWorkingPressure(double);
    double getDesignCapacity();
    double getWorkingPressure();
    void setPreviousPosition(QPointF pos);
    void setScPos(QPointF);
    QRectF boundingRect () const override;
    enum { Type = UserType + 5 };
    int type() const override { return Type;}
    QPainterPath shape() const override;
    friend QDataStream & operator<<(QDataStream & out, const  Pump & pump1);
    friend QDataStream & operator>>(QDataStream & in,  Pump & pump1);    
    QPointF scPos;
    QPointF m_previousPosition;
protected:
    double DesCapValue;
    double PressValue;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void PumpMove(bool flag);
    void PumpClicked(bool flag);
};



//Перегрузка операций << и >> для Core и QDataStream:
QDataStream & operator<<(QDataStream & out, const  Pump & pump1);
QDataStream & operator>>(QDataStream & in,  Pump & pump1);
#endif // PUMP_H
