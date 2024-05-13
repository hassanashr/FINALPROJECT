#ifndef TOWERBULLET_H
#define TOWERBULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "structure.h"
#include "game.h"
#include <QTimer>
class TowerBullet : public Structure{
    Q_OBJECT
public:
    TowerBullet(QGraphicsScene* Scene, Game* game);
    ~TowerBullet();
    Game* parentGame;
    QGraphicsScene* parentScene;
    QTimer * move_timer;
      static int count;
    static int stepsize_spirte;
      int damage;
    int damageIncreasedCount;
public slots:
    void move();
private:
    int counter;


};



#endif // TOWERBULLET_H
