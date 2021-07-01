/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "lisa_view.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport_Image;
    QAction *actionExit;
    QAction *actionScale_Image;
    QAction *actionRuler;
    QAction *actionSprinkler;
    QAction *actionPump;
    QAction *actionPipe;
    QAction *actionZoning;
    QAction *actionSave_as;
    QAction *actionOpen;
    QAction *actionValve;
    QAction *actionlock_Image;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    LISA_View *graphicsView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionImport_Image = new QAction(MainWindow);
        actionImport_Image->setObjectName(QString::fromUtf8("actionImport_Image"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/res/menu/picture .png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_Image->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionScale_Image = new QAction(MainWindow);
        actionScale_Image->setObjectName(QString::fromUtf8("actionScale_Image"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/res/menu/scale.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale_Image->setIcon(icon1);
        actionRuler = new QAction(MainWindow);
        actionRuler->setObjectName(QString::fromUtf8("actionRuler"));
        actionRuler->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/res/menu/measuringTape .png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRuler->setIcon(icon2);
        actionSprinkler = new QAction(MainWindow);
        actionSprinkler->setObjectName(QString::fromUtf8("actionSprinkler"));
        actionSprinkler->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/res/menu/sprinkler.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSprinkler->setIcon(icon3);
        actionPump = new QAction(MainWindow);
        actionPump->setObjectName(QString::fromUtf8("actionPump"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/res/menu/pump.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPump->setIcon(icon4);
        actionPipe = new QAction(MainWindow);
        actionPipe->setObjectName(QString::fromUtf8("actionPipe"));
        actionPipe->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/res/menu/pipeM.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPipe->setIcon(icon5);
        actionZoning = new QAction(MainWindow);
        actionZoning->setObjectName(QString::fromUtf8("actionZoning"));
        actionZoning->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/res/menu/zoning.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoning->setIcon(icon6);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/res/menu/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon7);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/res/menu/open-folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon8);
        actionValve = new QAction(MainWindow);
        actionValve->setObjectName(QString::fromUtf8("actionValve"));
        actionValve->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/res/menu/valve.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionValve->setIcon(icon9);
        actionlock_Image = new QAction(MainWindow);
        actionlock_Image->setObjectName(QString::fromUtf8("actionlock_Image"));
        actionlock_Image->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new LISA_View(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuFile->addAction(actionImport_Image);
        menuFile->addAction(actionExit);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionOpen);
        menuEdit->addAction(actionScale_Image);
        menuEdit->addAction(actionlock_Image);
        menuTools->addAction(actionRuler);
        menuTools->addAction(actionSprinkler);
        menuTools->addAction(actionPump);
        menuTools->addAction(actionPipe);
        menuTools->addAction(actionZoning);
        menuTools->addAction(actionValve);
        toolBar->addAction(actionImport_Image);
        toolBar->addAction(actionScale_Image);
        toolBar->addAction(actionRuler);
        toolBar->addAction(actionSprinkler);
        toolBar->addAction(actionPump);
        toolBar->addAction(actionPipe);
        toolBar->addAction(actionZoning);
        toolBar->addAction(actionValve);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionImport_Image->setText(QCoreApplication::translate("MainWindow", "Import Image", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionScale_Image->setText(QCoreApplication::translate("MainWindow", "Scale Image", nullptr));
        actionRuler->setText(QCoreApplication::translate("MainWindow", "Ruler", nullptr));
        actionSprinkler->setText(QCoreApplication::translate("MainWindow", "Sprinkler", nullptr));
        actionPump->setText(QCoreApplication::translate("MainWindow", "Pump", nullptr));
        actionPipe->setText(QCoreApplication::translate("MainWindow", "Pipe", nullptr));
        actionZoning->setText(QCoreApplication::translate("MainWindow", "Zoning", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
        actionValve->setText(QCoreApplication::translate("MainWindow", "Valve", nullptr));
        actionlock_Image->setText(QCoreApplication::translate("MainWindow", "lock Image", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
