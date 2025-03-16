#ifndef VIEW_H
#define VIEW_H

#include <QQuickItem>

class View: public QQuickItem
{
    Q_OBJECT
public:
    View(QQuickItem * parent = nullptr);
};

#endif // VIEW_H
