#ifndef PIPEWGT_H
#define PIPEWGT_H
#include <QWidget>
#include <QDebug>
#include <QRadioButton>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>

class PipeWgt: public QWidget{
    Q_OBJECT
public:
    PipeWgt(QWidget *parent = nullptr);
    ~PipeWgt();


protected:
    QGroupBox *pipeRoleChoice;
    QRadioButton *line;
    QRadioButton *magistral;
    QLabel *colorLegendLbl;
    QTextEdit *colorLegend;
    QComboBox *pipeSize;
    QPushButton *addPipeBtn;
    QPushButton *cancelPipeBtn;
    QColor PipeColor;
    int PipeRole;
    int Diameter;
signals:
    void newPipe(int Diameter,int PipeRole,QColor PipeColor);
    void pipeToolClose();
public slots:
    void cancelPipeBtn_Clicked();
    void addPipeBtn_Clicked();
    void clickkedstate(bool);
private slots:
    void changeColor();    
};
#endif // PIPEWGT_H
