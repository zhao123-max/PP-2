#ifndef QWIDGETDRAWFORSERIALRX_H
#define QWIDGETDRAWFORSERIALRX_H

#include "qwidgetdraw.h"
#include "qwidgetserialrx.h"

class QWidgetDrawForSerialRx : public QWidgetDraw
{
    Q_OBJECT
public:
    QWidgetSerialRx *rece;

    QWidgetDrawForSerialRx(QWidget *parent = nullptr);

    void initReceiver(const QString &pName, int maxD);
    void refreshFromData(char pID, int data);
};

#endif // QWIDGETDRAWFORSERIALRX_H
