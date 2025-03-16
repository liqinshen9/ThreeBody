#include "paintball.h"

PaintBall::PaintBall(QQuickItem * parent):
    QQuickPaintedItem(parent)
{

}

void PaintBall::paint(QPainter *painter)
{
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::black);

    painter->setBrush(Qt::NoBrush);
    painter->setPen(pen);

    painter->drawEllipse(0,0,width()-1,height()-1);
}
