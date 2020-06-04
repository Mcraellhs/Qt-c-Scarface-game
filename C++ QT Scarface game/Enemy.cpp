#include "Enemy.h"
#include <QTimer>
#include <stdlib.h>
Enemy::Enemy()
{

    setPos((rand()%700)+100,0);

    setPixmap(QPixmap(":/images/police.jpg"));
QTimer *timer = new QTimer();
connect(timer,SIGNAL(timeout()),this,SLOT(move()));
timer->start(50);
}

void Enemy::move()
{
   setPos(x(),y()+5);

   if(pos().y()<0){
scene()->removeItem(this);
delete this;
   }
}
