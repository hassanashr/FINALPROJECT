/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QLabel *sound_value;
    QSlider *sound;
    QLabel *sound_label;
    QLabel *label;
    QPushButton *back;

    void setupUi(QWidget *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName("settings");
        settings->resize(768, 1024);
        sound_value = new QLabel(settings);
        sound_value->setObjectName("sound_value");
        sound_value->setGeometry(QRect(660, 350, 71, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        sound_value->setFont(font);
        sound_value->setAlignment(Qt::AlignCenter);
        sound = new QSlider(settings);
        sound->setObjectName("sound");
        sound->setGeometry(QRect(418, 350, 226, 22));
        sound->setBaseSize(QSize(0, 26));
        sound->setFont(font);
        sound->setStyleSheet(QString::fromUtf8(""));
        sound->setMaximum(100);
        sound->setSingleStep(5);
        sound->setPageStep(1);
        sound->setOrientation(Qt::Horizontal);
        sound_label = new QLabel(settings);
        sound_label->setObjectName("sound_label");
        sound_label->setGeometry(QRect(20, 320, 331, 71));
        sound_label->setFont(font);
        sound_label->setAlignment(Qt::AlignCenter);
        label = new QLabel(settings);
        label->setObjectName("label");
        label->setGeometry(QRect(67, 50, 630, 181));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana Pro Cond Black")});
        font1.setPointSize(48);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        back = new QPushButton(settings);
        back->setObjectName("back");
        back->setGeometry(QRect(100, 610, 561, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        font2.setBold(false);
        font2.setItalic(false);
        back->setFont(font2);
        back->setStyleSheet(QString::fromUtf8(" background-color: rgb(238,215,161);\n"
"    border-style: solid;\n"
"    color:  rgb(71,92,108);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(205,139,98);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));

        retranslateUi(settings);

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QWidget *settings)
    {
        settings->setWindowTitle(QCoreApplication::translate("settings", "Form", nullptr));
        sound_value->setText(QString());
        sound_label->setText(QCoreApplication::translate("settings", "<html><head/><body><p><span style=\" font-size:24pt;\">Sound Volume</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("settings", "Settings", nullptr));
        back->setText(QCoreApplication::translate("settings", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
