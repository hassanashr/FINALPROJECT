/********************************************************************************
** Form generated from reading UI file 'map_designer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_DESIGNER_H
#define UI_MAP_DESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_map_designer
{
public:
    QPushButton *back;
    QPushButton *Grass;
    QPushButton *Stone;
    QLabel *label;

    void setupUi(QWidget *map_designer)
    {
        if (map_designer->objectName().isEmpty())
            map_designer->setObjectName("map_designer");
        map_designer->resize(768, 1024);
        back = new QPushButton(map_designer);
        back->setObjectName("back");
        back->setGeometry(QRect(100, 650, 561, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setBold(false);
        font.setItalic(false);
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
        Grass = new QPushButton(map_designer);
        Grass->setObjectName("Grass");
        Grass->setGeometry(QRect(60, 350, 291, 91));
        Grass->setFont(font);
        Grass->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        Stone = new QPushButton(map_designer);
        Stone->setObjectName("Stone");
        Stone->setGeometry(QRect(420, 350, 291, 91));
        Stone->setFont(font);
        Stone->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        label = new QLabel(map_designer);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 50, 630, 181));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana Pro Cond Black")});
        font1.setPointSize(48);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(map_designer);

        QMetaObject::connectSlotsByName(map_designer);
    } // setupUi

    void retranslateUi(QWidget *map_designer)
    {
        map_designer->setWindowTitle(QCoreApplication::translate("map_designer", "Form", nullptr));
        back->setText(QCoreApplication::translate("map_designer", "Back", nullptr));
        Grass->setText(QCoreApplication::translate("map_designer", "Grass", nullptr));
        Stone->setText(QCoreApplication::translate("map_designer", "Stone", nullptr));
        label->setText(QCoreApplication::translate("map_designer", "Choose Theme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class map_designer: public Ui_map_designer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_DESIGNER_H
