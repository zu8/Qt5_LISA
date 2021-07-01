#include <QLabel>
#include <Qt>
#include <QToolTip>
#include <QDataStream>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LISA_Scene.h"
#include "ImportedImage.h"
#include "Sprinkler.h"
#include "PumpWgt.h"
#include "PipeWgt.h"
#include "ZoningWgt.h"
#include "Zoning.h"
#include "DotGrabber.h"
#include "ruler.h"
#include "SprinklerWgt.h"
#include "core.h"
#include "Pump.h"
#include "pipe.h"
#include "ValveWgt.h"
#include "valve.h"
#include "losses.h"

QPointF start(0,0);
QPointF finish(0,0);
QVector<QGraphicsItem*> ActiveItemBand;
QWidget *ActiveWidget(nullptr);
Sprinkler *tmp;
DotGrabber* Dottmp;
Core* CoreTmp;
pipe* PipeTmp;
Pump* PumpTmp;
valve* ValveTmp;

//QLabel* mouseScCoordX(0);
//QLabel* mouseScCoordY(0);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    workplaceScene = new LISA_Scene(this);
    ui->graphicsView->setScene(workplaceScene);
    setWindowTitle("Landscape Irrigation System Application");
    setWindowIcon(QIcon(":/image/res/favicon.ico"));
    Ruler *rul = new Ruler(this);
    rul->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    SprList = new SprinklerWgt;
    SprList->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    SprList->setGeometry(rect().width(),100,300,300);
    SprList->hide();

    PumpWg = new PumpWgt;
    PumpWg->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    PumpWg->setGeometry(rect().width(),100,300,150);
    PumpWg->hide();
    PipeTool = new PipeWgt;
    PipeTool->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    PipeTool->setGeometry(rect().width(),100,300,215);
    PipeTool->hide();
    ZoningData = new Zoning(this);
    ZoningTool = new ZoningWgt;
    ZoningTool->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    ZoningTool->setGeometry(rect().width(),100,300,350);
    ZoningTool->hide();
    ValveTool = new ValveWgt;
    ValveTool->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    ValveTool->setGeometry(rect().width(),100,300,700);
    ValveTool->hide();

    QLabel* StatusMouse = new QLabel(this);
    ui->statusbar->addWidget(StatusMouse);
    StatusMouse->show();

    connect(workplaceScene, &LISA_Scene::signalSelectItem,this, &MainWindow::selectItem);
    connect(workplaceScene, &LISA_Scene::newSelection,this,&MainWindow::deselectAll);
    connect(workplaceScene, &LISA_Scene::deleteSelectedItem,this,&MainWindow::deleteItems);
    connect(ui->graphicsView, &LISA_View::selectionRectSquare,this, &MainWindow::rememberSelected);
    connect(ui->graphicsView, &LISA_View::rulerIsSituated,rul,&Ruler::ChangePosition);
    connect(ui->graphicsView, &LISA_View::rulerDisappear,rul,&Ruler::ShowRuler);
    connect(workplaceScene, &LISA_Scene::coordStart,rul,&Ruler::MeasureStart);
    connect(workplaceScene, &LISA_Scene::coordEnd,rul,&Ruler::MeasureEnd);
    connect(this, &MainWindow::ToolRulerIsOn,ui->graphicsView, &LISA_View::rulerToolOn);
    connect(ui->graphicsView, &LISA_View::mousePos,this,&MainWindow::getMousePosition);
    connect(workplaceScene,&LISA_Scene::cancelOperation,this,&MainWindow::quitTool);
    connect(SprList,&SprinklerWgt::newSprinkler,workplaceScene,&LISA_Scene::addsprinkler);
    connect(workplaceScene,&LISA_Scene::transsignal,ui->graphicsView,&LISA_View::NoNeedSelectionRect);
    connect(PumpWg ,&PumpWgt::newPump,workplaceScene,&LISA_Scene::addPump);    
    connect(PipeTool ,&PipeWgt::newPipe,workplaceScene,&LISA_Scene::addPipe);
    connect(PipeTool ,&PipeWgt::pipeToolClose,this,&MainWindow::ClosingPipeToolScript);
    connect(ZoningTool,&ZoningWgt::zoningToolClosed, this, &MainWindow::ClosingZoningToolScript);
    connect(ValveTool,&ValveWgt::ValveToolClosed, this, &MainWindow::ClosingValveToolScript);
    connect(SprList, &SprinklerWgt::sprinklerToolClosed,this,&MainWindow::ClosingSprListToolScript);
    connect(PumpWg,&PumpWgt::newPump,ZoningTool,&ZoningWgt::setRecommendFlow);
    connect(PumpWg,&PumpWgt::newPump,ZoningData,&Zoning::UserFlow);
    connect(ZoningData,&Zoning::coreChange,ZoningTool,&ZoningWgt::insertText);
    connect(ZoningData,&Zoning::textChanged,ZoningTool,&ZoningWgt::clear);
    connect(ZoningTool,&ZoningWgt::AddBtn_Clicked,ZoningData,&Zoning::AddFlowSprinkler);
    connect(ZoningTool,&ZoningWgt::RemoveBtn_Clicked,ZoningData,&Zoning::RemoveFlowSprinkler);
    connect(workplaceScene, &LISA_Scene::curCore,ZoningData,&Zoning::SelectedBody);
    connect(ZoningData,&Zoning::newFlowValue,ZoningTool,&ZoningWgt::SetNewFlowValue);
    connect(ZoningTool,&ZoningWgt::flowUpdated,this,&MainWindow::ZoningModeActive);
    connect(ZoningTool,&ZoningWgt::ZoneChanged,ZoningData,&Zoning::changeZnumber);
    connect(ValveTool, &ValveWgt::newValve,workplaceScene,&LISA_Scene::addValve);
    connect(ValveTool, &ValveWgt::selectedDiam,workplaceScene,&LISA_Scene::addLosses);
    connect(workplaceScene,&LISA_Scene::NewMLos,ValveTool,&ValveWgt::SetNewMLooseValue);
    connect(workplaceScene,&LISA_Scene::NewLLos,ValveTool,&ValveWgt::SetNewLLooseValue);
    connect(workplaceScene,&LISA_Scene::ResLos,ValveTool,&ValveWgt::SetResultPressValue);
    connect(ValveTool, &ValveWgt::ValveZoneChanged,workplaceScene,&LISA_Scene::findValveInfo);
    connect(PumpWg,&PumpWgt::NewPressure,ValveTool,&ValveWgt::SetPumpPressure);
    connect(this,&MainWindow::ZoningMode,workplaceScene,&LISA_Scene::SetZoningMode);
    connect(this,&MainWindow::ValveToolClose,workplaceScene,&LISA_Scene::CurValveIsNull);

}
//    ________________________________________________________

