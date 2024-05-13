/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QPushButton *start;
    QPushButton *exit;
    QPushButton *settings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(768, 1024);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 60, 630, 181));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana Pro Cond Black")});
        font.setPointSize(48);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        start->setGeometry(QRect(103, 350, 561, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setBold(false);
        font1.setItalic(false);
        start->setFont(font1);
        start->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(103, 550, 561, 81));
        exit->setFont(font1);
        exit->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        settings = new QPushButton(centralwidget);
        settings->setObjectName("settings");
        settings->setGeometry(QRect(103, 450, 561, 81));
        settings->setFont(font1);
        settings->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 768, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Tower Defence", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
