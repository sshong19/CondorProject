/****************************************************************************
** Meta object code from reading C++ file 'initialwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CondorImagingSoftware/initialwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'initialwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_initialWindow_t {
    QByteArrayData data[11];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_initialWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_initialWindow_t qt_meta_stringdata_initialWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "initialWindow"
QT_MOC_LITERAL(1, 14, 26), // "on_pushButton_Dest_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 24), // "on_pushButton_OP_clicked"
QT_MOC_LITERAL(4, 67, 25), // "on_pushButton_Sub_clicked"
QT_MOC_LITERAL(5, 93, 32), // "on_lineEdit_Dest_editingFinished"
QT_MOC_LITERAL(6, 126, 26), // "on_pushButton_Done_clicked"
QT_MOC_LITERAL(7, 153, 39), // "on_comboBox_Subject_currentIn..."
QT_MOC_LITERAL(8, 193, 4), // "arg1"
QT_MOC_LITERAL(9, 198, 40), // "on_comboBox_Operator_currentI..."
QT_MOC_LITERAL(10, 239, 37) // "on_lineEdit_StudyName_editing..."

    },
    "initialWindow\0on_pushButton_Dest_clicked\0"
    "\0on_pushButton_OP_clicked\0"
    "on_pushButton_Sub_clicked\0"
    "on_lineEdit_Dest_editingFinished\0"
    "on_pushButton_Done_clicked\0"
    "on_comboBox_Subject_currentIndexChanged\0"
    "arg1\0on_comboBox_Operator_currentIndexChanged\0"
    "on_lineEdit_StudyName_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_initialWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void initialWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        initialWindow *_t = static_cast<initialWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_Dest_clicked(); break;
        case 1: _t->on_pushButton_OP_clicked(); break;
        case 2: _t->on_pushButton_Sub_clicked(); break;
        case 3: _t->on_lineEdit_Dest_editingFinished(); break;
        case 4: _t->on_pushButton_Done_clicked(); break;
        case 5: _t->on_comboBox_Subject_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_Operator_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_StudyName_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObject initialWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_initialWindow.data,
      qt_meta_data_initialWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *initialWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *initialWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_initialWindow.stringdata0))
        return static_cast<void*>(const_cast< initialWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int initialWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
