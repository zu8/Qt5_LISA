#include <QDebug>
#include <QLayout>
#include "ZoningWgt.h"

//int ZoningWgt::ZoneNumber = 1;
ZoningWgt::ZoningWgt(QWidget *parent):QWidget(parent)
{   ZoneNumber = 1;
    setWindowTitle("Zoning tool");
    setWindowIcon(QIcon(":/image/res/menu/zoning.png"));
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
    //body top
    zFlowGr = new QGroupBox("Zone flow data");
    totalFlowLbl = new QLabel("Total flow: ");
    totalFlowLbl->setFont(QFont("Roboto",11,QFont::Medium));
    ttlFlowValue = new QLabel;
    ttlFlowValue->setNum(0.0);
    ttlFlowValue ->setFont(QFont("Roboto",11,QFont::Medium));
    ttlFlowValue->setAlignment(Qt::AlignRight);
    recmdFlowLbl = new QLabel("Recommended flow: ");
    recmdFlowLbl->setFont(QFont("Roboto",11,QFont::Medium));
    recmdFlowValue = new QLabel;
    recmdFlowValue->setText("0");
    recmdFlowValue->setFont(QFont("Roboto",12,QFont::Medium));
    recmdFlowValue->setAlignment(Qt::AlignRight);

    QHBoxLayout* h1 = new QHBoxLayout;
    QHBoxLayout* h2 = new QHBoxLayout;
    QVBoxLayout* v1 = new QVBoxLayout;

    h1->addWidget(totalFlowLbl);
    h1->addWidget(ttlFlowValue);
    h1 ->setContentsMargins(10,10,10,0);

    h2->addWidget(recmdFlowLbl);
    h2->addWidget(recmdFlowValue);
    h2 ->setContentsMargins(10,0,10,10);

    v1->addLayout(h1);
    v1->addLayout(h2);

    zFlowGr->setLayout(v1);
    // body bottom
    selectedGr = new QGroupBox("Selected item");
    selectedParam = new QTextEdit;
    selectedParam->setReadOnly(true);
    selectedParam->setFixedSize(120,50);

    addBtn = new QPushButton("Add");
    removeBtn = new QPushButton("Remove");

    QVBoxLayout* v2 = new QVBoxLayout;
    v2->addWidget(addBtn);
    v2->addWidget(removeBtn);
    v2 ->setContentsMargins(10,0,0,0);

    QHBoxLayout* h3 = new QHBoxLayout;
    h3->addWidget(selectedParam);
    h3->addLayout(v2);
    selectedGr->setLayout(h3);
    //footer
    QSpacerItem* sItem = new QSpacerItem(0,0);
    closeBtn = new QPushButton("Close");
    QHBoxLayout* h4 = new QHBoxLayout;
    h4 ->setContentsMargins(10,10,10,10);
    h4->addSpacerItem(sItem);
    h4->addWidget(closeBtn);
    h4->setStretch(0, 120);

    QVBoxLayout* v3 = new QVBoxLayout;    
    v3->addWidget(zNumGr);
    v3->addWidget(zFlowGr);
    v3->addWidget(selectedGr);
    v3->addLayout(h4);

    this->setLayout(v3);
    setGeometry(0,0,300,350);
    setMinimumWidth(300);
    setMaximumWidth(400);
    setMinimumHeight(350);
    setMaximumHeight(450);

    connect(closeBtn, SIGNAL(clicked() ), SLOT(CloseBtn_Clicked()));
    connect(zNleftBtn, SIGNAL(clicked()),SLOT(ChangeZ()));
    connect(zNrightBtn, SIGNAL(clicked()),SLOT(ChangeZ()));
    connect(this,&ZoningWgt::coreChange,selectedParam,&QTextEdit::insertPlainText);
    connect(this,&ZoningWgt::textChanged,selectedParam,&QTextEdit::clear);
    connect( addBtn,SIGNAL(clicked()),SIGNAL(AddBtn_Clicked()));
    connect( removeBtn,SIGNAL(clicked()),SIGNAL(RemoveBtn_Clicked()));

}

ZoningWgt::~ZoningWgt(){}

void ZoningWgt::SetNewFlowValue(double value)
{
    ttlFlowValue->setText(QString::number(value));
    if(ttlFlowValue->text().toDouble() > recmdFlowValue->text().toDouble())
    {
        ttlFlowValue->setStyleSheet("color: rgb(255, 0, 70)");
    }
    else
    {
        ttlFlowValue->setStyleSheet("color: rgb(0, 0, 0)");
    }
    emit flowUpdated();
}
void ZoningWgt::setRecommendFlow(double fl, double pr)
{

    recmdFlowValue->setText(QString::number(fl,'f', 2));
    Q_UNUSED(pr);
}

void ZoningWgt::CloseBtn_Clicked()
{
    this->hide();
    emit zoningToolClosed();
}

void ZoningWgt::clear()
{
    selectedParam->clear();
}

void ZoningWgt::insertText(QString text)
{
    selectedParam->insertPlainText( text);
}

void ZoningWgt::ChangeZ()
{
    if (sender() == zNleftBtn)
    {
        ZoneNumber<=1?ZoneNumber = 1:--ZoneNumber;
        emit ZoneChanged(ZoneNumber);
    }
    else
    {
        ++ZoneNumber;
        emit ZoneChanged(ZoneNumber);
    }
    zNtxt->setText(QString::number(ZoneNumber));
}




