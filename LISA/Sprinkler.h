#ifndef SPRINKLER_H
#define SPRINKLER_H
#include <QWidget>
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QLabel>

class DotGrabber;
class Body;
class Core;

class Sprinkler : public QObject, public QGraphicsItem {
    Q_OBJECT
public:

    Sprinkler(QGraphicsItem* parent = 0);
    Sprinkler(const Sprinkler &spr);
    Sprinkler(int radius, qreal flow,int art, int sprType, QGraphicsItem* parent = 0); //explicit
    ~Sprinkler();
    enum sprinklerType{
        rotor,
        rotator,
        spray,
        strip
    };
    enum { Type = UserType + 2 };
    int type() const override { return Type;}
    QString getLabelText();
    QPointF FixedTips(qreal StAngl, int Radius, int border);
    void ShowZoneNumLabel(bool);
    void setZoneNumLabel(QString Num);
    int GetRadius();
    Sprinkler::sprinklerType GetBodyType();
    QColor GetColor();
    QString getModel();
    void SetColor(int radius, qreal angle, Sprinkler::sprinklerType);
    void setZoningMode(int mode);
    void setCenter(QPointF);
    void setStartEndPos(QPointF S, QPointF E);
    QPointF previousPosition();
    void setPreviousPosition(QPointF);
    qreal getStartAngle(QPointF);
    qreal getExistingStartAngle();
    qreal getSpanAngle(QPointF);
    qreal getExistingSpanAngle();
    qreal getFlow();
    void RememberBodyTypeInt(int);
    void setType(int);
    void setClick(int);
    void setChildWidgetsPos();
    void setDotPos();
    QPointF getMidP();
    DotGrabber *getPointGrabSt();
    DotGrabber *getPointGrabEnd();
    void setPointGrabSt(DotGrabber* st);
    void setPointGrabEnd(DotGrabber* end);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    friend QDataStream & operator<<(QDataStream & out, const  Sprinkler & spr);
    friend QDataStream & operator>>(QDataStream & in,  Sprinkler & spr);
    //friend QDataStream & operator<<(QDataStream & out, const  Sprinkler* & spr);
    //friend QDataStream & operator>>(QDataStream & in,  Sprinkler* & spr);
    QString ZoneNumText;
    int TypeInt;
    int Articul;
    DotGrabber* PointGrabSt;
    DotGrabber* PointGrabEnd;
    qreal startAngle;
    qreal spanAngle;
protected:

     void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
     void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
     void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
     bool zoningMode;     
     QPen pen;
     QBrush brsh;
     QColor color;
     QPointF startP, midP, endP, center;
     QRectF IrriCircle;
     int Radius;
     qreal Flow;
     sprinklerType BodyType;
public:
     QGraphicsProxyWidget* proxy;
     QGraphicsSimpleTextItem* model;
     QLabel * ZoneNum;
     QPainterPathStroker* strokerS;
     QPainterPath formOfSector;
protected:

     bool FirstClick,SecondClick,ThirdClick;
     QPointF m_previousPosition;


signals:
    void SprinklerClicked(Sprinkler *Ccl);    
public slots:
    void updatePlease(bool);
    friend class SprinklerWgt;
    friend class Core;
};



//Перегрузка операций << и >> для Core и QDataStream:
QDataStream & operator<<(QDataStream & out, const  Sprinkler & spr);
QDataStream & operator>>(QDataStream & in,  Sprinkler & spr);
#endif // SPRINKLER_H
