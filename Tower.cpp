#include "Tower.h"
#include "TowerBullet.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>
#include <QLineF>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "game.h"

Tower::Tower(QGraphicsScene* Scene, Game* game):Structure() {
    parent = Scene;
    parentGame = game;
    setPixmap(QPixmap(":/mapAssets/Resources/tower.png")
                  .scaled(48, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setAcceptHoverEvents(true);


    healthBar = nullptr;
    maxHealth = 20;
    health = maxHealth;
    costOfWalk = 50;
    qDebug("Tower Created");

    setType(3);

}
double Tower:: distanceTo(QGraphicsItem * item){
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if(event->button() == Qt::LeftButton){
        fire(event->pos());

    }else if(event->button() == Qt::RightButton){
        changeHealth(-1);
    }
}

void Tower::fire(const QPointF &attackDest) {
    if (!parent || !parentGame) {
        qDebug() << "Error: game or game->scene is null";
        return;
    }


    TowerBullet *bullet = new TowerBullet(parent,parentGame);
    bullet->setPos(x() + 20, y() + 30);
    QLineF ln(QPointF(x() + 20, y() + 30), mapToScene(attackDest));
    double angle = -ln.angle();
    bullet->setRotation(angle);
    bullet->setZValue(20);
    parent->addItem(bullet);
}

void Tower::changeHealth(int healthChange){
    if(healthBar == nullptr){
        healthBar = new HealthBar(this, 50, 10, pos().x() + 5, pos().y() + 10, 1);
    }

    if(health + healthChange >= maxHealth){
        health = maxHealth;
        delete healthBar;
        healthBar = nullptr;
    }else if(health + healthChange <= 0){
        //Destruc object and emit game over
        delete healthBar;
        parent->removeItem(this);
        type = 0;
    }else{
        health += healthChange;
        healthBar->updateBar();
    }
    isDamaged();
}

