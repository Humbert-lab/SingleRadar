/****************************************************************************
** Meta object code from reading C++ file 'paramdisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../paramdisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paramdisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParamDisplay_t {
    QByteArrayData data[9];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParamDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParamDisplay_t qt_meta_stringdata_ParamDisplay = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ParamDisplay"
QT_MOC_LITERAL(1, 13, 14), // "choisesChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 18), // "QMap<QString,bool>"
QT_MOC_LITERAL(4, 48, 16), // "on_title_clicked"
QT_MOC_LITERAL(5, 65, 24), // "on_pushButton_ok_clicked"
QT_MOC_LITERAL(6, 90, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(7, 119, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(8, 141, 21) // "on_checkBox_3_clicked"

    },
    "ParamDisplay\0choisesChanged\0\0"
    "QMap<QString,bool>\0on_title_clicked\0"
    "on_pushButton_ok_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_checkBox_2_clicked\0on_checkBox_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParamDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ParamDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParamDisplay *_t = static_cast<ParamDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->choisesChanged((*reinterpret_cast< const QMap<QString,bool>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->on_title_clicked(); break;
        case 2: _t->on_pushButton_ok_clicked(); break;
        case 3: _t->on_pushButton_cancel_clicked(); break;
        case 4: _t->on_checkBox_2_clicked(); break;
        case 5: _t->on_checkBox_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (ParamDisplay::*_t)(const QMap<QString,bool> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParamDisplay::choisesChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ParamDisplay::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ParamDisplay.data,
      qt_meta_data_ParamDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParamDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParamDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParamDisplay.stringdata0))
        return static_cast<void*>(const_cast< ParamDisplay*>(this));
    return QDialog::qt_metacast(_clname);
}

int ParamDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
int ParamDisplay::choisesChanged(const QMap<QString,bool> & _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
