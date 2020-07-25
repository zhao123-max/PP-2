#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建 layout
    QHBoxLayout *layoutUsername = new QHBoxLayout();
    QHBoxLayout *layoutPassword = new QHBoxLayout();
    QVBoxLayout *layoutMain = new QVBoxLayout();

    // 添加控件
    layoutUsername->addWidget(new QLabel("用户名:"));
    layoutPassword->addWidget(new QLabel("密  码:"));

    // 创建文本框
    QLineEdit *lineEditUserName = new QLineEdit();
    QLineEdit *lineEditPassword = new QLineEdit();
    lineEditPassword->setEchoMode(QLineEdit::Password);

    layoutUsername->addWidget(lineEditUserName);
    layoutPassword->addWidget(lineEditPassword);

    layoutMain->addLayout(layoutUsername);
    layoutMain->addLayout(layoutPassword);

//    添加一个按钮
     QPushButton *btn = new QPushButton("登录");
     layoutMain->addWidget(btn);


    QWidget *widgetMain = new QWidget();
    widgetMain->resize(600, 400);

    widgetMain->setLayout(layoutMain);
    widgetMain->show();

    return a.exec();
}
