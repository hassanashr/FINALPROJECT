#ifndef MAP_DESIGNER_H
#define MAP_DESIGNER_H
#include "game.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
namespace Ui {
class map_designer;
}

class map_designer : public QWidget
{
    Q_OBJECT

public:
    explicit map_designer(QWidget *parent = nullptr);
    explicit map_designer(Game *);
    ~map_designer();
signals:
    void back();
    void grass();
    void stone();
private slots:
    void on_back_clicked();

    void on_Grass_clicked();

    void on_Stone_clicked();

private:
    Ui::map_designer *ui;
    Game * game_w;
    QGridLayout* layout;
    QGraphicsScene * scene;
    QGraphicsView * view;
};

#endif // MAP_DESIGNER_H
