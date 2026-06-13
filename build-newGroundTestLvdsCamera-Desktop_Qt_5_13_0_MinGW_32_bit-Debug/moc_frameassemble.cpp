/****************************************************************************
** Meta object code from reading C++ file 'frameassemble.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../newGroundTestLvdsCameraL_ZGG/frameFormat/frameassemble.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frameassemble.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrameAssemble_t {
    QByteArrayData data[41];
    char stringdata0[576];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrameAssemble_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrameAssemble_t qt_meta_stringdata_FrameAssemble = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FrameAssemble"
QT_MOC_LITERAL(1, 14, 19), // "hasSendDSPPackCount"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "totalCount"
QT_MOC_LITERAL(4, 46, 5), // "count"
QT_MOC_LITERAL(5, 52, 20), // "hasSendFPGAPackCount"
QT_MOC_LITERAL(6, 73, 21), // "hasSendRS422PackCount"
QT_MOC_LITERAL(7, 95, 13), // "SendLVDSImage"
QT_MOC_LITERAL(8, 109, 9), // "imageData"
QT_MOC_LITERAL(9, 119, 10), // "imageWidth"
QT_MOC_LITERAL(10, 130, 11), // "imageHeight"
QT_MOC_LITERAL(11, 142, 9), // "imageFlag"
QT_MOC_LITERAL(12, 152, 18), // "SendLVDSFrameInfo1"
QT_MOC_LITERAL(13, 171, 3), // "seq"
QT_MOC_LITERAL(14, 175, 8), // "timeCode"
QT_MOC_LITERAL(15, 184, 3), // "msg"
QT_MOC_LITERAL(16, 188, 18), // "SendLVDSFrameInfo2"
QT_MOC_LITERAL(17, 207, 8), // "frameNum"
QT_MOC_LITERAL(18, 216, 10), // "frameInNum"
QT_MOC_LITERAL(19, 227, 10), // "windowSize"
QT_MOC_LITERAL(20, 238, 19), // "SendLVDSFrameComeIn"
QT_MOC_LITERAL(21, 258, 4), // "type"
QT_MOC_LITERAL(22, 263, 28), // "SendLVDSImageFrameStatusInfo"
QT_MOC_LITERAL(23, 292, 11), // "totalFrames"
QT_MOC_LITERAL(24, 304, 13), // "successFrames"
QT_MOC_LITERAL(25, 318, 12), // "failedFrames"
QT_MOC_LITERAL(26, 331, 26), // "SendLVDSLowFrameStatusInfo"
QT_MOC_LITERAL(27, 358, 13), // "recvRS422Data"
QT_MOC_LITERAL(28, 372, 4), // "data"
QT_MOC_LITERAL(29, 377, 17), // "recvRS422CrCCheck"
QT_MOC_LITERAL(30, 395, 7), // "isRight"
QT_MOC_LITERAL(31, 403, 16), // "sendRS422Respond"
QT_MOC_LITERAL(32, 420, 11), // "QByteArray&"
QT_MOC_LITERAL(33, 432, 25), // "sendRS422TelemetryRequest"
QT_MOC_LITERAL(34, 458, 11), // "lowLVDSData"
QT_MOC_LITERAL(35, 470, 14), // "fpgaBinTimeout"
QT_MOC_LITERAL(36, 485, 18), // "LVDSCardDataRecved"
QT_MOC_LITERAL(37, 504, 7), // "channel"
QT_MOC_LITERAL(38, 512, 19), // "RS422CardDataRecved"
QT_MOC_LITERAL(39, 532, 25), // "RS422CardDataRecvedSerial"
QT_MOC_LITERAL(40, 558, 17) // "CANCardDataRecved"

    },
    "FrameAssemble\0hasSendDSPPackCount\0\0"
    "totalCount\0count\0hasSendFPGAPackCount\0"
    "hasSendRS422PackCount\0SendLVDSImage\0"
    "imageData\0imageWidth\0imageHeight\0"
    "imageFlag\0SendLVDSFrameInfo1\0seq\0"
    "timeCode\0msg\0SendLVDSFrameInfo2\0"
    "frameNum\0frameInNum\0windowSize\0"
    "SendLVDSFrameComeIn\0type\0"
    "SendLVDSImageFrameStatusInfo\0totalFrames\0"
    "successFrames\0failedFrames\0"
    "SendLVDSLowFrameStatusInfo\0recvRS422Data\0"
    "data\0recvRS422CrCCheck\0isRight\0"
    "sendRS422Respond\0QByteArray&\0"
    "sendRS422TelemetryRequest\0lowLVDSData\0"
    "fpgaBinTimeout\0LVDSCardDataRecved\0"
    "channel\0RS422CardDataRecved\0"
    "RS422CardDataRecvedSerial\0CANCardDataRecved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrameAssemble[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  114,    2, 0x06 /* Public */,
       5,    2,  119,    2, 0x06 /* Public */,
       6,    2,  124,    2, 0x06 /* Public */,
       7,    4,  129,    2, 0x06 /* Public */,
      12,    2,  138,    2, 0x06 /* Public */,
      12,    1,  143,    2, 0x06 /* Public */,
      16,    3,  146,    2, 0x06 /* Public */,
      20,    1,  153,    2, 0x06 /* Public */,
      22,    3,  156,    2, 0x06 /* Public */,
      26,    3,  163,    2, 0x06 /* Public */,
      27,    1,  170,    2, 0x06 /* Public */,
      29,    1,  173,    2, 0x06 /* Public */,
      31,    1,  176,    2, 0x06 /* Public */,
      33,    1,  179,    2, 0x06 /* Public */,
      34,    1,  182,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      35,    0,  185,    2, 0x0a /* Public */,
      36,    2,  186,    2, 0x0a /* Public */,
      38,    2,  191,    2, 0x0a /* Public */,
      39,    1,  196,    2, 0x0a /* Public */,
      40,    2,  199,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int, QMetaType::Int, QMetaType::QString,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   13,   14,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   23,   24,   25,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   23,   24,   25,
    QMetaType::Void, QMetaType::QByteArray,   28,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, 0x80000000 | 32,   28,
    QMetaType::Void, 0x80000000 | 32,   28,
    QMetaType::Void, QMetaType::QByteArray,   28,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   37,   28,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   37,   28,
    QMetaType::Void, QMetaType::QByteArray,   28,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,   37,   28,

       0        // eod
};