//    ________________________________________________________
MainWindow::~MainWindow()
{
    delete ui;
    delete workplaceScene;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    SprList->~SprinklerWgt();
    PumpWg->~PumpWgt();
    PipeTool->~PipeWgt();
    ZoningTool->~ZoningWgt();
    ValveTool ->~ValveWgt();
    QMainWindow::closeEvent(event);
}

void MainWindow::ClosingSprListToolScript()
{
    ui->actionSprinkler->setChecked(false);
}

void MainWindow::ClosingZoningToolScript()
{
    ui->actionZoning->setChecked(false);
}

void MainWindow::ClosingPipeToolScript()
{
    ui->actionPipe->setChecked(false);
    workplaceScene->setCurrentAction(LISA_Scene::SelectionType);
    //PipeTool->hide();
    //emit BlockMoving(false);
}

void MainWindow::ClosingValveToolScript()
{
    ui->actionValve->setChecked(false);
}
//________________________________________________________
void MainWindow::quitTool(){
    emit ToolScalingIsOn(false);
    emit ToolRulerIsOn(false);
    ui->actionRuler->setChecked(false);
}
void MainWindow::getMousePosition(QPointF MP) {
    statusBar()->showMessage("x: " + QString::number(MP.x()) + " " + ":" + " " + "y: "+ QString::number(MP.y()));
}
void MainWindow::addToSelected(QGraphicsItem * itm){
    Q_UNUSED(itm);
}
//    ________________________________________________________
void MainWindow::removeFromSelected(QGraphicsItem * itm){
    for(auto i(0); i < workplaceScene->selectedItems().size() ; i++){ // SelectedItems.size()
        if (workplaceScene->selectedItems().at(i) == itm) {
            itm->setSelected(false);

            break;
        }
    }
}
//    ________________________________________________________
//void MainWindow::removeAllSelected(){


