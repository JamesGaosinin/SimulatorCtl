/****************************************************************************
** Meta object code from reading C++ file 'NetWorkManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/NetWorkManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetWorkManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CNetWorkManager_t {
    QByteArrayData data[24];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CNetWorkManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CNetWorkManager_t qt_meta_stringdata_CNetWorkManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CNetWorkManager"
QT_MOC_LITERAL(1, 16, 21), // "Sig_UpDownTypeChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 28), // "E_SimulationFlat_UpDown_Type"
QT_MOC_LITERAL(4, 68, 5), // "eType"
QT_MOC_LITERAL(5, 74, 16), // "Sig_SpeedChanged"
QT_MOC_LITERAL(6, 91, 6), // "fSpeed"
QT_MOC_LITERAL(7, 98, 19), // "Sig_PositionChanged"
QT_MOC_LITERAL(8, 118, 7), // "fCurGLB"
QT_MOC_LITERAL(9, 126, 17), // "Sig_VectorChanged"
QT_MOC_LITERAL(10, 144, 24), // "_3Dcmd::SimulatiorVector"
QT_MOC_LITERAL(11, 169, 8), // "stVector"
QT_MOC_LITERAL(12, 178, 21), // "Sig_BoadStatusChanged"
QT_MOC_LITERAL(13, 200, 7), // "cStatus"
QT_MOC_LITERAL(14, 208, 19), // "Sig_AccBrakeChanged"
QT_MOC_LITERAL(15, 228, 9), // "nAccLevel"
QT_MOC_LITERAL(16, 238, 11), // "nBrakeLevel"
QT_MOC_LITERAL(17, 250, 11), // "Sig_RunMode"
QT_MOC_LITERAL(18, 262, 5), // "nMode"
QT_MOC_LITERAL(19, 268, 6), // "Sig_Eb"
QT_MOC_LITERAL(20, 275, 3), // "nEb"
QT_MOC_LITERAL(21, 279, 7), // "Sig_Dir"
QT_MOC_LITERAL(22, 287, 18), // "Slot_StatusChanged"
QT_MOC_LITERAL(23, 306, 7) // "nStatus"

    },
    "CNetWorkManager\0Sig_UpDownTypeChanged\0"
    "\0E_SimulationFlat_UpDown_Type\0eType\0"
    "Sig_SpeedChanged\0fSpeed\0Sig_PositionChanged\0"
    "fCurGLB\0Sig_VectorChanged\0"
    "_3Dcmd::SimulatiorVector\0stVector\0"
    "Sig_BoadStatusChanged\0cStatus\0"
    "Sig_AccBrakeChanged\0nAccLevel\0nBrakeLevel\0"
    "Sig_RunMode\0nMode\0Sig_Eb\0nEb\0Sig_Dir\0"
    "Slot_StatusChanged\0nStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CNetWorkManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       9,    1,   73,    2, 0x06 /* Public */,
      12,    1,   76,    2, 0x06 /* Public */,
      14,    2,   79,    2, 0x06 /* Public */,
      17,    1,   84,    2, 0x06 /* Public */,
      19,    1,   87,    2, 0x06 /* Public */,
      21,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    1,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Float,    6,
    QMetaType::Void, QMetaType::Float,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::UChar,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void CNetWorkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CNetWorkManager *_t = static_cast<CNetWorkManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Sig_UpDownTypeChanged((*reinterpret_cast< E_SimulationFlat_UpDown_Type(*)>(_a[1]))); break;
        case 1: _t->Sig_SpeedChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->Sig_PositionChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->Sig_VectorChanged((*reinterpret_cast< const _3Dcmd::SimulatiorVector(*)>(_a[1]))); break;
        case 4: _t->Sig_BoadStatusChanged((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 5: _t->Sig_AccBrakeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->Sig_RunMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->Sig_Eb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->Sig_Dir((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->Slot_StatusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< E_SimulationFlat_UpDown_Type >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< _3Dcmd::SimulatiorVector >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CNetWorkManager::*_t)(E_SimulationFlat_UpDown_Type );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_UpDownTypeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CNetWorkManager::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_SpeedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CNetWorkManager::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_PositionChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CNetWorkManager::*_t)(const _3Dcmd::SimulatiorVector & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_VectorChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CNetWorkManager::*_t)(unsigned char );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_BoadStatusChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CNetWorkManager::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_AccBrakeChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CNetWorkManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_RunMode)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CNetWorkManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_Eb)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (CNetWorkManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CNetWorkManager::Sig_Dir)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject CNetWorkManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CNetWorkManager.data,
      qt_meta_data_CNetWorkManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CNetWorkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CNetWorkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CNetWorkManager.stringdata0))
        return static_cast<void*>(const_cast< CNetWorkManager*>(this));
    return QObject::qt_metacast(_clname);
}

int CNetWorkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CNetWorkManager::Sig_UpDownTypeChanged(E_SimulationFlat_UpDown_Type _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CNetWorkManager::Sig_SpeedChanged(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CNetWorkManager::Sig_PositionChanged(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CNetWorkManager::Sig_VectorChanged(const _3Dcmd::SimulatiorVector & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CNetWorkManager::Sig_BoadStatusChanged(unsigned char _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CNetWorkManager::Sig_AccBrakeChanged(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CNetWorkManager::Sig_RunMode(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CNetWorkManager::Sig_Eb(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CNetWorkManager::Sig_Dir(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
