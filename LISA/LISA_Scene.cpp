#include<QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include"LISA_Scene.h"
#include"LISA_View.h"
#include "ImportedImage.h"
#include "core.h"
#include "Sprinkler.h"
#include"mainwindow.h"
#include "DotGrabber.h"
#include "Pump.h"
#include "pipe.h"
#include "valve.h"
#include "losses.h"

extern QPointF start;
extern QPointF finish;
extern QVector<QGraphicsItem*> ActiveItemBand;
extern QWidget *ActiveWidget;
extern Sprinkler* tmp;


int LISA_Scene::m_currentAction(SelectionType);
int LISA_Scene::m_previousAction(0);
QGraphicsItem* LISA_Scene::currentItem(nullptr);
QGraphicsItem* LISA_Scene::previousItem(nullptr);




LISA_Scene::LISA_Scene(QObject* parent) : QGraphicsScene(parent) {
    m_currentAction = SelectionType ,line = nullptr, FirstClick = false, SecondClick = false; clockwise = false;ImageBlocked = false;
    currentPump = nullptr; currentSprinkler = nullptr; currentGrabber = nullptr; body = nullptr; curPipe = nullptr;
    curValve = nullptr;curLosses = nullptr;// line = nullptr;

}

LISA_Scene::~LISA_Scene(){
    delete currentItem;
}
int LISA_Scene::currentAction()
{
    return m_currentAction;
}
void LISA_Scene::setCurrentAction(const int type)
{
    m_currentAction = type;
}
void LISA_Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    //auto isItem = (itemAt(event->scenePos(),QTransform()));
    //auto typeItem = (itemAt(event->scenePos(),QTransform()))->type();

    qDebug() << "тип на сцене" << this->m_currentAction;
    qDebug() << "кол-во итемов на сцене" << items().size();
    if (event->button() == Qt::LeftButton) {


        if(QApplication::keyboardModifiers() & Qt::ShiftModifier){
            m_previousAction = m_currentAction;
            setCurrentAction(SelectionType);
        }
    }
    switch (m_currentAction) {

        case SelectionType: {

            if(event->button() == Qt::LeftButton && (itemAt(event->scenePos(),QTransform())) && (itemAt(event->scenePos(),QTransform()))->type() == 65539){

                FirstClick = true;
                SecondClick = true;
                currentGrabber = qgraphicsitem_cast<DotGrabber*>(itemAt(event->scenePos(),QTransform()));
                if (qgraphicsitem_cast<Sprinkler*>(currentGrabber->parentItem()))
                {   qDebug() << "переходим на спринклер тайп";
                    currentSprinkler = qgraphicsitem_cast<Sprinkler*>(currentGrabber->parentItem());  // getting parent(sprinkler) from grabber
                    body = qgraphicsitem_cast<Core*>(currentSprinkler->parentItem()); // get body from sprinkler
                    //qDebug() << "центр currenysprinklera" <<  body->getAreal()->GetBodyType();
                    (currentGrabber == body->getAreal()->PointGrabSt)?clockwise = true:clockwise = false;

                    currentSprinkler->setClick(1);
                    m_currentAction = SprinklerType;
                }
                else if((qgraphicsitem_cast<pipe*>(currentGrabber->parentItem())))
                {
                    FirstClick = false;
                    m_currentAction = PipeType;
                    curPipe = qgraphicsitem_cast<pipe*>(currentGrabber->parentItem());
                    qDebug() << "переходим на пайп тайп";


                }
                //break;
            }
            else if (event->button() == Qt::LeftButton && (itemAt(event->scenePos(),QTransform())) &&
                     (itemAt(event->scenePos(),QTransform()))->type() == 65542)
            {
                FirstClick = false;
                SecondClick = true;
                m_currentAction = PipeType;
                curPipe = qgraphicsitem_cast<pipe*>(itemAt(event->scenePos(),QTransform()));
                QVector<DotGrabber*> tmp = curPipe->getPipeGrabbers();
                for(auto i = 0; i < tmp.size(); i++)
                {
                    tmp[i]->setVisible(true);
                    //tmp[i]->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                }
            }
            else if (event->button() == Qt::LeftButton){
                qDebug() << "в сцене левая мышь";
                qDebug() << m_currentAction;
                if(!(QApplication::keyboardModifiers() & Qt::ShiftModifier)){
                    emit newSelection();
                }
                currentItem = LISA_Scene::itemAt(event->scenePos(),QTransform());
                qDebug() << event->scenePos();
                qDebug() << (LISA_Scene::itemAt(event->scenePos(),QTransform()));
                if (currentItem != nullptr) {
                    emit signalSelectItem(currentItem);
                    qDebug() << "hey!!"<<selectedItems().size();
                }
            }            
            if(event->button() == Qt::LeftButton && (itemAt(event->scenePos(),QTransform())) && (itemAt(event->scenePos(),QTransform()))->type() == 65540) {
                emit newSelection(); // reset selection of all selected items before
                if (qgraphicsitem_cast<Core*>(itemAt(event->scenePos(),QTransform())))
                {
                    body = qgraphicsitem_cast<Core*>(itemAt(event->scenePos(),QTransform())); // select core item
                    if(zoningMode) m_currentAction = ZoningType;
                }
                currentSprinkler = body->getAreal();
                currentSprinkler->setCenter(body->centrPos);
                currentSprinkler->setStartEndPos(body->getAreal()->PointGrabSt->pos(),body->getAreal()->PointGrabEnd->pos());
                body->getAreal()->PointGrabSt->setVisible(true);
                body->getAreal()->PointGrabEnd->setVisible(true);
                qDebug() << "тип грабов" <<body->getAreal()->PointGrabSt->type();
                qDebug() << "коорд" << body->getAreal()->PointGrabSt->scenePos();
                //body->getAreal()->PointGrabSt->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                //body->getAreal()->PointGrabEnd->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

                body->getAreal()->PointGrabSt->setBrush(Qt::magenta);
                body->getAreal()->PointGrabEnd->setBrush(Qt::magenta);

               qDebug() << "угол1 " << body->getAreal()->getExistingStartAngle();
               qDebug() << "угол2 " << body->getAreal()->getExistingSpanAngle();
               qDebug() << body->Bodytype();

            }
            QGraphicsScene::mousePressEvent(event);
            break;
        }
        case RulerType: {
            if (event->button() == Qt::LeftButton){
                start_Position = event->scenePos();


                qDebug() << "работает рулетка!"<< start_Position;
                emit coordStart(start_Position);
                emit coordEnd(start_Position);
            }
            QGraphicsScene::mousePressEvent(event);
            break;
        }
        case ScaleType: {
            if(!FirstClick) {
                FirstClick = true;
                start_Position = event->scenePos();
            }
            else {
                if ( this->itemAt(start_Position,QTransform()) && (this->itemAt(start_Position,QTransform())->type() == 6) ){
                    this->removeItem(this->itemAt(start_Position,QTransform()));}
                FirstClick = false;
                SecondClick = false;
                end_Position = event->scenePos();
                //emit coordStart(start_Position);
                //emit coordEnd(end_Position);
                start = start_Position;
                finish = end_Position;
                QLineF line(start_Position,end_Position);

                QGraphicsLineItem* Measure = new QGraphicsLineItem;
                Measure->setLine(line);
                Measure->setPen(QPen(Qt::yellow, 2, Qt::SolidLine));
                Measure->setFlag(QGraphicsItem::ItemIsSelectable,false);
                this->addItem(Measure);
                end_Position = start_Position;
                if(qobject_cast<QLineEdit*>(ActiveWidget)) {ActiveWidget->setDisabled(false); ActiveWidget->setFocus();}

            }
            QGraphicsScene::mousePressEvent(event);
            break;
        }
        case SprinklerType:
        {
                if(!FirstClick){
                    qDebug() << "пришли в первый клик сцены";

                    //cr->setParent(this);
                    //bd->setCentrl(event->scenePos());
                    body->setPos(event->scenePos());
                    //cr->setBodyType(Core:: rotor);
                    //cr->setColorBody(spr->GetColor());
                    //spr->setParentItem(cr);
                    body->mapToScene(event->scenePos());
                    currentSprinkler->setCenter(body->centrPos);
                    //this->addItem(body);
                    currentSprinkler->setClick(0);
                    currentSprinkler->setOpacity(1);
                    //cr->setAreal(spr);
                    //currentItem = spr;
                    //currentSprinkler = spr;
                    FirstClick = true;
                    qDebug() <<"артикул после ареала" << body->getAreal()->Articul;
                    qDebug() <<"startAngle" << body->getAreal()->startAngle;
                    qDebug() <<"spanAngle" << body->getAreal()->spanAngle;
                }
                else if (FirstClick && !SecondClick)
                {
                    //ImportedImage* chosen = qgraphicsitem_cast<ImportedImage*>(workplaceScene->selectedItems().at(i));
                    //if(currentItem = qgraphicsitem_cast<Sprinkler*>(currentItem))
                    qDebug() << "пришли во второй клик сцены";
                    QPointF tmp = currentSprinkler->mapFromScene(event->scenePos());
                    currentSprinkler->getStartAngle(tmp);
                    currentSprinkler->setClick(1);
                    SecondClick = true;                    
                }
                else if (FirstClick && SecondClick && clockwise == true)
                {

                    currentSprinkler->setClick(2);
                    LISA_Scene::setCurrentAction(LISA_Scene::SelectionType);
                    currentSprinkler->setChildWidgetsPos(); // body->centrPos
//                    currentSprinkler->getStartAngle(event->scenePos());
//                   currentSprinkler->setClick(2);
                    qDebug() << "coord centrl point" << currentSprinkler->getMidP();

                    FirstClick = false; SecondClick = false; clockwise = false;
                    currentSprinkler = nullptr;
                    body = nullptr;                   
                }
                else
                {
                    currentSprinkler->setClick(2);                    
                    LISA_Scene::setCurrentAction(LISA_Scene::SelectionType);
                    currentSprinkler->setChildWidgetsPos(); //body->centrPos
//                    currentSprinkler->getStartAngle(event->scenePos());
//                    currentSprinkler->setClick(2);

                    qDebug() << "coord centrl point" << currentSprinkler->mapToScene(currentSprinkler->getMidP());
                    FirstClick = false; SecondClick = false;
                    currentSprinkler = nullptr;
                    body = nullptr;
                    emit transsignal(false);
                    //update();
                }
                if(event->button() == Qt::RightButton)  // delete ghost-sprinkler on right button click
                {
                    if ((this->itemAt(event->scenePos(),QTransform())) &&
                         this->itemAt(event->scenePos(),QTransform())->type() == 65540) {
                        body = qgraphicsitem_cast<Core*>(itemAt(event->scenePos(),QTransform()));
                        body->~Core();
                        m_currentAction = SelectionType;
                        FirstClick = false; SecondClick = false; clockwise = false;
                        currentSprinkler = nullptr;
                        body = nullptr;
                    }
                            //qgraphicsitem_cast<Core*>
                }
                QGraphicsScene::mousePressEvent(event);
                break;
        }
        case PumpType:
        {
                if (currentPump != nullptr) currentPump->setPos(event->scenePos());
                LISA_Scene::setCurrentAction(LISA_Scene::SelectionType);
                QGraphicsScene::mousePressEvent(event);                
                break;
        }
        case PipeType:
        {
            if (event->button() == Qt::LeftButton)
            {
                if (!FirstClick && !SecondClick)
                {
                    qDebug() << "one Time";
                    this->addItem(curPipe);
                    curPipe->setCurPos(event->scenePos());
                    curPipe->setClick(true);
                    FirstClick = true;
                    update();
                }
                else if(FirstClick && !SecondClick)
                {
                    qDebug() << "click to add dot";
                    curPipe->setCurPos(event->scenePos());
                    curPipe->setClick(true);
                }
                else if(FirstClick && SecondClick)
                {
                    qDebug() << "move to vector";

                }
            }
            QGraphicsScene::mousePressEvent(event);
            break;
        }
        case ZoningType:
        {
            if(event->button() == Qt::LeftButton && (itemAt(event->scenePos(),QTransform())) &&
                    (itemAt(event->scenePos(),QTransform()))->type() == 65540) // if type core
            {
                emit newSelection();
                body = qgraphicsitem_cast<Core*>(itemAt(event->scenePos(),QTransform()));
                body->getAreal()->setZoningMode(1);
                body->getCoreFlow();
                emit curCore(body);
                update();
            }
            else
            {
                foreach( QGraphicsItem* _item, items()) {
                    if(qgraphicsitem_cast<Sprinkler*>(_item)) {
                        tmp = qgraphicsitem_cast<Sprinkler*>(_item);
                        tmp->setZoningMode(0);
                        tmp = nullptr;
                    }
                }
                body = nullptr;
                emit curCore(body);
                update();
            }
            QGraphicsScene::mousePressEvent(event);
            break;
        }
        case ValveType:
        {
            if (curValve != nullptr){
                curValve->setPos(event->scenePos());
            }
            LISA_Scene::setCurrentAction(LISA_Scene::SelectionType);
            QGraphicsScene::mousePressEvent(event);
            break;
        }
        case LosType:
        {
           if (curLosses != nullptr) curLosses->setCurPos(event->scenePos());//curLosses->setPos(event->scenePos());
            QGraphicsScene::mousePressEvent(event);
            break;
        }
        default: {
            QGraphicsScene::mousePressEvent(event);
            break;
        }
    }
    if (event->button() == Qt::RightButton){
        qDebug() << "позиция в сцене" << event->scenePos();
        if (currentPump != nullptr) {qDebug() << "позиция в сцене" << currentPump->getWorkingPressure();}


         qDebug() << "начальная позиция circle в сцене" ; //It->pos();
         qDebug() << "начальная позиция body в сцене" ; //It->IrriBody->pos();
        //It->mapToScene(event->scenePos());

        QGraphicsScene::mousePressEvent(event);

    }

}
void LISA_Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if (m_currentAction == LosType)
    {
        if (curLosses != nullptr) {curLosses->setCurPos(event->scenePos()); update();}
       //if(curLosses != nullptr) { curLosses->setPos(event->scenePos()); update(); }
        QGraphicsScene::mouseMoveEvent(event);
    }
    if(m_currentAction == ValveType)
    {
        if(curValve != nullptr) {curValve->setPos(event->scenePos()); update();}

        QGraphicsScene::mouseMoveEvent(event);
    }
    if(m_currentAction == PumpType)
    {   qDebug() << "in pump move";
        if(currentPump) {currentPump->setPos(event->scenePos()); update();}
        QGraphicsScene::mouseMoveEvent(event);
    }
    if(m_currentAction == SprinklerType && SecondClick == false && FirstClick == false){        
        qDebug() << "items quantity on scene" << items().size();
        this->addItem(body);

        body->setPos(event->scenePos());
        currentSprinkler->setClick(0);
        currentSprinkler->setCenter(body->centrPos);
        currentSprinkler->setOpacity(0.7);

    }    
    if(m_currentAction == PipeType && FirstClick && !SecondClick)
    {
        curPipe->setCurPos(event->scenePos());        
        update();
        QGraphicsScene::mouseMoveEvent(event);
    }
    if (event->buttons() == Qt::LeftButton && (itemAt(event->scenePos(),QTransform())) &&
            (itemAt(event->scenePos(),QTransform()))->type() == 65539 &&  m_currentAction == PipeType && SecondClick)
    {
        //DotGrabber* tmpdotgrab = new DotGrabber;
        emit transsignal(true);
        currentGrabber = qgraphicsitem_cast<DotGrabber*>(itemAt(event->scenePos(),QTransform()));
        curPipe = qgraphicsitem_cast<pipe*>(currentGrabber->parentItem());
        curPipe->setCurrentDot(currentGrabber );
        currentGrabber->setPos(event->scenePos());        
        update();

    }
    if (m_currentAction == SprinklerType && SecondClick && FirstClick && clockwise == false){
        //qDebug() << "здесь!";
        QPointF tmp = currentSprinkler->mapFromScene(event->scenePos());
        currentSprinkler->getSpanAngle(tmp);
        currentSprinkler->SetColor(currentSprinkler->GetRadius(),currentSprinkler->getSpanAngle(tmp),currentSprinkler->GetBodyType());
        //currentSprinkler->GetColor();
        body->setColorBody(currentSprinkler->GetColor());
        update();
        qDebug() <<"stream " << body->getCoreFlow();
        QGraphicsScene::mouseMoveEvent(event);
    }
    else if (m_currentAction == SprinklerType && SecondClick && FirstClick && clockwise == true)
    {
        //qDebug() << "и здесь!";
        QPointF tmp = currentSprinkler->mapFromScene(event->scenePos());

        currentSprinkler->getStartAngle(tmp);
        currentSprinkler->getSpanAngle(currentSprinkler->PointGrabEnd->pos());
        currentSprinkler->SetColor(currentSprinkler->GetRadius(),currentSprinkler->getSpanAngle(currentSprinkler->PointGrabEnd->pos()),currentSprinkler->GetBodyType());
        body->setColorBody(currentSprinkler->GetColor());
        update();        
        QGraphicsScene::mouseMoveEvent(event);
    }

    //mouseScCoordY->setNum((position.y()));
    if (event->buttons() == Qt::NoButton && m_currentAction == ScaleType && FirstClick){
        if ( this->itemAt(start_Position,QTransform()) && (this->itemAt(start_Position,QTransform())->type() == 6) ){
            this->removeItem(this->itemAt(start_Position,QTransform()));}

        end_Position = event->scenePos();
        //emit coordEnd(end_Position);
        QLineF line(start_Position,end_Position);
        QGraphicsLineItem* Measure = new QGraphicsLineItem;
        Measure->setLine(line);
        Measure->setPen(QPen(QColorConstants::Svg::magenta, 2, Qt::SolidLine));
        Measure->setFlag(QGraphicsItem::ItemIsSelectable,true);
        this->addItem(Measure);
        QGraphicsScene::mouseMoveEvent(event);

    }

    if (event->buttons() == Qt::LeftButton) {

        switch (m_currentAction) {
            case RulerType: {
            if ( this->itemAt(start_Position,QTransform()) && (this->itemAt(start_Position,QTransform())->type() == 6) ){
                this->removeItem(this->itemAt(start_Position,QTransform()));}
                line = new QGraphicsLineItem(QLineF(start_Position,start_Position));
                line->setZValue(1);
                line->setFlag(QGraphicsItem::ItemIsSelectable,true);
                addItem(line);
                end_Position = event->scenePos();
                emit coordEnd(end_Position);
                QLineF newLine(start_Position, end_Position);                
                line->setLine(newLine);
                QGraphicsScene::mouseMoveEvent(event);
                break;
                }
            case ScaleType: {

                if ( this->itemAt(start_Position,QTransform()) && (this->itemAt(start_Position,QTransform())->type() == 6) ){
                    this->removeItem(this->itemAt(start_Position,QTransform()));}

                end_Position = event->scenePos();
                //emit coordEnd(end_Position);
                QLineF line(start_Position,end_Position);
                QGraphicsLineItem* Measure = new QGraphicsLineItem;
                Measure->setLine(line);
                Measure->setPen(QPen(QColorConstants::Svg::magenta, 2, Qt::SolidLine));
                Measure->setFlag(QGraphicsItem::ItemIsSelectable,true);
                this->addItem(Measure);
                QGraphicsScene::mouseMoveEvent(event);
                break;
            }
            case PipeType :
            {
                //curPipe->setCurPos(event->scenePos());
                QGraphicsScene::mouseMoveEvent(event);
                break;
            }

            default: {
                QGraphicsScene::mouseMoveEvent(event);
                break;
            }
        }
    }
}
void LISA_Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    //emit transsignal(false);
    if (event->button() == Qt::LeftButton) {

        switch (m_currentAction) {
            case RulerType: {
                if (this->itemAt(start_Position,QTransform())&&
                   (this->itemAt(start_Position,QTransform())->type() == 6))
                {
                    this->removeItem(this->itemAt(start_Position,QTransform()));
                }

                qDebug() << "отпустил"<< this->items().size();
                start_Position = event->scenePos();
                end_Position = event->scenePos();
                emit coordStart(start_Position);
                emit coordEnd(end_Position);

                QGraphicsScene::mouseReleaseEvent(event);
                break;
                }
            case SelectionType :
            {
                emit transsignal(false);
                QGraphicsScene::mouseReleaseEvent(event);
                break;
            }
            case PipeType :
            {
                if(!FirstClick && SecondClick)
                {
                   //currentGrabber->setPos(event->scenePos());
                    m_currentAction = SelectionType;


                }
               // m_currentAction = SelectionType;
                QGraphicsScene::mouseReleaseEvent(event);
                break;
            }
            default: {
                QGraphicsScene::mouseReleaseEvent(event);
                break;
            }
        }
    }
}
void LISA_Scene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Delete: {
            emit deleteSelectedItem(selectedItems());
        currentItem = nullptr;
        break;
        }
        case Qt::Key_Escape: {
            emit cancelOperation();
        foreach(QGraphicsItem* _it, selectedItems()){
            _it->setSelected(false);
        }
        break;
        }
    }

}
void LISA_Scene::addsprinkler(int Radius,qreal Flow,int Art,int BdTp){
    LISA_Scene::setCurrentAction(LISA_Scene::SprinklerType);

    Core* cr = new Core();
    Sprinkler* spr = new Sprinkler(Radius,Flow,Art,BdTp,cr);
    spr->RememberBodyTypeInt(BdTp);
    cr->setParent(this);

    qDebug() << spr->GetRadius();
    qDebug() <<"артикул до ареала" <<spr->Articul;
    qDebug() << this->items().size();

    //**************************************

    //cr->setPos(event->scenePos());
    cr->setBodyType(BdTp);
    cr->setColorBody(spr->GetColor());
    //spr->setParentItem(cr);

    cr->setAreal(spr);    
    currentSprinkler = spr;
    body = cr;    
    //FirstClick = true;    
    connect(cr, &Core::coremoving,this,&LISA_Scene::transsignal);
    connect(this, &LISA_Scene::transsignal,spr,&Sprinkler::updatePlease);
    //**************************************
}

