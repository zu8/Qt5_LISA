#ifndef LOSSES_H
#define LOSSES_H
#include <QVector>
#include <QGraphicsPathItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QtMath>
#include "LISA_Scene.h"

class losses : public QObject, public QGraphicsPathItem {
  Q_OBJECT

 public:
    losses(QGraphicsPathItem* = 0);
    losses(const losses &other);
    ~losses();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    QPainterPath shape() const override;
    enum {
        Type = UserType + 8};
    int type() const override { return Type; }
    void setStartPos(QPointF pos);
    void setCurPos(QPointF pos);
    void setRole(int Role);
    void setDiam(int Diam);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QPainterPath curPath;
    QPointF curPoint;
    QPointF previousPos;
    QPointF startPos;
    int LosDiameter;
    int LosRole; // 0 - mainLine , 1 - lateral
    QVector<QPointF> points;
    QRectF rectArea;
    bool StartDrawing;
    bool endDrawing;
    qreal PipeLos;


signals:
    void CalcLos(int role,qreal los);
    void EDrawingLos();
public slots:
   //void startCalc(int role, int diam);
   void LsrectScene(QRectF scR);
    };
#endif // LOSSES_H
