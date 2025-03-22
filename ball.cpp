#include "ball.h"

Ball::Ball() {}

void Ball::setPosition(QPointF position)
{
    paintball->setPosition(position);
}
QPointF Ball::position()
{
    return paintball->position();
}
