QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DotGrabber.cpp \
    ImportedImage.cpp \
    LISA_Scene.cpp \
    LISA_View.cpp \
    PipeWgt.cpp \
    Pump.cpp \
    PumpWgt.cpp \
    Sprinkler.cpp \
    SprinklerWgt.cpp \
    ValveWgt.cpp \
    Zoning.cpp \
    ZoningWgt.cpp \
    core.cpp \
    losses.cpp \
    main.cpp \
    mainwindow.cpp \
    pipe.cpp \
    ruler.cpp \
    valve.cpp

HEADERS += \
    DotGrabber.h \
    ImportedImage.h \
    LISA_Scene.h \
    LISA_View.h \
    PipeWgt.h \
    Pump.h \
    PumpWgt.h \
    Sprinkler.h \
    SprinklerWgt.h \
    ValveWgt.h \
    Zoning.h \
    ZoningWgt.h \
    core.h \
    losses.h \
    mainwindow.h \
    pipe.h \
    ruler.h \
    valve.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    LISA_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
#    # Добавлять в конец файла проекта для корректного отображения
#    # сообщений компилятора MSVC на русском (перекодировка в CP 1251)
#    QMAKE_EXTRA_TARGETS += before_build makefilehook

#    makefilehook.target = $(MAKEFILE)
#    makefilehook.depends = .beforebuild

#    PRE_TARGETDEPS += .beforebuild

#    before_build.target = .beforebuild
#    before_build.depends = FORCE
#    before_build.commands = chcp 1251

#    RESOURCES += \
#        resource.qrc

#    DISTFILES +=
