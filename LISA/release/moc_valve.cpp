/****************************************************************************
** Meta object code from reading C++ file 'valve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../valve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'valve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_valve_t {
    QByteArrayData data[12];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_valve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_valve_t qt_meta_stringdata_valve = {
    {
QT_MOC_LITERAL(0, 0, 5), // "valve"
QT_MOC_LITERAL(1, 6, 12), // "ValveClicked"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "ValveMove"
QT_MOC_LITERAL(4, 30, 4), // "flag"
QT_MOC_LITERAL(5, 35, 10), // "newMLosses"
QT_MOC_LITERAL(6, 46, 3), // "val"
QT_MOC_LITERAL(7, 50, 10), // "newLLosses"
QT_MOC_LITERAL(8, 61, 9), // "newResult"
QT_MOC_LITERAL(9, 71, 9), // "deleteLos"
QT_MOC_LITERAL(10, 81, 12), // "receveLosses"
QT_MOC_LITERAL(11, 94, 4) // "role"

    },
    "valve\0ValveClicked\0\0ValveMove\0flag\0"
    "newMLosses\0val\0newLLosses\0newResult\0"
    "deleteLos\0receveLosses\0role"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_valve[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       7,    1,   58,    2, 0x06 /* Public */,
       8,    1,   61,    2, 0x06 /* Public */,
       9,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QReal,    6,
    QMetaType::Void, QMetaType::QReal,    6,
    QMetaType::Void, QMetaType::QReal,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QReal,   11,    6,

       0        // eod
};

void valve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<valve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ValveClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ValveMove((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->newMLosses((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: _t->newLLosses((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: _t->newResult((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: _t->deleteLos(); break;
        case 6: _t->receveLosses((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (valve::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&valve::ValveClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (valve::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&valve::ValveMove)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (valve::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&valve::newMLosses)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (valve::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&valve::newLLosses)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (valve::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&valve::newResult)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (valve::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&valve::deleteLos)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject valve::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_valve.data,
    qt_meta_data_valve,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *valve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *valve::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_valve.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(this);
    return QObject::qt_metacast(_clname);
}

int valve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void valve::ValveClicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void valve::ValveMove(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void valve::newMLosses(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void valve::newLLosses(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void valve::newResult(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void valve::deleteLos()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
