#include "Wall.h"
#include <QDebug>
#include <iostream>
Wall::Wall(QGraphicsScene *scene)
    : Structure()
{
    setPixmap(QPixmap(":/mapAssets/Resources/Wall.png")
                  .scaled(48, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    parent = scene;
    setType(2);
    setMaxHealth(20);
    setHealth(getMaxHealth());
    setCost((getHealth() / getMaxHealth()) * 100);
    healthBar = nullptr;
}

Wall::~Wall() {}

void Wall::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        changeHealth(-2);

    }else if(e->button() == Qt::RightButton){
        changeHealth(1);

    }
}

void Wall::changeHealth(int healthChange)
{
    if(healthBar == nullptr){
        healthBar = new HealthBar(this, 50, 10, pos().x() + 5, pos().y() + 10, 1);
    }

    if (getHealth() + healthChange >= getMaxHealth()) {
        setHealth(getMaxHealth());
        qDebug("Before Delete Health: Restored");
        delete healthBar;
        qDebug("After Delete HealthBar: Restored");
        healthBar = nullptr;
    } else if (getHealth() + healthChange <= 0) {
        //Destruc object and emit game over
        qDebug("Before Delete Health: Destroy");
        delete healthBar;
        qDebug("After Delete HealthBar: Destory");
        parent->removeItem(this);
        setType(0);
        qDebug("After Wall is Destroyed");
    } else {
        setHealth(getHealth() + healthChange);
        healthBar->updateBar();
    }
    isDamaged();
}
