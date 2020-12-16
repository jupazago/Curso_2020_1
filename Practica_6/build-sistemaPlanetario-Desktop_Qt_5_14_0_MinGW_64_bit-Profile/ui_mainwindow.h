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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QDoubleSpinBox *A1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *A2;
    QDoubleSpinBox *A3;
    QDoubleSpinBox *A4;
    QDoubleSpinBox *A5;
    QDoubleSpinBox *A6;
    QDoubleSpinBox *B6;
    QDoubleSpinBox *B1;
    QDoubleSpinBox *B3;
    QDoubleSpinBox *B5;
    QDoubleSpinBox *B4;
    QDoubleSpinBox *B2;
    QDoubleSpinBox *C6;
    QDoubleSpinBox *C1;
    QDoubleSpinBox *C3;
    QDoubleSpinBox *C5;
    QDoubleSpinBox *C4;
    QDoubleSpinBox *C2;
    QDoubleSpinBox *D6;
    QDoubleSpinBox *D1;
    QDoubleSpinBox *D3;
    QDoubleSpinBox *D5;
    QDoubleSpinBox *D4;
    QDoubleSpinBox *D2;
    QDoubleSpinBox *E6;
    QDoubleSpinBox *E1;
    QDoubleSpinBox *E3;
    QDoubleSpinBox *E5;
    QDoubleSpinBox *E4;
    QDoubleSpinBox *E2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(933, 783);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 170, 901, 541));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 20, 171, 41));
        A1 = new QDoubleSpinBox(centralwidget);
        A1->setObjectName(QString::fromUtf8("A1"));
        A1->setGeometry(QRect(70, 21, 91, 23));
        A1->setMinimum(-100000.000000000000000);
        A1->setMaximum(100000.000000000000000);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(21, 0, 35, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 0, 71, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 0, 71, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 0, 25, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(380, 0, 28, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(450, 0, 91, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(560, 0, 81, 16));
        A2 = new QDoubleSpinBox(centralwidget);
        A2->setObjectName(QString::fromUtf8("A2"));
        A2->setGeometry(QRect(190, 20, 91, 23));
        A2->setMinimum(-100000.000000000000000);
        A2->setMaximum(100000.000000000000000);
        A3 = new QDoubleSpinBox(centralwidget);
        A3->setObjectName(QString::fromUtf8("A3"));
        A3->setGeometry(QRect(300, 21, 53, 23));
        A3->setMinimum(0.000000000000000);
        A3->setMaximum(100000.000000000000000);
        A4 = new QDoubleSpinBox(centralwidget);
        A4->setObjectName(QString::fromUtf8("A4"));
        A4->setGeometry(QRect(370, 21, 53, 23));
        A4->setMinimum(0.000000000000000);
        A4->setMaximum(100000.000000000000000);
        A5 = new QDoubleSpinBox(centralwidget);
        A5->setObjectName(QString::fromUtf8("A5"));
        A5->setGeometry(QRect(440, 20, 91, 23));
        A5->setMinimum(-100000.000000000000000);
        A5->setMaximum(100000.000000000000000);
        A6 = new QDoubleSpinBox(centralwidget);
        A6->setObjectName(QString::fromUtf8("A6"));
        A6->setGeometry(QRect(550, 20, 91, 23));
        A6->setMinimum(-100000.000000000000000);
        A6->setMaximum(100000.000000000000000);
        B6 = new QDoubleSpinBox(centralwidget);
        B6->setObjectName(QString::fromUtf8("B6"));
        B6->setGeometry(QRect(550, 50, 91, 23));
        B6->setMinimum(-100000.000000000000000);
        B6->setMaximum(100000.000000000000000);
        B1 = new QDoubleSpinBox(centralwidget);
        B1->setObjectName(QString::fromUtf8("B1"));
        B1->setGeometry(QRect(70, 51, 91, 23));
        B1->setMinimum(-100000.000000000000000);
        B1->setMaximum(100000.000000000000000);
        B3 = new QDoubleSpinBox(centralwidget);
        B3->setObjectName(QString::fromUtf8("B3"));
        B3->setGeometry(QRect(300, 51, 53, 23));
        B3->setMinimum(0.000000000000000);
        B3->setMaximum(100000.000000000000000);
        B5 = new QDoubleSpinBox(centralwidget);
        B5->setObjectName(QString::fromUtf8("B5"));
        B5->setGeometry(QRect(440, 50, 91, 23));
        B5->setMinimum(-100000.000000000000000);
        B5->setMaximum(100000.000000000000000);
        B4 = new QDoubleSpinBox(centralwidget);
        B4->setObjectName(QString::fromUtf8("B4"));
        B4->setGeometry(QRect(370, 51, 53, 23));
        B4->setMinimum(0.000000000000000);
        B4->setMaximum(100000.000000000000000);
        B2 = new QDoubleSpinBox(centralwidget);
        B2->setObjectName(QString::fromUtf8("B2"));
        B2->setGeometry(QRect(190, 50, 91, 23));
        B2->setMinimum(-100000.000000000000000);
        B2->setMaximum(100000.000000000000000);
        C6 = new QDoubleSpinBox(centralwidget);
        C6->setObjectName(QString::fromUtf8("C6"));
        C6->setGeometry(QRect(550, 80, 91, 23));
        C6->setMinimum(-100000.000000000000000);
        C6->setMaximum(100000.000000000000000);
        C1 = new QDoubleSpinBox(centralwidget);
        C1->setObjectName(QString::fromUtf8("C1"));
        C1->setGeometry(QRect(70, 81, 91, 23));
        C1->setMinimum(-100000.000000000000000);
        C1->setMaximum(100000.000000000000000);
        C3 = new QDoubleSpinBox(centralwidget);
        C3->setObjectName(QString::fromUtf8("C3"));
        C3->setGeometry(QRect(300, 81, 53, 23));
        C3->setMinimum(0.000000000000000);
        C3->setMaximum(100000.000000000000000);
        C5 = new QDoubleSpinBox(centralwidget);
        C5->setObjectName(QString::fromUtf8("C5"));
        C5->setGeometry(QRect(440, 80, 91, 23));
        C5->setMinimum(-100000.000000000000000);
        C5->setMaximum(100000.000000000000000);
        C4 = new QDoubleSpinBox(centralwidget);
        C4->setObjectName(QString::fromUtf8("C4"));
        C4->setGeometry(QRect(370, 81, 53, 23));
        C4->setMinimum(0.000000000000000);
        C4->setMaximum(100000.000000000000000);
        C2 = new QDoubleSpinBox(centralwidget);
        C2->setObjectName(QString::fromUtf8("C2"));
        C2->setGeometry(QRect(190, 80, 91, 23));
        C2->setMinimum(-100000.000000000000000);
        C2->setMaximum(100000.000000000000000);
        D6 = new QDoubleSpinBox(centralwidget);
        D6->setObjectName(QString::fromUtf8("D6"));
        D6->setGeometry(QRect(550, 110, 91, 23));
        D6->setMinimum(-100000.000000000000000);
        D6->setMaximum(100000.000000000000000);
        D1 = new QDoubleSpinBox(centralwidget);
        D1->setObjectName(QString::fromUtf8("D1"));
        D1->setGeometry(QRect(70, 111, 91, 23));
        D1->setMinimum(-100000.000000000000000);
        D1->setMaximum(100000.000000000000000);
        D3 = new QDoubleSpinBox(centralwidget);
        D3->setObjectName(QString::fromUtf8("D3"));
        D3->setGeometry(QRect(300, 111, 53, 23));
        D3->setMinimum(0.000000000000000);
        D3->setMaximum(100000.000000000000000);
        D5 = new QDoubleSpinBox(centralwidget);
        D5->setObjectName(QString::fromUtf8("D5"));
        D5->setGeometry(QRect(440, 110, 91, 23));
        D5->setMinimum(-100000.000000000000000);
        D5->setMaximum(100000.000000000000000);
        D4 = new QDoubleSpinBox(centralwidget);
        D4->setObjectName(QString::fromUtf8("D4"));
        D4->setGeometry(QRect(370, 111, 53, 23));
        D4->setMinimum(0.000000000000000);
        D4->setMaximum(100000.000000000000000);
        D2 = new QDoubleSpinBox(centralwidget);
        D2->setObjectName(QString::fromUtf8("D2"));
        D2->setGeometry(QRect(190, 110, 91, 23));
        D2->setMinimum(-100000.000000000000000);
        D2->setMaximum(100000.000000000000000);
        E6 = new QDoubleSpinBox(centralwidget);
        E6->setObjectName(QString::fromUtf8("E6"));
        E6->setGeometry(QRect(550, 140, 91, 23));
        E6->setMinimum(-100000.000000000000000);
        E6->setMaximum(100000.000000000000000);
        E1 = new QDoubleSpinBox(centralwidget);
        E1->setObjectName(QString::fromUtf8("E1"));
        E1->setGeometry(QRect(70, 141, 91, 23));
        E1->setMinimum(-100000.000000000000000);
        E1->setMaximum(100000.000000000000000);
        E3 = new QDoubleSpinBox(centralwidget);
        E3->setObjectName(QString::fromUtf8("E3"));
        E3->setGeometry(QRect(300, 141, 53, 23));
        E3->setMinimum(0.000000000000000);
        E3->setMaximum(100000.000000000000000);
        E5 = new QDoubleSpinBox(centralwidget);
        E5->setObjectName(QString::fromUtf8("E5"));
        E5->setGeometry(QRect(440, 140, 91, 23));
        E5->setMinimum(-100000.000000000000000);
        E5->setMaximum(100000.000000000000000);
        E4 = new QDoubleSpinBox(centralwidget);
        E4->setObjectName(QString::fromUtf8("E4"));
        E4->setGeometry(QRect(370, 141, 53, 23));
        E4->setMinimum(0.000000000000000);
        E4->setMaximum(100000.000000000000000);
        E2 = new QDoubleSpinBox(centralwidget);
        E2->setObjectName(QString::fromUtf8("E2"));
        E2->setGeometry(QRect(190, 140, 91, 23));
        E2->setMinimum(-100000.000000000000000);
        E2->setMaximum(100000.000000000000000);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(660, 120, 171, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(660, 70, 171, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(840, 20, 80, 131));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 16, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout->addWidget(label_13);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 933, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(pushButton, A2);
        QWidget::setTabOrder(A2, A6);
        QWidget::setTabOrder(A6, A3);
        QWidget::setTabOrder(A3, A4);
        QWidget::setTabOrder(A4, A5);
        QWidget::setTabOrder(A5, A1);
        QWidget::setTabOrder(A1, graphicsView);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Iniciar Simulaci\303\263n de 3", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Cuerpo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Posici\303\263n en X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Posici\303\263n en Y", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Masa", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Radio", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Velocidad en X", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Velocidad en Y", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Personalizada", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Iniciar Simulaci\303\263n de 5", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
