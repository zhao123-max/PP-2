#include "loginmodel.h"

LoginModel::LoginModel(QPushButton *btn, QObject *parent) : QObject(parent), btn(btn)
{

    connect(this->btn, &QPushButton::clicked, this, &LoginModel::loginBtnClicked);

}

void LoginModel::setLoginBtn(QPushButton *btn)
{
    this->btn = btn;
}

void LoginModel::loginBtnClicked()
{
    qDebug()<<"Clicked";
}

// todo 初始化
