/********************************************************************************
** Form generated from reading UI file 'win.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_H
#define UI_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_win
{
public:
    QPushButton *next;
    QPushButton *back;
    QLabel *label;

    void setupUi(QWidget *win)
    {
        if (win->objectName().isEmpty())
            win->setObjectName("win");
        win->resize(768, 1024);
        next = new QPushButton(win);
        next->setObjectName("next");
        next->setGeometry(QRect(110, 410, 561, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setBold(false);
        font.setItalic(false);
        next->setFont(font);
        next->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        back = new QPushButton(win);
        back->setObjectName("back");
        back->setGeometry(QRect(110, 510, 561, 81));
        back->setFont(font);
        back->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        label = new QLabel(win);
        label->setObjectName("label");
        label->setGeometry(QRect(77, 60, 630, 181));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana Pro Cond Black")});
        font1.setPointSize(48);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(win);

        QMetaObject::connectSlotsByName(win);
    } // setupUi

    void retranslateUi(QWidget *win)
    {
        win->setWindowTitle(QCoreApplication::translate("win", "Form", nullptr));
        next->setText(QCoreApplication::translate("win", "Next Level", nullptr));
        back->setText(QCoreApplication::translate("win", "Main Menu", nullptr));
        label->setText(QCoreApplication::translate("win", "YOU WIN!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class win: public Ui_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_H
