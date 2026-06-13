/****************************************************************************
** Meta object code from reading C++ file 'xmlcommandparser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../newGroundTestLvdsCameraL_ZGG/XML/xmlcommandparser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmlcommandparser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XMLCommandParser_t {
    QByteArrayData data[17];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLCommandParser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLCommandParser_t qt_meta_stringdata_XMLCommandParser = {
    {
QT_MOC_LITERAL(0, 0, 16), // "XMLCommandParser"
QT_MOC_LITERAL(1, 17, 24), // "updateUiCurComShowSignal"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 4), // "text"
QT_MOC_LITERAL(4, 48, 27), // "updateSubUiCurComShowSignal"
QT_MOC_LITERAL(5, 76, 20), // "updateParaListSignal"
QT_MOC_LITERAL(6, 97, 21), // "QVector<CommandQueue>"
QT_MOC_LITERAL(7, 119, 18), // "commandQueueVector"
QT_MOC_LITERAL(8, 138, 22), // "updateTMParaListSignal"
QT_MOC_LITERAL(9, 161, 20), // "QVector<TMitemQueue>"
QT_MOC_LITERAL(10, 182, 15), // "paraQueueVector"
QT_MOC_LITERAL(11, 198, 19), // "updateFrameTMSignal"
QT_MOC_LITERAL(12, 218, 8), // "FrameTM&"
QT_MOC_LITERAL(13, 227, 10), // "frameTmXML"
QT_MOC_LITERAL(14, 238, 24), // "updateFrameTMSignal_slow"
QT_MOC_LITERAL(15, 263, 27), // "updateTMParaListSignal_slow"
QT_MOC_LITERAL(16, 291, 20) // "paraQueueVector_slow"

    },
    "XMLCommandParser\0updateUiCurComShowSignal\0"
    "\0text\0updateSubUiCurComShowSignal\0"
    "updateParaListSignal\0QVector<CommandQueue>\0"
    "commandQueueVector\0updateTMParaListSignal\0"
    "QVector<TMitemQueue>\0paraQueueVector\0"
    "updateFrameTMSignal\0FrameTM&\0frameTmXML\0"
    "updateFrameTMSignal_slow\0"
    "updateTMParaListSignal_slow\0"
    "paraQueueVector_slow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLCommandParser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       8,    1,   58,    2, 0x06 /* Public */,
      11,    1,   61,    2, 0x06 /* Public */,
      14,    1,   64,    2, 0x06 /* Public */,
      15,    1,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 9,   16,

       0        // eod
};

void XMLCommandParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XMLCommandParser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateUiCurComShowSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateSubUiCurComShowSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateParaListSignal((*reinterpret_cast< QVector<CommandQueue>(*)>(_a[1]))); break;
        case 3: _t->updateTMParaListSignal((*reinterpret_cast< QVector<TMitemQueue>(*)>(_a[1]))); break;
        case 4: _t->updateFrameTMSignal((*reinterpret_cast< FrameTM(*)>(_a[1]))); break;
        case 5: _t->updateFrameTMSignal_slow((*reinterpret_cast< FrameTM(*)>(_a[1]))); break;
        case 6: _t->updateTMParaListSignal_slow((*reinterpret_cast< QVector<TMitemQueue>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XMLCommandParser::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLCommandParser::updateUiCurComShowSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (XMLCommandParser::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLCommandParser::updateSubUiCurComShowSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (XMLCommandParser::*)(QVector<CommandQueue> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLCommandParser::updateParaListSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (XMLCommandParser::*)(QVector<TMitemQueue> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLCommandParser::updateTMParaListSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (XMLCommandParser::*)(FrameTM & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLCommandParser::updateFrameTMSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (XMLCommandParser::*)(FrameTM & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLCommandParser::updateFrameTMSignal_slow)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (XMLCommandParser::*)(QVector<TMitemQueue> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLCommandParser::updateTMParaListSignal_slow)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject XMLCommandParser::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_XMLCommandParser.data,
    qt_meta_data_XMLCommandParser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XMLCommandParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLCommandParser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XMLCommandParser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int XMLCommandParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void XMLCommandParser::updateUiCurComShowSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XMLCommandParser::updateSubUiCurComShowSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XMLCommandParser::updateParaListSignal(QVector<CommandQueue> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XMLCommandParser::updateTMParaListSignal(QVector<TMitemQueue> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void XMLCommandParser::updateFrameTMSignal(FrameTM & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void XMLCommandParser::updateFrameTMSignal_slow(FrameTM & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void XMLCommandParser::updateTMParaListSignal_slow(QVector<TMitemQueue> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
