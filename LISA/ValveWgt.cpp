#include <QLayout>
#include <QDebug>
#include "ValveWgt.h"





ValveWgt::ValveWgt(QWidget *parent):QWidget(parent)
{
    ZoneNumber = 1;
    PumpPressure = 0;
    setWindowTitle("Valve tool");
    setWindowIcon(QIcon(":/image/res/menu/valve.png"));

    //header
    zNumGr = new QGroupBox("Zone Number");
    zNtxt = new QLineEdit;
    zNtxt->setReadOnly(true);
    zNtxt->setFixedSize(90,30);
    zNtxt->setFont(QFont("Roboto",12,QFont::Bold));
    zNtxt->setText(QString::number(ZoneNumber));
    zNtxt->setAlignment(Qt::AlignCenter);
    zNtxt->setText("1");

    zNleftBtn = new QPushButton;
    zNleftBtn->setIcon(QIcon(":/image/res/actions/back_icon-icons.com_52398.ico"));
    zNrightBtn = new QPushButton;
    zNrightBtn->setIcon(QIcon(":/image/res/actions/forward_icon-icons.com_52386.ico"));

    QHBoxLayout* header = new QHBoxLayout;

    header->addWidget(zNleftBtn);
    header->addWidget(zNtxt);
    header->addWidget(zNrightBtn);
    header->setContentsMargins(10,10,10,10);
    zNumGr->setLayout(header);

    // valve models
    ValveModelGr = new QGroupBox("Valve model");
    ValveModel = new QComboBox;
    QHBoxLayout* vlvMod = new QHBoxLayout;
    vlvMod->addWidget((ValveModel));
    vlvMod->setContentsMargins(20,10,20,10);
    ValveModelGr->setLayout(vlvMod);

    // pump pressure
    PumpPressureLbl = new QLabel("Pump pressure");
    PumpPressureLbl->setFont(QFont("Roboto",11,QFont::Medium));
    PumpPressureValue = new QLabel("0");
    PumpPressureValue->setFont(QFont("Roboto",12,QFont::Medium));
    PumpPressureValue->setAlignment(Qt::AlignRight);
    QHBoxLayout* pmpPr = new QHBoxLayout;
    pmpPr->addWidget(PumpPressureLbl);
    pmpPr->addWidget(PumpPressureValue);
    pmpPr->setContentsMargins(10,10,10,10);

    //MainLineLosses
    MainLineLosseslGr = new QGroupBox("Main Line");
    QSpacerItem* sItem1 = new QSpacerItem(20,0);
    MLossesLbl = new QLabel("Main line losses");
    MLossesLbl->setFont(QFont("Roboto",11,QFont::Medium));
    MLossesValue = new QLabel("0");
    MLossesValue->setFont(QFont("Roboto",12,QFont::Medium));
    MLossesValue->setAlignment(Qt::AlignRight);
    MDiameter = new QComboBox;
    MLossesCalcBtn = new QPushButton("Calculate");

    QHBoxLayout* MLosH1 = new QHBoxLayout;
    MLosH1->addWidget(MLossesLbl);
    MLosH1->addWidget(MLossesValue);
    MLosH1->setContentsMargins(10,10,10,10);

    QHBoxLayout* MLosH2 = new QHBoxLayout;
    MLosH2->addWidget(MDiameter);
    MLosH2->addSpacerItem(sItem1);
    MLosH2->addWidget(MLossesCalcBtn);
    MLosH2->setContentsMargins(10,10,10,10);

    QVBoxLayout* MLosV1 = new QVBoxLayout;
    MLosV1->addLayout(MLosH1);
    MLosV1->addLayout(MLosH2);
    MainLineLosseslGr->setLayout(MLosV1);

    //Lateral losses
    LateralLosseslGr = new QGroupBox("Lateral Line");
    QSpacerItem* sItem2 = new QSpacerItem(20,0);
    LLossesLbl = new QLabel("Lateral line losses");
    LLossesLbl->setFont(QFont("Roboto",11,QFont::Medium));
    LLossesValue = new QLabel("0");
    LLossesValue->setAlignment(Qt::AlignRight);
    LLossesValue->setFont(QFont("Roboto",12,QFont::Medium));
    LDiameter = new QComboBox;
    LLossesCalcBtn = new QPushButton("Calculate");

    QHBoxLayout* LLosH1 = new QHBoxLayout;
    LLosH1->addWidget(LLossesLbl);
    LLosH1->addWidget(LLossesValue);
    LLosH1->setContentsMargins(10,10,10,10);

    QHBoxLayout* LLosH2 = new QHBoxLayout;
    LLosH2->addWidget(LDiameter);
    LLosH2->addSpacerItem(sItem2);
    LLosH2->addWidget(LLossesCalcBtn);
    LLosH2->setContentsMargins(10,10,10,10);

    QVBoxLayout* LLosV1 = new QVBoxLayout;
    LLosV1->addLayout(LLosH1);
    LLosV1->addLayout(LLosH2);
    LateralLosseslGr->setLayout(LLosV1);

    //Other losses
    OtherLosseslGr = new QGroupBox("Other losses");

    OtherLossesLbl = new QLabel("Margin pressure");
    OtherLossesLbl->setFont(QFont("Roboto",11,QFont::Medium));
    OtherLossesTxt = new QLineEdit;
    OtherLossesTxt->setText("0");
    OtherLossesTxt->setMaximumWidth(105);
    QHBoxLayout* OthH1 = new QHBoxLayout;
    OthH1->addWidget(OtherLossesLbl);
    OthH1->addWidget(OtherLossesTxt);
    OthH1->setContentsMargins(10,10,10,10);

    QSpacerItem* sItem = new QSpacerItem(132,0);
    OtherLossesCalcBtn = new QPushButton("Add");
    QHBoxLayout* OthH2 = new QHBoxLayout;
    OthH2 ->setContentsMargins(10,10,10,10);
    OthH2->addSpacerItem(sItem);
    OthH2->addWidget(OtherLossesCalcBtn);

    QVBoxLayout* OthV1 = new QVBoxLayout;
    OthV1->addLayout(OthH1);
    OthV1->addLayout(OthH2);

    OtherLosseslGr->setLayout(OthV1);

    // Working pressure
    ResultPressureLbl = new QLabel("Working pressure");
    ResultPressureLbl->setFont(QFont("Roboto",11,QFont::Medium));
    ResultPressureValue = new QLabel("0");
    ResultPressureValue->setAlignment(Qt::AlignBaseline);
    ResultPressureValue->setAlignment(Qt::AlignRight);
    ResultPressureValue->setFont(QFont("Roboto",12,QFont::Medium));

    QHBoxLayout* WpH1 = new QHBoxLayout;
    WpH1->addWidget(ResultPressureLbl);
    WpH1->addWidget(ResultPressureValue);
    WpH1 ->setContentsMargins(20,20,20,20);

    // Footer
    PlaceValveBtn = new QPushButton("Place");
    QSpacerItem* sItem3 = new QSpacerItem(20,0);
    CloseBtn = new QPushButton("Close");
    QHBoxLayout* FH1 = new QHBoxLayout;
    FH1->addWidget(PlaceValveBtn);
    FH1->addSpacerItem(sItem3);
    FH1->addWidget(CloseBtn);
    FH1 ->setContentsMargins(20,20,20,20);

    QVBoxLayout* Com = new QVBoxLayout;

    Com->addWidget(zNumGr);
    Com->addLayout(pmpPr);
    Com->addWidget(ValveModelGr);
    Com->addWidget(MainLineLosseslGr);
    Com->addWidget(LateralLosseslGr);
    Com->addWidget(OtherLosseslGr);
    Com->addLayout(WpH1);
    Com->addLayout(FH1);

    setLayout(Com);
    setGeometry(0,0,300,700);
    setMinimumWidth(300);
    setMaximumWidth(400);
    setMinimumHeight(700);
    setMaximumHeight(800);

    setLists();


    connect(CloseBtn, SIGNAL(clicked() ), SLOT(CloseBtn_Clicked()));
    connect(zNleftBtn, SIGNAL(clicked()),SLOT(ChangeZ()));
    connect(zNrightBtn, SIGNAL(clicked()),SLOT(ChangeZ()));
    connect(MDiameter, SIGNAL(currentIndexChanged(QString)), SLOT(DiameterSelected()));
    connect(LDiameter, SIGNAL(currentIndexChanged(QString)), SLOT(DiameterSelected()));
    connect( MLossesCalcBtn, SIGNAL(clicked() ), SLOT(CalcMLosses()));
    connect( LLossesCalcBtn, SIGNAL(clicked() ), SLOT(CalcLLosses()));
    connect( OtherLossesCalcBtn, SIGNAL(clicked() ), SLOT(CalcOtherLosses()));
    connect(this,SIGNAL(NewValue(double)),SLOT(SetResultPressValue(double)));
    connect(PlaceValveBtn, SIGNAL(clicked() ), SLOT(PlaceValve()));

}

