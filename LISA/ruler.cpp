#include "ruler.h"
extern QPointF start;
extern QPointF finish;

class LISA_Scene;

Ruler::Ruler(QWidget * parent): QWidget(parent){
    //Rstart = start;
    //Rend = finish;
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    value = new QLabel;
    //QFont sansFont("Helvetica [Cronyx]", 10);
    QFont sansFont("Times",10);

    value->setFont(sansFont);
    phbxLayout->addWidget(value);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, QColor::fromRgb(200,200,250,250) );
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->setLayout(phbxLayout);
    this->setGeometry(20,20,80,40);
    this->hide();

}
//    ________________________________________________________
Ruler::~Ruler(){};
void Ruler::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
}
void Ruler::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
}
void Ruler::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
}
void Ruler::paintEvent(QPaintEvent * event){
    QWidget::paintEvent(event);
    qDebug() << "start" << start;
    qDebug() << "end" << Rend;
    auto len = (QLineF(Rstart,Rend).length());
    int Intlength = static_cast<int>(len);
    qDebug() << "start" << len;
    this->value->setNum(Intlength*10);

}
//    ________________________________________________________
void Ruler::ChangePosition(QPoint viewPos){
    QPoint UpperMouse(viewPos.x()+20,viewPos.y()+20);
    qDebug() <<"changePos working" <<UpperMouse;
    this->move(UpperMouse);
}
//    ________________________________________________________
void Ruler::ShowRuler(bool flag){
    if(flag){
        this->hide();
    }
    else {
        this->show();
    }
}
//    ________________________________________________________
void Ruler::importText(){
    value->setNum(QLineF(Rstart,Rend).length());
}
//    ________________________________________________________
void Ruler::MeasureStart(QPointF StartPoint){
    Rstart = StartPoint;
}
//    ________________________________________________________
void Ruler::MeasureEnd(QPointF EndPoint){
    Rend = EndPoint;
}

