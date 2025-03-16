#ifndef PAINTBALL_H
#define PAINTBALL_H

#include <QQuickPaintedItem>
#include <QPainter>

class PaintBall: public QQuickPaintedItem
{
    Q_OBJECT
public:
    PaintBall(QQuickItem * parent = nullptr);

    void paint(QPainter * painter);
};

#endif // PAINTBALL_H
