/****************************************************************************
** Meta object code from reading C++ file 'mymarker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mymarker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymarker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyMarker_t {
    QByteArrayData data[10];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyMarker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyMarker_t qt_meta_stringdata_MyMarker = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyMarker"
QT_MOC_LITERAL(1, 9, 14), // "changePosition"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "QwtPointPolar"
QT_MOC_LITERAL(4, 39, 3), // "pos"
QT_MOC_LITERAL(5, 43, 6), // "scaned"
QT_MOC_LITERAL(6, 50, 8), // "isscaned"
QT_MOC_LITERAL(7, 59, 8), // "setLabel"
QT_MOC_LITERAL(8, 68, 18), // "QMap<QString,bool>"
QT_MOC_LITERAL(9, 87, 7) // "choises"

    },
    "MyMarker\0changePosition\0\0QwtPointPolar\0"
    "pos\0scaned\0isscaned\0setLabel\0"
    "QMap<QString,bool>\0choises"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMarker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       7,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void MyMarker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyMarker *_t = static_cast<MyMarker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changePosition((*reinterpret_cast< const QwtPointPolar(*)>(_a[1]))); break;
        case 1: _t->scaned((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setLabel((*reinterpret_cast< const QMap<QString,bool>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MyMarker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyMarker.data,
      qt_meta_data_MyMarker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyMarker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyMarker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyMarker.stringdata0))
        return static_cast<void*>(const_cast< MyMarker*>(this));
    return QObject::qt_metacast(_clname);
}

int MyMarker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
