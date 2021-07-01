#include<QtMath>
#include"Sprinkler.h"
#include "DotGrabber.h"
#include "core.h"

class LISA_Scene;


Sprinkler::Sprinkler(QGraphicsItem *parent): QObject(),QGraphicsItem (parent){
    ZoneNumText = "0";
    Radius = 0;
    Flow = 0;
    Articul = 0;
    center = QPointF(0,0);
    startAngle = 0;
    spanAngle = 5;
    FirstClick = false;
    SecondClick = false;
    ThirdClick = false;
    strokerS = new QPainterPathStroker;
    strokerS->setWidth(6);


    color =QColor(250,100,240,220);
    pen = QPen(QColorConstants::Svg::steelblue,4,Qt::SolidLine);
    brsh = QBrush(Qt::NoBrush);
    model = new QGraphicsSimpleTextItem(this);
    model->setFont(QFont("Roboto",24,QFont::Medium));
    model->setText(getModel());
    model->setPos(30,30);
    model->setVisible(false);
    proxy = new QGraphicsProxyWidget(this);
    ZoneNum = new QLabel();
    proxy->setWidget(ZoneNum);
    ZoneNum->setText("0");
    ZoneNum->setFont(QFont("Roboto",45,QFont::Medium));
    ZoneNum->move(center.toPoint());
    ZoneNum->setVisible(false);
    zoningMode = false;
    //proxy->setFlag(QGraphicsItem::ItemIsSelectable, true);
    //proxy->setFlag(QGraphicsItem::ItemIsMovable, true);

        PointGrabSt = new DotGrabber(this);
        PointGrabEnd = new DotGrabber(this);
        //PointGrabSt->stackBefore(this);
        PointGrabSt->setVisible(false);
        PointGrabEnd->setVisible(false);
        //PointGrabSt->setFlag(GraphicsItemFlag::ItemIsMovable,false  );  // | QGraphicsItem::ItemIsSelectable
        //PointGrabEnd->setFlag(GraphicsItemFlag::ItemIsMovable,false  ); // | QGraphicsItem::ItemIsSelectable

    this->setFlags( QGraphicsItem::ItemClipsToShape | QGraphicsItem::ItemDoesntPropagateOpacityToChildren |
                    QGraphicsItem::ItemStacksBehindParent | QGraphicsItem::ItemSendsGeometryChanges);
    //setAcceptHoverEvents(true);
    this->setOpacity(0.6);
        setZValue(0.2);

}

