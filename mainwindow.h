#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map_designer.h"
#include "settings.h"
#include "win.h"
#include "lose.h"
#include "game.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_clicked();

    void on_settings_clicked();

    void reset();

    void map_design();

    void back_to_settings();
    void on_exit_clicked();
    void begin_game();

    void won();

    void lost();



private:
    Ui::MainWindow *ui;
    Game * game_w;
    settings * settings_w;
    win* win_w;
    lose* lose_w;
    int current_level;
};

#endif // MAINWINDOW_H