void LISA_Scene::addPump(double DC, double VP)
{
    foreach(QGraphicsItem* _item, items())
    {
        if (qgraphicsitem_cast<Pump*>(_item))
        {
            if(currentPump){
                currentPump->setDesignCapacity(DC);
                currentPump->setWorkingPressure(VP);
            }
            setCurrentAction(LISA_Scene::SelectionType);
            return;
        }
    }
    currentPump = new Pump();
    currentPump->setDesignCapacity(DC);
    currentPump->setWorkingPressure(VP);
    setCurrentAction(LISA_Scene::PumpType);    
    this->addItem(currentPump);
    connect(currentPump, &Pump::PumpMove,this,&LISA_Scene::transsignal);
}

void LISA_Scene::addPipe(int Diam, int Role, QColor Col)
{
    LISA_Scene::setCurrentAction(LISA_Scene::PipeType);
    curPipe = new pipe();
    curPipe->setDiameter(Diam);
    curPipe->setRole(Role);
    curPipe->setColor(Col);

    FirstClick = false;
    SecondClick = false;
    qDebug() << "pipe params: " << Diam << Role << Col;
    connect(curPipe,&pipe::finishDrawing,this,&LISA_Scene::pipeDrawingFinish);
    connect(this, &LISA_Scene::sceneRectChanged,curPipe,&pipe::rectScene);
}

