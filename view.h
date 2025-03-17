#ifndef VIEW_H
#define VIEW_H

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

    QQuickItem * createBall();

private:
    int counter  = 0;
    QTimer timer;

    QQmlApplicationEngine * engine = nullptr;

    QVector<QQuickItem*> objects;

public slots:
    void iterate();
};

#endif // VIEW_H