Sprinkler::Sprinkler(const Sprinkler &spr)
{
    PointGrabSt = new DotGrabber(*(spr.PointGrabSt));
    PointGrabEnd = new DotGrabber(*(spr.PointGrabEnd));
    formOfSector = spr.formOfSector;
    zoningMode = spr.zoningMode;
    strokerS = new QPainterPathStroker();
    strokerS->setWidth(6);
    pen = spr.pen;
    brsh = spr.brsh;
    color = spr.color;
    startP = spr.startP;
    midP = spr.midP;
    endP = spr.endP;
    center = spr.center;
    IrriCircle = spr.IrriCircle;
    Radius = spr.Radius;
    Flow = spr.Flow;
    Articul = spr.Articul;
    startAngle = spr.startAngle;
    spanAngle = spr.spanAngle;
    BodyType = spr.BodyType;
    proxy = new QGraphicsProxyWidget();
    model = new QGraphicsSimpleTextItem();
    ZoneNum = new QLabel();    
    FirstClick = spr.FirstClick;
    SecondClick = spr.SecondClick;
    ThirdClick = spr.ThirdClick;
    m_previousPosition = spr.m_previousPosition;
    //formOfSector = new QPainterPath(*(spr.formOfSector));

    model->setFont(QFont("Roboto",24,QFont::Medium));
    model->setText(getModel());
    model->setPos(30,30);
    model->setVisible(false);
    proxy->setWidget(ZoneNum);
    ZoneNum->setText("0");
    ZoneNum->setFont(QFont("Roboto",45,QFont::Medium));
    ZoneNum->move(center.toPoint());
    ZoneNum->setVisible(false);

   this->setFlags( QGraphicsItem::ItemClipsToShape | QGraphicsItem::ItemDoesntPropagateOpacityToChildren |
                   QGraphicsItem::ItemStacksBehindParent | QGraphicsItem::ItemSendsGeometryChanges);
   this->setOpacity(0.6);
   setZValue(0.2);
};
Sprinkler::Sprinkler(int GivenRadius, qreal GivenFlow,int GivenArt, int sprType,QGraphicsItem *parent): QObject(),QGraphicsItem (parent){
    //formOfSector = new QPainterPath;
    Radius = GivenRadius;
    Flow = GivenFlow;
    Articul = GivenArt;     
    center = QPointF(0,0);
    startAngle = 0;
    spanAngle = 5;
    FirstClick = false;
    SecondClick = false;
    ThirdClick = false;
    strokerS = new QPainterPathStroker;
    strokerS->setWidth(6);
    setType(sprType);
    color =QColor(250,100,240,220);
    pen = QPen(QColorConstants::Svg::steelblue,4,Qt::SolidLine);
    brsh = QBrush(Qt::NoBrush);
    model = new QGraphicsSimpleTextItem(this);
    model->setFont(QFont("Roboto",24,QFont::Medium));
    model->setText(getModel());
    model->setPos(30,30);
    model->setVisible(false);
    proxy = new QGraphicsProxyWidget(this);
    ZoneNum = new QLabel();
    proxy->setWidget(ZoneNum);    
    ZoneNum->setText("0");
    ZoneNum->setFont(QFont("Roboto",45,QFont::Medium));
    ZoneNum->move(center.toPoint());
    ZoneNum->setVisible(false);
    zoningMode = false;
    //proxy->setFlag(QGraphicsItem::ItemIsSelectable, true);
    //proxy->setFlag(QGraphicsItem::ItemIsMovable, true);

        PointGrabSt = new DotGrabber(this);
        PointGrabEnd = new DotGrabber(this);
        //PointGrabSt->stackBefore(this);
        PointGrabSt->setVisible(false);
        PointGrabEnd->setVisible(false);
        //PointGrabSt->setFlag(GraphicsItemFlag::ItemIsMovable,false  );  // | QGraphicsItem::ItemIsSelectable
        //PointGrabEnd->setFlag(GraphicsItemFlag::ItemIsMovable,false  ); // | QGraphicsItem::ItemIsSelectable

    this->setFlags( QGraphicsItem::ItemClipsToShape | QGraphicsItem::ItemDoesntPropagateOpacityToChildren |
                    QGraphicsItem::ItemStacksBehindParent | QGraphicsItem::ItemSendsGeometryChanges);
    //setAcceptHoverEvents(true);
    this->setOpacity(0.6);
        setZValue(0.2);
}
//    ________________________________________________________

//    ________________________________________________________
Sprinkler::~Sprinkler(){
    deleteLater();
}

QString Sprinkler::getLabelText()
{
    return ZoneNum->text();
}
//    ________________________________________________________
int Sprinkler::GetRadius(){
    return Radius;
}
//    ________________________________________________________
QColor Sprinkler::GetColor(){
    return color;
}