//    //SelectedItems.clear();
//}
//    ________________________________________________________
void MainWindow::deleteItems(QList<QGraphicsItem *> itemlist){

    for (int i = 0; i < workplaceScene->selectedItems().size(); i++ ){  //SelectedItems.size()
        workplaceScene->selectedItems().at(i)->~QGraphicsItem();
        workplaceScene->items().clear();
        i--;
            qDebug() <<"SelectedItems.size after delete: " << workplaceScene->selectedItems().size();  // SelectedItems.size();
            qDebug() << "itemlistSiZE: " << itemlist.size();
            qDebug() << "SceneitemSiZE: " << workplaceScene->items().size();
        //}
    }
}
//    ________________________________________________________
void MainWindow::deselectAll(){

    for(int i = 0; i < workplaceScene->selectedItems().size();i++){
        workplaceScene->selectedItems().at(i)->setSelected(false);
    }

    foreach( QGraphicsItem* _item, workplaceScene->items()) {
        if(qgraphicsitem_cast<Sprinkler*>(_item)) {
            tmp = qgraphicsitem_cast<Sprinkler*>(_item);
            tmp->setFlag(QGraphicsItem::ItemIsSelectable,false);
//            tmp->PointGrabSt->setBrush(Qt::black);
//            tmp->PointGrabEnd->setBrush(Qt::black);
            tmp->PointGrabSt->setVisible(false);
            tmp->PointGrabEnd->setVisible(false);
            tmp->setZoningMode(0);
            tmp = nullptr;
        }
        else if(qgraphicsitem_cast<DotGrabber*>(_item)) {
            Dottmp = qgraphicsitem_cast<DotGrabber*>(_item);
            Dottmp->setVisible(false);
            Dottmp = nullptr;
        }
    }
}
//    ________________________________________________________
void MainWindow:: rememberSelected(QRectF area){
//    foreach (QGraphicsItemGroup * _item, workplaceScene->){
//        if ( area.intersects(_item->mapRectToScene(_item->boundingRect())) ) {
//            workplaceScene->destroyItemGroup(_item);
//            //SelectedItems.push_back(_item);
//            _item->setSelected(true);

//        }
//    }

    foreach (QGraphicsItem * _item, workplaceScene->items()){
        if ( area.intersects(_item->mapRectToScene(_item->boundingRect())) ) {
            //SelectedItems.push_back(_item);
            _item->setSelected(true);

        }
    }



}
//    ________________________________________________________
void MainWindow::selectItem(QGraphicsItem *item)
{   qDebug() << "in selectitem";
    switch (item->type()) {
    case ImportedImage::Type: {

        if (workplaceScene->selectedItems().contains(item)) { // SelectedItems
            MainWindow::removeFromSelected(item);
            //qDebug() << item->isSelected();
            //qDebug() << SelectedItems.size();
            break;
        }
        item->setSelected(true);
        MainWindow::addToSelected(item);
        //qDebug() << item->isSelected();
       // qDebug() << SelectedItems.size();
        break;
    }
    case Sprinkler::Type: {

        if (workplaceScene->selectedItems().contains(item)) { // SelectedItems
            MainWindow::removeFromSelected(item);
            //qDebug() << item->isSelected();
            //qDebug() << SelectedItems.size();
            break;
        }
        item->setSelected(true);
        MainWindow::addToSelected(item);
        //qDebug() << item->isSelected();
       // qDebug() << SelectedItems.size();
        break;
    }
    case DotGrabber::Type: {
        if (workplaceScene->selectedItems().contains(item)) { // SelectedItems
            MainWindow::removeFromSelected(item);
            //qDebug() << item->isSelected();
            //qDebug() << SelectedItems.size();
            break;
        }
        item->setSelected(true);
        MainWindow::addToSelected(item);
        //qDebug() << item->isSelected();
       // qDebug() << SelectedItems.size();
        break;
    }
    case Core::Type:{

        break;
    }
    default:
        qDebug() << "oops";
        break;
    }
}
//    ________________________________________________________
void MainWindow::scalingImageTool(){
    QLineF* scaleline = new QLineF(start, finish);
    qreal ScLength = scaleline->length()*10;
    qreal dimentionForScaling;
    dimentionForScaling = qobject_cast<QLineEdit*>(ActiveWidget)->text().toDouble();
    //qDebug() << "размер"<< dimentionForScaling;
    QGraphicsPixmapItem * Patient = qgraphicsitem_cast<ImportedImage*>(workplaceScene->selectedItems().at(0)); // SelectedItems
    if (dimentionForScaling)
    {
        Patient->setScale(dimentionForScaling/ScLength);
        qgraphicsitem_cast<ImportedImage*>(Patient)->setScValue(dimentionForScaling/ScLength);
    }
    ActiveWidget->~QWidget();
    workplaceScene->removeItem(workplaceScene->itemAt(start,QTransform()));
    LISA_Scene::setCurrentAction(LISA_Scene::SelectionType);
    emit ToolScalingIsOn(false);
    emit BlockMoving(false);

}
//    ________________________________________________________
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
//    ________________________________________________________
void MainWindow::on_actionImport_Image_triggered()
{
    ui->actionRuler->setChecked(false);
    auto path = QFileDialog::getOpenFileName(
            this, "Open Dialog", "", "*.png *.jpg *.bmp *.JPG");
      if (path.isEmpty())
        return;
      QPixmap MyImage(path);
      ImportedImage* img = new ImportedImage;
      img->setImportedImage(MyImage);
      if( workplaceScene->ImageBlocked == false) img->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
      img->setZValue(-1);
      workplaceScene->addItem(img);
      ActiveItemBand.push_back(img);
      ui->graphicsView->fitInView(img->boundingRect(),Qt::AspectRatioMode::KeepAspectRatio);
      connect(img,&ImportedImage::ImgClicked,ui->graphicsView,&LISA_View::NoNeedSelectionRect);
      connect(this,&MainWindow::BlockMoving,img,&ImportedImage::ImageIsBlocked);
      emit ToolRulerIsOn(false);
}

