#ifndef PIPE_H
#define PIPE_H
#include<QVector>
#include <QGraphicsPathItem>
#include <QGraphicsView>
#include "DotGrabber.h"

class pipe : public QObject, public QGraphicsPathItem {
  Q_OBJECT

 public:
    pipe(QGraphicsPathItem* = 0);
    pipe(const pipe &other);
    ~pipe();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    QPainterPath shape() const override;
    enum {
        Type = UserType + 6
    };
    int type() const override;
    void setCurrentDot(DotGrabber* dot);
    DotGrabber* getCurrentDot();
    QVector<DotGrabber*> getPipeGrabbers();
    QPointF getDotPos();
    void setClick(bool);
    void setDotPos(QPointF);
    void setCurPos(QPointF);
    void setStartPos(QPointF);
    qreal getPipeLength();
    void setPipeLength(qreal len);
    void setDiameter(int Diam);
    void setRole(int Role);
    void setColor(QColor col);
    void setDrop(bool);
    bool Draging();
    void refreshPoints();

    friend QDataStream& operator<<(QDataStream & out, const  pipe & pp);
    friend QDataStream& operator>>( QDataStream& in, pipe& pp );   
    QPointF scPos;
    QVector<QPointF>DotPoints;
    QVector<DotGrabber*> milestones;
    int P_Diameter;
    int P_Role;
    QColor P_Color;
    DotGrabber* currentDot;
 private:
    QLineF line;
    QRectF rectArea;
    QPointF startP,endP,previousP,curP;
    QPainterPath currentPath;
    QPainterPathStroker* stroker;
    bool PipeClick;
    bool startDrawing,endDrawing;
    bool DragPipe,DropPipe;
    qreal Pipelength;

 signals:
    void finishDrawing(qreal Pipelength);
 public slots:
    void rectScene(QRectF scR);
};

QDataStream& operator<<(QDataStream & out,const   pipe  & pp);
QDataStream& operator>>( QDataStream& in, pipe& pp );

#endif // PIPE_H
