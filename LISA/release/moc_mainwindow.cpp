/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[38];
    char stringdata0[696];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "SendSelectedItems"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 23), // "QVector<QGraphicsItem*>"
QT_MOC_LITERAL(4, 54, 11), // "ToolChanged"
QT_MOC_LITERAL(5, 66, 13), // "ToolRulerIsOn"
QT_MOC_LITERAL(6, 80, 15), // "ToolScalingIsOn"
QT_MOC_LITERAL(7, 96, 11), // "BlockMoving"
QT_MOC_LITERAL(8, 108, 10), // "ZoningMode"
QT_MOC_LITERAL(9, 119, 14), // "ValveToolClose"
QT_MOC_LITERAL(10, 134, 24), // "ClosingSprListToolScript"
QT_MOC_LITERAL(11, 159, 23), // "ClosingZoningToolScript"
QT_MOC_LITERAL(12, 183, 21), // "ClosingPipeToolScript"
QT_MOC_LITERAL(13, 205, 22), // "ClosingValveToolScript"
QT_MOC_LITERAL(14, 228, 8), // "quitTool"
QT_MOC_LITERAL(15, 237, 10), // "selectItem"
QT_MOC_LITERAL(16, 248, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(17, 263, 4), // "item"
QT_MOC_LITERAL(18, 268, 11), // "deselectAll"
QT_MOC_LITERAL(19, 280, 11), // "deleteItems"
QT_MOC_LITERAL(20, 292, 21), // "QList<QGraphicsItem*>"
QT_MOC_LITERAL(21, 314, 16), // "rememberSelected"
QT_MOC_LITERAL(22, 331, 16), // "scalingImageTool"
QT_MOC_LITERAL(23, 348, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(24, 372, 31), // "on_actionImport_Image_triggered"
QT_MOC_LITERAL(25, 404, 22), // "on_actionRuler_toggled"
QT_MOC_LITERAL(26, 427, 4), // "arg1"
QT_MOC_LITERAL(27, 432, 30), // "on_actionScale_Image_triggered"
QT_MOC_LITERAL(28, 463, 16), // "getMousePosition"
QT_MOC_LITERAL(29, 480, 26), // "on_actionSprinkler_toggled"
QT_MOC_LITERAL(30, 507, 16), // "ZoningModeActive"
QT_MOC_LITERAL(31, 524, 23), // "on_actionPump_triggered"
QT_MOC_LITERAL(32, 548, 21), // "on_actionPipe_toggled"
QT_MOC_LITERAL(33, 570, 23), // "on_actionZoning_toggled"
QT_MOC_LITERAL(34, 594, 26), // "on_actionSave_as_triggered"
QT_MOC_LITERAL(35, 621, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(36, 645, 22), // "on_actionValve_toggled"
QT_MOC_LITERAL(37, 668, 27) // "on_actionlock_Image_toggled"

    },
    "MainWindow\0SendSelectedItems\0\0"
    "QVector<QGraphicsItem*>\0ToolChanged\0"
    "ToolRulerIsOn\0ToolScalingIsOn\0BlockMoving\0"
    "ZoningMode\0ValveToolClose\0"
    "ClosingSprListToolScript\0"
    "ClosingZoningToolScript\0ClosingPipeToolScript\0"
    "ClosingValveToolScript\0quitTool\0"
    "selectItem\0QGraphicsItem*\0item\0"
    "deselectAll\0deleteItems\0QList<QGraphicsItem*>\0"
    "rememberSelected\0scalingImageTool\0"
    "on_actionExit_triggered\0"
    "on_actionImport_Image_triggered\0"
    "on_actionRuler_toggled\0arg1\0"
    "on_actionScale_Image_triggered\0"
    "getMousePosition\0on_actionSprinkler_toggled\0"
    "ZoningModeActive\0on_actionPump_triggered\0"
    "on_actionPipe_toggled\0on_actionZoning_toggled\0"
    "on_actionSave_as_triggered\0"
    "on_actionOpen_triggered\0on_actionValve_toggled\0"
    "on_actionlock_Image_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  169,    2, 0x06 /* Public */,
       4,    0,  172,    2, 0x06 /* Public */,
       5,    1,  173,    2, 0x06 /* Public */,
       6,    1,  176,    2, 0x06 /* Public */,
       7,    1,  179,    2, 0x06 /* Public */,
       8,    1,  182,    2, 0x06 /* Public */,
       9,    0,  185,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  186,    2, 0x08 /* Private */,
      11,    0,  187,    2, 0x08 /* Private */,
      12,    0,  188,    2, 0x08 /* Private */,
      13,    0,  189,    2, 0x08 /* Private */,
      14,    0,  190,    2, 0x08 /* Private */,
      15,    1,  191,    2, 0x08 /* Private */,
      18,    0,  194,    2, 0x08 /* Private */,
      19,    1,  195,    2, 0x08 /* Private */,
      21,    1,  198,    2, 0x08 /* Private */,
      22,    0,  201,    2, 0x08 /* Private */,
      23,    0,  202,    2, 0x08 /* Private */,
      24,    0,  203,    2, 0x08 /* Private */,
      25,    1,  204,    2, 0x08 /* Private */,
      27,    0,  207,    2, 0x08 /* Private */,
      28,    1,  208,    2, 0x08 /* Private */,
      29,    1,  211,    2, 0x08 /* Private */,
      30,    0,  214,    2, 0x08 /* Private */,
      31,    0,  215,    2, 0x08 /* Private */,
      32,    1,  216,    2, 0x08 /* Private */,
      33,    1,  219,    2, 0x08 /* Private */,
      34,    0,  222,    2, 0x08 /* Private */,
      35,    0,  223,    2, 0x08 /* Private */,
      36,    1,  224,    2, 0x08 /* Private */,
      37,    1,  227,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, QMetaType::QRectF,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendSelectedItems((*reinterpret_cast< QVector<QGraphicsItem*>(*)>(_a[1]))); break;
        case 1: _t->ToolChanged(); break;
        case 2: _t->ToolRulerIsOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->ToolScalingIsOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->BlockMoving((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->ZoningMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->ValveToolClose(); break;
        case 7: _t->ClosingSprListToolScript(); break;
        case 8: _t->ClosingZoningToolScript(); break;
        case 9: _t->ClosingPipeToolScript(); break;
        case 10: _t->ClosingValveToolScript(); break;
        case 11: _t->quitTool(); break;
        case 12: _t->selectItem((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 13: _t->deselectAll(); break;
        case 14: _t->deleteItems((*reinterpret_cast< QList<QGraphicsItem*>(*)>(_a[1]))); break;
        case 15: _t->rememberSelected((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 16: _t->scalingImageTool(); break;
        case 17: _t->on_actionExit_triggered(); break;
        case 18: _t->on_actionImport_Image_triggered(); break;
        case 19: _t->on_actionRuler_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_actionScale_Image_triggered(); break;
        case 21: _t->getMousePosition((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 22: _t->on_actionSprinkler_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->ZoningModeActive(); break;
        case 24: _t->on_actionPump_triggered(); break;
        case 25: _t->on_actionPipe_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->on_actionZoning_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->on_actionSave_as_triggered(); break;
        case 28: _t->on_actionOpen_triggered(); break;
        case 29: _t->on_actionValve_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_actionlock_Image_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QGraphicsItem*> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QGraphicsItem*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QVector<QGraphicsItem*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendSelectedItems)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ToolChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ToolRulerIsOn)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ToolScalingIsOn)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::BlockMoving)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ZoningMode)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ValveToolClose)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::SendSelectedItems(QVector<QGraphicsItem*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::ToolChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::ToolRulerIsOn(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::ToolScalingIsOn(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::BlockMoving(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::ZoningMode(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::ValveToolClose()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