QString Sprinkler::getModel()
{
    QString coreName;
    switch(Articul){
    case 0: coreName += "PGP \n"; break;
    case 1: coreName += "MP800SR \n"; break;
    case 2: coreName += "MP1000 \n"; break;
    case 3: coreName += "MP2000 \n"; break;
    case 4: coreName += "MP3000 \n"; break;
    case 5: coreName += "MP3500 \n"; break;
    case 6: coreName += "MPCorner \n"; break;
    case 7: coreName += "MPLCS515 \n"; break;
    case 8: coreName += "MPRCS515 \n"; break;
    case 9: coreName += "MPSS530 \n"; break;
    case 100: coreName += "5004-PC \n"; break;
    case 101: coreName += "HE-VAN-08 \n"; break;
    case 102: coreName += "HE-VAN-10 \n"; break;
    case 103: coreName += "HE-VAN-12 \n"; break;
    case 104: coreName += "HE-VAN-15 \n"; break;
    default: coreName += "undefined \n"; break;
    }
    if (spanAngle >= 90 && spanAngle <= 210 && Articul >=1 && Articul <=5) coreName += "90-210 ";
    else if (spanAngle > 210 && spanAngle <= 270 && Articul >=1 && Articul <=4) coreName += "210-270 ";
    else if (spanAngle > 270 && spanAngle <=360 &&  Articul >=1 && Articul <=4) coreName += "360 ";
    else if (spanAngle < 90 && Articul == 6) coreName += "45-105 ";

    coreName += QString::number(getFlow());
    model->setText(coreName);

    return  coreName;
}
//    ________________________________________________________
void Sprinkler::SetColor(int rad, qreal angle, Sprinkler::sprinklerType SType){
    switch (SType) {
    case(Sprinkler::rotor) : {
        color = QColor(10,80,255,255);
        break;
    }
    case (Sprinkler::rotator) : // All radius values devided on 10!!! to correct representation on scene
    {
        if ( rad < 390 && rad > 300 ) {color = QColor(30,100,100,255);}
        else if(angle >0 && angle <= 210 && rad <= 450 && rad > 390) color = QColor(130,20,20,255);
        else if(angle > 210 && angle <= 270 && rad <= 450 && rad > 390 ) color = QColor(130,255,255,255);
        else if(angle > 270 && rad <= 450 && rad > 390) color = QColor(200,230,60,255);
        else if(angle <= 210 && rad <= 650 && rad > 450) color = QColor(0,0,0,255);
        else if(angle > 210 && angle <= 270 && rad <= 650 && rad > 450 ) color = QColor(10,192,82,255);
        else if(angle > 270 && rad <= 650 && rad > 450 ) color = QColor(225,35,35,255);
        else if(angle <= 210 && rad > 650 && rad <= 910) color = QColor(0,130,210,255);
        else if(angle > 210 && angle <= 270 && rad <= 910 && rad > 650 ) color = QColor(255,210,0,255);
        else if(angle > 270 && rad >650 && rad <=910) color = QColor(100,100,100,255);
        else if(rad > 910) color = QColor(255,180,110,255);
        else if (rad <= 300 && angle <= 210) color = QColor(255,100,20,255);
        else color = QColor(130,255,20,255);
        break;
    }
    case(Sprinkler::spray) : {
        if (rad <= 200) color = QColor(60,150,60,255);
        else if (rad > 200 && rad <=300) color = QColor(80,180,255,255);
        else if (rad > 300 && rad <=370) color = QColor(206,169,125,255);
        else if (rad > 370) color = QColor(0,0,0,255);
        break;
    }
    case(Sprinkler::strip) : {
        if (angle < 0) color = QColor(255,240,211,255);
        else if(angle == 0) color = QColor(86,52,0,255);
        else if(angle > 0) color = QColor(200,120,0,255);
        break;
    }
    default : break;
    }
}

void Sprinkler::setZoningMode(int mode)
{
    if (mode == 1){
        brsh = QBrush(QColor(255,0,255,100));
        pen = QPen(Qt::magenta,7,Qt::SolidLine);
        zoningMode = true;
    }
    else if(mode == 2)
    {
        brsh = QBrush(QColor(20,255,20,100));
        pen = QPen(Qt::green,7,Qt::SolidLine);
        zoningMode = true;
    }
    else
    {
        brsh = QBrush(Qt::NoBrush);
        pen = QPen(QColorConstants::Svg::steelblue,4,Qt::SolidLine);
        zoningMode = false;
    }
}


//    ________________________________________________________
void Sprinkler::setCenter(QPointF scPos){
    center = scPos;
    setChildWidgetsPos();

}

void Sprinkler::setStartEndPos(QPointF S, QPointF E)
{
   startP = S;
   endP = E;
}
//    ________________________________________________________
void Sprinkler::setChildWidgetsPos(){

   qreal x,y;
   qreal MidAngle = startAngle + 0.5*spanAngle;
   qreal Rad = qDegreesToRadians(MidAngle);
   y  = - 60*qSin(Rad);
   x  = 60*qCos(Rad);
   ZoneNum->move(x-(ZoneNum->width()/2),y-(ZoneNum->height()/2));

}
//    ________________________________________________________
void Sprinkler::setDotPos(){
    PointGrabSt->setPos(startP);
    PointGrabEnd->setPos(endP);
}

