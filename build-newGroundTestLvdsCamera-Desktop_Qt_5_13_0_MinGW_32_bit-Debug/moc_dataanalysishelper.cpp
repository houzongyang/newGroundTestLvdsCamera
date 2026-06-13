/****************************************************************************
** Meta object code from reading C++ file 'dataanalysishelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../newGroundTestLvdsCameraL_ZGG/frameFormatCamera/dataanalysishelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataanalysishelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataAnalysisHelper_t {
    QByteArrayData data[18];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataAnalysisHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataAnalysisHelper_t qt_meta_stringdata_DataAnalysisHelper = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DataAnalysisHelper"
QT_MOC_LITERAL(1, 19, 11), // "imageSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "image"
QT_MOC_LITERAL(4, 38, 20), // "upgradeErrorImgNumUi"
QT_MOC_LITERAL(5, 59, 15), // "ImageAttributes"
QT_MOC_LITERAL(6, 75, 5), // "attrs"
QT_MOC_LITERAL(7, 81, 17), // "upgradeCentroidUi"
QT_MOC_LITERAL(8, 99, 23), // "CentroidFrameAttributes"
QT_MOC_LITERAL(9, 123, 12), // "upgradeTemUi"
QT_MOC_LITERAL(10, 136, 26), // "TemperatureFrameAttributes"
QT_MOC_LITERAL(11, 163, 22), // "updateParaListUiSignal"
QT_MOC_LITERAL(12, 186, 19), // "QVector<ParaListUi>"
QT_MOC_LITERAL(13, 206, 14), // "paraListUiList"
QT_MOC_LITERAL(14, 221, 22), // "updateFrameCheckSignal"
QT_MOC_LITERAL(15, 244, 7), // "isValid"
QT_MOC_LITERAL(16, 252, 20), // "updateSaveCoordinate"
QT_MOC_LITERAL(17, 273, 18) // "isSaveCoordinateUi"

    },
    "DataAnalysisHelper\0imageSignal\0\0image\0"
    "upgradeErrorImgNumUi\0ImageAttributes\0"
    "attrs\0upgradeCentroidUi\0CentroidFrameAttributes\0"
    "upgradeTemUi\0TemperatureFrameAttributes\0"
    "updateParaListUiSignal\0QVector<ParaListUi>\0"
    "paraListUiList\0updateFrameCheckSignal\0"
    "isValid\0updateSaveCoordinate\0"
    "isSaveCoordinateUi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataAnalysisHelper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       7,    1,   55,    2, 0x06 /* Public */,
       9,    1,   58,    2, 0x06 /* Public */,
      11,    1,   61,    2, 0x06 /* Public */,
      14,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void, 0x80000000 | 10,    6,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   17,

       0        // eod
};

void DataAnalysisHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataAnalysisHelper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageSignal((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->upgradeErrorImgNumUi((*reinterpret_cast< const ImageAttributes(*)>(_a[1]))); break;
        case 2: _t->upgradeCentroidUi((*reinterpret_cast< const CentroidFrameAttributes(*)>(_a[1]))); break;
        case 3: _t->upgradeTemUi((*reinterpret_cast< const TemperatureFrameAttributes(*)>(_a[1]))); break;
        case 4: _t->updateParaListUiSignal((*reinterpret_cast< QVector<ParaListUi>(*)>(_a[1]))); break;
        case 5: _t->updateFrameCheckSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->updateSaveCoordinate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataAnalysisHelper::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalysisHelper::imageSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataAnalysisHelper::*)(const ImageAttributes & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalysisHelper::upgradeErrorImgNumUi)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataAnalysisHelper::*)(const CentroidFrameAttributes & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalysisHelper::upgradeCentroidUi)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataAnalysisHelper::*)(const TemperatureFrameAttributes & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalysisHelper::upgradeTemUi)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataAnalysisHelper::*)(QVector<ParaListUi> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalysisHelper::updateParaListUiSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataAnalysisHelper::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalysisHelper::updateFrameCheckSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataAnalysisHelper::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataAnalysisHelper.data,
    qt_meta_data_DataAnalysisHelper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataAnalysisHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataAnalysisHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataAnalysisHelper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataAnalysisHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void DataAnalysisHelper::imageSignal(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataAnalysisHelper::upgradeErrorImgNumUi(const ImageAttributes & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataAnalysisHelper::upgradeCentroidUi(const CentroidFrameAttributes & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataAnalysisHelper::upgradeTemUi(const TemperatureFrameAttributes & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataAnalysisHelper::updateParaListUiSignal(QVector<ParaListUi> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataAnalysisHelper::updateFrameCheckSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
