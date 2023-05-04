/****************************************************************************
** Meta object code from reading C++ file 'SimulationPlatform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/SimulationPlatform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimulationPlatform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSimulationPlatform_t {
    QByteArrayData data[27];
    char stringdata0[405];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSimulationPlatform_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSimulationPlatform_t qt_meta_stringdata_CSimulationPlatform = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CSimulationPlatform"
QT_MOC_LITERAL(1, 20, 21), // "Sig_DoadStatusChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "cStatus"
QT_MOC_LITERAL(4, 51, 22), // "Sig_StatusTimerRestart"
QT_MOC_LITERAL(5, 74, 23), // "Slot_StatusTimerRestart"
QT_MOC_LITERAL(6, 98, 22), // "Slot_UpDownTypeChanged"
QT_MOC_LITERAL(7, 121, 28), // "E_SimulationFlat_UpDown_Type"
QT_MOC_LITERAL(8, 150, 5), // "eType"
QT_MOC_LITERAL(9, 156, 17), // "Slot_SpeedChanged"
QT_MOC_LITERAL(10, 174, 6), // "fSpeed"
QT_MOC_LITERAL(11, 181, 20), // "Slot_PositionChanged"
QT_MOC_LITERAL(12, 202, 7), // "fCurGLB"
QT_MOC_LITERAL(13, 210, 18), // "Slot_VectorChanged"
QT_MOC_LITERAL(14, 229, 24), // "_3Dcmd::SimulatiorVector"
QT_MOC_LITERAL(15, 254, 8), // "stVector"
QT_MOC_LITERAL(16, 263, 22), // "Slot_BoadStatusChanged"
QT_MOC_LITERAL(17, 286, 20), // "Slot_AccBrakeChanged"
QT_MOC_LITERAL(18, 307, 4), // "nAcc"
QT_MOC_LITERAL(19, 312, 6), // "nBrake"
QT_MOC_LITERAL(20, 319, 19), // "Slot_RunModeChanged"
QT_MOC_LITERAL(21, 339, 5), // "nMode"
QT_MOC_LITERAL(22, 345, 14), // "Slot_EbChanged"
QT_MOC_LITERAL(23, 360, 3), // "nEb"
QT_MOC_LITERAL(24, 364, 15), // "Slot_DirChanged"
QT_MOC_LITERAL(25, 380, 4), // "nDir"
QT_MOC_LITERAL(26, 385, 19) // "Slot_RunModeTimeout"

    },
    "CSimulationPlatform\0Sig_DoadStatusChanged\0"
    "\0cStatus\0Sig_StatusTimerRestart\0"
    "Slot_StatusTimerRestart\0Slot_UpDownTypeChanged\0"
    "E_SimulationFlat_UpDown_Type\0eType\0"
    "Slot_SpeedChanged\0fSpeed\0Slot_PositionChanged\0"
    "fCurGLB\0Slot_VectorChanged\0"
    "_3Dcmd::SimulatiorVector\0stVector\0"
    "Slot_BoadStatusChanged\0Slot_AccBrakeChanged\0"
    "nAcc\0nBrake\0Slot_RunModeChanged\0nMode\0"
    "Slot_EbChanged\0nEb\0Slot_DirChanged\0"
    "nDir\0Slot_RunModeTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSimulationPlatform[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   83,    2, 0x0a /* Public */,
       6,    1,   84,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      13,    1,   93,    2, 0x0a /* Public */,
      16,    1,   96,    2, 0x0a /* Public */,
      17,    2,   99,    2, 0x0a /* Public */,
      20,    1,  104,    2, 0x0a /* Public */,
      22,    1,  107,    2, 0x0a /* Public */,
      24,    1,  110,    2, 0x0a /* Public */,
      26,    0,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void, QMetaType::Float,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   18,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,

       0        // eod
};

void CSimulationPlatform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSimulationPlatform *_t = static_cast<CSimulationPlatform *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Sig_DoadStatusChanged((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 1: _t->Sig_StatusTimerRestart(); break;
        case 2: _t->Slot_StatusTimerRestart(); break;
        case 3: _t->Slot_UpDownTypeChanged((*reinterpret_cast< E_SimulationFlat_UpDown_Type(*)>(_a[1]))); break;
        case 4: _t->Slot_SpeedChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->Slot_PositionChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->Slot_VectorChanged((*reinterpret_cast< const _3Dcmd::SimulatiorVector(*)>(_a[1]))); break;
        case 7: _t->Slot_BoadStatusChanged((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 8: _t->Slot_AccBrakeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->Slot_RunModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->Slot_EbChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->Slot_DirChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->Slot_RunModeTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSimulationPlatform::*_t)(unsigned char );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSimulationPlatform::Sig_DoadStatusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CSimulationPlatform::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSimulationPlatform::Sig_StatusTimerRestart)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CSimulationPlatform::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CSimulationPlatform.data,
      qt_meta_data_CSimulationPlatform,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSimulationPlatform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSimulationPlatform::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSimulationPlatform.stringdata0))
        return static_cast<void*>(const_cast< CSimulationPlatform*>(this));
    return QObject::qt_metacast(_clname);
}

int CSimulationPlatform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void CSimulationPlatform::Sig_DoadStatusChanged(unsigned char _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CSimulationPlatform::Sig_StatusTimerRestart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
