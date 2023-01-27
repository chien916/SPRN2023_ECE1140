/****************************************************************************
** Meta object code from reading C++ file 't3trackdatabase.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Prototypes/ui/t3trackdatabase.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't3trackdatabase.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_T3TrackDatabase_t {
    QByteArrayData data[22];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T3TrackDatabase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T3TrackDatabase_t qt_meta_stringdata_T3TrackDatabase = {
    {
QT_MOC_LITERAL(0, 0, 15), // "T3TrackDatabase"
QT_MOC_LITERAL(1, 16, 3), // "put"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "request"
QT_MOC_LITERAL(4, 29, 3), // "get"
QT_MOC_LITERAL(5, 33, 9), // "QVariant*"
QT_MOC_LITERAL(6, 43, 7), // "respond"
QT_MOC_LITERAL(7, 51, 6), // "import"
QT_MOC_LITERAL(8, 58, 8), // "filePath"
QT_MOC_LITERAL(9, 67, 14), // "lineObjects_OA"
QT_MOC_LITERAL(10, 82, 13), // "TrackProperty"
QT_MOC_LITERAL(11, 96, 8), // "Crossing"
QT_MOC_LITERAL(12, 105, 9), // "Elevation"
QT_MOC_LITERAL(13, 115, 5), // "Grade"
QT_MOC_LITERAL(14, 121, 6), // "Length"
QT_MOC_LITERAL(15, 128, 10), // "NextBlock1"
QT_MOC_LITERAL(16, 139, 10), // "NextBlock2"
QT_MOC_LITERAL(17, 150, 10), // "PrevBlock1"
QT_MOC_LITERAL(18, 161, 10), // "PrevBlock2"
QT_MOC_LITERAL(19, 172, 10), // "SpeedLimit"
QT_MOC_LITERAL(20, 183, 7), // "Station"
QT_MOC_LITERAL(21, 191, 11) // "Underground"

    },
    "T3TrackDatabase\0put\0\0request\0get\0"
    "QVariant*\0respond\0import\0filePath\0"
    "lineObjects_OA\0TrackProperty\0Crossing\0"
    "Elevation\0Grade\0Length\0NextBlock1\0"
    "NextBlock2\0PrevBlock1\0PrevBlock2\0"
    "SpeedLimit\0Station\0Underground"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T3TrackDatabase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   40, // properties
       1,   43, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    2,   32,    2, 0x0a /* Public */,
       7,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    3,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // properties: name, type, flags
       9, QMetaType::QJsonArray, 0x00095003,

 // enums: name, alias, flags, count, data
      10,   10, 0x0,   11,   48,

 // enum data: key, value
      11, uint(T3TrackDatabase::Crossing),
      12, uint(T3TrackDatabase::Elevation),
      13, uint(T3TrackDatabase::Grade),
      14, uint(T3TrackDatabase::Length),
      15, uint(T3TrackDatabase::NextBlock1),
      16, uint(T3TrackDatabase::NextBlock2),
      17, uint(T3TrackDatabase::PrevBlock1),
      18, uint(T3TrackDatabase::PrevBlock2),
      19, uint(T3TrackDatabase::SpeedLimit),
      20, uint(T3TrackDatabase::Station),
      21, uint(T3TrackDatabase::Underground),

       0        // eod
};

void T3TrackDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<T3TrackDatabase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->put((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->get((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVariant*(*)>(_a[2]))); break;
        case 2: _t->import((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<T3TrackDatabase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QJsonArray*>(_v) = _t->lineObjects; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<T3TrackDatabase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->lineObjects != *reinterpret_cast< QJsonArray*>(_v)) {
                _t->lineObjects = *reinterpret_cast< QJsonArray*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject T3TrackDatabase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_T3TrackDatabase.data,
    qt_meta_data_T3TrackDatabase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *T3TrackDatabase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T3TrackDatabase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_T3TrackDatabase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int T3TrackDatabase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