QPointF Sprinkler::getMidP()
{
    QPointF middlePoint;
    qreal x,y;
    qreal MidAngle = startAngle + 0.5*spanAngle;
    qreal Rad = qDegreesToRadians(MidAngle);
    y  = - Radius*qSin(Rad);
    x  = Radius*qCos(Rad);
    middlePoint = QPointF(x,y);
    return middlePoint;

}

DotGrabber *Sprinkler::getPointGrabSt()
{
    return PointGrabSt;
}

DotGrabber *Sprinkler::getPointGrabEnd()
{
    return PointGrabEnd;
}

void Sprinkler::setPointGrabSt(DotGrabber *st)
{
    PointGrabSt = st;
}

void Sprinkler::setPointGrabEnd(DotGrabber *end)
{
    PointGrabEnd = end;
}
//    ________________________________________________________
//void Sprinkler::setStartLine(QPointF arc){

//    ________________________________________________________
void Sprinkler::setPreviousPosition(QPointF position){
    m_previousPosition = position;
}
//    ________________________________________________________
QPointF Sprinkler::previousPosition(){
    return m_previousPosition;
}
//    ________________________________________________________
QRectF Sprinkler::boundingRect() const{

    return QRectF(center.x()- Radius,center.y()- Radius,2*Radius,2*Radius);
}
//    ________________________________________________________
void Sprinkler::paint(QPainter *painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/){

    setDotPos();   
    QPainterPath path;
    qreal EndTmp;
    switch (BodyType)
    {
        case rotor :
        case spray :
        {
                        if(!FirstClick && !SecondClick && !ThirdClick ){  // && BodyType == sprinklerType::rotor
                        //qDebug()<< "in pain Circle";
                            // draw ghost
                            painter->setPen(pen);
                            path.addEllipse(center.x() - Radius,center.y() - Radius,2*Radius,2*Radius);
                            formOfSector = path;
                            painter->drawPath(path);
                            qDebug() << "move to 1 painter sprinkler";                            
                        }
                        else if (FirstClick && !SecondClick && !ThirdClick )  // && BodyType == sprinklerType::rotor
                        {   //qDebug() << "move to 2 painter sprinkler";
                            path.clear();
                            //painter->eraseRect(boundingRect());
                            painter->setPen(pen);
                            painter->setBrush(brsh); // QBrush(QColor(0,100,200,30))
                            path.moveTo(center);
                            QRectF tmp(startP.x()-20,startP.y()-20,40,40);
                            if (tmp.contains(endP) && spanAngle > 90){
                                spanAngle = 360;
                                path.addEllipse(center.x() - Radius,center.y() - Radius,2*Radius,2*Radius);
                                formOfSector = path;
                                painter->drawPath(path);
                                //painter->drawPath(path);
                            }
                            else{
                                path.arcTo(boundingRect(),getStartAngle(startP),getSpanAngle(endP));
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);
                                //painter->drawPath(path);
                            }
                            model->setText(getModel());
                            return;
                        }
                        else if (FirstClick && SecondClick && !ThirdClick ){ // && BodyType == sprinklerType::rotor
                            path.clear();
                            //painter->eraseRect(boundingRect());
                            painter->setPen(pen);
                            painter->setBrush(brsh); // QBrush(QColor(0,100,200,30))
                            path.moveTo(center);
                            QRectF tmp(startP.x()-20,startP.y()-20,40,40);
                            if (tmp.contains(endP) && spanAngle > 90){
                                spanAngle = 360;
                                path.addEllipse(center.x() - Radius,center.y() - Radius,2*Radius,2*Radius);
                                formOfSector = path;
                                painter->drawPath(path);
                                //painter->drawPath(path);
                                SetColor(Radius,360,rotor);
                            }
                            else{
                                path.arcTo(boundingRect(),getStartAngle(startP),getSpanAngle(endP));
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);
                                //painter->drawPath(path);
                                SetColor(Radius,getSpanAngle(endP),rotor);
                            }
                        }
                        else{
                            qDebug() << "move from painter sprinkler-rotor";
                            model->setText(getModel());
                            return;
                        }

                        break;
        }
        case rotator :
        {
                        if(!FirstClick && !SecondClick && !ThirdClick ){  // && BodyType == sprinklerType::rotator
                        //qDebug()<< "in pain Circle";
                            // draw ghost
                            painter->setPen(pen);
                            path.addEllipse(center.x() - Radius,center.y() - Radius,2*Radius,2*Radius);
                            formOfSector = path;
                            painter->drawPath(path);
                            qDebug() << "move to 1 painter sprinkler-rotator";
                        }
                        else if (FirstClick && !SecondClick && !ThirdClick )  // && BodyType == sprinklerType::rotator
                        {   //qDebug() << "move to 2 painter sprinkler";
                            path.clear();
                            //painter->eraseRect(boundingRect());
                            painter->setPen(pen);
                            painter->setBrush(brsh); // QBrush(QColor(0,100,200,30))
                            path.moveTo(center);
                            QRectF tmp(startP.x()-100,startP.y()-100,200,200);
                            if (tmp.contains(endP) && spanAngle > 90){
                                spanAngle = 360;
                                path.addEllipse(center.x() - Radius,center.y() - Radius,2*Radius,2*Radius);
                                formOfSector = path;
                                painter->drawPath(path);
                                //painter->drawPath(path);
                            }
                            else{
                                path.arcTo(boundingRect(),getStartAngle(startP),getSpanAngle(endP));
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);
                               // painter->drawPath(path); // for brigtness
                            }
                            model->setText(getModel());
                            return;
                        }
                        else if (FirstClick && SecondClick && !ThirdClick )
                        { // && BodyType == sprinklerType::rotor
                            //qDebug() << "это должно вылезти один раз";                           
                            EndTmp = getSpanAngle(endP);
                            path.clear();                            
                            painter->setPen(pen);
                            painter->setBrush(brsh); // QBrush(QColor(0,100,200,30))
                            path.moveTo(center);
                            QRectF tmp(startP.x()-100,startP.y()-100,200,200);
                            if ((Radius > 911 && EndTmp > 210) ) // for 3500 rotator
                            {
                                EndTmp = 210;
                                spanAngle = 210;
                                SetColor(Radius,EndTmp,rotator);
                                path.arcTo(boundingRect(),getStartAngle(startP),EndTmp);
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);                                
                                endP = FixedTips(startAngle, Radius, EndTmp);

                            }
                            else if (tmp.contains(endP) && Articul != 6)
                            {
                                spanAngle = 360;
                                path.addEllipse(center.x() - Radius,center.y() - Radius,2*Radius,2*Radius);
                                formOfSector = path;
                                painter->drawPath(path);                                
                                endP = startP;
                            }
                            else if(EndTmp > 270 || (Radius < 300 && EndTmp > 210) )
                            {
                                spanAngle = 360;
                                path.addEllipse(center.x() - Radius,center.y() - Radius,2*Radius,2*Radius);
                                formOfSector = path;
                                painter->drawPath(path);                                
                                endP = startP;
                            }
                            else if (Articul == 2 && EndTmp >= 90)
                            {
                                SetColor(Radius,EndTmp,rotator);
                                path.arcTo(boundingRect(),getStartAngle(startP),EndTmp);
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);
                                endP = FixedTips(startAngle, Radius, EndTmp);
                            }
                            else if (Articul == 2 && EndTmp < 90 )
                            {
                                SetColor(400,180,rotator); // color = QColor(130,20,20,255);
                                EndTmp = 90;
                                spanAngle = 90;
                                path.arcTo(boundingRect(),getStartAngle(startP),EndTmp);
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);

                                endP = FixedTips(startAngle, Radius, EndTmp);
                               //PointGrabEnd->setPos( FixedTips(startAngle, Radius, EndTmp));
                            }
                            else if (Articul == 6 && EndTmp <= 45 )
                            {
                                EndTmp = 45;
                                spanAngle = 45;
                                SetColor(Radius,EndTmp,rotator);
                                path.arcTo(boundingRect(),getStartAngle(startP),EndTmp);
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);

                                endP = FixedTips(startAngle, Radius, EndTmp);
                               //PointGrabEnd->setPos( FixedTips(startAngle, Radius, EndTmp));
                            }
                            else if (Articul == 6 && EndTmp > 45 && EndTmp <= 90)
                            {

                                SetColor(Radius,EndTmp,rotator);
                                path.arcTo(boundingRect(),getStartAngle(startP),EndTmp);
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);
                                endP = FixedTips(startAngle, Radius, EndTmp);
                               //PointGrabEnd->setPos( FixedTips(startAngle, Radius, EndTmp));
                            }
                            else if (Articul == 6 && EndTmp > 90)
                            {
                                EndTmp = 90;
                                spanAngle = 90;
                                SetColor(Radius,EndTmp,rotator);
                                path.arcTo(boundingRect(),getStartAngle(startP),EndTmp);
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);
                                endP = FixedTips(startAngle, Radius, EndTmp);
                               //PointGrabEnd->setPos( FixedTips(startAngle, Radius, EndTmp));
                            }
                            else if ( EndTmp < 90)
                            {
                                EndTmp = 90;
                                spanAngle = 90;
                                SetColor(Radius,EndTmp,rotator);
                                path.arcTo(boundingRect(),getStartAngle(startP),EndTmp);
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);
                                endP = FixedTips(startAngle, Radius, EndTmp);
                               //PointGrabEnd->setPos( FixedTips(startAngle, Radius, EndTmp));
                            }
                            else
                            {
                                SetColor(Radius,EndTmp,rotator);
                                path.arcTo(boundingRect(),getStartAngle(startP),EndTmp);
                                path.lineTo(center);
                                formOfSector = path;
                                painter->drawPath(path);
                                endP = FixedTips(startAngle, Radius, EndTmp);
                               //PointGrabEnd->setPos( FixedTips(startAngle, Radius, EndTmp));
                            }

                            model->setText(getModel());
                        }
                        else
                        {
                            qDebug() << "move from painter sprinkler";
                            model->setText(getModel());
                            return;
                        }
                        break;
        }
    }
}
//    ________________________________________________________
QPainterPath Sprinkler::shape() const
 {
     QPainterPath path;
     path = formOfSector;
    if (!zoningMode)
    {
        strokerS->setWidth(15);
        return strokerS->createStroke(formOfSector);
    }
    else
    {
    strokerS->setWidth(15);
    return strokerS->createStroke(formOfSector);
    }
    //return path;
 }
