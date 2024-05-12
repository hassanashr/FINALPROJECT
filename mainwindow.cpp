#include "mainwindow.h"
#include "game.h"
#include "map_designer.h"
#include "settings.h"
#include "ui_mainwindow.h"
#include <iostream>

extern Game *game;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    current_level = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::won(){
    current_level++;
    win_w = new win();
    setCentralWidget(win_w);
    QObject::connect(win_w,&win::back,this,&MainWindow::reset);
    QObject::connect(win_w,&win::next,this,&MainWindow::begin_game);
//add connections
}
void MainWindow::lost(){
    lose_w = new lose();
    setCentralWidget(lose_w);
    QObject::connect(lose_w,&lose::back,this,&MainWindow::reset);
    QObject::connect(lose_w,&lose::retry,this,&MainWindow::begin_game);
    //add connections
}
void MainWindow::on_start_clicked()
{
    begin_game();
}
void MainWindow::begin_game(){
    game = new Game(current_level);
    setCentralWidget(game);
    QObject::connect(game,&Game::win,this,&MainWindow::won);
    QObject::connect(game,&Game::lose,this,&MainWindow::lost);
    game->startLevel();
    qDebug() << "After start.";
}
void MainWindow::on_settings_clicked()
{
    /* Code for switching to settings widget
    settings_w = new settings();
    QObject::connect(settings_w,&settings::back,this,&MainWindow::reset);
    QObject::connect(settings_w,&settings::map_design,this,&MainWindow::map_design);
    setCentralWidget(settings_w);
    */
}
void MainWindow::back_to_settings(){
    setCentralWidget(settings_w);
}
void MainWindow::map_design(){
    //settings_w->map_designer_w = new map_designer;
    //QObject::connect(settings_w->map_designer_w,&map_designer::back,this,&MainWindow::back_to_settings);
    //setCentralWidget(settings_w->map_designer_w);
}
void MainWindow::reset(){
    ui->setupUi(this);
}

void MainWindow::on_exit_clicked()
{
    this->close();
}
