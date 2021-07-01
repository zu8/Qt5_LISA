#include<QScrollBar>
#include "LISA_View.h"
#include "LISA_Scene.h"
#include "mainwindow.h"


extern QPointF start;
extern QPointF finish;
extern QVector<QGraphicsItem*> ActiveItemBand;
extern QWidget *ActiveWidget;


LISA_View::LISA_View(QWidget *parent): QGraphicsView(parent){
    selectionRect = new QRubberBand(QRubberBand::Rectangle, this);
    setTransformationAnchor(AnchorUnderMouse);
    showSelectionRect = true;
    setRenderHint(QPainter::Antialiasing);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);    
}
//    ________________________________________________________
void LISA_View::enterEvent(QEvent* event)
{
    if (LISA_Scene::currentAction() == LISA_Scene::RulerType) {
        QCursor MeasureTape = QCursor(QPixmap(":/image/res/cursors/measuring-tape .png"),24,3);
        viewport()->setCursor(MeasureTape);
        QGraphicsView::enterEvent(event);
    }
    else if(LISA_Scene::currentAction() == LISA_Scene::SprinklerType){
        QCursor sprinkler = QCursor(QPixmap(":/image/res/cursors/precision.png"),12,12);
        viewport()->setCursor(sprinkler);
        QGraphicsView::enterEvent(event);
    }
    else{
        viewport()->setCursor(Qt::CrossCursor);
        //QGraphicsView::enterEvent(event);
    }

}
//    ________________________________________________________
void LISA_View::mousePressEvent(QMouseEvent* event) {
    //qDebug() <<"showSelectionRect "<< showSelectionRect;
    if (event->button() == Qt::MiddleButton){
       _move = true;
       _moveStartX = event->x();
       _moveStartY = event->y();
       viewport()->setCursor(Qt::ClosedHandCursor);

    }
    else if (event->button() == Qt::LeftButton && showSelectionRect) {

        //qDebug() << "щелк!";
           mapToScene((start = event->pos()).toPoint());
           qDebug() << start;
           selectionRect->setGeometry(QRect(start.toPoint(), QSize(1,1)));
           selectionRect->show();
           QGraphicsView::mousePressEvent(event);
    }
    else if (event->button() == Qt::LeftButton && LISA_Scene::currentAction() == LISA_Scene::RulerType){

           emit rulerDisappear(false);
           start = event->pos();
           emit rulerIsSituated(start.toPoint());
           qDebug() << "click on view "<< start.toPoint();
           QGraphicsView::mousePressEvent(event);

    }
    else if (event->button() == Qt::LeftButton && LISA_Scene::currentAction() == LISA_Scene::ScaleType){
        showSelectionRect = false;
        QGraphicsView::mousePressEvent(event);
    }
    else{
        QGraphicsView::mousePressEvent(event);
    }
}
//    ________________________________________________________
void LISA_View::mouseMoveEvent(QMouseEvent *event) {
    emit mousePos(mapToScene(event->pos()));

    if (event->buttons() == Qt::MiddleButton){
    viewport()->setCursor(Qt::ClosedHandCursor);
        if (_move){

          horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - _moveStartX));
           verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - _moveStartY));
           _moveStartX = event->x();
           _moveStartY = event->y();
       }
    }
    else if (event->buttons() == Qt::LeftButton && showSelectionRect) {
        selectionRect->setGeometry(QRect(start.toPoint(), event->pos()).normalized());
        QGraphicsView::mouseMoveEvent(event);
    }
    else if(event->buttons() == Qt::LeftButton && LISA_Scene::currentAction() == LISA_Scene::RulerType){
        QCursor MeasureTape = QCursor(QPixmap(":/image/res/cursors/measuring-tape .png"),24,3);
        viewport()->setCursor(MeasureTape);
        start = event->pos();
        qDebug() << "start" << start;
        emit rulerIsSituated(start.toPoint());
        QGraphicsView::mouseMoveEvent(event);
    }
    else if(LISA_Scene::currentAction() == LISA_Scene::SprinklerType){

        QCursor sprinkler = QCursor(QPixmap(":/image/res/cursors/precision.png"),12,12);
        viewport()->setCursor(sprinkler);
        showSelectionRect = false;
        //start = event->pos();
        //emit  mousePos( start);
        QGraphicsView::mouseMoveEvent(event);
    }
    else if(event->buttons() == Qt::LeftButton && LISA_Scene::currentAction() == LISA_Scene::PipeType)
    {
        showSelectionRect = false;
        QGraphicsView::mouseMoveEvent(event);

    }
    else if(event->buttons() == Qt::LeftButton && LISA_Scene::currentAction() == LISA_Scene::ValveType)
    {
        showSelectionRect = false;
        QGraphicsView::mouseMoveEvent(event);

    }
    else{
        QGraphicsView::mouseMoveEvent(event);
        if (LISA_Scene::currentAction() == LISA_Scene::RulerType) {
            QCursor MeasureTape = QCursor(QPixmap(":/image/res/cursors/measuring-tape .png"),24,3);
            viewport()->setCursor(MeasureTape);
        }
        else{
            viewport()->setCursor(Qt::CrossCursor);
        }
    }
}
//    ________________________________________________________
void LISA_View::mouseReleaseEvent(QMouseEvent* event)
{
    if (LISA_Scene::currentAction() == LISA_Scene::RulerType) {
        QCursor MeasureTape = QCursor(QPixmap(":/image/res/cursors/measuring-tape .png"),24,3);
        viewport()->setCursor(MeasureTape);
        QGraphicsView::mouseReleaseEvent(event);
    }
    else if(event->buttons() == Qt::LeftButton && LISA_Scene::currentAction() == LISA_Scene::SprinklerType){
        QCursor sprinkler = QCursor(QPixmap(":/image/res/cursors/precision.png"),12,12);
        viewport()->setCursor(sprinkler);
        QGraphicsView::mouseReleaseEvent(event);
    }
    else{
        viewport()->setCursor(Qt::CrossCursor);
    }
    if (event->button() == Qt::LeftButton){
        qDebug() <<"showSelectionRect in release"<< showSelectionRect;
        this->repaint(sceneRect().toRect());
        _move = false;
        if (showSelectionRect){
        QPointF SceneOrigin = mapToScene(start.toPoint());
        QPointF SceneEnd = mapToScene(finish.toPoint() = event->pos());
        QRectF SceneRB(SceneOrigin,SceneEnd);
        qDebug() << "sent selectionRect: " << SceneRB;
        emit selectionRectSquare(SceneRB);
        selectionRect->hide();
        }
        if (!(LISA_Scene::currentAction() == LISA_Scene::RulerType))showSelectionRect = true;
        emit rulerDisappear(true);
        QGraphicsView::mouseReleaseEvent(event);
        update();
    }
}
//    ________________________________________________________
void LISA_View::wheelEvent(QWheelEvent* event)
{

    int angle = event->angleDelta().y();
    qreal factor;

    if (angle > 0) {
        factor = 1.1;
    } else {
        factor = 0.9;
    }
    qreal ScaleFactor = transform().scale(factor, factor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (ScaleFactor < 0.01 || ScaleFactor > 100)  return;

    scale(factor, factor);
}
//    ________________________________________________________
void LISA_View::NoNeedSelectionRect(bool flag){
    if(flag) showSelectionRect = false;
    else showSelectionRect = true;

}
//    ________________________________________________________
void LISA_View::rulerToolOn(bool flag){
    if (flag) {
        showSelectionRect = false;// showSelectionRect = false;
    }
    else{
        showSelectionRect = true; // showSelectionRect = true;
    }
}
//    ________________________________________________________
void LISA_View::scaleToolOn(bool flag){
    if (flag) {
        showSelectionRect = false;
        //scaleTool = true;
    }
    else{
        showSelectionRect = true;
        //scaleTool = false;
    }
}
