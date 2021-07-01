#include <QLayout>
#include "PipeWgt.h"


PipeWgt::PipeWgt(QWidget *parent): QWidget(parent)
{
    PipeColor = QColor(0,0,0);
    setWindowTitle("Pipe tool");
    setWindowIcon(QIcon(":/image/res/menu/pipeM.png"));

    pipeRoleChoice = new  QGroupBox("Chose the pipe role");
    line = new QRadioButton("Lateral pipe");
    QObject::connect(line,SIGNAL(clicked(bool)),this,SLOT(clickkedstate(bool)));
    //line->setAutoExclusive(false);
    magistral = new QRadioButton("Mainline pipe");
    QObject::connect(magistral,SIGNAL(clicked(bool)),this,SLOT(clickkedstate(bool)));
    //magistral->setAutoExclusive(false);

    line->setChecked(true);
    magistral->setChecked(false);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(line);
    vbox->addWidget(magistral);
    vbox->addStretch(1);
    pipeRoleChoice->setLayout(vbox);

    colorLegendLbl = new QLabel("Color of pipe in the drawing");
    colorLegendLbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    colorLegendLbl->setWordWrap(true);

    colorLegend = new QTextEdit;
    colorLegend->setFixedSize(119,25);
    colorLegend->setReadOnly(true);
    colorLegend->setStyleSheet("background-color: blue;");

    pipeSize = new QComboBox;
    pipeSize->addItem("25 mm");
    pipeSize->addItem("32 mm");
    pipeSize->addItem("40 mm");
    addPipeBtn = new QPushButton("Draw");
    cancelPipeBtn = new QPushButton("Close");

    QHBoxLayout *hbox1 = new QHBoxLayout;
    QHBoxLayout *hbox2 = new QHBoxLayout;
    QHBoxLayout *hbox3 = new QHBoxLayout;
    QVBoxLayout *vboxMain = new QVBoxLayout;

    hbox1->addWidget(pipeRoleChoice);
    hbox1->addWidget(colorLegendLbl);
    hbox1->setContentsMargins(10,10,10,0);
    hbox1->setSpacing(20);

    hbox2->addWidget(pipeSize);
    hbox2->addWidget(colorLegend);
    hbox2->setContentsMargins(10,5,10,10);
    hbox2->setSpacing(20);

    hbox3->addWidget(addPipeBtn);
    hbox3->addWidget(cancelPipeBtn);
    hbox3->setContentsMargins(10,10,10,10);
    hbox3->setSpacing(20);

    vboxMain->addLayout(hbox1);
    vboxMain->addLayout(hbox2);
    vboxMain->addLayout(hbox3);

    this->setLayout(vboxMain);    
    setGeometry(0,0,300,215);
    setMinimumWidth(300);
    setMaximumWidth(420);
    setMinimumHeight(215);
    setMaximumHeight(400);
    connect(cancelPipeBtn, SIGNAL(clicked() ), SLOT(cancelPipeBtn_Clicked()));
    connect(addPipeBtn, SIGNAL(clicked() ), SLOT(addPipeBtn_Clicked()));
    connect(pipeSize, SIGNAL(currentIndexChanged(QString)), SLOT(changeColor()));

}

PipeWgt::~PipeWgt(){}

void PipeWgt::cancelPipeBtn_Clicked()
{
    this->hide();
    emit pipeToolClose();
}

void PipeWgt::addPipeBtn_Clicked()
{
    QRegExp re("(\\d+)");
    if (re.indexIn(pipeSize->currentText()) != -1) Diameter = re.cap(1).toInt();
    if(line->isChecked()) PipeRole = 0;
    else{PipeRole = 1;}
    switch (Diameter)
    {
        case 25: {PipeColor = QColor(Qt::blue); break;}
        case 32: {PipeColor = QColor(Qt::red); break;}
    case 40: {PipeColor = QColor(QColorConstants::Svg::blueviolet); break;}
    default: {PipeColor = QColor(Qt::black); break;}
    }
    emit newPipe(Diameter,PipeRole,PipeColor);
}

void PipeWgt::clickkedstate(bool)
{
    if (sender() == line)
    {
        line->setChecked(true);
        magistral->setChecked(false);
    }
    else
    {
        line->setChecked(false);
        magistral->setChecked(true);
    }
}

void PipeWgt::changeColor()
{
    if(pipeSize->currentIndex() == 0)
    {

        colorLegend->setStyleSheet("background-color: blue;");
        PipeColor = QColor(Qt::blue);
    }
    else if(pipeSize->currentIndex() == 1)
    {
        colorLegend->setStyleSheet("background-color: red;");
        PipeColor = QColor(Qt::red);
    }
    else
    {
        colorLegend->setStyleSheet("background-color: BlueViolet;");
        PipeColor = QColor(Qt::green);
    }
};






