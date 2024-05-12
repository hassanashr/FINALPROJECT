#include "closebutton.h"


CloseButton::CloseButton(QWidget* parent): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/mapAssets/Resources/X.png").scaled(50, 50));
    setPos(786 - 100, 0);
    original = parent;
}


void CloseButton::mousePressEvent(QGraphicsSceneMouseEvent * e){
    //Code that quits game
}
