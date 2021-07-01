#ifndef PUMPWGT_H
#define PUMPWGT_H
#include <QWidget>
#include <QDebug>
#include <QComboBox>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>

class PumpWgt: public QWidget{
    Q_OBJECT
public:
    PumpWgt(QWidget *parent = nullptr);
    ~PumpWgt();
    double getDesCapValue();
    double getPressValue();
    void setDesCapValue(double);
    void setPressValue(double);
    //void setDescr();
protected:

    QTextEdit* DCwindow;
    QTextEdit* Pwindow;
    QLabel* DCLabel;
    QLabel* PLabel;
    QPushButton* addPump;
    QPushButton* closePump;
    double DesCapValue;
    double PressValue;


signals:
    void newPump(double DesCap,double Pressure);
    void NewPressure(double PressValue);
public slots:
    void ButtonCncl_Clicked();
    void ButtonAdd_Clicked();
private slots:
    void WhatNext();    
    friend class Sprinkler;
};
#endif // PUMPWGT_H
