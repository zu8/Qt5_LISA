#ifndef LISA_VIEW_H
#define LISA_VIEW_H
#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QRubberBand>
#include <QLabel>


class LISA_View : public QGraphicsView {
    Q_OBJECT

public:
    explicit LISA_View(QWidget *parent = 0);
protected:
    void enterEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent * event) override;
    void scaleView(qreal scaleFactor);


    QRubberBand *selectionRect;
    bool showSelectionRect;
    bool _move;
    int _moveStartX, _moveStartY;


public slots:
    void NoNeedSelectionRect(bool);
    void rulerToolOn(bool);
    void scaleToolOn(bool);


signals:
    void mousePos(QPointF);
    void selectionRectSquare(QRectF);
    void rulerIsSituated(QPoint);
    void rulerDisappear(bool);
    friend class LISA_Scene;
};
#endif // LISA_VIEW_H
