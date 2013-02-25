/****************************************************************************
** Meta object code from reading C++ file 'Prototype.hpp'
**
** Created: Sun Feb 24 20:15:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Prototype.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Prototype.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Prototype[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   11,   10,   10, 0x0a,
      42,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Prototype[] = {
    "Prototype\0\0posX,posY\0addText(float,float)\0"
    "showSocialNetworkPicker()\0"
};

void Prototype::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Prototype *_t = static_cast<Prototype *>(_o);
        switch (_id) {
        case 0: _t->addText((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->showSocialNetworkPicker(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Prototype::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Prototype::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Prototype,
      qt_meta_data_Prototype, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Prototype::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Prototype::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Prototype::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Prototype))
        return static_cast<void*>(const_cast< Prototype*>(this));
    return QObject::qt_metacast(_clname);
}

int Prototype::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
