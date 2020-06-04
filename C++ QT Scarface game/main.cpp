#include <QApplication>
#include<QGraphicsScene>
#include <QGraphicsView>
#include "MyRect.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>
#include<QGraphicsItem>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    MyRect *item = new MyRect();

    //item->setRect(0,0,100,100);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();

    scene->addItem(item);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/backgroundscface.jpg")));

   // item->setPos(view->width()/2,view->height()-item->rect().height());

QTimer *timer = new QTimer();
QObject::connect(timer,SIGNAL(timeout()),item,SLOT(spawn()));
timer->start(5000);

QMediaPlayer *music = new QMediaPlayer();
music->setMedia(QUrl("qrc:/sounds/bakrnd.mp3"));
music->play();















    return a.exec();
}