void Sprinkler::setType(int t){
    switch(t){
        case 0:{ BodyType = sprinklerType::rotor; break; }
        case 1:{ BodyType = sprinklerType::rotator; break;}
        case 2:{ BodyType = sprinklerType::spray; break;}
        default:{break;}
    }

}
//    ________________________________________________________
void Sprinkler::setClick(int num){
    switch(num){
        case 0:{ FirstClick = false;SecondClick = false; ThirdClick = false; break;}
        case 1:{ FirstClick = true; SecondClick = false; ThirdClick = false; break;}
        case 2:{ FirstClick = true; SecondClick = true; ThirdClick = false; break;}
        case 3:{ FirstClick = true; SecondClick = true; ThirdClick = true; break;}
    }
}
//    ________________________________________________________
void Sprinkler::mousePressEvent(QGraphicsSceneMouseEvent *event){

    qDebug()<<"Sprinkler press ";
    QGraphicsItem::mousePressEvent(event);
}
void Sprinkler::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

    QGraphicsItem::mouseMoveEvent(event);
}
void Sprinkler::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

    QGraphicsItem::mouseReleaseEvent(event);
}

void Sprinkler::updatePlease(bool flag)
{
    if (!flag) this->update(center.x() - Radius,center.y() - Radius,2*Radius,2*Radius);
}

