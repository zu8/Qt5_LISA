#include "ImportedImage.h"
#include "LISA_Scene.h"
#include<QPainter>

ImportedImage::ImportedImage(QGraphicsPixmapItem* parent): QObject(), QGraphicsPixmapItem(parent){
    scalingValue = 1;
    scPos = QPointF(0,0);
}

ImportedImage::ImportedImage(const ImportedImage &other)
{
    m_pxmp = other.m_pxmp;
    selection_mask = other.selection_mask;
    m_previousPosition = other.m_previousPosition;
    status = other.status;
    scalingValue = other.scalingValue;
    scPos = other.scPos;
}
//    ________________________________________________________
void ImportedImage::setImportedImage(const QPixmap &pxmp){
    m_pxmp = pxmp;
}

void ImportedImage::setScValue(qreal val)
{
    scalingValue = val;
}

qreal ImportedImage::getScValue()
{
    return scalingValue;
}

void ImportedImage::setScPos(QPointF sp)
{
    scPos = sp;
}

QPointF ImportedImage::getScPos()
{
    return scPos;
}
//    ________________________________________________________
QPointF ImportedImage::previousPosition() const {
    return m_previousPosition;
}
//    ________________________________________________________
void ImportedImage::setPreviousPosition(const QPointF previousPosition){
    if (m_previousPosition == previousPosition)
        return;
    m_previousPosition = previousPosition;
}
//    ________________________________________________________
QRectF ImportedImage::boundingRect () const {
    return QRectF(m_pxmp.rect());
}
//    ________________________________________________________
void ImportedImage::mousePressEvent(QGraphicsSceneMouseEvent* event){

    if (event->button() & Qt::LeftButton ){
        setPreviousPosition(event->scenePos());
        qDebug() << "координатыитема: "<<event->scenePos();
    emit ImgClicked(true);

    }
    QGraphicsItem::mousePressEvent(event);
}
//    ________________________________________________________
void ImportedImage::mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
    qDebug() << "move!";
    if(status){
    auto dx = event->scenePos().x() - m_previousPosition.x();
    auto dy = event->scenePos().y() - m_previousPosition.y();
    moveBy(dx,dy);
    setPreviousPosition(event->scenePos());
    }
    else {
        return;
    }

}
//    ________________________________________________________
void ImportedImage::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
                          QWidget * /*widget*/) {
    if (m_pxmp.isNull()==false){

         painter->drawPixmap(m_pxmp.rect(),m_pxmp);
         if(this->isSelected()){
             selection_mask.setRect(m_pxmp.rect().x(),m_pxmp.rect().y(),m_pxmp.width(),m_pxmp.height());
             painter->setBrush(QBrush(QColor(0,100,200,100)));
             painter->drawRect(selection_mask);
         }
         else{
             selection_mask.setRect(m_pxmp.rect().x(),m_pxmp.rect().y(),0,0);
         }

    }
}
//    ________________________________________________________
QPainterPath ImportedImage::shape() const{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
//    ________________________________________________________
int ImportedImage::type() const
{
    return Type;
}
//    ________________________________________________________
void ImportedImage::ImageIsBlocked(bool flag){
    if (flag) {
        status = false;
    }
    else {
        status = true;
    }
}

QDataStream & operator<<(QDataStream & out,  ImportedImage const & image)
{
  out<<image.m_pxmp;
  out<<image.selection_mask;
  out<<image.m_previousPosition;
  out<<image.status;
  out<<image.scalingValue;
  return out;
}

QDataStream & operator>>(QDataStream & in,  ImportedImage & image)
{
 in>>image.m_pxmp;
 in>>image.selection_mask;
 in>>image.m_previousPosition;
 in>>image.status;
 in>>image.scalingValue;
 return in;
}

