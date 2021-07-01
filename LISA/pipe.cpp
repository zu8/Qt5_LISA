#include <QtMath>
#include <QDebug>
#include "pipe.h"


pipe::pipe(QGraphicsPathItem * parent): QObject(),QGraphicsPathItem(parent)
{
    currentDot = new DotGrabber(this);   
    currentDot->setFlag(QGraphicsItem::ItemIsMovable,true);
    rectArea = QRectF (0,0,5000,5000);
    P_Color.setRgb(0,0,0);
    Pipelength = 0;
    stroker = new QPainterPathStroker;
    stroker->setWidth(6);    
    PipeClick = false;
    DragPipe = false;
    endDrawing = false;
    startDrawing = false;
    DropPipe = false;
    curP = startP;
    this->setFlag( QGraphicsItem::ItemIsSelectable,true);
    this->setZValue(0.6);

}

pipe::pipe(const pipe &other)
{
    line = other.line;
    rectArea = other.rectArea;
    startP = other.startP;
    endP = other.endP;
    previousP = other.previousP;
    curP = other.curP;
    milestones = other.milestones;
    currentDot = new DotGrabber(*(other.currentDot));
    currentPath = other.currentPath;
    stroker = new QPainterPathStroker();
    stroker->setWidth(6);
    PipeClick = other.PipeClick;
    startDrawing = other.startDrawing;
    endDrawing = other.endDrawing;
    DragPipe = other.DragPipe;
    DropPipe = other.DropPipe;
    Pipelength = other.Pipelength;
    P_Diameter = other.P_Diameter;
    P_Role = other.P_Role;
    P_Color = other.P_Color;
    this->setFlag( QGraphicsItem::ItemIsSelectable,true);
    this->setZValue(0.6);
}

pipe::~pipe()
{
    deleteLater();
}

QRectF pipe::boundingRect() const
{
    return rectArea;
}

void pipe::paint(QPainter *painter, const QStyleOptionGraphicsItem* /*option*/, QWidget */*widget*/)
{


    if (previousP.isNull() && PipeClick)
    {
        qDebug() << "at start and no more";
        startP = curP;
        currentDot->setPos(curP); // place first dot
        milestones.push_back(currentDot);
        DotPoints.push_back(curP); // save first point
        currentDot->setVisible(false);
        //milestones.push_back(startP); // push point to vector
        previousP = curP; // set previous position
        PipeClick = false; // reset click
        startDrawing = true;
    }
    else if ( (qFabs(milestones[0]->pos().x() - curP.x()) < 20 && qFabs(milestones[0]->pos().y() - curP.y()) < 20 )  && PipeClick && Pipelength< 20)
    {
       deleteLater();
       emit finishDrawing(0);

    }
    else if (  ( qFabs(previousP.x() - curP.x()) < 20 && qFabs(previousP.y() - curP.y()) < 20 ) && PipeClick)
    {

        qDebug() << "here to end it without loop";
        endDrawing = true;
        //startDrawing = false;
        Pipelength = currentPath.length();
        endP = curP;
        PipeClick = false;
        emit finishDrawing(Pipelength);
    }
    else if ( (qFabs(milestones[0]->pos().x() - curP.x()) < 20 && qFabs(milestones[0]->pos().y() - curP.y()) < 20 )  && PipeClick)
    {
        qDebug() << "here to end it with loop";
        endDrawing = true;
        //startDrawing = false;
        endP = startP;
        PipeClick = false;
        emit finishDrawing(Pipelength);
    }
    else if( PipeClick &&   ( qFabs(previousP.x() - curP.x()) > 20 || qFabs(previousP.y() - curP.y()) > 20 ) && !endDrawing ) // Fuzzy compare
    {
        // if not edit mode
        qDebug() << "always";
        currentDot = new DotGrabber(this); // create new dot
        //currentDot->setFlag(QGraphicsItem::ItemIsSelectable,true);
        currentDot->setPos(curP);   // getting position
        milestones.push_back(currentDot);
        DotPoints.push_back(curP);
        currentDot->setVisible(false);
        //milestones.push_back(curP);  // push it to vector
        previousP = curP; // set previous position
        PipeClick = false; // reset click
        qDebug() << "milestones.size() "<< milestones.size();
    }
    else if (PipeClick && endDrawing)  // if edit some point position
    {
        previousP = curP;
        //startDrag();
        PipeClick = false;
        startDrawing = true;
        DragPipe = true;
        DropPipe = false;
    }
    else
    {
        //qDebug() << "nothing";
    }

    if(DropPipe)
    {
        Pipelength = currentPath.length();
        qDebug() <<"CurDotScPos" <<currentDot->scenePos();
        emit finishDrawing(Pipelength);
    }
    if(P_Role == 0 && startDrawing)
    {
        if(!PipeClick)
            {
                if(DragPipe) {
                    qDebug() << "realy?";
                    currentDot->setPos(curP);
                }
                currentPath.clear();
                painter->setPen(QPen(P_Color,5,Qt::SolidLine));
                currentPath.moveTo(milestones[0]->pos());
                for(auto i = 0; i < milestones.size(); i++){
                    currentPath.lineTo(milestones[i]->pos());
                }                
                if(!DragPipe && (!endDrawing || endP == milestones[0]->pos()))
                {
                    currentPath.lineTo(curP);
                    //Pipelength = currentPath.length();
                }
                painter->drawPath(currentPath);
                Pipelength = currentPath.length();
            }
    }
    else if (P_Role == 1 && startDrawing)
    {
        if(!PipeClick)
            {
                if(DragPipe) currentDot->setPos(curP);
                currentPath.clear();
                painter->setPen(QPen(P_Color,8,Qt::DashLine));
                currentPath.moveTo(milestones[0]->pos());
                for(auto i = 0; i < milestones.size(); i++){
                    currentPath.lineTo(milestones[i]->pos());
                }
                if(!DragPipe && (!endDrawing || endP == milestones[0]->pos()) )
                {
                    currentPath.lineTo(curP);
                    //Pipelength = currentPath.length();
                }
                painter->drawPath(currentPath);
                Pipelength = currentPath.length();
            }
    }
}

