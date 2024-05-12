#include "lose.h"
#include "ui_lose.h"

lose::lose(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lose)
{
    ui->setupUi(this);
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

