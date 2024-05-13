#include "win.h"
#include "ui_win.h"
#include <QAudioOutput>
#include <QMediaPlayer>
win::win(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::win)
{
    ui->setupUi(this);
    QAudioOutput* gameAudio = new QAudioOutput();
    gameAudio->setVolume(50);
    QMediaPlayer* gameSound = new QMediaPlayer();
    gameSound->setAudioOutput(gameAudio);
    gameSound->setSource(QUrl("qrc:/sound/win.mpeg"));
    gameSound->play();
}

win::~win()
{
    delete ui;
}

void win::on_next_clicked()
{
    emit next();
    delete this;
}


void win::on_back_clicked()
{
    emit back();
    delete this;
}

