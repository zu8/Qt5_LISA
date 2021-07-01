/****************************************************************************
** Meta object code from reading C++ file 'SprinklerWgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SprinklerWgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SprinklerWgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SprinklerWgt_t {
    QByteArrayData data[13];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SprinklerWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SprinklerWgt_t qt_meta_stringdata_SprinklerWgt = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SprinklerWgt"
QT_MOC_LITERAL(1, 13, 12), // "newSprinkler"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "Radius"
QT_MOC_LITERAL(4, 34, 4), // "Flow"
QT_MOC_LITERAL(5, 39, 3), // "Art"
QT_MOC_LITERAL(6, 43, 8), // "bodyType"
QT_MOC_LITERAL(7, 52, 19), // "currentIndexChanged"
QT_MOC_LITERAL(8, 72, 16), // "sprinklerClicked"
QT_MOC_LITERAL(9, 89, 19), // "sprinklerToolClosed"
QT_MOC_LITERAL(10, 109, 9), // "showPosts"
QT_MOC_LITERAL(11, 119, 18), // "ButtonCncl_Clicked"
QT_MOC_LITERAL(12, 138, 17) // "ButtonAdd_Clicked"

    },
    "SprinklerWgt\0newSprinkler\0\0Radius\0"
    "Flow\0Art\0bodyType\0currentIndexChanged\0"
    "sprinklerClicked\0sprinklerToolClosed\0"
    "showPosts\0ButtonCncl_Clicked\0"
    "ButtonAdd_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SprinklerWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x06 /* Public */,
       7,    1,   58,    2, 0x06 /* Public */,
       8,    0,   61,    2, 0x06 /* Public */,
       9,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   63,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QReal, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SprinklerWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SprinklerWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newSprinkler((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sprinklerClicked(); break;
        case 3: _t->sprinklerToolClosed(); break;
        case 4: _t->showPosts(); break;
        case 5: _t->ButtonCncl_Clicked(); break;
        case 6: _t->ButtonAdd_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SprinklerWgt::*)(int , qreal , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SprinklerWgt::newSprinkler)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SprinklerWgt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SprinklerWgt::currentIndexChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SprinklerWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SprinklerWgt::sprinklerClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SprinklerWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SprinklerWgt::sprinklerToolClosed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SprinklerWgt::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SprinklerWgt.data,
    qt_meta_data_SprinklerWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SprinklerWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SprinklerWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SprinklerWgt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SprinklerWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void SprinklerWgt::newSprinkler(int _t1, qreal _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SprinklerWgt::currentIndexChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SprinklerWgt::sprinklerClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SprinklerWgt::sprinklerToolClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
