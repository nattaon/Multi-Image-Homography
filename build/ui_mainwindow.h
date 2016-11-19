/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_src_open;
    QPushButton *btn_tar_open;
    QTreeWidget *tree_src_point;
    QTreeWidget *tree_tar_point;
    QPushButton *btn_src_del;
    QPushButton *btn_src_clear;
    QPushButton *btn_tar_del;
    QPushButton *btn_tar_clear;
    QPushButton *btn_perspective;
    QPushButton *btn_undo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(385, 403);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_src_open = new QPushButton(centralWidget);
        btn_src_open->setObjectName(QStringLiteral("btn_src_open"));
        btn_src_open->setGeometry(QRect(30, 20, 141, 41));
        btn_tar_open = new QPushButton(centralWidget);
        btn_tar_open->setObjectName(QStringLiteral("btn_tar_open"));
        btn_tar_open->setGeometry(QRect(210, 20, 141, 41));
        tree_src_point = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        tree_src_point->setHeaderItem(__qtreewidgetitem);
        tree_src_point->setObjectName(QStringLiteral("tree_src_point"));
        tree_src_point->setGeometry(QRect(30, 80, 141, 192));
        tree_tar_point = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setTextAlignment(0, Qt::AlignCenter);
        tree_tar_point->setHeaderItem(__qtreewidgetitem1);
        tree_tar_point->setObjectName(QStringLiteral("tree_tar_point"));
        tree_tar_point->setGeometry(QRect(210, 80, 141, 192));
        btn_src_del = new QPushButton(centralWidget);
        btn_src_del->setObjectName(QStringLiteral("btn_src_del"));
        btn_src_del->setGeometry(QRect(30, 280, 61, 28));
        btn_src_clear = new QPushButton(centralWidget);
        btn_src_clear->setObjectName(QStringLiteral("btn_src_clear"));
        btn_src_clear->setGeometry(QRect(110, 280, 61, 28));
        btn_tar_del = new QPushButton(centralWidget);
        btn_tar_del->setObjectName(QStringLiteral("btn_tar_del"));
        btn_tar_del->setGeometry(QRect(210, 280, 61, 28));
        btn_tar_clear = new QPushButton(centralWidget);
        btn_tar_clear->setObjectName(QStringLiteral("btn_tar_clear"));
        btn_tar_clear->setGeometry(QRect(290, 280, 61, 28));
        btn_perspective = new QPushButton(centralWidget);
        btn_perspective->setObjectName(QStringLiteral("btn_perspective"));
        btn_perspective->setGeometry(QRect(30, 320, 141, 41));
        btn_undo = new QPushButton(centralWidget);
        btn_undo->setObjectName(QStringLiteral("btn_undo"));
        btn_undo->setGeometry(QRect(210, 320, 141, 41));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_src_open->setText(QApplication::translate("MainWindow", "open source image", 0));
        btn_tar_open->setText(QApplication::translate("MainWindow", "open target image", 0));
        QTreeWidgetItem *___qtreewidgetitem = tree_src_point->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "select 4 points", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = tree_tar_point->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "select 4 points", 0));
        btn_src_del->setText(QApplication::translate("MainWindow", "delete", 0));
        btn_src_clear->setText(QApplication::translate("MainWindow", "clear all", 0));
        btn_tar_del->setText(QApplication::translate("MainWindow", "delete", 0));
        btn_tar_clear->setText(QApplication::translate("MainWindow", "clear all", 0));
        btn_perspective->setText(QApplication::translate("MainWindow", "Perspective Transform", 0));
        btn_undo->setText(QApplication::translate("MainWindow", "Undo Transform", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
