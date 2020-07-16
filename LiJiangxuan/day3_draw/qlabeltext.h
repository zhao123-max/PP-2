#ifndef QLABELTEXT_H
#define QLABELTEXT_H

#include <QLabel>

class QLabelText : public QLabel
{
    Q_OBJECT
public:
    QLabelText(QWidget *parent = nullptr, const QString& text = "a label text", const QString& styleSheet = "font-size: 20px");
};

#endif // QLABELTEXT_H
