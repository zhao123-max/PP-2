#ifndef LOGINMODEL_H
#define LOGINMODEL_H

#include <QObject>
#include <QPushButton>
#include <QDebug>

class LoginModel : public QObject
{
    Q_OBJECT
public:
    QString *username;
    QString *password;

    QPushButton *btn;

    explicit LoginModel(QPushButton *btn, QObject *parent = nullptr);

    void setLoginBtn(QPushButton *btn);

private slots:
    void loginBtnClicked();

signals:

};

#endif // LOGINMODEL_H
