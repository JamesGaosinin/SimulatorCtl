/****************************************************************************
** Meta object code from reading C++ file 'EffectsManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/EffectsManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EffectsManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CEffectsManager_t {
    QByteArrayData data[10];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CEffectsManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CEffectsManager_t qt_meta_stringdata_CEffectsManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CEffectsManager"
QT_MOC_LITERAL(1, 16, 13), // "StartAccTimer"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "StartSwingTimer"
QT_MOC_LITERAL(4, 47, 18), // "Slot_EffectTrigger"
QT_MOC_LITERAL(5, 66, 22), // "Slot_TimerAccTriggered"
QT_MOC_LITERAL(6, 89, 24), // "Slot_TimerSwingTriggered"
QT_MOC_LITERAL(7, 114, 25), // "Slot_TimerResumeTriggered"
QT_MOC_LITERAL(8, 140, 18), // "Slot_StartAccTimer"
QT_MOC_LITERAL(9, 159, 20) // "Slot_StartSwingTimer"

    },
    "CEffectsManager\0StartAccTimer\0\0"
    "StartSwingTimer\0Slot_EffectTrigger\0"
    "Slot_TimerAccTriggered\0Slot_TimerSwingTriggered\0"
    "Slot_TimerResumeTriggered\0Slot_StartAccTimer\0"
    "Slot_StartSwingTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CEffectsManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CEffectsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CEffectsManager *_t = static_cast<CEffectsManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StartAccTimer(); break;
        case 1: _t->StartSwingTimer(); break;
        case 2: _t->Slot_EffectTrigger(); break;
        case 3: _t->Slot_TimerAccTriggered(); break;
        case 4: _t->Slot_TimerSwingTriggered(); break;
        case 5: _t->Slot_TimerResumeTriggered(); break;
        case 6: _t->Slot_StartAccTimer(); break;
        case 7: _t->Slot_StartSwingTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CEffectsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEffectsManager::StartAccTimer)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CEffectsManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CEffectsManager::StartSwingTimer)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CEffectsManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CEffectsManager.data,
      qt_meta_data_CEffectsManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CEffectsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CEffectsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CEffectsManager.stringdata0))
        return static_cast<void*>(const_cast< CEffectsManager*>(this));
    return QObject::qt_metacast(_clname);
}

int CEffectsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CEffectsManager::StartAccTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CEffectsManager::StartSwingTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
