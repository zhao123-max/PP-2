#include "qlabeltext.h"

QLabelText::QLabelText(QWidget *parent, const QString& text, const QString& styleSheet): QLabel(parent)
{
    this->setText(text);
    this->setStyleSheet(styleSheet);
}
