#ifndef LISA_SCENE_H
#define LISA_SCENE_H
#include<QWidget>
#include<QGraphicsScene>
#include <QMetaType>
#include"LISA_View.h"


class Sprinkler;
class DotGrabber;
class Core;
class Pump;
class pipe;
class valve;
class losses;
//class ImportedImage;

class LISA_Scene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit LISA_Scene (QObject* parent = 0);
    ~LISA_Scene();
    enum ActionTypes {
         DefaultType,
         SelectionType,
         RulerType,
         ScaleType,
         SprinklerType,
         PumpType,
         PipeType,
         ZoningType,
         ValveType,
         LosType
    };
private:

    static int m_currentAction;
    static int m_previousAction;
    static QGraphicsItem *currentItem;
    static QGraphicsItem *previousItem;
    QPointF curPos;
    QPointF start_Position;
    QPointF end_Position;
    QGraphicsLineItem* line;
    Sprinkler* currentSprinkler;
    Pump* currentPump;
    DotGrabber* currentGrabber;
    Core* body;
    pipe* curPipe;
    valve* curValve;
    losses* curLosses;
    bool FirstClick;
    bool SecondClick;
    bool clockwise;
    bool zoningMode;
    bool ImageBlocked;
    static int currentAction();
    static void setCurrentAction(const int type);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    //void mousePos(QPointF);
    void curCore(Core* cr);
    void signalSelectItem(QGraphicsItem *item);
    void transsignal(bool);
    void newSelection();
    void deleteSelectedItem(QList<QGraphicsItem*>);
    void cancelOperation();
    void coordStart(QPointF);
    void coordEnd(QPointF);
    void NewMLos(qreal los);
    void NewLLos(qreal los);
    void ResLos(qreal los);
    //void scValveMove(bool flag);
public slots:
  //  void slotMove(QGraphicsItem *signalOwner, qreal dx, qreal dy);
    void addsprinkler(int Radius,qreal Flow,int Art,int BodyType);
    void addPump(double DC, double VP);
    void addPipe(int Diam,int Role, QColor Col);
    void addValve(int zone,QString Model);
    void addLosses(int zone,int role,int diam);
    void pipeDrawingFinish(qreal Pipelength);
    void endDrawingLos();
    void findValveInfo(int zone);
    void SetZoningMode(bool);
    void CurValveIsNull();
    void RemoveLos();
    friend class LISA_View;
    friend class MainWindow;
    friend class ImportedImage;
};
#endif // LISA_SCENE_H