//    ________________________________________________________
void MainWindow::on_actionRuler_toggled(bool flag)
{
    if (flag) {
        ui->actionSprinkler->setChecked(false);
        ui->actionPipe->setChecked(false);
        ui->actionZoning->setChecked(false);
        emit ToolRulerIsOn(true);
        LISA_Scene::setCurrentAction(LISA_Scene::RulerType);
        emit BlockMoving(true);
        foreach( QGraphicsItem* _item , workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item)){
                _item = qgraphicsitem_cast<ImportedImage*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,false);
            }
        }
    }
    else { emit ToolRulerIsOn(false);
        LISA_Scene::setCurrentAction(LISA_Scene::SelectionType);
        if( workplaceScene->ImageBlocked == false) emit BlockMoving(false);
        foreach( QGraphicsItem* _item , workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item) && workplaceScene->ImageBlocked == false){
                _item = qgraphicsitem_cast<ImportedImage*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,true);
            }
        }
    };
}
//    ________________________________________________________
void MainWindow::on_actionScale_Image_triggered()
{
    ui->actionRuler->setChecked(false);
    if (workplaceScene->selectedItems().size() == 0){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Notification");
        msgBox.setText("For scaling you need to choose an image");
        msgBox.exec();
        return;
    }
    for (int i(0); i < workplaceScene->selectedItems().size(); i++){
        if(qgraphicsitem_cast<ImportedImage*>(workplaceScene->selectedItems().at(i))){
            ImportedImage* chosen = qgraphicsitem_cast<ImportedImage*>(workplaceScene->selectedItems().at(i)); // SelectedItems[i]
            deselectAll();
            //SelectedItems.push_back(chosen);
            chosen->setSelected(true);
        }
        else{
            QMessageBox msgBox;
            msgBox.setWindowTitle("Notification");
            msgBox.setText("For scaling you need to choose an image");
            msgBox.exec();
            return;
        }
    }
    QLineEdit* dimWin = new QLineEdit("enter dimension",this);
    dimWin->setFont(QFont("Roboto",12,QFont::Medium));
    dimWin->selectAll();
    //dimWin->selectedText();
    ActiveWidget = dimWin;
    dimWin->setGeometry(100,100,200,40);    
    QAction *LineEditAction = dimWin->addAction(QIcon(":/image/res/actions/ok-button2.png"), QLineEdit::TrailingPosition);
    connect(LineEditAction, &QAction::triggered, this, &MainWindow::scalingImageTool);
    dimWin->show();
    dimWin->setDisabled(true);
    //connect(this,&MainWindow::ToolScalingIsOn,workplaceScene,&LISA_Scene::scaleOn);
    connect(this,&MainWindow::ToolScalingIsOn,ui->graphicsView,&LISA_View::scaleToolOn);
    LISA_Scene::setCurrentAction(LISA_Scene::ScaleType);
    emit ToolScalingIsOn(true);
    emit BlockMoving(true);
}
//    ________________________________________________________
void MainWindow::on_actionSprinkler_toggled(bool flag)
{
    if(flag == true){        
        ui->actionRuler->setChecked(false);
        ui->actionPipe->setChecked(false);
        ui->actionZoning->setChecked(false);

        SprList->show();
        emit BlockMoving(true);
        foreach( QGraphicsItem* _item , workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item)){
                _item = qgraphicsitem_cast<ImportedImage*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,false);
            }
        }
        //LISA_Scene::setCurrentAction(LISA_Scene::SprinklerType);
    }
    else{
        SprList->hide();

        if( workplaceScene->ImageBlocked == false) emit BlockMoving(false);
        foreach( QGraphicsItem* _item , workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item) && workplaceScene->ImageBlocked == false){
                _item = qgraphicsitem_cast<ImportedImage*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,true);
            }
        }
        LISA_Scene::setCurrentAction(LISA_Scene::SelectionType);
    }
}

