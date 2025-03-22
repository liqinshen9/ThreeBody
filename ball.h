#ifndef BALL_H
#define BALL_H

#include <QQuickItem>
#include <QVector2D>

class Ball
{
public:
    Ball();

    void setVelocity(QVector2D v){velocity = v;}
    QVector2D getVelocity(){return velocity;}

    void setPaintball(QQuickItem * object){paintball = object;}

    void setPosition(QPointF position);
    QPointF position();

private:
    QVector2D velocity;
    QQuickItem * paintball = nullptr;

};

#endif // BALL_H
