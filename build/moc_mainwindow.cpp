/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "ButtonOpenSourceImagePressed"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 30), // "ButtonDeleteSourcePointPressed"
QT_MOC_LITERAL(4, 72, 29), // "ButtonClearSourcePointPressed"
QT_MOC_LITERAL(5, 102, 28), // "ButtonOpenTargetImagePressed"
QT_MOC_LITERAL(6, 131, 35), // "ButtonDeleteTargetPointCloudP..."
QT_MOC_LITERAL(7, 167, 29), // "ButtonClearTargetPointPressed"
QT_MOC_LITERAL(8, 197, 33), // "ButtonPerspectiveTransformPre..."
QT_MOC_LITERAL(9, 231, 26), // "ButtonUndoTransformPressed"
QT_MOC_LITERAL(10, 258, 22), // "TreeSourcePointClicked"
QT_MOC_LITERAL(11, 281, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(12, 298, 19), // "current_select_item"
QT_MOC_LITERAL(13, 318, 22) // "TreeTargetPointClicked"

    },
    "MainWindow\0ButtonOpenSourceImagePressed\0"
    "\0ButtonDeleteSourcePointPressed\0"
    "ButtonClearSourcePointPressed\0"
    "ButtonOpenTargetImagePressed\0"
    "ButtonDeleteTargetPointCloudPressed\0"
    "ButtonClearTargetPointPressed\0"
    "ButtonPerspectiveTransformPressed\0"
    "ButtonUndoTransformPressed\0"
    "TreeSourcePointClicked\0QTreeWidgetItem*\0"
    "current_select_item\0TreeTargetPointClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      13,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ButtonOpenSourceImagePressed(); break;
        case 1: _t->ButtonDeleteSourcePointPressed(); break;
        case 2: _t->ButtonClearSourcePointPressed(); break;
        case 3: _t->ButtonOpenTargetImagePressed(); break;
        case 4: _t->ButtonDeleteTargetPointCloudPressed(); break;
        case 5: _t->ButtonClearTargetPointPressed(); break;
        case 6: _t->ButtonPerspectiveTransformPressed(); break;
        case 7: _t->ButtonUndoTransformPressed(); break;
        case 8: _t->TreeSourcePointClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->TreeTargetPointClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
