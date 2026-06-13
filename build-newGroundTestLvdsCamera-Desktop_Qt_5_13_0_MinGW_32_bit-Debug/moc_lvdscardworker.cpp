/****************************************************************************
** Meta object code from reading C++ file 'lvdscardworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../newGroundTestLvdsCameraL_ZGG/cardModule/lvdscardworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lvdscardworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lvdsCardWorker_t {
    QByteArrayData data[21];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lvdsCardWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lvdsCardWorker_t qt_meta_stringdata_lvdsCardWorker = {
    {
QT_MOC_LITERAL(0, 0, 14), // "lvdsCardWorker"
QT_MOC_LITERAL(1, 15, 21), // "updateBarStatusSignal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 10), // "chooseCard"
QT_MOC_LITERAL(4, 49, 9), // "errorText"
QT_MOC_LITERAL(5, 59, 13), // "stopThreadRec"
QT_MOC_LITERAL(6, 73, 8), // "RunError"
QT_MOC_LITERAL(7, 82, 3), // "msg"
QT_MOC_LITERAL(8, 86, 14), // "onLVDSDataToUi"
QT_MOC_LITERAL(9, 101, 7), // "channel"
QT_MOC_LITERAL(10, 109, 8), // "LVDSData"
QT_MOC_LITERAL(11, 118, 15), // "onRS422DataToUi"
QT_MOC_LITERAL(12, 134, 9), // "RS422Data"
QT_MOC_LITERAL(13, 144, 18), // "onLVDSAnalysisToUi"
QT_MOC_LITERAL(14, 163, 4), // "data"
QT_MOC_LITERAL(15, 168, 19), // "onRS422AnalysisToUi"
QT_MOC_LITERAL(16, 188, 11), // "imageSignal"
QT_MOC_LITERAL(17, 200, 5), // "image"
QT_MOC_LITERAL(18, 206, 12), // "emitRunError"
QT_MOC_LITERAL(19, 219, 12), // "readyReceive"
QT_MOC_LITERAL(20, 232, 13) // "currentCardNo"

    },
    "lvdsCardWorker\0updateBarStatusSignal\0"
    "\0chooseCard\0errorText\0stopThreadRec\0"
    "RunError\0msg\0onLVDSDataToUi\0channel\0"
    "LVDSData\0onRS422DataToUi\0RS422Data\0"
    "onLVDSAnalysisToUi\0data\0onRS422AnalysisToUi\0"
    "imageSignal\0image\0emitRunError\0"
    "readyReceive\0currentCardNo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lvdsCardWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    0,   69,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       8,    2,   73,    2, 0x06 /* Public */,
      11,    2,   78,    2, 0x06 /* Public */,
      13,    2,   83,    2, 0x06 /* Public */,
      15,    2,   88,    2, 0x06 /* Public */,
      16,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,   96,    2, 0x0a /* Public */,
      19,    3,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::UChar, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::UChar, QMetaType::QString,    9,   12,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,    9,   14,
    QMetaType::Void, QMetaType::UChar, QMetaType::QByteArray,    9,   14,
    QMetaType::Void, QMetaType::QImage,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::QByteArray,   20,    9,   14,

       0        // eod
};

void lvdsCardWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lvdsCardWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBarStatusSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->stopThreadRec(); break;
        case 2: _t->RunError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onLVDSDataToUi((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->onRS422DataToUi((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->onLVDSAnalysisToUi((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 6: _t->onRS422AnalysisToUi((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 7: _t->imageSignal((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 8: _t->emitRunError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->readyReceive((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lvdsCardWorker::*)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lvdsCardWorker::updateBarStatusSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (lvdsCardWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lvdsCardWorker::stopThreadRec)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (lvdsCardWorker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lvdsCardWorker::RunError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (lvdsCardWorker::*)(quint8 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lvdsCardWorker::onLVDSDataToUi)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (lvdsCardWorker::*)(quint8 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lvdsCardWorker::onRS422DataToUi)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (lvdsCardWorker::*)(quint8 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lvdsCardWorker::onLVDSAnalysisToUi)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (lvdsCardWorker::*)(quint8 , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lvdsCardWorker::onRS422AnalysisToUi)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (lvdsCardWorker::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lvdsCardWorker::imageSignal)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject lvdsCardWorker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_lvdsCardWorker.data,
    qt_meta_data_lvdsCardWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lvdsCardWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lvdsCardWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lvdsCardWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int lvdsCardWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void lvdsCardWorker::updateBarStatusSignal(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lvdsCardWorker::stopThreadRec()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void lvdsCardWorker::RunError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void lvdsCardWorker::onLVDSDataToUi(quint8 _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void lvdsCardWorker::onRS422DataToUi(quint8 _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void lvdsCardWorker::onLVDSAnalysisToUi(quint8 _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void lvdsCardWorker::onRS422AnalysisToUi(quint8 _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void lvdsCardWorker::imageSignal(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
