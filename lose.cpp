#include "lose.h"
#include "ui_lose.h"
#include <QAudioOutput>
#include <QMediaPlayer>
lose::lose(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lose)
{
    ui->setupUi(this);
    QAudioOutput* gameAudio = new QAudioOutput();
    gameAudio->setVolume(50);
    QMediaPlayer* gameSound = new QMediaPlayer();
    gameSound->setAudioOutput(gameAudio);
    gameSound->setSource(QUrl("qrc:/sound/lose.mpeg"));
    gameSound->play();
}

lose::~lose()
{
    delete ui;
}

void lose::on_retry_clicked()
{
    emit retry();
    delete this;
}


void lose::on_back_clicked()
{
    emit back();
    delete this;
}