void MainWindow::ZoningModeActive()
{
    LISA_Scene::setCurrentAction(LISA_Scene::ZoningType);
}

void MainWindow::on_actionPump_triggered()
{
    PumpWg->show();
}
//ooopss
//void MainWindow::on_actionPipe_triggered()
//{
//}
//
void MainWindow::on_actionPipe_toggled(bool flag)
{
   if(flag == true)
   {
       ui->actionRuler->setChecked(false);
       ui->actionSprinkler->setChecked(false);
       ui->actionZoning->setChecked(false);
       PipeTool->show();
       emit BlockMoving(true);
       ui->graphicsView->NoNeedSelectionRect(true);
       foreach( QGraphicsItem* _item , workplaceScene->items()){
           if(qgraphicsitem_cast<ImportedImage*>(_item)){
               _item = qgraphicsitem_cast<ImportedImage*>(_item);
               _item->setFlag(QGraphicsItem::ItemIsSelectable,false);
           }
       }
       foreach( QGraphicsItem* _item , workplaceScene->items()){
           if(qgraphicsitem_cast<Sprinkler*>(_item)){
               _item = qgraphicsitem_cast<Sprinkler*>(_item);
               _item->setFlag(QGraphicsItem::ItemIsSelectable,false);
               _item->setOpacity(0.02);
           }
       }
   }
   else
   {
       workplaceScene->setCurrentAction(LISA_Scene::SelectionType);
       PipeTool->hide();
       if( workplaceScene->ImageBlocked == false) emit BlockMoving(false);
       ui->graphicsView->NoNeedSelectionRect(false);
       foreach( QGraphicsItem* _item , workplaceScene->items()){
           if(qgraphicsitem_cast<ImportedImage*>(_item) && workplaceScene->ImageBlocked == false){
               _item = qgraphicsitem_cast<ImportedImage*>(_item);
               _item->setFlag(QGraphicsItem::ItemIsSelectable,true);
           }
       }
       foreach( QGraphicsItem* _item , workplaceScene->items()){
           if(qgraphicsitem_cast<Sprinkler*>(_item)){
               _item = qgraphicsitem_cast<Sprinkler*>(_item);
               _item->setFlag(QGraphicsItem::ItemIsSelectable,true);
               _item->setOpacity(1);
           }
       }
   }
}

