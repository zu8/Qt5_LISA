#include<QLayout>
#include <QMessageBox>
#include "PumpWgt.h"


PumpWgt::PumpWgt(QWidget *parent): QWidget(parent)
{
    setWindowTitle("Pump tool");
    setWindowIcon(QIcon(":/image/res/menu/pump.png"));
    DCwindow = new QTextEdit;
    DCwindow->setFont(QFont("Roboto",12,QFont::Medium));
    Pwindow = new QTextEdit;
    Pwindow->setFont(QFont("Roboto",12,QFont::Medium));
    DCLabel = new QLabel("Design Capacity (m3/h)");
    PLabel = new QLabel("Pump Pressure (Bar)");
    addPump = new QPushButton("Accept");
    closePump = new QPushButton("Close");

    QVBoxLayout* pvbxLayout1 = new QVBoxLayout;
    QVBoxLayout* pvbxLayout2 = new QVBoxLayout;
    QHBoxLayout* phbxLayout = new QHBoxLayout;


    pvbxLayout1->setContentsMargins(10,10,10,10);
    pvbxLayout1->setSpacing(20);
    pvbxLayout1->addWidget(DCwindow);
    pvbxLayout1->addWidget(DCLabel);
    pvbxLayout1->addWidget(addPump);

    pvbxLayout2->setContentsMargins(10,10,10,10);
    pvbxLayout2->setSpacing(20);

    pvbxLayout2->addWidget(Pwindow);
    pvbxLayout2->addWidget(PLabel);
    pvbxLayout2->addWidget(closePump);


    phbxLayout->setContentsMargins(10,10,10,10);
    phbxLayout->setSpacing(10);
    phbxLayout->addLayout(pvbxLayout1);
    phbxLayout->addLayout(pvbxLayout2);

    this->setLayout(phbxLayout);
    addPump->setEnabled(false);


    connect(DCwindow, SIGNAL(textChanged() ), SLOT(WhatNext()));
    connect(Pwindow, SIGNAL(textChanged() ), SLOT(WhatNext()));
    connect(closePump, SIGNAL(clicked() ), SLOT(ButtonCncl_Clicked()));
    connect(addPump, SIGNAL(clicked() ), SLOT(ButtonAdd_Clicked()));

    setGeometry(0,0,300,150);
    setMinimumWidth(300);
    setMaximumWidth(420);
    setMinimumHeight(150);
    setMaximumHeight(200);
}

PumpWgt::~PumpWgt(){}

double PumpWgt::getDesCapValue()
{
    return DesCapValue;
}

double PumpWgt::getPressValue()
{
    return PressValue;
}

void PumpWgt::setDesCapValue(double DCV)
{
    DesCapValue = DCV;
    DCwindow->setPlainText(QString::number(DesCapValue));
}

void PumpWgt::setPressValue(double PV)
{
    PressValue = PV;
    Pwindow->setPlainText(QString::number(PressValue));
};


void PumpWgt::ButtonCncl_Clicked()
{
    this->hide();
}


void PumpWgt::ButtonAdd_Clicked()
{
   if(DCwindow->toPlainText() == "" || Pwindow->toPlainText() == "")
   {
    return;
   }
   qDebug() << "adding pump";
   emit newPump(DCwindow->toPlainText().toDouble(),Pwindow->toPlainText().toDouble());
   PressValue = Pwindow->toPlainText().toDouble();
   emit NewPressure(PressValue);

}

void PumpWgt::WhatNext()
{
    if((DCwindow->toPlainText() == "" || Pwindow->toPlainText() == "") ||
      (DCwindow->toPlainText().toDouble() == 0.00 || Pwindow->toPlainText().toDouble() == 0.00))
    {
    addPump->setEnabled(false);
    }
    else addPump->setEnabled(true);

}
