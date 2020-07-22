#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QDateTime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // 服务器地址 本地 远程 IP 或者 域名
    db.setHostName("localhost");
    // 数据库名
    db.setDatabaseName("medical_monitor1");
    // 用户名及密码
    db.setUserName("doctor3");
    db.setPassword("1234567");
    bool openOK = db.open();

    if (openOK)
        qDebug()<<"OK";
    else
        qDebug()<<"BAD";

    if (openOK)
    {
        // 查询 db参数指定连接
        QSqlQuery query(db);

//        query.exec("SELECT * FROM doctors");
        // 方法2
//        QString userid = "d1";
//        QString sql = "SELECT * FROM doctors WHERE uid='";
//        sql += userid;
//        sql += "'";
//        qDebug()<<sql;
//        query.exec(sql);
        // 方法三
        QString userid = "d1";
        query.prepare("SELECT * FROM doctors WHERE uid = :id");
        query.bindValue(":id", userid);
        query.exec();

        qDebug()<<query.size();
        while (query.next()) {
            qDebug()<<query.value("name")<<query.value("mobile");
            QString name = query.value("name").toString();
            QString mobile = query.value("mobile").toString();
            qDebug()<<name<<mobile;
        }

        // 模拟终端
//        query.exec("INSERT INTO sample (value, time) VALUES (x'2000', '2020-07-22 10:30:02')");

        // 批量添加数据
        query.prepare("INSERT INTO sample (value, time) VALUES (:array, :time)");

        QByteArray waves;
        waves.resize(10*2);
        for (int i = 0; i < 10; i++)
        {
            waves[i*2] = 2020 & 0xFF; // 低八位
            waves[i*2+1] = 2020 >> 8; // 高8位
        }
        query.bindValue(":array", waves);
        query.bindValue(":time", QDateTime::currentDateTime());
        bool queryOk = query.exec();
        if (!queryOk) qDebug()<<query.lastError();
        qDebug()<<query.lastQuery();

        //  工作站从数据库读取数据
        query.prepare("SELECT * FROM sample WHERE time > :start and time < :end");
        query.bindValue(":start", "2020-07-22 11:00:00");
        query.bindValue(":end", "2020-07-22 12:00:00");

        queryOk = query.exec();
        if(queryOk)
        {
            qDebug()<<query.size();
            while(query.next())
            {
                QByteArray waveData = query.value("value").toByteArray();
                // todo, 画波形
                qDebug()<<query.size()<<waveData;
            }
        }else
        {
            qDebug()<<query.lastError();
        }
    }
    return a.exec();
}
