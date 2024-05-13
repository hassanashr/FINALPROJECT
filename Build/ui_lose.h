/********************************************************************************
** Form generated from reading UI file 'lose.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSE_H
#define UI_LOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lose
{
public:
    QLabel *label;
    QPushButton *retry;
    QPushButton *back;

    void setupUi(QWidget *lose)
    {
        if (lose->objectName().isEmpty())
            lose->setObjectName("lose");
        lose->resize(768, 1024);
        label = new QLabel(lose);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 630, 181));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana Pro Cond Black")});
        font.setPointSize(48);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        retry = new QPushButton(lose);
        retry->setObjectName("retry");
        retry->setGeometry(QRect(103, 440, 561, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setBold(false);
        font1.setItalic(false);
        retry->setFont(font1);
        retry->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        back = new QPushButton(lose);
        back->setObjectName("back");
        back->setGeometry(QRect(103, 540, 561, 81));
        back->setFont(font1);
        back->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));

        retranslateUi(lose);

        QMetaObject::connectSlotsByName(lose);
    } // setupUi

    void retranslateUi(QWidget *lose)
    {
        lose->setWindowTitle(QCoreApplication::translate("lose", "Form", nullptr));
        label->setText(QCoreApplication::translate("lose", "YOU LOSE!", nullptr));
        retry->setText(QCoreApplication::translate("lose", "Retry", nullptr));
        back->setText(QCoreApplication::translate("lose", "Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lose: public Ui_lose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSE_H
