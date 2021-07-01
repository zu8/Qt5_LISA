/****************************************************************************
** Meta object code from reading C++ file 'LISA_View.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../LISA_View.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LISA_View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LISA_View_t {
    QByteArrayData data[9];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LISA_View_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LISA_View_t qt_meta_stringdata_LISA_View = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LISA_View"
QT_MOC_LITERAL(1, 10, 8), // "mousePos"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 19), // "selectionRectSquare"
QT_MOC_LITERAL(4, 40, 15), // "rulerIsSituated"
QT_MOC_LITERAL(5, 56, 14), // "rulerDisappear"
QT_MOC_LITERAL(6, 71, 19), // "NoNeedSelectionRect"
QT_MOC_LITERAL(7, 91, 11), // "rulerToolOn"
QT_MOC_LITERAL(8, 103, 11) // "scaleToolOn"

    },
    "LISA_View\0mousePos\0\0selectionRectSquare\0"
    "rulerIsSituated\0rulerDisappear\0"
    "NoNeedSelectionRect\0rulerToolOn\0"
    "scaleToolOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LISA_View[] = {

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
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   61,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       8,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void, QMetaType::QRectF,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void LISA_View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LISA_View *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePos((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->selectionRectSquare((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 2: _t->rulerIsSituated((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->rulerDisappear((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->NoNeedSelectionRect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->rulerToolOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->scaleToolOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LISA_View::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LISA_View::mousePos)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LISA_View::*)(QRectF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LISA_View::selectionRectSquare)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LISA_View::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LISA_View::rulerIsSituated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LISA_View::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LISA_View::rulerDisappear)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LISA_View::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_LISA_View.data,
    qt_meta_data_LISA_View,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LISA_View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LISA_View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LISA_View.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int LISA_View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
void LISA_View::mousePos(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LISA_View::selectionRectSquare(QRectF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LISA_View::rulerIsSituated(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LISA_View::rulerDisappear(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
