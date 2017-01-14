/****************************************************************************
** Meta object code from reading C++ file 'myplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyPlot_t {
    QByteArrayData data[8];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyPlot_t qt_meta_stringdata_MyPlot = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyPlot"
QT_MOC_LITERAL(1, 7, 15), // "changeMarkerPos"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "QwtPointPolar"
QT_MOC_LITERAL(4, 38, 10), // "scanMarker"
QT_MOC_LITERAL(5, 49, 9), // "showCoord"
QT_MOC_LITERAL(6, 59, 12), // "simulateTail"
QT_MOC_LITERAL(7, 72, 18) // "changeScanLineData"

    },
    "MyPlot\0changeMarkerPos\0\0QwtPointPolar\0"
    "scanMarker\0showCoord\0simulateTail\0"
    "changeScanLineData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyPlot *_t = static_cast<MyPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeMarkerPos((*reinterpret_cast< const QwtPointPolar(*)>(_a[1]))); break;
        case 1: _t->scanMarker((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->showCoord((*reinterpret_cast< const QwtPointPolar(*)>(_a[1]))); break;
        case 3: _t->simulateTail(); break;
        case 4: _t->changeScanLineData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyPlot::*_t)(const QwtPointPolar & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPlot::changeMarkerPos)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyPlot::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPlot::scanMarker)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyPlot::*_t)(const QwtPointPolar & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPlot::showCoord)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MyPlot::staticMetaObject = {
    { &QwtPolarPlot::staticMetaObject, qt_meta_stringdata_MyPlot.data,
      qt_meta_data_MyPlot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyPlot.stringdata0))
        return static_cast<void*>(const_cast< MyPlot*>(this));
    return QwtPolarPlot::qt_metacast(_clname);
}

int MyPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPolarPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MyPlot::changeMarkerPos(const QwtPointPolar & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyPlot::scanMarker(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyPlot::showCoord(const QwtPointPolar & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
