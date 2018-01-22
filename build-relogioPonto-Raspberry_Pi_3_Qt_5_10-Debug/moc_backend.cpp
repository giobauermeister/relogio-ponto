/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../relogioPonto/backend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackEnd_t {
    QByteArrayData data[17];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackEnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackEnd_t qt_meta_stringdata_BackEnd = {
    {
QT_MOC_LITERAL(0, 0, 7), // "BackEnd"
QT_MOC_LITERAL(1, 8, 13), // "idtextChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 2), // "id"
QT_MOC_LITERAL(4, 26, 20), // "employeePhotoChanged"
QT_MOC_LITERAL(5, 47, 5), // "photo"
QT_MOC_LITERAL(6, 53, 19), // "employeeNameChanged"
QT_MOC_LITERAL(7, 73, 4), // "name"
QT_MOC_LITERAL(8, 78, 17), // "employeeIDChanged"
QT_MOC_LITERAL(9, 96, 16), // "timeIndexChanged"
QT_MOC_LITERAL(10, 113, 9), // "timeIndex"
QT_MOC_LITERAL(11, 123, 9), // "decodeTag"
QT_MOC_LITERAL(12, 133, 7), // "readTag"
QT_MOC_LITERAL(13, 141, 7), // "zeroTag"
QT_MOC_LITERAL(14, 149, 13), // "employeePhoto"
QT_MOC_LITERAL(15, 163, 12), // "employeeName"
QT_MOC_LITERAL(16, 176, 10) // "employeeID"

    },
    "BackEnd\0idtextChanged\0\0id\0"
    "employeePhotoChanged\0photo\0"
    "employeeNameChanged\0name\0employeeIDChanged\0"
    "timeIndexChanged\0timeIndex\0decodeTag\0"
    "readTag\0zeroTag\0employeePhoto\0"
    "employeeName\0employeeID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackEnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   72, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,
       9,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   69,    2, 0x0a /* Public */,
      12,    0,   70,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,   10,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      10, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       1,
       2,
       3,
       4,

       0        // eod
};

void BackEnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackEnd *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->idtextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->employeePhotoChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->employeeNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->employeeIDChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->timeIndexChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: { bool _r = _t->decodeTag();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->readTag(); break;
        case 7: _t->zeroTag(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BackEnd::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::idtextChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BackEnd::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::employeePhotoChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BackEnd::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::employeeNameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BackEnd::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::employeeIDChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BackEnd::*_t)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::timeIndexChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BackEnd *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->employeePhoto(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->employeeName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->employeeID(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->timeIndex(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BackEnd *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEmployeePhoto(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setEmployeeName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setEmployeeID(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setTimeIndex(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject BackEnd::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BackEnd.data,
      qt_meta_data_BackEnd,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BackEnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackEnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackEnd.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BackEnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
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
void BackEnd::idtextChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BackEnd::employeePhotoChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BackEnd::employeeNameChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BackEnd::employeeIDChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BackEnd::timeIndexChanged(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
