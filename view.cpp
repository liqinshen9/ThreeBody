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
    objects[0]->setVelocity(QVector2D(2,0));
    objects[1]->setVelocity(QVector2D(-1,0));
    objects[2]->setVelocity(QVector2D(3,0));
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
            QVector2D v = objects[i]->getVelocity();
            QVector2D new_v = QVector2D(v.x(),v.y() * -0.9);
            objects[i]->setVelocity(new_v);
        }
        if(objects[i]->position().x() + 100 > width()){
            objects[i]->setPosition(QPointF(width()-100,objects[i]->position().y()));
            QVector2D v = objects[i]->getVelocity();
            QVector2D new_v = QVector2D(v.x()*-0.9,v.y());
            objects[i]->setVelocity(new_v);
        }
        if(objects[i]->position().x()< 0){
            objects[i]->setPosition(QPointF(0,objects[i]->position().y()));
            QVector2D v = objects[i]->getVelocity();
            QVector2D new_v = QVector2D(v.x()*-0.9,v.y());
            objects[i]->setVelocity(new_v);
        }



    }
}
