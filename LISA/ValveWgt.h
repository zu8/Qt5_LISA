#ifndef VALVEWGT_H
#define VALVEWGT_H
#include <QWidget>
#include <QDebug>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>

class ValveWgt: public QWidget{
    Q_OBJECT
public:
    ValveWgt(QWidget *parent = nullptr);
    ~ValveWgt();
    void setLists();
protected:

    int ZoneNumber;
    int curMDiam;
    int curLDiam;
    qreal otherLosses;
    qreal PumpPressure;

    QGroupBox * zNumGr;
    QLineEdit* zNtxt;
    QPushButton* zNleftBtn;
    QPushButton* zNrightBtn;

    QGroupBox * ValveModelGr;
    QComboBox* ValveModel;

    QLabel* PumpPressureLbl;
    QLabel* PumpPressureValue;

    QGroupBox * MainLineLosseslGr;
    QLabel* MLossesLbl;
    QLabel* MLossesValue;
    QComboBox* MDiameter;
    QPushButton* MLossesCalcBtn;

    QGroupBox * LateralLosseslGr;
    QLabel* LLossesLbl;
    QLabel* LLossesValue;
    QComboBox* LDiameter;
    QPushButton* LLossesCalcBtn;

    QGroupBox * OtherLosseslGr;
    QLabel* OtherLossesLbl;
    QLineEdit* OtherLossesTxt;
    QPushButton* OtherLossesCalcBtn;

    QLabel* ResultPressureLbl;
    QLabel* ResultPressureValue;

    QPushButton* PlaceValveBtn;
    QPushButton* CloseBtn;

signals:
    void ValveToolClosed();
    void ValveZoneChanged(int zone);
    void selectedDiam(int zone,int role,int diam);
    void NewValue(double Val);
    void newValve(int Zone, QString Model);

private slots:
    void CloseBtn_Clicked();
    void ChangeZ();
    void DiameterSelected();
    void CalcMLosses();
    void CalcLLosses();
    void CalcOtherLosses();
    void PlaceValve();
public slots:
    void SetPumpPressure(double value);
    void SetNewMLooseValue(double value);
    void SetNewLLooseValue(double value);
    void SetResultPressValue(double value);


};
#endif // VALVEWGT_H