void MainWindow::on_actionZoning_toggled(bool flag)
{
    if(flag)
    {
        ui->actionRuler->setChecked(false);
        ui->actionSprinkler->setChecked(false);
        ui->actionPipe->setChecked(false);
        ZoningTool->show();
        ZoningTool->ZoneChanged(1);
        ZoningTool->SetNewFlowValue((ZoningData->getAreaZones())[1]);
        workplaceScene->setCurrentAction(LISA_Scene::ZoningType);
        emit ZoningMode(true);
        emit BlockMoving(true);
        foreach( QGraphicsItem* _item , workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item)){
                _item = qgraphicsitem_cast<ImportedImage*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,false);
            }
        }
    }

    else
    {
        emit ZoningMode(false);
        ZoningTool->hide();
        workplaceScene->setCurrentAction(LISA_Scene::SelectionType);
        deselectAll();
        if( workplaceScene->ImageBlocked == false) emit BlockMoving(false);
        foreach( QGraphicsItem* _item , workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item) && workplaceScene->ImageBlocked == false){
                _item = qgraphicsitem_cast<ImportedImage*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,true);
            }
        }
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                            tr("Save LISA-file"), "",
                                            tr("LISA (*.lis);;All Files (*)"));
    if (fileName.isEmpty()) return;
    else
    {
        QFile mfile(fileName);
        if (!mfile.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
            mfile.errorString());
            return;
        }
        QDataStream out(&mfile);
        out.setVersion(QDataStream::Qt_4_8);
        int counter(0);
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if(qgraphicsitem_cast<ImportedImage*>(_item)) counter++;
        }
        out << counter;
        foreach(QGraphicsItem* _item, workplaceScene->items()){

          if(qgraphicsitem_cast<ImportedImage*>(_item))
          {
              qgraphicsitem_cast<ImportedImage*>(_item)->setScPos(qgraphicsitem_cast<ImportedImage*>(_item)->scenePos());
              out << *qgraphicsitem_cast<ImportedImage*>(_item);
          }
        }
        counter = 0;
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if(qgraphicsitem_cast<Core*>(_item)) counter++;
        }
        out << counter;
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if(qgraphicsitem_cast<Core*>(_item))
          {              
              // record areal
              tmp = (qgraphicsitem_cast<Core*>(_item)->getAreal());             
              out << *(tmp);
              // remember scene position
              qgraphicsitem_cast<Core*>(_item)->scPos = qgraphicsitem_cast<Core*>(_item)->scenePos();
              // at last write core itself
              out << *qgraphicsitem_cast<Core*>(_item);
          }
        }
        counter = 0;    
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if (qgraphicsitem_cast<pipe*>(_item)) counter++;
        }
        out << counter;
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if (qgraphicsitem_cast<pipe*>(_item))
          {
              qgraphicsitem_cast<pipe*>(_item)->scPos = qgraphicsitem_cast<pipe*>(_item)->scenePos();
              qgraphicsitem_cast<pipe*>(_item)->refreshPoints();
              out << *qgraphicsitem_cast<pipe*>(_item);
          }
        }
        counter = 0;
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if (qgraphicsitem_cast<Pump*>(_item)) counter++;
        }
        out << counter;
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if (qgraphicsitem_cast<Pump*>(_item))
          {
              //qgraphicsitem_cast<Pump*>(_item)->setScPos(qgraphicsitem_cast<Pump*>(_item)->scenePos());
              qgraphicsitem_cast<Pump*>(_item)->scPos = qgraphicsitem_cast<Pump*>(_item)->scenePos();
              out << *qgraphicsitem_cast<Pump*>(_item);
          }
        }
        counter = 0;
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if (qgraphicsitem_cast<valve*>(_item)) counter++;
        }
        out << counter;
        foreach(QGraphicsItem* _item, workplaceScene->items()){
          if (qgraphicsitem_cast<valve*>(_item))
          {
              //qgraphicsitem_cast<Pump*>(_item)->setScPos(qgraphicsitem_cast<Pump*>(_item)->scenePos());
              qgraphicsitem_cast<valve*>(_item)->setPosition( qgraphicsitem_cast<valve*>(_item)->scenePos());

              out << *qgraphicsitem_cast<valve*>(_item);
          }
        }

        out << ZoningData->getAreaZones();

        mfile.flush();
        mfile.close();
    }

}



