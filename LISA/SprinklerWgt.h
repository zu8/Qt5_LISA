#ifndef SPRINKLERWGT_H
#define SPRINKLERWGT_H
#include<QWidget>
#include<QDebug>
#include<QComboBox>
#include<QTextEdit>
#include <QPushButton>

class Sprinkler;
class SprinklerWgt: public QWidget{
    Q_OBJECT
public:
    SprinklerWgt(QWidget *parent = nullptr);
    ~SprinklerWgt();
    void setFirm();
    void setProduct();
    //void setDescr();
protected:
    QComboBox* Firm;
    QComboBox* Product;
    QTextEdit* Descr;
    QPushButton* add;
    QPushButton* close;

signals:
    void newSprinkler(int Radius,qreal Flow,int Art, int bodyType);
    void currentIndexChanged(QString);
    void sprinklerClicked();
    void sprinklerToolClosed();
public slots:
    void showPosts();
    void ButtonCncl_Clicked();
    void ButtonAdd_Clicked();
    friend class Sprinkler;
};
#endif // SPRINKLERWGT_H
