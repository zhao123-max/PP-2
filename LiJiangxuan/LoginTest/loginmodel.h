#ifndef LOGINMODEL_H
#define LOGINMODEL_H

#include <QObject>

class LoginModel : public QObject
{
    Q_OBJECT
public:
    QString *username;
    QString *password;


    explicit LoginModel(QObject *parent = nullptr);

signals:

};

#endif // LOGINMODEL_H
