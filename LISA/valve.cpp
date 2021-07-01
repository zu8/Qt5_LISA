#include "valve.h"


valve::valve(QGraphicsEllipseItem *parent): QObject(),QGraphicsEllipseItem (parent)
{

    m_previousPosition = QPointF(0,0);
    ValveZoneNumText = "0";
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    this->setFlag(QGraphicsItem::ItemIsMovable,true);
    zoneNum = 0;
    model = "";
    MLosses = 0.00;
    LLosses = 0.00;
    Result = 0.00;
    ValveProxy = new QGraphicsProxyWidget(this);
    ValveZoneNum = new QLabel;
    ValveProxy->setWidget(ValveZoneNum);
    ValveZoneNum->setText(ValveZoneNumText);
    ValveZoneNum->setFont(QFont("Roboto",45,QFont::Medium));
    ValveZoneNum->move(40,-70);
    ValveZoneNum->setVisible(true);
    setZValue(0.95);
}

valve::valve(const valve &other)
{
    Result = other.Result;
    scPosition = other.scPosition;
    m_previousPosition = other.m_previousPosition;
    ValveZoneNumText = other.ValveZoneNumText;
    zoneNum = other.zoneNum;
    model = other.model;
    MLosses = other.MLosses;
    LLosses = other.LLosses;
    ValveForm = other.ValveForm;
    ValveProxy = new QGraphicsProxyWidget(this);
    ValveZoneNum = new QLabel;
    ValveProxy->setWidget(ValveZoneNum);
    ValveZoneNum->setText(ValveZoneNumText);
    ValveZoneNum->setFont(QFont("Roboto",45,QFont::Medium));
    ValveZoneNum->move(40,-70);
    ValveZoneNum->setVisible(true);
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    this->setFlag(QGraphicsItem::ItemIsMovable,true);
    setZValue(0.95);
}

valve::~valve(){deleteLater();}

int valve::getZoneNum()
{
    return zoneNum;
}

void valve::setZoneNum(int Zone)
{
    zoneNum = Zone;
}

double valve::getMLosses()
{
    return MLosses;
}

double valve::getLLosses()
{
    return LLosses;
}

void valve::setMLosses(double losses)
{
    MLosses = losses;
}

void valve::setLLosses(double losses)
{
    LLosses = losses;
}

QString valve::getValveZoneNum()
{
    return ValveZoneNumText;
}

void valve::setValveZoneNum(QString ZNum)
{
    ValveZoneNumText = ZNum;
    ValveZoneNum->setText(ValveZoneNumText);
}

void valve::setPreviousPosition(QPointF pos)
{
    m_previousPosition = pos;
}

void valve::showZoneNumLabel(bool flag)
{
    if(flag) ValveZoneNum->setVisible(true);
    else ValveZoneNum->setVisible(false);
}

void valve::setModel(QString AnyModel)
{
    model = AnyModel;
}

void valve::setPosition(QPointF p)
{
    scPosition = p;
}

void valve::paint(QPainter *painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/)
{
    QPainterPath pp;
    ValveForm.clear();
    painter->rotate(45);
    painter->setBrush(QBrush(QColor(Qt::black)));

    painter->drawEllipse(-30,-30,60,60);
    pp.arcTo(-30,-30,60,60,90,90);
    painter->fillPath(pp,QColor(Qt::white)); //
    pp.moveTo(0,0);
    pp.arcTo(-30,-30,60,60,0,-90);
    painter->fillPath(pp,QColor(Qt::white));
    painter->setBrush(Qt::NoBrush);
    painter->setPen(QPen(Qt::black,2,Qt::SolidLine));
    painter->drawLine(0,-30,0,30);
    painter->drawLine(-30,0,30,0);
    painter->drawEllipse(-30,-30,60,60);
    ValveForm = pp;
}

QRectF valve::boundingRect() const
{
    return QRectF(-40,-40,80,80);
}

QPainterPath valve::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void valve::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "valve";
    if (event->button() & Qt::LeftButton ){
        setPreviousPosition(event->scenePos());
    emit ValveClicked(true);

    }
    QGraphicsItem::mousePressEvent(event);

}

void valve::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    auto dx = event->scenePos().x() - m_previousPosition.x();
    auto dy = event->scenePos().y() - m_previousPosition.y();
    moveBy(dx,dy);
    setPreviousPosition(event->scenePos());
    emit ValveMove(true);

    QGraphicsItem::mouseMoveEvent(event);
}

void valve::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit ValveMove(false);
    QGraphicsItem::mouseReleaseEvent(event);
}

void valve::receveLosses(int role, qreal val)
{
    if (role == 0)
    {
        MLosses = val;
        Result += val;
        emit newMLosses(val);
        emit newResult(Result);
        emit deleteLos();

    }
    else
    {
        LLosses = val;
        Result += val;
        emit newLLosses(val);
        emit newResult(Result);
        emit deleteLos();
    }
}
QDataStream & operator<<(QDataStream & out, const  valve & vl)
{
    out << vl.Result;
    out << vl.scPosition;
    out << vl.m_previousPosition;
    out << vl.ValveZoneNumText;
    out << vl.zoneNum;
    out << vl.model;
    out << vl.MLosses;
    out << vl.LLosses;
    out << vl.ValveForm;
    return out;
}
QDataStream & operator>>(QDataStream & in,  valve & vl)
{
    in >> vl.Result;
    in >> vl.scPosition;
    in >> vl.m_previousPosition;
    in >> vl.ValveZoneNumText;
    in >> vl.zoneNum;
    in >> vl.model;
    in >> vl.MLosses;
    in >> vl.LLosses;
    in >> vl.ValveForm;
    return in;
}
