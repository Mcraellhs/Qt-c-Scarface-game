
#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"

Game::Game(QWidget* parent){


    QGraphicsScene *scene = new QGraphicsScene();

    MyRect *item = new MyRect();

    item->setRect(0,0,100,100);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();

    scene->addItem(item);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    item->setPos(view->width()/2,view->height()-item->rect().height());

QTimer *timer = new QTimer();
QObject::connect(timer,SIGNAL(timeout()),item,SLOT(spawn()));
timer->start(4000);




show();









}
