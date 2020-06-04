#include "MyRect.h"
#include <QKeyEvent>
#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include <QMediaPlayer>


QMediaPlayer *pla = new QMediaPlayer();





MyRect::MyRect()
{
    setPixmap(QPixmap(":/images/tonymontana.png"));

}

void MyRect::keyPressEvent(QKeyEvent *event){

   if(event->key()==Qt::Key_Left){

       if(pos().x()>0){
       setPos(x()-10,y());

}
   }

   else if (event->key() == Qt::Key_Right){
       if(pos().x()+100<800){
        setPos(x()+10,y());
       }
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);

}
    else if (event->key() == Qt::Key_Space){
       Bullet *bullet = new Bullet();
       bullet->setPos(x(),y());
       scene()->addItem(bullet);
       pla->setMedia(QUrl("qrc:/sounds/bullet.mp3"));
       pla->play();
   }
}

void MyRect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