void LISA_Scene::addValve(int zone, QString Model)
{
    LISA_Scene::setCurrentAction(LISA_Scene::ValveType);
    curValve = new valve();
    curValve->setZoneNum(zone);
    curValve->setValveZoneNum(QString::number(zone));

    curValve->setModel(Model);
    foreach(QGraphicsItem* _item , items())
    {
        if(qgraphicsitem_cast<valve*>(_item) && qgraphicsitem_cast<valve*>(_item)->getZoneNum() == zone)
        {
            emit NewLLos(0);
            emit NewMLos(0);
            qgraphicsitem_cast<valve*>(_item)->deleteLater();
            break;
        }

    }
    this->addItem(curValve);
    connect(curValve, &valve::ValveMove,this, &LISA_Scene::transsignal);
    connect(curValve, &valve::newLLosses,this, &LISA_Scene::NewLLos);
    connect(curValve, &valve::newMLosses,this, &LISA_Scene::NewMLos);
    connect(curValve, &valve::newResult,this, &LISA_Scene::ResLos);
    connect(curValve, &valve::deleteLos,this,&LISA_Scene::RemoveLos);

}

void LISA_Scene::addLosses(int zone, int role, int diam)
{
    LISA_Scene::setCurrentAction(LISA_Scene::LosType);
    curLosses = new losses;
    curLosses->setRole(role);
    qDebug() << "role" << role;
    qDebug() << "diam" << diam;
    curLosses->setDiam(diam);
    curLosses->LsrectScene(this->sceneRect());
    bool condition = false;

    foreach(QGraphicsItem* _item, items())
    {
     if(qgraphicsitem_cast<valve*>(_item) && qgraphicsitem_cast<valve*>(_item)->getZoneNum() == zone)
     {
         condition = true;
         this->addItem(curLosses);

         curLosses->setStartPos((qgraphicsitem_cast<valve*>(_item)->scenePos()));
         curValve = qgraphicsitem_cast<valve*>(_item);
         break;
     }
    }
    if(condition == false)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Notification");
        msgBox.setText("Zone " + QString::number(zone) + " does not contain a valve");
        msgBox.exec();
        return;
    }
    connect(curLosses,&losses::CalcLos,curValve,&valve::receveLosses);
    connect(curLosses,&losses::EDrawingLos,this,&LISA_Scene::endDrawingLos);
    connect(this, &LISA_Scene::sceneRectChanged,curLosses,&losses::LsrectScene);

}