void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open LISA-file"), "",
             tr("LISA (*.lis);;All Files (*)"));

    if (fileName.isEmpty())
             return;
    else
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
            return;
        }
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_8);

        // очистка существующих айтемов!!!
        foreach(QGraphicsItem* _item, workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item)) {
                workplaceScene->removeItem(_item); (qgraphicsitem_cast<ImportedImage*>(_item))->~ImportedImage();}
            else if (qgraphicsitem_cast<Core*>(_item)) {
                CoreTmp = qgraphicsitem_cast<Core*>(_item);
                workplaceScene->removeItem(_item);
                CoreTmp->deleteLater();
            }
            else if (qgraphicsitem_cast<pipe*>(_item)) {
                PipeTmp = qgraphicsitem_cast<pipe*>(_item);
                workplaceScene->removeItem(_item);
                PipeTmp->deleteLater();
            }
            else if (qgraphicsitem_cast<Pump*>(_item)) {
                PumpTmp = qgraphicsitem_cast<Pump*>(_item);
                workplaceScene->removeItem(_item);
                PumpTmp->deleteLater();
            }
            else if (qgraphicsitem_cast<valve*>(_item)) {
                ValveTmp = qgraphicsitem_cast<valve*>(_item);
                workplaceScene->removeItem(_item);
                ValveTmp->deleteLater();
            }            
        }

        int counter;
        in >> counter;
        for (auto i(0);i < counter;i++) {
            ImportedImage* img = new ImportedImage;
            in >> *img;
            workplaceScene->addItem(img);
            img->setPos(img->getScPos());
            img->setScale(img->getScValue());
        }
        in >> counter;
        for (auto i(0);i < counter;i++) {

            Sprinkler* SprTmp = new Sprinkler;
            in >> *SprTmp;
            Core* CrTmp = new Core;
            in >> *CrTmp;

            SprTmp->ZoneNum->setText(SprTmp->ZoneNumText);
            SprTmp->setOpacity(1);
            SprTmp->ZoneNum->setVisible(true);
            CrTmp->setBodyType(SprTmp->TypeInt);
            CrTmp->setAreal(SprTmp);
            SprTmp->setParentItem(CrTmp);
            CrTmp->setColorBody( SprTmp->GetColor());
            workplaceScene->addItem(CrTmp);
            SprTmp->setCenter(CrTmp->centrPos);
            CrTmp->setPos(CrTmp->scPos);
        }
        in >> counter;
        for (auto i(0);i < counter;i++) {
            pipe* pp = new pipe;
            in >> *pp;
            pp->milestones.clear();
            pp->setColor(pp->P_Color);
            pp->setDiameter(pp->P_Diameter);
            pp->setRole(pp->P_Role);
            pp->currentDot->setPos(pp->DotPoints[0]);
            pp->milestones.push_back(pp->currentDot);
            pp->currentDot->setVisible(false);
            for(auto i(1);i < pp->DotPoints.size(); i++){
                DotGrabber* dot = new DotGrabber(pp);
                dot->setPos(pp->DotPoints[i]);
                pp->milestones.push_back(dot);
                dot->setVisible(false);
            }
            workplaceScene->addItem(pp);
            pp->setPos(pp->scPos);            
        }
        in >> counter;
        for (auto i(0);i < counter;i++) {
            Pump* pmp = new Pump;
            in >> *pmp;
            PumpWg->setDesCapValue(pmp->getDesignCapacity());            
            PumpWg->setPressValue(pmp->getWorkingPressure());
            ValveTool->SetPumpPressure(pmp->getWorkingPressure());
            workplaceScene->addItem(pmp);
            pmp->setPos(pmp->scPos);
            workplaceScene->currentPump = pmp;
        }
        in >> counter;
        for (auto i(0);i < counter;i++) {
            valve* vlv = new valve;
            in >> *vlv;
            workplaceScene->addItem(vlv);
            vlv->setPos(vlv->scPosition);
            vlv->setZoneNum(vlv->zoneNum);
            vlv->setValveZoneNum(QString::number(vlv->zoneNum));
            vlv->setModel(vlv->model);
            connect(vlv, &valve::ValveMove,workplaceScene, &LISA_Scene::transsignal);
            connect(vlv, &valve::newLLosses,workplaceScene, &LISA_Scene::NewLLos);
            connect(vlv, &valve::newMLosses,workplaceScene, &LISA_Scene::NewMLos);
            connect(vlv, &valve::newResult,workplaceScene, &LISA_Scene::ResLos);
            connect(vlv, &valve::deleteLos,workplaceScene,&LISA_Scene::RemoveLos);


        }
        workplaceScene->curValve = nullptr;
        QMap<int,double> map;

        in >> map;
        ZoningData->setAreaZones(map);
        ZoningData->UserFlow(PumpWg->getDesCapValue(),PumpWg->getPressValue());
        if(ZoningData->getCurrentBody()) ZoningData->setCurrentBody(nullptr);
        if(PumpWg->getDesCapValue() > 0.05) ZoningTool->setRecommendFlow(PumpWg->getDesCapValue(),PumpWg->getPressValue());
        else {ZoningTool->setRecommendFlow(0,0);}
        ZoningTool->SetNewFlowValue(map[1]);
        workplaceScene->setCurrentAction(LISA_Scene::SelectionType);


    }
}

