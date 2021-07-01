#ifndef RULER_H
#define RULER_H
#include<QWidget>
#include<QDebug>
#include<QLabel>
#include<QLayout>
#include <QGraphicsView>

class Ruler: public QWidget{
    Q_OBJECT
public:
    Ruler(QWidget *parent = nullptr);
    ~Ruler();
    void importText();
    void paintMeasure(QPoint,QPoint);
    void paintEvent(QPaintEvent *) override;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QLabel *value;
    QPointF Rstart,Rend;
public slots:
    void ChangePosition(QPoint);
    void ShowRuler(bool);
    void MeasureStart(QPointF);
    void MeasureEnd(QPointF);

};
#endif // RULER_H
