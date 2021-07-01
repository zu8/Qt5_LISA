#ifndef ZONINGWGT_H
#define ZONINGWGT_H
#include <QWidget>
#include <QDebug>
#include <QComboBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>


class ZoningWgt: public QWidget{
    Q_OBJECT
public:
    ZoningWgt(QWidget *parent = nullptr);
    ~ZoningWgt();


protected:

    int ZoneNumber;
    QGroupBox * zNumGr;
    QLineEdit* zNtxt;
    QPushButton* zNleftBtn;
    QPushButton* zNrightBtn;
    QGroupBox * zFlowGr;
    QLabel* totalFlowLbl;
    QLabel* ttlFlowValue;
    QLabel* recmdFlowLbl;
    QLabel* recmdFlowValue;
    QGroupBox * selectedGr;
    QTextEdit* selectedParam;
    QPushButton* addBtn;
    QPushButton* removeBtn;
    QPushButton* closeBtn;

signals:
    void ZoneChanged(int);
    void textChanged();
    void coreChange(QString data);
    void zoningToolClosed();
    void AddBtn_Clicked();
    void RemoveBtn_Clicked();
    void flowUpdated();
public slots:
    void SetNewFlowValue(double value);
    void setRecommendFlow(double fl,double Pr);
    void clear();
    void insertText(QString text);
private slots:
    void CloseBtn_Clicked();
    void ChangeZ();

};


#endif // ZONINGWGT_H
