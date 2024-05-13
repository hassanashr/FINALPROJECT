#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "map_designer.h"
#include "game.h"
namespace Ui {
class settings;
}

class settings : public QWidget
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    explicit settings(Game *);
    ~settings();
    map_designer * map_designer_w;
signals:
    void back();
    void map_design();
private slots:
    void on_back_clicked();

    void on_map_design_clicked();


    void on_sound_valueChanged(int value);

private:
    Ui::settings *ui;
    Game * game_w;
};

#endif // SETTINGS_H
