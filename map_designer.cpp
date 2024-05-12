#include "map_designer.h"
#include "ui_map_designer.h"
#include <QGraphicsRectItem>
map_designer::map_designer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::map_designer)
{
    ui->setupUi(this);
}
map_designer::map_designer(Game* game)
    : QWidget(nullptr)
    , ui(new Ui::map_designer)
{
    ui->setupUi(this);
    game_w = game;
}
map_designer::~map_designer()
{
    delete ui;
}

void map_designer::on_back_clicked()
{
    emit back();
    delete this;
}


void map_designer::on_Grass_clicked()
{
    emit grass();
}


void map_designer::on_Stone_clicked()
{
    emit stone();
}

