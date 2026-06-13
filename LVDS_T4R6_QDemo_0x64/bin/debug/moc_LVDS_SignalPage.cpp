/****************************************************************************
** Meta object code from reading C++ file 'LVDS_SignalPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LVDS_SignalPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LVDS_SignalPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LVDS_SignalPage_t {
    QByteArrayData data[13];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LVDS_SignalPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LVDS_SignalPage_t qt_meta_stringdata_LVDS_SignalPage = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LVDS_SignalPage"
QT_MOC_LITERAL(1, 16, 20), // "DEBUG_Message_Signal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 4), // "type"
QT_MOC_LITERAL(4, 43, 3), // "msg"
QT_MOC_LITERAL(5, 47, 25), // "Rx_Deal_PictureData_Slots"
QT_MOC_LITERAL(6, 73, 5), // "frame"
QT_MOC_LITERAL(7, 79, 9), // "showSLots"
QT_MOC_LITERAL(8, 89, 1), // "s"
QT_MOC_LITERAL(9, 91, 30), // "on_Rx_State_pushButton_clicked"
QT_MOC_LITERAL(10, 122, 30), // "on_Tx_State_pushButton_clicked"
QT_MOC_LITERAL(11, 153, 29), // "on_Tx_Time_pushButton_clicked"
QT_MOC_LITERAL(12, 183, 21) // "on_pushButton_clicked"

    },
    "LVDS_SignalPage\0DEBUG_Message_Signal\0"
    "\0type\0msg\0Rx_Deal_PictureData_Slots\0"
    "frame\0showSLots\0s\0on_Rx_State_pushButton_clicked\0"
    "on_Tx_State_pushButton_clicked\0"
    "on_Tx_Time_pushButton_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LVDS_SignalPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   54,    2, 0x0a /* Public */,
       7,    1,   57,    2, 0x0a /* Public */,
       9,    0,   60,    2, 0x08 /* Private */,
      10,    0,   61,    2, 0x08 /* Private */,
      11,    0,   62,    2, 0x08 /* Private */,
      12,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LVDS_SignalPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LVDS_SignalPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DEBUG_Message_Signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->Rx_Deal_PictureData_Slots((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 2: _t->showSLots((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_Rx_State_pushButton_clicked(); break;
        case 4: _t->on_Tx_State_pushButton_clicked(); break;
        case 5: _t->on_Tx_Time_pushButton_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LVDS_SignalPage::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LVDS_SignalPage::DEBUG_Message_Signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LVDS_SignalPage::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_LVDS_SignalPage.data,
    qt_meta_data_LVDS_SignalPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LVDS_SignalPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LVDS_SignalPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LVDS_SignalPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LVDS_SignalPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void LVDS_SignalPage::DEBUG_Message_Signal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
