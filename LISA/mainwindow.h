#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsItem>
#include <QDebug>
#include <QVector>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QMouseEvent>
#include "LISA_Scene.h"

class LISA_Scene;
class SprinklerWgt;
class PumpWgt;
class PipeWgt;
class ZoningWgt;
class Zoning;
class ValveWgt;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addToSelected(QGraphicsItem * itm);
    void removeFromSelected(QGraphicsItem * itm);
    //void removeAllSelected();
    QLabel* StatusMouse;
    QPointF position;

private:
    Ui::MainWindow *ui;
    LISA_Scene * workplaceScene;
    SprinklerWgt* SprList;
    valve* currentValve;
    PumpWgt* PumpWg;
    PipeWgt* PipeTool;
    ZoningWgt* ZoningTool;
    Zoning* ZoningData;
    ValveWgt* ValveTool;
protected:
     void closeEvent(QCloseEvent *event);
signals:
    void SendSelectedItems(QVector<QGraphicsItem *>);
    void ToolChanged();
    void ToolRulerIsOn(bool);
    void ToolScalingIsOn(bool);
    void BlockMoving(bool);
    void ZoningMode(bool);
    void ValveToolClose();
private slots:
    void ClosingSprListToolScript();
    void ClosingZoningToolScript();
    void ClosingPipeToolScript();
    void ClosingValveToolScript();
    void quitTool();
    void selectItem(QGraphicsItem *item);
    void deselectAll();
    void deleteItems(QList<QGraphicsItem *>);
    void rememberSelected(QRectF);
    void scalingImageTool();
    void on_actionExit_triggered();
    void on_actionImport_Image_triggered();
    void on_actionRuler_toggled(bool arg1);
    void on_actionScale_Image_triggered();
     void getMousePosition(QPointF);
    void on_actionSprinkler_toggled(bool arg1);
    void ZoningModeActive();
    friend class LISA_Scene;
    void on_actionPump_triggered();
    //void on_actionPipe_triggered();
    void on_actionPipe_toggled(bool arg1);
    void on_actionZoning_toggled(bool arg1);
    void on_actionSave_as_triggered();
    void on_actionOpen_triggered();
    void on_actionValve_toggled(bool arg1);
    void on_actionlock_Image_toggled(bool arg1);
};
#endif // MAINWINDOW_H
