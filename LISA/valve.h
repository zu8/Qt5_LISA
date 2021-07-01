#ifndef VALVE_H
#define VALVE_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEllipseItem>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QDebug>

class valve : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT

public:
    valve(QGraphicsEllipseItem* = 0);
    valve(const valve &other);
    ~valve();
    int getZoneNum();
    void setZoneNum(int Zone);
    double getMLosses();
    double getLLosses();
    void setMLosses(double losses);
    void setLLosses(double losses);
    QString getValveZoneNum();
    void setValveZoneNum(QString ZNum);
    void setPreviousPosition(QPointF pos);
    void showZoneNumLabel(bool flag);
    void setModel(QString AnyModel);
    void setPosition(QPointF p);    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect () const override;
    enum { Type = UserType + 7 };
    int type() const override { return Type;}
    QPainterPath shape() const override;
    friend QDataStream & operator<<(QDataStream & out, const  valve & vl);
    friend QDataStream & operator>>(QDataStream & in,  valve & vl);    
    QPointF scPosition;
    QPointF m_previousPosition;
    QString ValveZoneNumText;
    int zoneNum;
    QString model;
    QPainterPath ValveForm;
protected:
    double MLosses;
    double LLosses;
    double Result;
    QGraphicsProxyWidget* ValveProxy;
    QLabel* ValveZoneNum;


    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void ValveClicked(bool);
    void ValveMove(bool flag);
    void newMLosses(qreal val);
    void newLLosses(qreal val);
    void newResult(qreal val);
    void deleteLos();
public slots:
    void receveLosses(int role,qreal val);
};
QDataStream & operator<<(QDataStream & out, const  valve & vl);
QDataStream & operator>>(QDataStream & in,  valve & vl);
#endif // VALVE_H