qreal Sprinkler::getStartAngle(QPointF startPoint) {
    QLineF helpLine(center,startPoint);
    helpLine.setLength(Radius);
    startP = helpLine.p2();
    startAngle = helpLine.angle();
    return  helpLine.angle();
}
qreal Sprinkler::getExistingStartAngle()
{
   return startAngle;
}
qreal Sprinkler::getSpanAngle(QPointF finishPoint) {
    QLineF helpLine(center,finishPoint);
    helpLine.setLength(Radius);
    endP = helpLine.p2();
    QLineF endLine(center,endP);
    QLineF startline(center,startP);
    spanAngle = startline.angleTo(endLine);
    return startline.angleTo(endLine);
}
qreal Sprinkler::getExistingSpanAngle()
{
    return spanAngle;
}

qreal Sprinkler::getFlow()
{
    switch (BodyType) {
        case (Sprinkler::rotor) : {
            // rotor PGP-Hunter
            if (Articul == 0) {return Flow = 0.61;}
            // rotor Rainbird 5004
            else if (Articul == 100) {return Flow = 0.67;}
            break;
        }
        case (Sprinkler::rotator): {
            // articul 1 mp-800
            if (Articul == 1 && spanAngle >0 && spanAngle < 120) {return Flow = 0.05;}
            else if (Articul == 1 && spanAngle >=120 && spanAngle <=180) {return Flow = 0.1;}
            else if (Articul == 1 && spanAngle >180 && spanAngle <=210) {return Flow = 0.11;}
            else if (Articul == 1 && spanAngle >210 && spanAngle <=360) {return Flow = 0.18;}
             // articul 2 mp-1000
            else if (Articul == 2 && spanAngle >0 && spanAngle <=120) {return Flow = 0.05;}
            else if (Articul == 2 && spanAngle >120 && spanAngle <=180) {return Flow = 0.1;}
            else if (Articul == 2 && spanAngle >180 && spanAngle <=210) {return Flow = 0.11;}
            else if (Articul == 2 && spanAngle >210 && spanAngle <=270) {return Flow = 0.14;}
            else if (Articul == 2 && spanAngle >270 && spanAngle <=360 ) {return Flow = 0.19;}
            // articul 3 mp-2000
            else if (Articul == 3 && spanAngle >0 && spanAngle <=120) {return Flow = 0.1;}
            else if (Articul == 3 && spanAngle >120 && spanAngle <=180) {return Flow = 0.18;}
            else if (Articul == 3 && spanAngle >180 && spanAngle <=210) {return Flow = 0.2;}
            else if (Articul == 3 && spanAngle >210 && spanAngle <=270) {return Flow = 0.25;}
            else if (Articul == 3 && spanAngle >270 && spanAngle <=360 ) {return Flow = 0.34;}
            // articul 4 mp-3000
            else if (Articul == 4 && spanAngle >0 && spanAngle <=120) {return Flow = 0.2;}
            else if (Articul == 4 && spanAngle >120 && spanAngle <=180) {return Flow = 0.42;}
            else if (Articul == 4 && spanAngle >180 && spanAngle <=210) {return Flow = 0.49;}
            else if (Articul == 4 && spanAngle >210 && spanAngle <=270) {return Flow = 0.63;}
            else if (Articul == 4 && spanAngle >270  && spanAngle <=360 ) {return Flow = 0.84;}
             // articul 5 mp-3500
            else if (Articul == 5 && spanAngle >0 && spanAngle <=120) {return Flow = 0.29;}
            else if (Articul == 5 && spanAngle >120 && spanAngle <=180) {return Flow = 0.65;}
            else if (Articul == 5 && spanAngle >180 && spanAngle <=210) {return Flow = 0.75;}
            // articul 6 mp-corner
            else if (Articul == 6 && spanAngle >0 && spanAngle <=45) {return Flow = 0.04;}
            else if (Articul == 6 && spanAngle >45 && spanAngle <=90) {return Flow = 0.09;}
            break;
        }
        case (Sprinkler::strip) : {
            // articul 7 mp-strip L
            if (Articul == 7) {return Flow = 0.05;}
            // articul 8 mp-strip R
            else if (Articul == 8) {return Flow = 0.05;}
            // articul 9 mp-strip M
            else if (Articul == 9) {return Flow = 0.1;}
            break;
        }
        case (Sprinkler::spray) : {
            // articul 101 he-van 8
            if (Articul == 101 && spanAngle >0 && spanAngle <=90) {return Flow = 0.07;}
            else if (Articul == 101 && spanAngle >90 && spanAngle <=180) {return Flow = 0.13;}
            else if (Articul == 101 && spanAngle >180 && spanAngle <=270) {return Flow = 0.2;}
            else if (Articul == 101 && spanAngle >270 && spanAngle <=360) {return Flow = 0.27;}
            // articul 102 he-van 10
            else if (Articul == 102 && spanAngle >0 && spanAngle <=90) {return Flow = 0.1;}
            else if (Articul == 102 && spanAngle >90 && spanAngle <=180) {return Flow = 0.21;}
            else if (Articul == 102 && spanAngle >180 && spanAngle <=270) {return Flow = 0.31;}
            else if (Articul == 102 && spanAngle >270 && spanAngle <=360) {return Flow = 0.41;}
            // articul 103 he-van 12
            else if (Articul == 103 && spanAngle >0 && spanAngle <=90) {return Flow = 0.13;}
            else if (Articul == 103 && spanAngle >90 && spanAngle <=180) {return Flow = 0.27;}
            else if (Articul == 103 && spanAngle >180 && spanAngle <=270) {return Flow = 0.4;}
            else if (Articul == 103 && spanAngle >270 && spanAngle <=360) {return Flow = 0.54;}
            // articul 104 he-van 15
            else if (Articul == 104 && spanAngle >0 && spanAngle <=90) {return Flow = 0.21;}
            else if (Articul == 104 && spanAngle >90 && spanAngle <=180) {return Flow = 0.42;}
            else if (Articul == 104 && spanAngle >180 && spanAngle <=270) {return Flow = 0.63;}
            else if (Articul == 104 && spanAngle >270 && spanAngle <=360) {return Flow = 0.84;}
            break;
        }
        default: return 0;
    }
}

