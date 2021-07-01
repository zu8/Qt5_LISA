#ifndef ZONING_H
#define ZONING_H
#include <QWidget>
#include<QMap>
#include <QMetaType>

class Core;

class Zoning: public QObject {
  Q_OBJECT

public:
Zoning(QObject * parent = 0);
Zoning(const Zoning &Zn);
~Zoning();
friend QDataStream & operator<<(QDataStream & out,  const Zoning &Z);
friend QDataStream & operator>>(QDataStream & in,  Zoning &Z);
QMap<int,double> getAreaZones();
void setAreaZones(QMap<int,double>);
Core* getCurrentBody();
void setCurrentBody(Core*);
protected:
int zone;
double MaxFlow;
double TotalFlow;
QMap<int,double> AreaZones;
Core* currentBody;
signals:
void textChanged();
void coreChange(QString);
void newFlowValue(double);
//void refresh();
public slots:
void SelectedBody(Core* crntBody);
void changeZnumber(int num);
void AddFlowSprinkler();
void RemoveFlowSprinkler();
void UserFlow(double DC,double Pr);

friend class core;
};



//Перегрузка операций << и >> для Core и QDataStream:
QDataStream & operator<<(QDataStream & out, const  Zoning  & Z);
QDataStream & operator>>(QDataStream & in,  Zoning & Z);
#endif // ZONING_H
