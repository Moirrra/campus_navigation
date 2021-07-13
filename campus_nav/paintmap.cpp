#include "paintmap.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDir>
#include <QGraphicsScene>

PaintMap::PaintMap()
{
    readMap(1);
    readMap(2);
    map1.load(":/img/shahe.png");
    int width1=map1.width(),width2=map2.width();
    int height1 =map1.height(),height2 =map2.height();
    QGraphicsScene *scene1=new QGraphicsScene(this);
    QGraphicsScene *scene2=new QGraphicsScene(this);
    scene1->setSceneRect(50,150,width1,height1);
    scene2->setSceneRect(50,150,width2,height2);
    setScene(scene1);

    setCacheMode(CacheBackground);
}

void PaintMap::readMap(const int type)
{
    QSqlQuery query;
    QString str="";
    if(type==1)
    {
        str = "SELECT * FROM shahe;";
    }
    else if(type==2)
    {
        str = "SELECT * FROM benbu;";
    }
    else
    {
        qDebug()<<"readMap() type error";
        return;
    }
    query.exec(str);

    /* 读取坐标 */
    int x, y;
    QPoint p;
    if(type==1)
    {
        while(query.next())
        {
            x = query.value(2).toInt();
            y = query.value(3).toInt();
            p = QPoint(x,y);
            qpoint1.append(p);
        }
    }
    else
    {
        while(query.next())
        {
            x = query.value(2).toInt();
            y = query.value(3).toInt();
            p = QPoint(x,y);
            qpoint2.append(p);
        }
    }
}

//void PaintMap::drawBackground(QPainter *painter,const int type)
//{
//    if(type==1)
//        painter->drawPixmap(int(sceneRect().left()),int(sceneRect().top()),map1);
////    else if(type==2)
////        painter->drawPixmap(int(sceneRect().left()),int(sceneRect().top()),map2);
//    else
//        qDebug()<<"drawBackground() type Error";
//}
void PaintMap::drawBackground(QPainter *painter)
{
    painter->drawPixmap(int(sceneRect().left()),int(sceneRect().top()),map1);
}
