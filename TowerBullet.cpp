#include "TowerBullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "enemy.h"
#include "Boosters.h"
int TowerBullet::count = 0;
int TowerBullet::stepsize_spirte = 10;
TowerBullet::TowerBullet(QGraphicsScene* Scene, Game* game):Structure() {
    setPixmap(QPixmap(":/mapAssets/Bomb3.png"));
    move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);
    parent = Scene;
    parentGame = game;
    damage = 5;
    damageIncreasedCount = 0;
}

TowerBullet::~TowerBullet()
{
    delete move_timer;
}

void TowerBullet::move(){
    double theta = rotation();

    double dy = stepsize_spirte * qSin(qDegreesToRadians(theta));
    double dx = stepsize_spirte * qCos(qDegreesToRadians(theta));
    setPos(pos().x() + dx, pos().y() + dy);

    QList<QGraphicsItem *> collidedItems = collidingItems();

    for (auto item : collidedItems) {
        if (typeid(*item) == typeid(Enemy)) {
            Enemy* enemy = dynamic_cast<Enemy*>(item);
            enemy->decreaseHealth(damage);
            qDebug() << "Bullet collided with enemy";
            scene()->removeItem(this);


            if (enemy->getHealth() <= 0) {
                parent->removeItem(enemy);
                deleteLater();
                count++;
                qDebug() << "Enemy destroyed! Count: " << count;
            }
        }

        if (typeid(*item) == typeid(Booster)) {
            Booster* booster = dynamic_cast<Booster*>(item);
            scene()->removeItem(this);
            parent->removeItem(booster);
            stepsize_spirte = stepsize_spirte + 30;
            qDebug() <<"sprite" << stepsize_spirte;
        }

        if (count >= 20 * (damageIncreasedCount + 1)) {
            damage = damage + (damage * 0.1);
            damageIncreasedCount++;
            qDebug() << "Increased bullet damage to" << damage << "after" << count << "kills";
        }
    }
}
