/****************************************************************************
** Meta object code from reading C++ file 'Closer.hpp'
**
** Created: Tue Mar 5 22:07:48 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Closer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Closer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Closer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,    8,    7,    7, 0x0a,

 // methods: signature, parameters, type, tag, flags
     103,   31,    7,    7, 0x02,
     349,  181,    7,    7, 0x02,
     499,    7,    7,    7, 0x02,
     514,    7,    7,    7, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_Closer[] = {
    "Closer\0\0message\0share(QString)\0"
    "company,name,corporateTitle,email,phone,address,aboutMe,linkedinProfil"
    "e\0"
    "addNewRecord(QString,QString,QString,QString,QString,QString,QString,Q"
    "String)\0"
    "company,name,corporateTitle,email,phone,address,aboutMe,linkedinProfil"
    "e,oldCompany,oldName,oldCorporateTitle,oldEmail,oldPhone,oldAddress,ol"
    "dAboutMe,oldLinkedinProfile\0"
    "updateSelectedRecord(QString,QString,QString,QString,QString,QString,Q"
    "String,QString,QString,QString,QString,QString,QString,QString,QString"
    ",QString)\0"
    "deleteRecord()\0popNavigationPane()\0"
};

void Closer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Closer *_t = static_cast<Closer *>(_o);
        switch (_id) {
        case 0: _t->share((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addNewRecord((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
        case 2: _t->updateSelectedRecord((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16]))); break;
        case 3: _t->deleteRecord(); break;
        case 4: _t->popNavigationPane(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Closer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Closer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Closer,
      qt_meta_data_Closer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Closer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Closer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Closer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Closer))
        return static_cast<void*>(const_cast< Closer*>(this));
    return QObject::qt_metacast(_clname);
}

int Closer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
