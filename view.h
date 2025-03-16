#ifndef VIEW_H
#define VIEW_H

#include <QTimer>
#include <QQuickItem>

class View: public QQuickItem
{
    Q_OBJECT
public:
    View(QQuickItem * parent = nullptr);

private:
    int counter  = 0;
    QTimer timer;

public slots:
    void iterate();
};

#endif // VIEW_H
