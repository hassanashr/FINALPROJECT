#include "game.h"
#include <QGraphicsScene>
#include "closebutton.h"
#include "graph.h"
#include "Boosters.h"
#include "timerwidget.h"
#include <QAudioOutput>
#include <QMediaPlayer>

Game::Game(int l)
{
    gameScene = new QGraphicsScene();
    gameGraph = new Graph();
    gameScene->setSceneRect(0, 0, 768, 1024);
    setFixedSize(768, 1024);
    setWindowTitle("Clash Of Clans");
    blockPixel = 64;
    currentLevel = l;
    TimerWidget* timer = new TimerWidget(this);
    gameScene->addItem(timer);
    timer->setZValue(50);
    gameAudio = new QAudioOutput();
    gameAudio->setVolume(1);
    gameSound = new QMediaPlayer();
    gameSound->setAudioOutput(gameAudio);
    gameSound->setSource(QUrl("qrc:/sound/26. Combat Music.mp3"));
    gameSound->play();
}

void Game::createGraph()
{
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 12; j++) {
            int cost = 1;
            if (data[i][j] == 1)
                cost = 5;
            else if (data[i][j] == 2)
                cost = 50;
            Cell *newCell = new Cell(i, j, cost);
            gameGraph->addCell(newCell);
        }
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 12; j++) {
            gameGraph->connectNeighbours(i, j);
        }
    }
}

void Game::startLevel()
{
    setScene(gameScene);
    spawnedEnemy.clear();
    buildBoard(":/mapAssets/board1.txt");
    createGraph();
    enemySpawning = new QTimer(this);
    connect(enemySpawning, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    spawnEnemy();
    enemySpawning->start(10000);
    //boosterSpawning = new QTimer(this);
    //connect(boosterSpawning, SIGNAL(timeout()), this, SLOT(spawnBooster()));

}

void Game::Lost() {
    emit lose();
    gameSound->stop();
    delete gameAudio;
    delete gameSound;
    delete this;
}

void Game::Won() {
    emit win();
    gameSound->stop();
    delete gameAudio;
    delete gameSound;
    delete this;
}

void Game::nextLevel() {}

int Game::getLevel()
{
    return currentLevel;
}

int Game::getMapID()
{
    return mapID;
}

double Game::getVolume()
{
    return gameVolume;
}

void Game::setMap() {}

void Game::readData(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QTextStream in(&file);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 12; j++) {
            in >> data[i][j];
        }
    }
}



void Game::spawnEnemy()
{
    int spawnLocation = rand() % 4;
    int x, y;

    switch (spawnLocation) {
    case 0:
        x = 0; // left side
        y = 0; // top side
        break;
    case 1:
        x = 1024; // right side
        y = 0;    // top side
        break;
    case 2:
        x = 0;   // left side
        y = 768; // bottom side
        break;
    case 3:
        x = 1024; // right side
        y = 768;  // bottom side
        break;
    }
    Enemy *enemy = new Enemy(gameScene, x, y);
    gameScene->addItem(enemy);
    spawnedEnemy.append(enemy);
}

void Game::spawnBooster()
{
    Booster* booster = new Booster(gameScene);
    gameScene->addItem(booster);
}

void Game::buildBoard(QString filePath)
{
    readData(filePath);
    QPixmap gridTile(":/mapAssets/Grass.png");
    gridTile = gridTile.scaled(blockPixel, blockPixel);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 12; j++) {
            mapTile[i][j] = new QGraphicsPixmapItem(gridTile);
            mapTile[i][j]->setPos(j * blockPixel, i * blockPixel);
            gameScene->addItem(mapTile[i][j]);
            if (data[i][j] == 1) {
                Wall *w = new Wall(gameScene);
                w->setPos(j * blockPixel, i * blockPixel);
                gameScene->addItem(w);
                w->setZValue(3);

            } else if (data[i][j] == 2) {
                Tower *t = new Tower(gameScene, this);
                t->setPos(j * blockPixel, i * blockPixel);
                gameScene->addItem(t);
                t->setZValue(3);

            } else if (data[i][j] == 3) {
                Castle *c = new Castle(gameScene, this);
                c->setPos(j * blockPixel, i * blockPixel);
                gameScene->addItem(c);
                c->setZValue(3);
            }
        }
    }
}
