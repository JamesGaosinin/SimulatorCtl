/****************************************************************************
** Meta object code from reading C++ file 'SimulatorCtl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/SimulatorCtl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimulatorCtl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSimulatorCtl_t {
    QByteArrayData data[15];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSimulatorCtl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSimulatorCtl_t qt_meta_stringdata_CSimulatorCtl = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CSimulatorCtl"
QT_MOC_LITERAL(1, 14, 7), // "Slot_Up"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "Slot_Down"
QT_MOC_LITERAL(4, 33, 9), // "Slot_Left"
QT_MOC_LITERAL(5, 43, 10), // "Slot_Right"
QT_MOC_LITERAL(6, 54, 9), // "Slot_High"
QT_MOC_LITERAL(7, 64, 8), // "Slot_Low"
QT_MOC_LITERAL(8, 73, 22), // "Slot_BoadStatusChanged"
QT_MOC_LITERAL(9, 96, 7), // "cStatus"
QT_MOC_LITERAL(10, 104, 21), // "Slot_BtnStatusClicked"
QT_MOC_LITERAL(11, 126, 11), // "Slot_Update"
QT_MOC_LITERAL(12, 138, 17), // "Slot_SendCtrlData"
QT_MOC_LITERAL(13, 156, 16), // "Slot_MileChanged"
QT_MOC_LITERAL(14, 173, 16) // "Slot_AppShutDown"

    },
    "CSimulatorCtl\0Slot_Up\0\0Slot_Down\0"
    "Slot_Left\0Slot_Right\0Slot_High\0Slot_Low\0"
    "Slot_BoadStatusChanged\0cStatus\0"
    "Slot_BtnStatusClicked\0Slot_Update\0"
    "Slot_SendCtrlData\0Slot_MileChanged\0"
    "Slot_AppShutDown"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSimulatorCtl[] = {

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
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    1,   80,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CSimulatorCtl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSimulatorCtl *_t = static_cast<CSimulatorCtl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Slot_Up(); break;
        case 1: _t->Slot_Down(); break;
        case 2: _t->Slot_Left(); break;
        case 3: _t->Slot_Right(); break;
        case 4: _t->Slot_High(); break;
        case 5: _t->Slot_Low(); break;
        case 6: _t->Slot_BoadStatusChanged((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 7: _t->Slot_BtnStatusClicked(); break;
        case 8: _t->Slot_Update(); break;
        case 9: _t->Slot_SendCtrlData(); break;
        case 10: _t->Slot_MileChanged(); break;
        case 11: _t->Slot_AppShutDown(); break;
        default: ;
        }
    }
}

const QMetaObject CSimulatorCtl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CSimulatorCtl.data,
      qt_meta_data_CSimulatorCtl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSimulatorCtl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSimulatorCtl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSimulatorCtl.stringdata0))
        return static_cast<void*>(const_cast< CSimulatorCtl*>(this));
    return QWidget::qt_metacast(_clname);
}

int CSimulatorCtl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
