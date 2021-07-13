#include "mainwindow.h"
#include <QApplication>
#include "sqlhelp.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //连接数据库
    if(!createConnection())
    {
        qDebug()<<"Connection failed";
        return 1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
