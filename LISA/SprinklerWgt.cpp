#include<QLayout>
#include"SprinklerWgt.h"
#include"Sprinkler.h"

SprinklerWgt::SprinklerWgt(QWidget *parent): QWidget(parent){
    setWindowTitle("Sprinkler tool");
    setWindowIcon(QIcon(":/image/res/menu/sprinkler.png"));
    Firm = new QComboBox;
    Product = new QComboBox;
    Descr = new QTextEdit;
    Descr->setReadOnly(true);   
    this->setMinimumWidth(300);
    this->setMaximumWidth(600);
    this->setMinimumHeight(300);
    this->setMaximumHeight(650);
    add = new QPushButton("Add");
    close = new QPushButton("Close");

    QHBoxLayout* phbxLayout = new QHBoxLayout;
    QVBoxLayout* pvbxLayout = new QVBoxLayout;

    phbxLayout->setContentsMargins(10,10,10,10);
    phbxLayout->setSpacing(20);
    phbxLayout->addWidget(add);
    phbxLayout->addWidget(close);

    pvbxLayout->setContentsMargins(10,10,10,10);
    pvbxLayout->setSpacing(20);
    pvbxLayout->addWidget(Firm);
    pvbxLayout->addWidget(Product);
    pvbxLayout->addWidget(Descr);
    pvbxLayout->addLayout(phbxLayout);

    this->setLayout(pvbxLayout);

    setFirm();
    setProduct();
    //setDescr();
    connect(Firm, SIGNAL(currentIndexChanged(QString)), SLOT(showPosts()));
    connect(close, SIGNAL(clicked() ), SLOT(ButtonCncl_Clicked()));
    connect(add, SIGNAL(clicked() ), SLOT(ButtonAdd_Clicked()));

}

SprinklerWgt::~SprinklerWgt(){};

void SprinklerWgt::setFirm(){

    Firm->insertItem(1,"Hunter");
    Firm->insertItem(2,"Rainbird");

}

void SprinklerWgt::setProduct(){

    QStringList HunterPr = {"RotorPGP","MPRotator 800","MPRotator 1000",
                           "MPRotator 2000","MPRotator 3000","MPRotator 3500",
                           "MPRotator Corner","MPRotator Strip"};
    QStringList RainBirdPr = {"Rotor 5000","8 HE-VAN ","10 HE-VAN",
                             "12 HE-VAN","15 HE-VAN "};
    if (Firm->currentIndex() == 0){
        Product->clear();
        Product->addItems(HunterPr);
    }
    else {
        Product->clear();
        Product->addItems(RainBirdPr);
    }
}
void SprinklerWgt::showPosts(){
    setProduct();
}
void SprinklerWgt::ButtonCncl_Clicked(){
    emit sprinklerToolClosed();
    this->hide();
}
void SprinklerWgt::ButtonAdd_Clicked(){
    qDebug() << "in switch btn";
    if (Firm->currentIndex() == 0){
        qDebug() << "in switch firm 0";
        switch (Product->currentIndex())
        {
            case 0:
            {

                emit newSprinkler(1100,0.61, 0, 0); // radius devided by 10!
                break;
            }
            case 1:
            {
                emit newSprinkler(290,0.05, 1, 1); // radius devided by 10!
                break;
            }
            case 2:
            {
                emit newSprinkler(400,0.1, 2, 1); // radius devided by 10!
                break;
            }
            case 3:
            {
                emit newSprinkler(580,0.2, 3, 1); // radius devided by 10!
                break;
            }
            case 4:
            {
                emit newSprinkler(905,0.42, 4, 1); // radius devided by 10!
                break;
            }
            case 5:{
                emit newSprinkler(1070,0.7, 5, 1); // radius devided by 10!
                break;
            }
            case 6:
            {
                emit newSprinkler(380,0.05, 6, 1); // radius devided by 10!
                break;
            }
        }
    }
    else{
        qDebug() << "in switch firm 1";
        switch (Product->currentIndex()){
            case 0:{
                emit newSprinkler(940,0.67, 100, 0); // radius devided by 10!
                break;
            }
            case 1:{
                emit newSprinkler(240,0.13, 101, 2); // radius devided by 10!
                break;
            }
            case 2:
            {
                emit newSprinkler(300,0.21, 102, 2); // radius devided by 10!
                break;
            }
            case 3:
            {
                emit newSprinkler(370,0.27, 103, 2); // radius devided by 10!
                break;
            }
            case 4:
            {
                emit newSprinkler(460,0.42, 104, 2); // radius devided by 10!
                break;
            }
        }
    }
}
