#include "paintmap.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <set>
#include <string>
#include <QDir>
PaintMap::PaintMap()
{

}

void PaintMap::readMap(const QString vtable)
{
    /* 连接数据库 */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath() + QString("/campusMap.db"));
    if (!db.open())
        qDebug() << "Failed to connect to database";

    /* 配置接口 */
    QSqlQuery vQuery(db),dQuery(db);
    QString str= QString("select * from %1").arg(vtable);
    vQuery.exec(str);

    /* 读取坐标 */
    int x, y;
    QPoint p;
    while(vQuery.next())
    {
        x = vQuery.value(2).toInt();
        y = vQuery.value(3).toInt();
        p = QPoint(x,y);
        qpoint.push_back(p);
    }

    db.close();
}