ValveWgt::~ValveWgt(){}

void ValveWgt::setLists()
{
     QStringList VlvModels = {"Hunter PGV 1'", "Hunter PGV JAR-TOP 1'","RainBird DV-100 1'","RainBird LFV-075 3/4'"};
     ValveModel->addItems(VlvModels);
     QStringList MainDiam = {"25", "32", "40"};
     MDiameter->addItems(MainDiam);
     QStringList LaterDiam = {"25", "32"};
     LDiameter->addItems(LaterDiam);
}

void ValveWgt::CloseBtn_Clicked()
{
    this->hide();
    emit ValveToolClosed();
}

void ValveWgt::ChangeZ()
{
    if (sender() == zNleftBtn)
    {
        ZoneNumber<=1?ZoneNumber = 1:--ZoneNumber;
        emit ValveZoneChanged(ZoneNumber);
    }
    else
    {
        ++ZoneNumber;
        emit ValveZoneChanged(ZoneNumber);
    }
    zNtxt->setText(QString::number(ZoneNumber));
}

void ValveWgt::SetPumpPressure(double value)
{

    if (value > 0.01) PumpPressureValue->setText(QString::number(value));
    else PumpPressureValue->setText("0");
}

void ValveWgt::SetNewMLooseValue(double value)
{
    if (value > 0.01)
    {
        MLossesValue->setText(QString::number(value));
        ResultPressureValue->setText(QString::number((PumpPressureValue->text().toDouble()) - value - (LLossesValue->text().toDouble()) - OtherLossesTxt->text().toDouble(),'f', 2));

    }

    else
    {
        MLossesValue->setText("0");
    }

}
void ValveWgt::SetNewLLooseValue(double value)
{
    if (value > 0.01)
    {
        LLossesValue->setText(QString::number(value));
        ResultPressureValue->setText(QString::number((PumpPressureValue->text().toDouble()) - value - (MLossesValue->text().toDouble()) - OtherLossesTxt->text().toDouble(),'f', 2));
    }

    else LLossesValue->setText("0");
}

