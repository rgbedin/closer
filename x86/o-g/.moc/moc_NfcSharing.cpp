/****************************************************************************
** Meta object code from reading C++ file 'NfcSharing.hpp'
**
** Created: Tue Mar 5 21:17:58 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/NfcSharing.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NfcSharing.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NfcSharing[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       1,   79, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      62,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      90,   84,   11,   11, 0x0a,
     140,  123,   11,   11, 0x0a,
     191,  181,   11,   11, 0x0a,
     223,   11,   11,   11, 0x0a,
     240,   11,   11,   11, 0x0a,
     260,   11,   11,   11, 0x0a,
     280,   11,   11,   11, 0x0a,
     299,   12,   11,   11, 0x0a,
     355,  348,   11,   11, 0x0a,
     405,  399,   11,   11, 0x0a,
     444,   11,   11,   11, 0x0a,

 // properties: name, type, flags
     465,  460, 0x01495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

static const char qt_meta_stringdata_NfcSharing[] = {
    "NfcSharing\0\0mode\0"
    "setShareMode(bb::system::NfcShareMode::Type)\0"
    "detectSharingActive()\0paths\0"
    "fileShareContentChanged(QString)\0"
    "message,dataType\0"
    "dataShareContentChanged(QString,QString)\0"
    "urlString\0urlShareContentChanged(QString)\0"
    "disableSharing()\0enableDataSharing()\0"
    "enableFileSharing()\0enableUrlSharing()\0"
    "shareModeChanged(bb::system::NfcShareMode::Type)\0"
    "result\0finished(bb::system::NfcShareSuccess::Type)\0"
    "error\0error(bb::system::NfcShareError::Type)\0"
    "cleanUpOnExit()\0bool\0sharingActive\0"
};

void NfcSharing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NfcSharing *_t = static_cast<NfcSharing *>(_o);
        switch (_id) {
        case 0: _t->setShareMode((*reinterpret_cast< bb::system::NfcShareMode::Type(*)>(_a[1]))); break;
        case 1: _t->detectSharingActive(); break;
        case 2: _t->fileShareContentChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->dataShareContentChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->urlShareContentChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->disableSharing(); break;
        case 6: _t->enableDataSharing(); break;
        case 7: _t->enableFileSharing(); break;
        case 8: _t->enableUrlSharing(); break;
        case 9: _t->shareModeChanged((*reinterpret_cast< bb::system::NfcShareMode::Type(*)>(_a[1]))); break;
        case 10: _t->finished((*reinterpret_cast< bb::system::NfcShareSuccess::Type(*)>(_a[1]))); break;
        case 11: _t->error((*reinterpret_cast< bb::system::NfcShareError::Type(*)>(_a[1]))); break;
        case 12: _t->cleanUpOnExit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NfcSharing::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NfcSharing::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NfcSharing,
      qt_meta_data_NfcSharing, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NfcSharing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NfcSharing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NfcSharing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NfcSharing))
        return static_cast<void*>(const_cast< NfcSharing*>(this));
    return QObject::qt_metacast(_clname);
}

int NfcSharing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = sharingActive(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setSharingActive(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
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

// SIGNAL 0
void NfcSharing::setShareMode(bb::system::NfcShareMode::Type _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NfcSharing::detectSharingActive()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
