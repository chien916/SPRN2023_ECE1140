/****************************************************************************
** Meta object code from reading C++ file 't3database.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Prototypes/ui/t3database.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't3database.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_T3Database_t {
    QByteArrayData data[33];
    char stringdata0[428];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T3Database_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T3Database_t qt_meta_stringdata_T3Database = {
    {
QT_MOC_LITERAL(0, 0, 10), // "T3Database"
QT_MOC_LITERAL(1, 11, 30), // "onTrackConstantsObjectsChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 30), // "onTrackVariablesObjectsChanged"
QT_MOC_LITERAL(4, 74, 25), // "trackConstantsObjects_QML"
QT_MOC_LITERAL(5, 100, 25), // "trackVariablesObjects_QML"
QT_MOC_LITERAL(6, 126, 13), // "TrackProperty"
QT_MOC_LITERAL(7, 140, 14), // "CommandedSpeed"
QT_MOC_LITERAL(8, 155, 9), // "Authority"
QT_MOC_LITERAL(9, 165, 13), // "SwitchPostion"
QT_MOC_LITERAL(10, 179, 12), // "ForwardLight"
QT_MOC_LITERAL(11, 192, 13), // "ReversedLight"
QT_MOC_LITERAL(12, 206, 16), // "CrossingPosition"
QT_MOC_LITERAL(13, 223, 12), // "TrainOnBlock"
QT_MOC_LITERAL(14, 236, 7), // "Failure"
QT_MOC_LITERAL(15, 244, 7), // "Heaters"
QT_MOC_LITERAL(16, 252, 15), // "PeopleOnStation"
QT_MOC_LITERAL(17, 268, 13), // "TrainProperty"
QT_MOC_LITERAL(18, 282, 6), // "LENGTH"
QT_MOC_LITERAL(19, 289, 6), // "HEIGHT"
QT_MOC_LITERAL(20, 296, 5), // "WIDTH"
QT_MOC_LITERAL(21, 302, 4), // "MASS"
QT_MOC_LITERAL(22, 307, 12), // "Acceleration"
QT_MOC_LITERAL(23, 320, 8), // "Velocity"
QT_MOC_LITERAL(24, 329, 9), // "CrewCount"
QT_MOC_LITERAL(25, 339, 14), // "PassangerCount"
QT_MOC_LITERAL(26, 354, 6), // "Aircon"
QT_MOC_LITERAL(27, 361, 14), // "ExteriorLights"
QT_MOC_LITERAL(28, 376, 14), // "InteriorLights"
QT_MOC_LITERAL(29, 391, 9), // "LeftDoors"
QT_MOC_LITERAL(30, 401, 10), // "RightDoors"
QT_MOC_LITERAL(31, 412, 6), // "Brakes"
QT_MOC_LITERAL(32, 419, 8) // "Failures"

    },
    "T3Database\0onTrackConstantsObjectsChanged\0"
    "\0onTrackVariablesObjectsChanged\0"
    "trackConstantsObjects_QML\0"
    "trackVariablesObjects_QML\0TrackProperty\0"
    "CommandedSpeed\0Authority\0SwitchPostion\0"
    "ForwardLight\0ReversedLight\0CrossingPosition\0"
    "TrainOnBlock\0Failure\0Heaters\0"
    "PeopleOnStation\0TrainProperty\0LENGTH\0"
    "HEIGHT\0WIDTH\0MASS\0Acceleration\0Velocity\0"
    "CrewCount\0PassangerCount\0Aircon\0"
    "ExteriorLights\0InteriorLights\0LeftDoors\0"
    "RightDoors\0Brakes\0Failures"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T3Database[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   26, // properties
       2,   34, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::QJsonArray, 0x00495003,
       5, QMetaType::QJsonArray, 0x00495003,

 // properties: notify_signal_id
       0,
       1,

 // enums: name, alias, flags, count, data
       6,    6, 0x0,   10,   44,
      17,   17, 0x0,   15,   64,

 // enum data: key, value
       7, uint(T3Database::CommandedSpeed),
       8, uint(T3Database::Authority),
       9, uint(T3Database::SwitchPostion),
      10, uint(T3Database::ForwardLight),
      11, uint(T3Database::ReversedLight),
      12, uint(T3Database::CrossingPosition),
      13, uint(T3Database::TrainOnBlock),
      14, uint(T3Database::Failure),
      15, uint(T3Database::Heaters),
      16, uint(T3Database::PeopleOnStation),
      18, uint(T3Database::LENGTH),
      19, uint(T3Database::HEIGHT),
      20, uint(T3Database::WIDTH),
      21, uint(T3Database::MASS),
      22, uint(T3Database::Acceleration),
      23, uint(T3Database::Velocity),
      24, uint(T3Database::CrewCount),
      25, uint(T3Database::PassangerCount),
      26, uint(T3Database::Aircon),
      27, uint(T3Database::ExteriorLights),
      28, uint(T3Database::InteriorLights),
      29, uint(T3Database::LeftDoors),
      30, uint(T3Database::RightDoors),
      31, uint(T3Database::Brakes),
      32, uint(T3Database::Failures),

       0        // eod
};

void T3Database::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<T3Database *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTrackConstantsObjectsChanged(); break;
        case 1: _t->onTrackVariablesObjectsChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (T3Database::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&T3Database::onTrackConstantsObjectsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (T3Database::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&T3Database::onTrackVariablesObjectsChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<T3Database *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QJsonArray*>(_v) = _t->trackConstantsObjects; break;
        case 1: *reinterpret_cast< QJsonArray*>(_v) = _t->trackVariablesObjects; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<T3Database *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->trackConstantsObjects != *reinterpret_cast< QJsonArray*>(_v)) {
                _t->trackConstantsObjects = *reinterpret_cast< QJsonArray*>(_v);
                Q_EMIT _t->onTrackConstantsObjectsChanged();
            }
            break;
        case 1:
            if (_t->trackVariablesObjects != *reinterpret_cast< QJsonArray*>(_v)) {
                _t->trackVariablesObjects = *reinterpret_cast< QJsonArray*>(_v);
                Q_EMIT _t->onTrackVariablesObjectsChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject T3Database::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_T3Database.data,
    qt_meta_data_T3Database,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *T3Database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T3Database::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_T3Database.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int T3Database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
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
void T3Database::onTrackConstantsObjectsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void T3Database::onTrackVariablesObjectsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
