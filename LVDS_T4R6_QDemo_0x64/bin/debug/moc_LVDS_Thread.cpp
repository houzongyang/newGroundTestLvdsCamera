/****************************************************************************
** Meta object code from reading C++ file 'LVDS_Thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LVDS_Thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LVDS_Thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LVDS_Rx_Thead_t {
    QByteArrayData data[9];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LVDS_Rx_Thead_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LVDS_Rx_Thead_t qt_meta_stringdata_LVDS_Rx_Thead = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LVDS_Rx_Thead"
QT_MOC_LITERAL(1, 14, 20), // "DEBUG_Message_Signal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "type"
QT_MOC_LITERAL(4, 41, 3), // "msg"
QT_MOC_LITERAL(5, 45, 20), // "Tx_StreamData_Signal"
QT_MOC_LITERAL(6, 66, 10), // "streamData"
QT_MOC_LITERAL(7, 77, 9), // "NET_Seppd"
QT_MOC_LITERAL(8, 87, 5) // "speed"

    },
    "LVDS_Rx_Thead\0DEBUG_Message_Signal\0\0"
    "type\0msg\0Tx_StreamData_Signal\0streamData\0"
    "NET_Seppd\0speed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LVDS_Rx_Thead[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    1,   34,    2, 0x06 /* Public */,
       7,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void LVDS_Rx_Thead::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LVDS_Rx_Thead *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DEBUG_Message_Signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->Tx_StreamData_Signal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->NET_Seppd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LVDS_Rx_Thead::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LVDS_Rx_Thead::DEBUG_Message_Signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LVDS_Rx_Thead::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LVDS_Rx_Thead::Tx_StreamData_Signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LVDS_Rx_Thead::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LVDS_Rx_Thead::NET_Seppd)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LVDS_Rx_Thead::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_LVDS_Rx_Thead.data,
    qt_meta_data_LVDS_Rx_Thead,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LVDS_Rx_Thead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LVDS_Rx_Thead::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LVDS_Rx_Thead.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int LVDS_Rx_Thead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LVDS_Rx_Thead::DEBUG_Message_Signal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LVDS_Rx_Thead::Tx_StreamData_Signal(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LVDS_Rx_Thead::NET_Seppd(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_ToolCircleBuffer_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolCircleBuffer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolCircleBuffer_t qt_meta_stringdata_ToolCircleBuffer = {
    {
QT_MOC_LITERAL(0, 0, 16) // "ToolCircleBuffer"

    },
    "ToolCircleBuffer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolCircleBuffer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ToolCircleBuffer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ToolCircleBuffer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ToolCircleBuffer.data,
    qt_meta_data_ToolCircleBuffer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ToolCircleBuffer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolCircleBuffer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToolCircleBuffer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ToolCircleBuffer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Dis_Data_Thead_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dis_Data_Thead_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dis_Data_Thead_t qt_meta_stringdata_Dis_Data_Thead = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Dis_Data_Thead"
QT_MOC_LITERAL(1, 15, 22), // "Tx_Picture_Data_Signal"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "frame"
QT_MOC_LITERAL(4, 45, 19), // "Rx_StreamData_Slots"
QT_MOC_LITERAL(5, 65, 10), // "streamData"
QT_MOC_LITERAL(6, 76, 7) // "Cul_FPS"

    },
    "Dis_Data_Thead\0Tx_Picture_Data_Signal\0"
    "\0frame\0Rx_StreamData_Slots\0streamData\0"
    "Cul_FPS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dis_Data_Thead[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,

       0        // eod
};

void Dis_Data_Thead::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dis_Data_Thead *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Tx_Picture_Data_Signal((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->Rx_StreamData_Slots((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->Cul_FPS(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dis_Data_Thead::*)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dis_Data_Thead::Tx_Picture_Data_Signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dis_Data_Thead::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Dis_Data_Thead.data,
    qt_meta_data_Dis_Data_Thead,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dis_Data_Thead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dis_Data_Thead::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dis_Data_Thead.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Dis_Data_Thead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Dis_Data_Thead::Tx_Picture_Data_Signal(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
