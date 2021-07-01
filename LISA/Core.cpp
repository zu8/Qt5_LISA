#include"core.h"
#include"Sprinkler.h"
#include <QGraphicsSceneMouseEvent>

Core::Core(QGraphicsEllipseItem* parent) : QObject(),QGraphicsEllipseItem(parent){
    centrPos = QPointF(0,0);
    BType = ghost;
    BodyColor = QColor(Qt::magenta);
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    this->setFlag(QGraphicsItem::ItemIsMovable,true);
    this->setZValue(0.9);

}

Core::~Core()
{
    areal->~Sprinkler();

}

Core::Core(const Core &other)
{
    scPos = other.scPos;
    centrPos = other.centrPos;
    BType = other.BType;
    BodyColor = other.BodyColor;
    m_previousPosition = other.m_previousPosition;
    areal = new Sprinkler(*(other.areal));
    coreFlow = other.coreFlow;
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    this->setFlag(QGraphicsItem::ItemIsMovable,true);
    this->setZValue(0.9);
}

qreal Core::getCoreFlow()
{
    return coreFlow =  areal->getFlow();
}

void Core::setCentrl(QPointF Scpos){
    centrPos = Scpos;
}

Core::bodyType Core::Bodytype(){
    return BType;
}
void Core::setBodyType (Core::bodyType newBt){

    BType = newBt;
}
void Core::setBodyType(int Type){

    if (Type == 0) BType = rotor;
    else if (Type == 1 || Type == 3) BType = rotator;
    else if (Type == 2) BType = spray;
    else BType = ghost;
 }
void Core::setColorBody(QColor col){
    BBrush.setColor(col);
    BodyColor = col;
}
QColor Core::getColor(){
    return BodyColor;
}
QPointF Core::previousPosition(){
    return m_previousPosition;
}
void Core::setPreviousPosition(QPointF position){
     m_previousPosition = position;
}

void Core::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() & Qt::LeftButton){
        //this->setPos(event->scenePos());
        this->mapToScene(event->scenePos());
        setPreviousPosition(event->scenePos());        
        if (this->parentItem() != nullptr) {            
            emit SprinklerClicked(qgraphicsitem_cast<Sprinkler*>(parentItem()));
        }
        else{
           //qDebug() << "Нед предка! ";
        }

    QGraphicsItem::mousePressEvent(event);
    }
}
void Core::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    emit Core::coremoving(true);

    QGraphicsItem::mouseMoveEvent(event);
}
void Core::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    emit Core::coremoving(false);
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
void Core::paint(QPainter* painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/ ) {
    //qDebug() << "в паинте core";
    //setPos(centrPos);
    switch (BType) {
        case ghost:{

                painter->setPen(QPen(Qt::black,2,Qt::SolidLine));
                painter->setBrush(QBrush(QColor(0,100,200,100)));
                painter->drawEllipse(-10,-10,20,20);
        break;
        }
        case rotor:{

                painter->setPen(QPen(Qt::black,2,Qt::SolidLine));
                painter->setBrush(QColor(10,80,255,255));
                painter->drawEllipse(-15,-15,30,30);
        break;
        }
        case rotator:{

                painter->setPen(QPen(Qt::black,3,Qt::SolidLine));
                painter->setBrush(BBrush);
                painter->drawEllipse(-14,-14,28,28);
                painter->drawEllipse(-10,-10,20,20);
                QPainterPath p;
                p.addEllipse(-10,-10,20,20);
                painter->fillPath(p, BodyColor);
        break;
        }
        case spray:{

                painter->setPen(QPen(Qt::black,3,Qt::SolidLine));
                painter->setBrush(QBrush(BodyColor));
                painter->drawEllipse(-14,-14,28,28);
                painter->setBrush(QBrush(Qt::white));
                painter->drawEllipse(-8,-8,16,16);

        break;
        }
        case tap:{
            QPainterPath pp;
            painter->setBrush(QBrush(QColor(50,50,200,255)));
            painter->drawEllipse(-30,-30,60,60);
            pp.arcTo(-30,-30,60,60,90,90);
            painter->fillPath(pp,QColor(Qt::white));
            pp.moveTo(0,0);
            pp.arcTo(-30,-30,60,60,0,-90);
            painter->fillPath(pp,QColor(Qt::white));
            painter->setBrush(Qt::NoBrush);
            painter->setPen(QPen(Qt::black,2,Qt::SolidLine));
            painter->drawLine(0,-30,0,30);
            painter->drawLine(-30,0,30,0);
            painter->drawEllipse(-30,-30,60,60);
        break;
        }
        default: {
        break;
        }
    }
}
QPainterPath Core::shape() const{
    QPainterPath path;
    path.addEllipse(-30, -30, 60, 60);
    return path;
}
Sprinkler* Core::getAreal(){
    return areal;
}
void Core::setAreal(Sprinkler* somesprinkler){
    areal = somesprinkler;
}

//Перегрузка операций << и >> для ImportedImage и QDataStream:
QDataStream & operator<<(QDataStream & out, const  Core  & body)
{
    out << body.scPos;
    out << body.centrPos;  
    out << body.m_previousPosition;
    return out;
}

QDataStream & operator>>(QDataStream & in,  Core & body)
{
    in >> body.scPos;
    in >> body.centrPos;  
    in >> body.m_previousPosition;
    return in;
}
