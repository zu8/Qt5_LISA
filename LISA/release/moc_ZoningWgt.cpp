/****************************************************************************
** Meta object code from reading C++ file 'ZoningWgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ZoningWgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZoningWgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZoningWgt_t {
    QByteArrayData data[20];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZoningWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZoningWgt_t qt_meta_stringdata_ZoningWgt = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ZoningWgt"
QT_MOC_LITERAL(1, 10, 11), // "ZoneChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "textChanged"
QT_MOC_LITERAL(4, 35, 10), // "coreChange"
QT_MOC_LITERAL(5, 46, 4), // "data"
QT_MOC_LITERAL(6, 51, 16), // "zoningToolClosed"
QT_MOC_LITERAL(7, 68, 14), // "AddBtn_Clicked"
QT_MOC_LITERAL(8, 83, 17), // "RemoveBtn_Clicked"
QT_MOC_LITERAL(9, 101, 11), // "flowUpdated"
QT_MOC_LITERAL(10, 113, 15), // "SetNewFlowValue"
QT_MOC_LITERAL(11, 129, 5), // "value"
QT_MOC_LITERAL(12, 135, 16), // "setRecommendFlow"
QT_MOC_LITERAL(13, 152, 2), // "fl"
QT_MOC_LITERAL(14, 155, 2), // "Pr"
QT_MOC_LITERAL(15, 158, 5), // "clear"
QT_MOC_LITERAL(16, 164, 10), // "insertText"
QT_MOC_LITERAL(17, 175, 4), // "text"
QT_MOC_LITERAL(18, 180, 16), // "CloseBtn_Clicked"
QT_MOC_LITERAL(19, 197, 7) // "ChangeZ"

    },
    "ZoningWgt\0ZoneChanged\0\0textChanged\0"
    "coreChange\0data\0zoningToolClosed\0"
    "AddBtn_Clicked\0RemoveBtn_Clicked\0"
    "flowUpdated\0SetNewFlowValue\0value\0"
    "setRecommendFlow\0fl\0Pr\0clear\0insertText\0"
    "text\0CloseBtn_Clicked\0ChangeZ"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZoningWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    0,   82,    2, 0x06 /* Public */,
       4,    1,   83,    2, 0x06 /* Public */,
       6,    0,   86,    2, 0x06 /* Public */,
       7,    0,   87,    2, 0x06 /* Public */,
       8,    0,   88,    2, 0x06 /* Public */,
       9,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   90,    2, 0x0a /* Public */,
      12,    2,   93,    2, 0x0a /* Public */,
      15,    0,   98,    2, 0x0a /* Public */,
      16,    1,   99,    2, 0x0a /* Public */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ZoningWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZoningWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ZoneChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->textChanged(); break;
        case 2: _t->coreChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->zoningToolClosed(); break;
        case 4: _t->AddBtn_Clicked(); break;
        case 5: _t->RemoveBtn_Clicked(); break;
        case 6: _t->flowUpdated(); break;
        case 7: _t->SetNewFlowValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setRecommendFlow((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 9: _t->clear(); break;
        case 10: _t->insertText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->CloseBtn_Clicked(); break;
        case 12: _t->ChangeZ(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZoningWgt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZoningWgt::ZoneChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZoningWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZoningWgt::textChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ZoningWgt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZoningWgt::coreChange)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ZoningWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZoningWgt::zoningToolClosed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ZoningWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZoningWgt::AddBtn_Clicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ZoningWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZoningWgt::RemoveBtn_Clicked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ZoningWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZoningWgt::flowUpdated)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ZoningWgt::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZoningWgt.data,
    qt_meta_data_ZoningWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ZoningWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZoningWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZoningWgt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ZoningWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ZoningWgt::ZoneChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZoningWgt::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ZoningWgt::coreChange(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ZoningWgt::zoningToolClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ZoningWgt::AddBtn_Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ZoningWgt::RemoveBtn_Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ZoningWgt::flowUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