void Sprinkler::RememberBodyTypeInt(int tp)
{
    TypeInt = tp;
}
Sprinkler::sprinklerType Sprinkler::GetBodyType()
{
    return BodyType;
}
QPointF Sprinkler::FixedTips(qreal StAngl, int Radius, int borderAngle)
{
    QPointF FixedPoint;
    qreal x,y;
    double radians;
    qreal AngleInDegrees = StAngl + borderAngle;
    radians = qDegreesToRadians(AngleInDegrees);
    y  = - Radius*qSin(radians);
    x  = Radius*qCos(radians);
    FixedPoint = QPointF(x,y);
    return FixedPoint;
}

void Sprinkler::ShowZoneNumLabel(bool flag)
{
    if (flag)
        ZoneNum->setVisible(true);
    else ZoneNum->setVisible(false);
}

void Sprinkler::setZoneNumLabel(QString Num)
{    
    this->ZoneNum->setText(Num);
    ZoneNumText = Num;    
}


QDataStream & operator<<(QDataStream & out, const Sprinkler &spr)
{
    out<< spr.ZoneNumText;
    out<< spr.formOfSector;
    out<< spr.TypeInt;
    out<< spr.zoningMode;
    out<< spr.pen;
    out<< spr.brsh;
    out<< spr.color;
    out<< spr.startP;
    out<< spr.midP;
    out<< spr.endP;
    out<< spr.center;
    out<< spr.IrriCircle;
    out<< spr.Radius;
    out<< spr.Flow;
    out<< spr.Articul;
    out<< spr.startAngle;
    out<< spr.spanAngle;
    out<< spr.BodyType;   
    out<< spr.FirstClick;
    out<< spr.SecondClick;
    out<< spr.ThirdClick;
    out<< spr.m_previousPosition;


    return out;
}

QDataStream & operator>>(QDataStream & in,  Sprinkler &spr)
{    
    in>> spr.ZoneNumText;
    in>> spr.formOfSector;
    in>> spr.TypeInt;
    in>> spr.zoningMode;
    in>> spr.pen;
    in>> spr.brsh;
    in>> spr.color;
    in>> spr.startP;
    in>> spr.midP;
    in>> spr.endP;
    in>> spr.center;
    in>> spr.IrriCircle;
    in>> spr.Radius;
    in>> spr.Flow;
    in>> spr.Articul;
    in>> spr.startAngle;
    in>> spr.spanAngle;
    in>> spr.BodyType;    
    in>> spr.FirstClick;
    in>> spr.SecondClick;
    in>> spr.ThirdClick;
    in>> spr.m_previousPosition;


    return in;
}
