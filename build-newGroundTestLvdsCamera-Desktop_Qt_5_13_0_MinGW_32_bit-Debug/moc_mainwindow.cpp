/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../newGroundTestLvdsCameraL_ZGG/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[55];
    char stringdata0[769];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "initSerialSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "portName"
QT_MOC_LITERAL(4, 38, 8), // "baudRate"
QT_MOC_LITERAL(5, 47, 7), // "dataBit"
QT_MOC_LITERAL(6, 55, 6), // "parity"
QT_MOC_LITERAL(7, 62, 7), // "stopBit"
QT_MOC_LITERAL(8, 70, 15), // "openCloseSignal"
QT_MOC_LITERAL(9, 86, 15), // "writeDataSignal"
QT_MOC_LITERAL(10, 102, 12), // "byteDataSend"
QT_MOC_LITERAL(11, 115, 18), // "initSerialSignal_2"
QT_MOC_LITERAL(12, 134, 17), // "openCloseSignal_2"
QT_MOC_LITERAL(13, 152, 17), // "writeDataSignal_2"
QT_MOC_LITERAL(14, 170, 17), // "closeSerialSignal"
QT_MOC_LITERAL(15, 188, 19), // "closeSerialSignal_2"
QT_MOC_LITERAL(16, 208, 18), // "imgToPeakingSignal"
QT_MOC_LITERAL(17, 227, 14), // "isImgToPeaking"
QT_MOC_LITERAL(18, 242, 16), // "peakingThreshold"
QT_MOC_LITERAL(19, 259, 18), // "cardNoConfigSignal"
QT_MOC_LITERAL(20, 278, 10), // "no0IsRs422"
QT_MOC_LITERAL(21, 289, 19), // "hexStringDataSiganl"
QT_MOC_LITERAL(22, 309, 13), // "hexStringData"
QT_MOC_LITERAL(23, 323, 13), // "cardSetSignal"
QT_MOC_LITERAL(24, 337, 6), // "cardNo"
QT_MOC_LITERAL(25, 344, 9), // "channelNo"
QT_MOC_LITERAL(26, 354, 12), // "channelNoRec"
QT_MOC_LITERAL(27, 367, 19), // "lvdsStartStopSignal"
QT_MOC_LITERAL(28, 387, 7), // "isStart"
QT_MOC_LITERAL(29, 395, 19), // "setChannelNumSignal"
QT_MOC_LITERAL(30, 415, 10), // "chooseCard"
QT_MOC_LITERAL(31, 426, 10), // "channelNum"
QT_MOC_LITERAL(32, 437, 21), // "updateIsT1StartSignal"
QT_MOC_LITERAL(33, 459, 9), // "isT1Start"
QT_MOC_LITERAL(34, 469, 15), // "startLVDSSignal"
QT_MOC_LITERAL(35, 485, 14), // "stopLVDSSignal"
QT_MOC_LITERAL(36, 500, 15), // "resetCardSignal"
QT_MOC_LITERAL(37, 516, 15), // "clearFIFOSignal"
QT_MOC_LITERAL(38, 532, 14), // "openCardSignal"
QT_MOC_LITERAL(39, 547, 15), // "closeCardSignal"
QT_MOC_LITERAL(40, 563, 15), // "setChannelFrame"
QT_MOC_LITERAL(41, 579, 20), // "updateWorkerCardNum1"
QT_MOC_LITERAL(42, 600, 8), // "rss422No"
QT_MOC_LITERAL(43, 609, 6), // "lvdsNo"
QT_MOC_LITERAL(44, 616, 20), // "updateWorkerCardNum2"
QT_MOC_LITERAL(45, 637, 26), // "updateSaveCoordinateSignal"
QT_MOC_LITERAL(46, 664, 7), // "checked"
QT_MOC_LITERAL(47, 672, 15), // "handleRS422Data"
QT_MOC_LITERAL(48, 688, 7), // "channel"
QT_MOC_LITERAL(49, 696, 10), // "dataString"
QT_MOC_LITERAL(50, 707, 14), // "handleLVDSData"
QT_MOC_LITERAL(51, 722, 8), // "runError"
QT_MOC_LITERAL(52, 731, 11), // "errorString"
QT_MOC_LITERAL(53, 743, 15), // "updateStatusBar"
QT_MOC_LITERAL(54, 759, 9) // "errorText"

    },
    "MainWindow\0initSerialSignal\0\0portName\0"
    "baudRate\0dataBit\0parity\0stopBit\0"
    "openCloseSignal\0writeDataSignal\0"
    "byteDataSend\0initSerialSignal_2\0"
    "openCloseSignal_2\0writeDataSignal_2\0"
    "closeSerialSignal\0closeSerialSignal_2\0"
    "imgToPeakingSignal\0isImgToPeaking\0"
    "peakingThreshold\0cardNoConfigSignal\0"
    "no0IsRs422\0hexStringDataSiganl\0"
    "hexStringData\0cardSetSignal\0cardNo\0"
    "channelNo\0channelNoRec\0lvdsStartStopSignal\0"
    "isStart\0setChannelNumSignal\0chooseCard\0"
    "channelNum\0updateIsT1StartSignal\0"
    "isT1Start\0startLVDSSignal\0stopLVDSSignal\0"
    "resetCardSignal\0clearFIFOSignal\0"
    "openCardSignal\0closeCardSignal\0"
    "setChannelFrame\0updateWorkerCardNum1\0"
    "rss422No\0lvdsNo\0updateWorkerCardNum2\0"
    "updateSaveCoordinateSignal\0checked\0"
    "handleRS422Data\0channel\0dataString\0"
    "handleLVDSData\0runError\0errorString\0"
    "updateStatusBar\0errorText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      25,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,  159,    2, 0x06 /* Public */,
       8,    0,  170,    2, 0x06 /* Public */,
       9,    1,  171,    2, 0x06 /* Public */,
      11,    5,  174,    2, 0x06 /* Public */,
      12,    0,  185,    2, 0x06 /* Public */,
      13,    1,  186,    2, 0x06 /* Public */,
      14,    0,  189,    2, 0x06 /* Public */,
      15,    0,  190,    2, 0x06 /* Public */,
      16,    2,  191,    2, 0x06 /* Public */,
      19,    1,  196,    2, 0x06 /* Public */,
      21,    1,  199,    2, 0x06 /* Public */,
      23,    3,  202,    2, 0x06 /* Public */,
      27,    1,  209,    2, 0x06 /* Public */,
      29,    2,  212,    2, 0x06 /* Public */,
      32,    2,  217,    2, 0x06 /* Public */,
      34,    1,  222,    2, 0x06 /* Public */,
      35,    1,  225,    2, 0x06 /* Public */,
      36,    1,  228,    2, 0x06 /* Public */,
      37,    1,  231,    2, 0x06 /* Public */,
      38,    1,  234,    2, 0x06 /* Public */,
      39,    1,  237,    2, 0x06 /* Public */,
      40,    1,  240,    2, 0x06 /* Public */,
      41,    2,  243,    2, 0x06 /* Public */,
      44,    2,  248,    2, 0x06 /* Public */,
      45,    1,  253,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      47,    2,  256,    2, 0x08 /* Private */,
      50,    2,  261,    2, 0x08 /* Private */,
      51,    1,  266,    2, 0x08 /* Private */,
      53,    2,  269,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   24,   25,   26,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::Bool, QMetaType::UChar,   30,   31,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   30,   33,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   42,   43,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   42,   43,
    QMetaType::Void, QMetaType::Bool,   46,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::QString,   48,   49,
    QMetaType::Void, QMetaType::UChar, QMetaType::QString,   48,   49,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   30,   54,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initSerialSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->openCloseSignal(); break;
        case 2: _t->writeDataSignal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->initSerialSignal_2((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 4: _t->openCloseSignal_2(); break;
        case 5: _t->writeDataSignal_2((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->closeSerialSignal(); break;
        case 7: _t->closeSerialSignal_2(); break;
        case 8: _t->imgToPeakingSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->cardNoConfigSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->hexStringDataSiganl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->cardSetSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 12: _t->lvdsStartStopSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setChannelNumSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 14: _t->updateIsT1StartSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: _t->startLVDSSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->stopLVDSSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->resetCardSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->clearFIFOSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->openCardSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->closeCardSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->setChannelFrame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->updateWorkerCardNum1((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 23: _t->updateWorkerCardNum2((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 24: _t->updateSaveCoordinateSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->handleRS422Data((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: _t->handleLVDSData((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 27: _t->runError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->updateStatusBar((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initSerialSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::openCloseSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::writeDataSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initSerialSignal_2)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::openCloseSignal_2)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::writeDataSignal_2)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::closeSerialSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::closeSerialSignal_2)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::imgToPeakingSignal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::cardNoConfigSignal)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hexStringDataSiganl)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 , quint8 , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::cardSetSignal)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::lvdsStartStopSignal)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setChannelNumSignal)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::updateIsT1StartSignal)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startLVDSSignal)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::stopLVDSSignal)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::resetCardSignal)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::clearFIFOSignal)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::openCardSignal)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::closeCardSignal)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setChannelFrame)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::updateWorkerCardNum1)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::updateWorkerCardNum2)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::updateSaveCoordinateSignal)) {
                *result = 24;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::initSerialSignal(QString _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::openCloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::writeDataSignal(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::initSerialSignal_2(QString _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::openCloseSignal_2()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::writeDataSignal_2(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::closeSerialSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::closeSerialSignal_2()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainWindow::imgToPeakingSignal(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::cardNoConfigSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::hexStringDataSiganl(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::cardSetSignal(quint8 _t1, quint8 _t2, quint8 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::lvdsStartStopSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainWindow::setChannelNumSignal(bool _t1, quint8 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::updateIsT1StartSignal(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainWindow::startLVDSSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MainWindow::stopLVDSSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MainWindow::resetCardSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::clearFIFOSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MainWindow::openCardSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MainWindow::closeCardSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainWindow::setChannelFrame(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void MainWindow::updateWorkerCardNum1(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainWindow::updateWorkerCardNum2(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void MainWindow::updateSaveCoordinateSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