void MainWindow::on_actionValve_toggled(bool flag)
{
    if(flag)
    {
        ui->actionRuler->setChecked(false);
        ui->actionSprinkler->setChecked(false);
        ui->actionPipe->setChecked(false);
        ValveTool->show();
        //ValveTool->ZoneChanged(1);
        workplaceScene->setCurrentAction(LISA_Scene::ValveType);        
        emit BlockMoving(true);
        foreach( QGraphicsItem* _item , workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item)){
                _item = qgraphicsitem_cast<ImportedImage*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,false);
            }
            else if(qgraphicsitem_cast<pipe*>(_item)){
                _item = qgraphicsitem_cast<pipe*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,false);
            }
        }
    }

    else
    {
        ValveTool->hide();
        workplaceScene->setCurrentAction(LISA_Scene::SelectionType);
        emit ValveToolClose();
        deselectAll();
        if( workplaceScene->ImageBlocked == false) emit BlockMoving(false);

        foreach( QGraphicsItem* _item , workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item) && workplaceScene->ImageBlocked == false){
                _item = qgraphicsitem_cast<ImportedImage*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,true);
            }
            else if(qgraphicsitem_cast<pipe*>(_item)){
                _item = qgraphicsitem_cast<pipe*>(_item);
                _item->setFlag(QGraphicsItem::ItemIsSelectable,true);
            }
        }
    }
}

void MainWindow::on_actionlock_Image_toggled(bool flag)
{
    if(flag){
        foreach(QGraphicsItem* _item, workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item)){
                qgraphicsitem_cast<ImportedImage*>(_item)->setFlag(QGraphicsItem::ItemIsSelectable,false);
                qgraphicsitem_cast<ImportedImage*>(_item)->setFlag(QGraphicsItem::ItemIsMovable,false);
                workplaceScene->ImageBlocked = true;
            }
        }
    }
    else
    {
        foreach(QGraphicsItem* _item, workplaceScene->items()){
            if(qgraphicsitem_cast<ImportedImage*>(_item))
            {
                qgraphicsitem_cast<ImportedImage*>(_item)->setFlag(QGraphicsItem::ItemIsSelectable,true);
                qgraphicsitem_cast<ImportedImage*>(_item)->setFlag(QGraphicsItem::ItemIsMovable,true);
                workplaceScene->ImageBlocked = false;
            }
        }
    }
}
