#ifndef VIEW_H
#define VIEW_H

#include <ball.h>

#include <QTimer>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QQmlContext> //needed to find engine

class View: public QQuickItem
{
    Q_OBJECT
public:
    View(QQuickItem * parent = nullptr);

    Q_INVOKABLE void initialize();

    Ball * createBall();

private:
    int counter  = 0;
    QTimer timer;

    QQmlApplicationEngine * engine = nullptr;

    QVector<Ball*> objects;

public slots:
    void iterate();
};

#endif // VIEW_H
