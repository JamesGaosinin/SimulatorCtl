/****************************************************************************
** Meta object code from reading C++ file 'SensingWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/SensingWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SensingWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSensingWidget_t {
    QByteArrayData data[9];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSensingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSensingWidget_t qt_meta_stringdata_CSensingWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CSensingWidget"
QT_MOC_LITERAL(1, 15, 6), // "Sig_Up"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "Sig_Down"
QT_MOC_LITERAL(4, 32, 8), // "Sig_Left"
QT_MOC_LITERAL(5, 41, 9), // "Sig_Right"
QT_MOC_LITERAL(6, 51, 8), // "Sig_High"
QT_MOC_LITERAL(7, 60, 7), // "Sig_Low"
QT_MOC_LITERAL(8, 68, 15) // "Slot_BtnClicked"

    },
    "CSensingWidget\0Sig_Up\0\0Sig_Down\0"
    "Sig_Left\0Sig_Right\0Sig_High\0Sig_Low\0"
    "Slot_BtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSensingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CSensingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSensingWidget *_t = static_cast<CSensingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Sig_Up(); break;
        case 1: _t->Sig_Down(); break;
        case 2: _t->Sig_Left(); break;
        case 3: _t->Sig_Right(); break;
        case 4: _t->Sig_High(); break;
        case 5: _t->Sig_Low(); break;
        case 6: _t->Slot_BtnClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSensingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensingWidget::Sig_Up)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CSensingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensingWidget::Sig_Down)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CSensingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensingWidget::Sig_Left)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CSensingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensingWidget::Sig_Right)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CSensingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensingWidget::Sig_High)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CSensingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSensingWidget::Sig_Low)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CSensingWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CSensingWidget.data,
      qt_meta_data_CSensingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSensingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSensingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSensingWidget.stringdata0))
        return static_cast<void*>(const_cast< CSensingWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CSensingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CSensingWidget::Sig_Up()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CSensingWidget::Sig_Down()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CSensingWidget::Sig_Left()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CSensingWidget::Sig_Right()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void CSensingWidget::Sig_High()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CSensingWidget::Sig_Low()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
