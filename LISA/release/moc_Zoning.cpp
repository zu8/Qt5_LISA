/****************************************************************************
** Meta object code from reading C++ file 'Zoning.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Zoning.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Zoning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Zoning_t {
    QByteArrayData data[15];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Zoning_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Zoning_t qt_meta_stringdata_Zoning = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Zoning"
QT_MOC_LITERAL(1, 7, 11), // "textChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "coreChange"
QT_MOC_LITERAL(4, 31, 12), // "newFlowValue"
QT_MOC_LITERAL(5, 44, 12), // "SelectedBody"
QT_MOC_LITERAL(6, 57, 5), // "Core*"
QT_MOC_LITERAL(7, 63, 8), // "crntBody"
QT_MOC_LITERAL(8, 72, 13), // "changeZnumber"
QT_MOC_LITERAL(9, 86, 3), // "num"
QT_MOC_LITERAL(10, 90, 16), // "AddFlowSprinkler"
QT_MOC_LITERAL(11, 107, 19), // "RemoveFlowSprinkler"
QT_MOC_LITERAL(12, 127, 8), // "UserFlow"
QT_MOC_LITERAL(13, 136, 2), // "DC"
QT_MOC_LITERAL(14, 139, 2) // "Pr"

    },
    "Zoning\0textChanged\0\0coreChange\0"
    "newFlowValue\0SelectedBody\0Core*\0"
    "crntBody\0changeZnumber\0num\0AddFlowSprinkler\0"
    "RemoveFlowSprinkler\0UserFlow\0DC\0Pr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Zoning[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       4,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   61,    2, 0x0a /* Public */,
       8,    1,   64,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    2,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   13,   14,

       0        // eod
};

void Zoning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Zoning *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textChanged(); break;
        case 1: _t->coreChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->newFlowValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->SelectedBody((*reinterpret_cast< Core*(*)>(_a[1]))); break;
        case 4: _t->changeZnumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->AddFlowSprinkler(); break;
        case 6: _t->RemoveFlowSprinkler(); break;
        case 7: _t->UserFlow((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Zoning::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Zoning::textChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Zoning::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Zoning::coreChange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Zoning::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Zoning::newFlowValue)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Zoning::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Zoning.data,
    qt_meta_data_Zoning,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Zoning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Zoning::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Zoning.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Zoning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Zoning::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Zoning::coreChange(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Zoning::newFlowValue(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