QPainterPath pipe::shape() const
{
    return stroker->createStroke(currentPath);
}

int pipe::type() const
{
    return Type;
}

void pipe::setCurrentDot(DotGrabber* dot)
{
    currentDot = dot;
}

DotGrabber *pipe::getCurrentDot()
{
    return currentDot;
}
QVector<DotGrabber *> pipe::getPipeGrabbers()
{
    return milestones;
}

QPointF pipe::getDotPos()
{
    return currentDot->pos();
}

void pipe::setClick(bool flag)
{
    PipeClick = flag;
}

void pipe::setDotPos(QPointF pos)
{
    currentDot->setPos(pos);
}

void pipe::setCurPos(QPointF pos)
{
    curP = pos;
}

void pipe::setStartPos(QPointF pos)
{
    startP = pos;
}

qreal pipe::getPipeLength()
{
    return Pipelength;
}

void pipe::setPipeLength(qreal len)
{
    Pipelength += len; //to decrease you should pass negative value
}

void pipe::setDiameter(int Diam)
{
    P_Diameter = Diam;
}

void pipe::setRole(int Role)
{
    P_Role = Role;
}

void pipe::setColor(QColor col)
{
    P_Color = col;
}

void pipe::setDrop(bool flag)
{
    DropPipe = flag;
}

bool pipe::Draging()
{
    return DragPipe;
}

void pipe::refreshPoints()
{
    for(auto i(0); i < milestones.size(); i++){

     DotPoints[i] = milestones.at(i)->scenePos();
    }

}

void pipe::rectScene(QRectF scR)
{
    rectArea = scR;
}


QDataStream& operator<< (QDataStream & out, const  pipe & pp)
{
    out << pp.line;
    out << pp.rectArea;
    out << pp.startP;
    out << pp.endP;
    out << pp.previousP;
    out << pp.curP;
    out << pp.DotPoints;    
    out << pp.currentPath;   
    out << pp.PipeClick;
    out << pp.startDrawing;
    out << pp.endDrawing;
    out << pp.DragPipe;
    out << pp.DropPipe;
    out << pp.Pipelength;
    out << pp.P_Diameter;
    out << pp.P_Role;
    out << pp.P_Color;

    return out;
}

QDataStream& operator>> (QDataStream & in,  pipe & pp)
{
    in >> pp.line;
    in >> pp.rectArea;
    in >> pp.startP;
    in >> pp.endP;
    in >> pp.previousP;
    in >> pp.curP;
    in >> pp.DotPoints;   
    in >> pp.currentPath;   
    in >> pp.PipeClick;
    in >> pp.startDrawing;
    in >> pp.endDrawing;
    in >> pp.DragPipe;
    in >> pp.DropPipe;
    in >> pp.Pipelength;
    in >> pp.P_Diameter;
    in >> pp.P_Role;
    in >> pp.P_Color;

    return in;
}
