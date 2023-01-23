/****************************************************************************
** Meta object code from reading C++ file 't3traincontroller.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Prototypes/ui/t3traincontroller.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 't3traincontroller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_T3TrainController_t {
    QByteArrayData data[10];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_T3TrainController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_T3TrainController_t qt_meta_stringdata_T3TrainController = {
    {
QT_MOC_LITERAL(0, 0, 17), // "T3TrainController"
QT_MOC_LITERAL(1, 18, 17), // "onrybufferChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "post"
QT_MOC_LITERAL(4, 42, 7), // "request"
QT_MOC_LITERAL(5, 50, 9), // "rbuffer_q"
QT_MOC_LITERAL(6, 60, 12), // "QList<float>"
QT_MOC_LITERAL(7, 73, 9), // "tbuffer_q"
QT_MOC_LITERAL(8, 83, 9), // "ybuffer_q"
QT_MOC_LITERAL(9, 93, 3) // "r_q"

    },
    "T3TrainController\0onrybufferChanged\0"
    "\0post\0request\0rbuffer_q\0QList<float>\0"
    "tbuffer_q\0ybuffer_q\0r_q"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_T3TrainController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       4,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x0049500b,
       7, 0x80000000 | 6, 0x0049500b,
       8, 0x80000000 | 6, 0x0049500b,
       9, QMetaType::Float, 0x00495003,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

void T3TrainController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<T3TrainController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onrybufferChanged(); break;
        case 1: _t->post((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (T3TrainController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&T3TrainController::onrybufferChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<float> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<T3TrainController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<float>*>(_v) = _t->rbuffer; break;
        case 1: *reinterpret_cast< QList<float>*>(_v) = _t->tbuffer; break;
        case 2: *reinterpret_cast< QList<float>*>(_v) = _t->ybuffer; break;
        case 3: *reinterpret_cast< float*>(_v) = _t->readR(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<T3TrainController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->rbuffer != *reinterpret_cast< QList<float>*>(_v)) {
                _t->rbuffer = *reinterpret_cast< QList<float>*>(_v);
                Q_EMIT _t->onrybufferChanged();
            }
            break;
        case 1:
            if (_t->tbuffer != *reinterpret_cast< QList<float>*>(_v)) {
                _t->tbuffer = *reinterpret_cast< QList<float>*>(_v);
                Q_EMIT _t->onrybufferChanged();
            }
            break;
        case 2:
            if (_t->ybuffer != *reinterpret_cast< QList<float>*>(_v)) {
                _t->ybuffer = *reinterpret_cast< QList<float>*>(_v);
                Q_EMIT _t->onrybufferChanged();
            }
            break;
        case 3: _t->writeR(*reinterpret_cast< float*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject T3TrainController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_T3TrainController.data,
    qt_meta_data_T3TrainController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *T3TrainController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *T3TrainController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_T3TrainController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int T3TrainController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void T3TrainController::onrybufferChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
