#ifndef GAME_H
#define GAME_H
#include <QFile>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTextStream>
#include <QTimer>
#include <QWidget>
#include <castle.h>
#include <cell.h>
#include <enemy.h>
#include <graph.h>
#include <tower.h>
#include <wall.h>
class Enemy;
class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(int l);
    Graph *gameGraph;
    QGraphicsScene *gameScene;

    void buildBoard(QString filePath);
    void readData(QString filePath);
    void createGraph();
    void startLevel();
    void Lost();
    void Won();
    void nextLevel();

    //getters
    int getLevel();
    int getMapID();
    double getVolume();

    //setters
    void setMap();

private:
    QGraphicsView *gameView;
    int data[16][12];
    QGraphicsPixmapItem *mapTile[16][12];
    int blockPixel;
    int currentLevel;
    int mapID;
    double gameVolume;
    void makeGraph();
    void readData();
    void saveData();
    void makeBoard();

    QTimer *enemySpawning;
    QTimer *boosterSpawning;

    QList<Enemy *> spawnedEnemy;
    QList<Wall *> damagedWall;

signals:
    void win();
    void lose();

public slots:
    void spawnEnemy();
    void spawnBooster();
};

#endif // GAME_H