void ValveWgt::SetResultPressValue(double value)
{
    if(value > 0.01 ||  otherLosses > 0.01)
    {

        if (otherLosses < 0.01) ResultPressureValue->setText(QString::number(value ,'f', 2));
        else ResultPressureValue->setText(QString::number((value - otherLosses),'f', 2));
        if(ResultPressureValue->text().toDouble() < 2 )
        {
            ResultPressureValue->setStyleSheet("color: rgb(255, 0, 70)");
        }
        else
        {
            ResultPressureValue->setStyleSheet("color: rgb(0, 0, 0)");
        }
    }
    else ResultPressureValue->setText(QString::number(PumpPressure,'f',2));
}

void ValveWgt::DiameterSelected()
{
    if (sender() == MDiameter)
    {
        if(MDiameter->currentText() == "25")  curMDiam = 25;
        else if (MDiameter->currentText() == "32") curMDiam = 32;
        else if (MDiameter->currentText() == "40") curMDiam = 40;
        else curMDiam = 0;
    }
    else
    {
        if(LDiameter->currentText() == "25")  curLDiam = 25;
        else if (LDiameter->currentText() == "32") curLDiam = 32;
        else curLDiam = 0;
    }
}

void ValveWgt::CalcMLosses()
{
    curMDiam = MDiameter->currentText().toInt();
    emit selectedDiam(ZoneNumber, 0,curMDiam);
}

void ValveWgt::CalcLLosses()
{
    curLDiam = LDiameter->currentText().toInt();
    emit selectedDiam(ZoneNumber, 1,curLDiam);
}

void ValveWgt::CalcOtherLosses()
{
    if(OtherLossesTxt->text().toDouble() && OtherLossesTxt->text() != "")
    {
        qDebug() << "text != 0 ";
        otherLosses = OtherLossesTxt->text().toDouble();
        emit NewValue(ResultPressureValue->text().toDouble());
    }
    else
    {
        qDebug() << "text == 0 ";
        otherLosses = 0.00;
        emit NewValue(ResultPressureValue->text().toDouble());
    }
}

void ValveWgt::PlaceValve()
{
    emit newValve(ZoneNumber, ValveModel->currentText());
}