void LISA_Scene::pipeDrawingFinish(qreal pipeLength)
{
    FirstClick = false;
    SecondClick = false;
    setCurrentAction(SelectionType);
    qDebug() << "pipe length: " << pipeLength;
}

void LISA_Scene::endDrawingLos()
{
    setCurrentAction(SelectionType);
    //RemoveLos();

}

void LISA_Scene::findValveInfo(int zone)
{
    bool flag = false;
    foreach(QGraphicsItem* _item, items())
    {
        if(qgraphicsitem_cast<valve*>(_item) && qgraphicsitem_cast<valve*>(_item)->getZoneNum() == zone)
        {
            curValve = qgraphicsitem_cast<valve*>(_item);
            emit NewLLos(curValve->getLLosses());
            emit NewMLos(curValve->getMLosses());
            if (currentPump) emit ResLos(currentPump->getWorkingPressure() - (curValve->getLLosses() + curValve->getMLosses()));
            else emit ResLos(0 - (curValve->getLLosses() + curValve->getMLosses()));
            flag = true;
            curValve = nullptr;
        }

    }
    if(flag == false)
    {
        emit NewLLos(0);
        emit NewMLos(0);
        if (currentPump) emit ResLos(currentPump->getWorkingPressure());
        else emit ResLos(0);
    }
}

void LISA_Scene::SetZoningMode(bool flag)
{
    if (flag )zoningMode = true;
    else zoningMode = false;
}

void LISA_Scene::CurValveIsNull()
{
    curValve = nullptr;
}

void LISA_Scene::RemoveLos()
{
    foreach(QGraphicsItem* _item,items()){
        if(qgraphicsitem_cast<losses*>(_item)) this->removeItem( qgraphicsitem_cast<losses*>(_item));
    }
}