void FrameAssemble::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrameAssemble *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hasSendDSPPackCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->hasSendFPGAPackCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->hasSendRS422PackCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->SendLVDSImage((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->SendLVDSFrameInfo1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->SendLVDSFrameInfo1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->SendLVDSFrameInfo2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->SendLVDSFrameComeIn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->SendLVDSImageFrameStatusInfo((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 9: _t->SendLVDSLowFrameStatusInfo((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 10: _t->recvRS422Data((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 11: _t->recvRS422CrCCheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->sendRS422Respond((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 13: _t->sendRS422TelemetryRequest((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 14: _t->lowLVDSData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 15: _t->fpgaBinTimeout(); break;
        case 16: _t->LVDSCardDataRecved((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 17: _t->RS422CardDataRecved((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 18: _t->RS422CardDataRecvedSerial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 19: _t->CANCardDataRecved((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrameAssemble::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::hasSendDSPPackCount)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::hasSendFPGAPackCount)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::hasSendRS422PackCount)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(QByteArray , int , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::SendLVDSImage)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::SendLVDSFrameInfo1)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::SendLVDSFrameInfo1)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::SendLVDSFrameInfo2)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::SendLVDSFrameComeIn)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(quint32 , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::SendLVDSImageFrameStatusInfo)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(quint32 , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::SendLVDSLowFrameStatusInfo)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::recvRS422Data)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::recvRS422CrCCheck)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::sendRS422Respond)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::sendRS422TelemetryRequest)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (FrameAssemble::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrameAssemble::lowLVDSData)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrameAssemble::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_FrameAssemble.data,
    qt_meta_data_FrameAssemble,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrameAssemble::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrameAssemble::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrameAssemble.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FrameAssemble::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void FrameAssemble::hasSendDSPPackCount(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FrameAssemble::hasSendFPGAPackCount(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FrameAssemble::hasSendRS422PackCount(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FrameAssemble::SendLVDSImage(QByteArray _t1, int _t2, int _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FrameAssemble::SendLVDSFrameInfo1(int _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FrameAssemble::SendLVDSFrameInfo1(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void FrameAssemble::SendLVDSFrameInfo2(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void FrameAssemble::SendLVDSFrameComeIn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void FrameAssemble::SendLVDSImageFrameStatusInfo(quint32 _t1, quint32 _t2, quint32 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void FrameAssemble::SendLVDSLowFrameStatusInfo(quint32 _t1, quint32 _t2, quint32 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void FrameAssemble::recvRS422Data(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void FrameAssemble::recvRS422CrCCheck(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void FrameAssemble::sendRS422Respond(QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void FrameAssemble::sendRS422TelemetryRequest(QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void FrameAssemble::lowLVDSData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
