/****************************************************************************
** Meta object code from reading C++ file 'form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Form_t {
    QByteArrayData data[16];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form_t qt_meta_stringdata_Form = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Form"
QT_MOC_LITERAL(1, 5, 16), // "showGrab_message"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "showUnzoom_message"
QT_MOC_LITERAL(4, 42, 17), // "showParam_message"
QT_MOC_LITERAL(5, 60, 17), // "showstart_message"
QT_MOC_LITERAL(6, 78, 17), // "showCoord_message"
QT_MOC_LITERAL(7, 96, 13), // "QwtPointPolar"
QT_MOC_LITERAL(8, 110, 5), // "point"
QT_MOC_LITERAL(9, 116, 15), // "grabAct_clicked"
QT_MOC_LITERAL(10, 132, 17), // "unzoomAct_clicked"
QT_MOC_LITERAL(11, 150, 16), // "paramAct_clicked"
QT_MOC_LITERAL(12, 167, 16), // "startAct_clicked"
QT_MOC_LITERAL(13, 184, 16), // "coordBtn_clicked"
QT_MOC_LITERAL(14, 201, 14), // "RPMBtn_clicked"
QT_MOC_LITERAL(15, 216, 16) // "powerBtn_clicked"

    },
    "Form\0showGrab_message\0\0showUnzoom_message\0"
    "showParam_message\0showstart_message\0"
    "showCoord_message\0QwtPointPolar\0point\0"
    "grabAct_clicked\0unzoomAct_clicked\0"
    "paramAct_clicked\0startAct_clicked\0"
    "coordBtn_clicked\0RPMBtn_clicked\0"
    "powerBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    1,   78,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,
      14,    0,   86,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Form *_t = static_cast<Form *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showGrab_message(); break;
        case 1: _t->showUnzoom_message(); break;
        case 2: _t->showParam_message(); break;
        case 3: _t->showstart_message(); break;
        case 4: _t->showCoord_message((*reinterpret_cast< const QwtPointPolar(*)>(_a[1]))); break;
        case 5: _t->grabAct_clicked(); break;
        case 6: _t->unzoomAct_clicked(); break;
        case 7: _t->paramAct_clicked(); break;
        case 8: _t->startAct_clicked(); break;
        case 9: _t->coordBtn_clicked(); break;
        case 10: _t->RPMBtn_clicked(); break;
        case 11: _t->powerBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Form::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Form.data,
      qt_meta_data_Form,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Form.stringdata0))
        return static_cast<void*>(const_cast< Form*>(this));
    return QWidget::qt_metacast(_clname);
}

int Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
