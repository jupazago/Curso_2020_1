/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLineEdit *LE_Posx;
    QLineEdit *LE_Posy;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *LE_vel;
    QLineEdit *LE_Angulo;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btnSimular;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(709, 507);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 481, 361));
        LE_Posx = new QLineEdit(centralwidget);
        LE_Posx->setObjectName(QString::fromUtf8("LE_Posx"));
        LE_Posx->setGeometry(QRect(612, 40, 91, 21));
        LE_Posy = new QLineEdit(centralwidget);
        LE_Posy->setObjectName(QString::fromUtf8("LE_Posy"));
        LE_Posy->setGeometry(QRect(612, 70, 91, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(520, 40, 47, 14));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 70, 47, 14));
        LE_vel = new QLineEdit(centralwidget);
        LE_vel->setObjectName(QString::fromUtf8("LE_vel"));
        LE_vel->setGeometry(QRect(612, 100, 91, 21));
        LE_Angulo = new QLineEdit(centralwidget);
        LE_Angulo->setObjectName(QString::fromUtf8("LE_Angulo"));
        LE_Angulo->setGeometry(QRect(612, 130, 91, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(520, 130, 47, 14));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(520, 100, 47, 14));
        btnSimular = new QPushButton(centralwidget);
        btnSimular->setObjectName(QString::fromUtf8("btnSimular"));
        btnSimular->setGeometry(QRect(550, 200, 80, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 709, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "pos X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "pos Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "angulo", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "velocidad", nullptr));
        btnSimular->setText(QCoreApplication::translate("MainWindow", "Simular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
