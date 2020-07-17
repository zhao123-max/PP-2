#ifndef QLABELCLOCK_H
#define QLABELCLOCK_H


#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>
#include <QDateTime>

class QLabelClock : public QLabel
{
    Q_OBJECT
public:
    QTimer *timer;
    int toggle = 1;
    QLabelClock(QWidget *parent);
    void refresh();
    void mousePressEvent(QMouseEvent *ev) override;
};

#endif // QLABELCLOCK_H
