#include "view.h"

View::View(QQuickItem * parent):
    QQuickItem(parent)
{
    timer.setInterval(17);
    connect(&timer,SIGNAL(timeout()),this,SLOT(iterate()));

    timer.start();

}

void View::initialize()
{
    //finds application engine pointer
    engine = qobject_cast<QQmlApplicationEngine*>(QQmlEngine::contextForObject(this)->engine());

    for(int i=0; i<3; i++){
        objects.append(createBall());
    }

    objects[0]->setPosition(QPointF(60,60));
    objects[1]->setPosition(QPointF(600,450));
    objects[2]->setPosition(QPointF(300,500));

}

Ball* View::createBall()
{
    Ball * ball = new Ball();
    QQmlComponent component(engine, QUrl::fromLocalFile("ThreeBody/PaintBallQML.qml"));
    QQuickItem* object = qobject_cast<QQuickItem*>(component.create());
    object->setParentItem(this);
    object->setParent(engine);
    ball->setPaintball(object);
    return ball;
}

void View::iterate()
{
    for(int i=0; i<objects.length(); i++){

        QVector2D velocity = objects[i]->getVelocity();
        objects[i]->setPosition(objects[i]->position() + velocity.toPointF());

        objects[i]->setVelocity(velocity + QVector2D(0,0.05));

        if(objects[i]->position().y() + 100 > height()){
            objects[i]->setPosition(QPointF(objects[i]->position().x(),height()-100));
            objects[i]->setVelocity(objects[i]->getVelocity() * -0.9);
        }

    }
}
