#include "view.h"

View::View(QQuickItem * parent):
    QQuickItem(parent)
{
    timer.setInterval(1000);
    connect(&timer,SIGNAL(timeout()),this,SLOT(iterate()));

    timer.start();

}

void View::iterate()
{
    counter += 1;
    qDebug()<<counter;
}
