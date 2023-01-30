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
    QByteArrayData data[27];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T3TrackDatabase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T3TrackDatabase_t qt_meta_stringdata_T3TrackDatabase = {
    {
QT_MOC_LITERAL(0, 0, 15), // "T3TrackDatabase"
QT_MOC_LITERAL(1, 16, 29), // "onLineConstantsObjectsChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 29), // "onLineVariablesObjectsChanged"
QT_MOC_LITERAL(4, 77, 3), // "put"
QT_MOC_LITERAL(5, 81, 7), // "blockId"
QT_MOC_LITERAL(6, 89, 30), // "T3TrackDatabase::TrackProperty"
QT_MOC_LITERAL(7, 120, 13), // "trackProperty"
QT_MOC_LITERAL(8, 134, 5), // "value"
QT_MOC_LITERAL(9, 140, 3), // "get"
QT_MOC_LITERAL(10, 144, 7), // "request"
QT_MOC_LITERAL(11, 152, 9), // "QVariant*"
QT_MOC_LITERAL(12, 162, 7), // "respond"
QT_MOC_LITERAL(13, 170, 6), // "import"
QT_MOC_LITERAL(14, 177, 8), // "filePath"
QT_MOC_LITERAL(15, 186, 24), // "lineConstantsObjects_QML"
QT_MOC_LITERAL(16, 211, 24), // "lineVariablesObjects_QML"
QT_MOC_LITERAL(17, 236, 13), // "TrackProperty"
QT_MOC_LITERAL(18, 250, 14), // "CommandedSpeed"
QT_MOC_LITERAL(19, 265, 9), // "Authority"
QT_MOC_LITERAL(20, 275, 13), // "SwitchPostion"
QT_MOC_LITERAL(21, 289, 5), // "Light"
QT_MOC_LITERAL(22, 295, 16), // "CrossingPosition"
QT_MOC_LITERAL(23, 312, 12), // "TrainOnBlock"
QT_MOC_LITERAL(24, 325, 7), // "Failure"
QT_MOC_LITERAL(25, 333, 7), // "Heaters"
QT_MOC_LITERAL(26, 341, 15) // "PeopleOnStation"

    },
    "T3TrackDatabase\0onLineConstantsObjectsChanged\0"
    "\0onLineVariablesObjectsChanged\0put\0"
    "blockId\0T3TrackDatabase::TrackProperty\0"
    "trackProperty\0value\0get\0request\0"
    "QVariant*\0respond\0import\0filePath\0"
    "lineConstantsObjects_QML\0"
    "lineVariablesObjects_QML\0TrackProperty\0"
    "CommandedSpeed\0Authority\0SwitchPostion\0"
    "Light\0CrossingPosition\0TrainOnBlock\0"
    "Failure\0Heaters\0PeopleOnStation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T3TrackDatabase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   56, // properties
       1,   64, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   41,    2, 0x0a /* Public */,
       9,    2,   48,    2, 0x0a /* Public */,
      13,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6, QMetaType::QVariant,    5,    7,    8,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 11,   10,   12,
    QMetaType::Void, QMetaType::QString,   14,

 // properties: name, type, flags
      15, QMetaType::QJsonArray, 0x00495003,
      16, QMetaType::QJsonArray, 0x00495003,

 // properties: notify_signal_id
       0,
       1,

 // enums: name, alias, flags, count, data
      17,   17, 0x0,    9,   69,

 // enum data: key, value
      18, uint(T3TrackDatabase::CommandedSpeed),
      19, uint(T3TrackDatabase::Authority),
      20, uint(T3TrackDatabase::SwitchPostion),
      21, uint(T3TrackDatabase::Light),
      22, uint(T3TrackDatabase::CrossingPosition),
      23, uint(T3TrackDatabase::TrainOnBlock),
      24, uint(T3TrackDatabase::Failure),
      25, uint(T3TrackDatabase::Heaters),
      26, uint(T3TrackDatabase::PeopleOnStation),

       0        // eod
};

void T3TrackDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<T3TrackDatabase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onLineConstantsObjectsChanged(); break;
        case 1: _t->onLineVariablesObjectsChanged(); break;
        case 2: _t->put((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< T3TrackDatabase::TrackProperty(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3]))); break;
        case 3: _t->get((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVariant*(*)>(_a[2]))); break;
        case 4: _t->import((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (T3TrackDatabase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&T3TrackDatabase::onLineConstantsObjectsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (T3TrackDatabase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&T3TrackDatabase::onLineVariablesObjectsChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<T3TrackDatabase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QJsonArray*>(_v) = _t->lineConstantsObjects; break;
        case 1: *reinterpret_cast< QJsonArray*>(_v) = _t->lineVariablesObjects; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<T3TrackDatabase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->lineConstantsObjects != *reinterpret_cast< QJsonArray*>(_v)) {
                _t->lineConstantsObjects = *reinterpret_cast< QJsonArray*>(_v);
                Q_EMIT _t->onLineConstantsObjectsChanged();
            }
            break;
        case 1:
            if (_t->lineVariablesObjects != *reinterpret_cast< QJsonArray*>(_v)) {
                _t->lineVariablesObjects = *reinterpret_cast< QJsonArray*>(_v);
                Q_EMIT _t->onLineVariablesObjectsChanged();
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void T3TrackDatabase::onLineConstantsObjectsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void T3TrackDatabase::onLineVariablesObjectsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
