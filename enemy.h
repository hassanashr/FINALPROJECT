#ifndef ENEMY_H
#define ENEMY_H

#include <castle.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QTimer>
#include <Wall.h>
class Tower;
class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    double levelSpeed[5] = {2, 2.5, 3, 3.5, 3.75};
    double levelHealth[5] = {15, 20, 25, 30, 32.5};
    double levelDamage[5] = {5, 6, 6.5, 7, 7.5};
    double maxHealth;
    double currHealth;
    double currSpeed;
    double currDamage;
    QList<QPixmap> animatedAttack;
    QList<QPixmap> animatedWalk;
    QList<QPixmap> animatedDeath;
    QTimer *animatedWalkTimer;
    QTimer *animatedAttackTimer;
    QTimer *animatedDeathTimer;
    QTimer *movementTimer;
    QTimer *cooldownTimer;
    int currentWalkFrame = 0;
    int currentAttackFrame = 0;
    int currentDeathFrame = 0;
    int animationInterval = 100;
    bool isAttackOver;
    bool toRight;
    bool isDead = false;
    bool inAttack = false;


public:
    Enemy(QGraphicsScene*, int, int);
    ~Enemy();

    //setters
    void setDamage(double d);
    void setSpeed(double s);
    void setHealth(double h);
    void increaseHealth(double h);
    void decreaseHealth(double h);
    void setFrame(int frameIndex);
    //getters
    double getDamage();
    double getSpeed();
    double getHealth();
    double getMaxHealth();

    //functionalities
    void attackCastle(Castle *);
    void attackWall(Wall *);
    void attackTower(Tower *);
    void startWalkingAnimation();
    void startAttackingAnimation();
    void startDeathAnimation();
    void updatePixmap();
    void updateHealth(int);

    //Public variable to allow healthBar to be added to the game scene
    QGraphicsScene* parentScene;

public slots:
    void movePath();
    void advanceWalkFrame();
    void advanceAttackFrame();
    void advanceDeathFrame();
    void cooldownTime();
    void die();
};

#endif // ENEMY_H
