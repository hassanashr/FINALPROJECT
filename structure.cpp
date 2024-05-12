#include "structure.h"
#include "worker.h"

Structure::Structure(): QObject(), QGraphicsPixmapItem() {
    health = 0;
}

double Structure::getHealth()
{
    return health;
}

double Structure::getMaxHealth()
{
    return maxHealth;
}

int Structure::getType()
{
    return type;
}

int Structure::getX()
{
    return xx;
}
int Structure::getY()
{
    return yy;
}



void Structure::changeHealth(int x)
{
    //Update health
    health += x;
}

void Structure::setPosition(int xPos, int yPos)
{
    xx = xPos;
    yy = yPos;
    //Sets the position of the structure into an appropriate position according to 13x13 grid
    if(xx > 12 || xx < 0)
        return;
    if(yy > 12 || yy < 0)
        return;
    //The offsets is due to the upper bar containing health, close button, timer, and score.
    setPos(xx*61+1, yy*57 + 51);

}

void Structure::setType(int t)
{
    type = t;
}

void Structure::setHealth(double h)
{
    health = h;
}

void Structure::setMaxHealth(double h)
{
    maxHealth = h;
}

void Structure::setCost(double c)
{
    costOfWalk = c;
}



bool Structure::isDamaged()
{
    //Used to check if the strucutre is damaged and emit a signal for the worker to spawn
    if(!requestedAid && health < maxHealth && Worker::currentWorkers < Worker::maxWorkers){
        requestedAid = true;
        Worker* worker = new Worker(6*61+1, 6*57 + 51);
        worker->setStruct(this);
        parent->addItem(worker);
    }
    if(health >= maxHealth)
        requestedAid = false;
    qDebug() << Worker::currentWorkers;
    return health < maxHealth;
}
