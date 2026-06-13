/****************************************************************************
** Meta object code from reading C++ file 'cardmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../newGroundTestLvdsCameraL_ZGG/frameFormat/cardmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CardManager_t {
    QByteArrayData data[12];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CardManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CardManager_t qt_meta_stringdata_CardManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CardManager"
QT_MOC_LITERAL(1, 12, 15), // "onLVDSDataReady"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 7), // "channel"
QT_MOC_LITERAL(4, 37, 4), // "data"
QT_MOC_LITERAL(5, 42, 16), // "onRS422DataReady"
QT_MOC_LITERAL(6, 59, 14), // "onCanDataReady"
QT_MOC_LITERAL(7, 74, 8), // "errorMsg"
QT_MOC_LITERAL(8, 83, 24), // "LVDSCardHelper::CardType"
QT_MOC_LITERAL(9, 108, 4), // "type"
QT_MOC_LITERAL(10, 113, 3), // "msg"
QT_MOC_LITERAL(11, 117, 11) // "RunErrorMsg"

    },
    "CardManager\0onLVDSDataReady\0\0channel\0"
    "data\0onRS422DataReady\0onCanDataReady\0"
    "errorMsg\0LVDSCardHelper::CardType\0"
    "type\0msg\0RunErrorMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CardManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    2,   44,    2, 0x06 /* Public */,
       6,    2,   49,    2, 0x06 /* Public */,
       7,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void CardManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CardManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onLVDSDataReady((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->onRS422DataReady((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->onCanDataReady((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 3: _t->errorMsg((*reinterpret_cast< LVDSCardHelper::CardType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->RunErrorMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CardManager::*)(quint8 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardManager::onLVDSDataReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CardManager::*)(quint8 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardManager::onRS422DataReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CardManager::*)(quint8 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardManager::onCanDataReady)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CardManager::*)(LVDSCardHelper::CardType , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardManager::errorMsg)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CardManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CardManager.data,
    qt_meta_data_CardManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CardManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CardManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CardManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void CardManager::onLVDSDataReady(quint8 _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CardManager::onRS422DataReady(quint8 _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CardManager::onCanDataReady(quint8 _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CardManager::errorMsg(LVDSCardHelper::CardType _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
