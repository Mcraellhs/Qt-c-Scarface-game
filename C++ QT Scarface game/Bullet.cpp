#include "Bullet.h"
#include <QTimer>
#include <QList>
#include "Enemy.h"
Bullet::Bullet()
{

   setPixmap(QPixmap(":/images/bullet.png"));
QTimer *timer = new QTimer();
connect(timer,SIGNAL(timeout()),this,SLOT(move()));
timer->start(50);
}

void Bullet::move()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy)){
                // remove them both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them both
                delete colliding_items[i];
                delete this;
                return;
            }
        }
   setPos(x(),y()-10);

   if(pos().y()<0){
scene()->removeItem(this);
delete this;
   }
}
