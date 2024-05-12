#ifndef WORKER_H
#define WORKER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <Wall.h>
#include <QPointF>
#include "structure.h"

class Wall;

class Worker : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int healing;
    double currSpeed;
    int xHome, yHome;

    //Timers and their Pixmaps
    QTimer *moveTimer;
    QTimer *walkTimer;
    QTimer *healingTimer;
    QTimer *deathTimer;
    QTimer *returnTimer;
    QList<QPixmap> movingAnimation;
    QList<QPixmap> healingAnimation;
    QList<QPixmap> deathAnimation;
    int currentWalkFrame = 0;
    int currentHealthFrame = 0;
    int currentDeathFrame = 0;
    int animationInterval = 100;
    bool doneHealingAnimation;
    bool toRight;
    bool isDead = false;

    //Location to go
    QPointF* destination;
    Structure* structToFix;

public:
    Worker(int, int);
    ~Worker();

    //getters
    int getHealing();
    bool isDone();
    static int currentWorkers;
    static int maxWorkers;

    //setters
    void setHealing(int h);
    void decreaseHealth(int h);
    void setDestination(QPointF*);
    void setStruct(Structure*);

    //functionalities
    void healWall(Wall *&);
    void Die();
    void returnHome();
    void stopWorking();

    //Update animation
    void startWalkingAnimation();
    void startHealingAnimation();
    void startDeathAnimation();
    void updatePixmap();

    //To allow the spawner direct access to its avialability
    bool doneHealing;

signals:
    void finishedTask();

public slots:
    void movePath();
    void advanceWalkFrame();
    void advanceHealFrame();
    void advanceDeathFrame();
    void cooldownTime();
    void deleteWorker();
};

#endif // WORKER_H
