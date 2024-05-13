#include "settings.h"
#include "ui_settings.h"
#include <QFile>
#include <QDebug>
settings::settings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::settings)
{
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}

void settings::on_back_clicked()
{
    emit back();
    delete this;
}


void settings::on_map_design_clicked()
{
    map_designer_w = new map_designer;
    emit map_design();
    delete this;
}



void settings::on_sound_valueChanged(int value)
{
    QFile sound("sound.txt");
    if(sound.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)){
        QTextStream out(&sound);
        out << QString::number(value);
    }else{
        qDebug("Could not open file to write");
    }
}

