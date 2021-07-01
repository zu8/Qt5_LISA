/****************************************************************************
** Meta object code from reading C++ file 'ValveWgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ValveWgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ValveWgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ValveWgt_t {
    QByteArrayData data[25];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ValveWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ValveWgt_t qt_meta_stringdata_ValveWgt = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ValveWgt"
QT_MOC_LITERAL(1, 9, 15), // "ValveToolClosed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "ValveZoneChanged"
QT_MOC_LITERAL(4, 43, 4), // "zone"
QT_MOC_LITERAL(5, 48, 12), // "selectedDiam"
QT_MOC_LITERAL(6, 61, 4), // "role"
QT_MOC_LITERAL(7, 66, 4), // "diam"
QT_MOC_LITERAL(8, 71, 8), // "NewValue"
QT_MOC_LITERAL(9, 80, 3), // "Val"
QT_MOC_LITERAL(10, 84, 8), // "newValve"
QT_MOC_LITERAL(11, 93, 4), // "Zone"
QT_MOC_LITERAL(12, 98, 5), // "Model"
QT_MOC_LITERAL(13, 104, 16), // "CloseBtn_Clicked"
QT_MOC_LITERAL(14, 121, 7), // "ChangeZ"
QT_MOC_LITERAL(15, 129, 16), // "DiameterSelected"
QT_MOC_LITERAL(16, 146, 11), // "CalcMLosses"
QT_MOC_LITERAL(17, 158, 11), // "CalcLLosses"
QT_MOC_LITERAL(18, 170, 15), // "CalcOtherLosses"
QT_MOC_LITERAL(19, 186, 10), // "PlaceValve"
QT_MOC_LITERAL(20, 197, 15), // "SetPumpPressure"
QT_MOC_LITERAL(21, 213, 5), // "value"
QT_MOC_LITERAL(22, 219, 17), // "SetNewMLooseValue"
QT_MOC_LITERAL(23, 237, 17), // "SetNewLLooseValue"
QT_MOC_LITERAL(24, 255, 19) // "SetResultPressValue"

    },
    "ValveWgt\0ValveToolClosed\0\0ValveZoneChanged\0"
    "zone\0selectedDiam\0role\0diam\0NewValue\0"
    "Val\0newValve\0Zone\0Model\0CloseBtn_Clicked\0"
    "ChangeZ\0DiameterSelected\0CalcMLosses\0"
    "CalcLLosses\0CalcOtherLosses\0PlaceValve\0"
    "SetPumpPressure\0value\0SetNewMLooseValue\0"
    "SetNewLLooseValue\0SetResultPressValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ValveWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       5,    3,   98,    2, 0x06 /* Public */,
       8,    1,  105,    2, 0x06 /* Public */,
      10,    2,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  113,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,
      20,    1,  120,    2, 0x0a /* Public */,
      22,    1,  123,    2, 0x0a /* Public */,
      23,    1,  126,    2, 0x0a /* Public */,
      24,    1,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    6,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Double,   21,

       0        // eod
};

void ValveWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ValveWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ValveToolClosed(); break;
        case 1: _t->ValveZoneChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->selectedDiam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->NewValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->newValve((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->CloseBtn_Clicked(); break;
        case 6: _t->ChangeZ(); break;
        case 7: _t->DiameterSelected(); break;
        case 8: _t->CalcMLosses(); break;
        case 9: _t->CalcLLosses(); break;
        case 10: _t->CalcOtherLosses(); break;
        case 11: _t->PlaceValve(); break;
        case 12: _t->SetPumpPressure((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->SetNewMLooseValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->SetNewLLooseValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->SetResultPressValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ValveWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ValveWgt::ValveToolClosed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ValveWgt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ValveWgt::ValveZoneChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ValveWgt::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ValveWgt::selectedDiam)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ValveWgt::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ValveWgt::NewValue)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ValveWgt::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ValveWgt::newValve)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ValveWgt::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ValveWgt.data,
    qt_meta_data_ValveWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ValveWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ValveWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ValveWgt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ValveWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ValveWgt::ValveToolClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ValveWgt::ValveZoneChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ValveWgt::selectedDiam(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ValveWgt::NewValue(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ValveWgt::newValve(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
