#include "graph.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDir>
#include <cmath>
using namespace std;

/*
 * @brief Graph::Graph
 * @param num1 地图1的结点数
 * @param num2 地图2的结点数
 * @author ts
 */
Graph::Graph(int num1, int num2)
{
    vexnum1 = num1;
    vexnum2 = num2;
    /* 动态申请内存*/
    adjMatrix1 = new Path *[vexnum1];
    for (int i = 0; i < vexnum1; i++)
        adjMatrix1[i] = new Path[vexnum1];

    adjMatrix2 = new Path *[vexnum2];
    for (int i = 0; i < vexnum2; i++)
        adjMatrix2[i] = new Path[vexnum2];
    //不用初始化值，因为Path类构造时已经赋值MAXINT
    loadGraph();
}

/*
 * @brief Graph::~Graph
 * @author ts
 */
Graph::~Graph()
{
    for (int i = 0; i < vexnum1; i++)
        delete[] adjMatrix1[i];
    delete[] adjMatrix1;

    for (int i = 0; i < vexnum2; i++)
        delete[] adjMatrix2[i];
    delete[] adjMatrix2;
}

/*
 * @usage 修改邻接矩阵
 * @brief void Graph::setMatrix
 * @author ts
 */
void Graph::setMatrix()
{
    QSqlQuery query1,query2;
    query1.exec("SELECT * FROM distance1;");
    while(query1.next())
    {
        int i = query1.value(0).toInt();//src
        int j = query1.value(1).toInt();//dest
        adjMatrix1[i][j].length = query1.value(2).toInt(); //distance
        adjMatrix1[i][j].ifBike = query1.value(3).toInt(); //ifbike
        adjMatrix1[i][j].congestion = query1.value(4).toFloat(); //congestion
        //无向图
        adjMatrix1[j][i].length = query1.value(2).toInt();
        adjMatrix1[j][i].ifBike = query1.value(3).toInt();
        adjMatrix1[j][i].congestion = query1.value(4).toFloat();
    }

    query2.exec("SELECT * FROM distance2;");
    while(query2.next())
    {
        int i = query2.value(0).toInt();//src
        int j = query2.value(1).toInt();//dest
        adjMatrix2[i][j].length = query2.value(2).toInt(); //distance
        adjMatrix2[i][j].ifBike = query2.value(3).toInt(); //ifbike
        adjMatrix2[i][j].congestion = query2.value(4).toFloat(); //congestion
        //无向图
        adjMatrix2[j][i].length = query2.value(2).toInt();
        adjMatrix2[j][i].ifBike = query2.value(3).toInt();
        adjMatrix2[j][i].congestion = query2.value(4).toFloat();
    }

}

/*
 * @usage 读取名称、类型、坐标
 * @brief void Graph::readMap
 * @author ts
 */
void Graph::readMap()
{
    QSqlQuery query1,query2;
    QString str1 = "SELECT * FROM shahe;";
    QString str2 = "SELECT * FROM benbu;";
    query1.exec(str1);
    query2.exec(str2);
    /* 读取数据库 */
    QString name1,name2,type1,type2;
    int x1, y1, x2, y2;
    QPointF p1, p2;
    while(query1.next())
    {
        name1 = query1.value(1).toString();
        type1 = query1.value(4).toString();
        vexsName1.append(name1);
        vexsType1.append(type1);
        x1 = query1.value(2).toInt();
        y1 = query1.value(3).toInt();
        p1 = QPointF(x1,y1);
        qpoint1.append(p1);
    }
    while(query2.next())
    {
        name2 = query2.value(1).toString();
        type2 = query2.value(4).toString();
        vexsName2.append(name2);
        vexsType2.append(type2);
        x2 = query2.value(2).toInt();
        y2 = query2.value(3).toInt();
        p2 = QPointF(x2,y2);
        qpoint2.append(p2);
    }
}

/*
 * @usage 地图数据初始化
 * @brief void Graph::loadGraph
 * @author ts
 */
void Graph::loadGraph()
{
    /*读取地点名称\类型\坐标*/
    readMap();
    /*修改邻接矩阵（距离+拥挤度）*/
    setMatrix();
}

/*
 * @usage 返回顶点序号
 * @brief int Graph::locateVex
 * @param type 地图选择
 * @param vexName 顶点名称
 * @return 顶点序号 -1找不到
 * @author ts
 */
int Graph::locateVex(int type, QString vexName)
{
    if(type==1)
    {
        for(int i = 0; i < vexsName1.size(); i++)
        {
            if(vexsName1.at(i)==vexName)
                return i;
        }
    }
    else if(type==2)
    {
        for(int i = 0; i < vexsName2.size(); i++)
        {
            if(vexsName2.at(i)==vexName)
                return i;
        }
    }

    qDebug()<<"locateVex error!";
    return -1;
}

/*
 * @usage 返回顶点名称
 * @brief QString Graph::getVexName
 * @param type 地图选择
 * @param id 顶点序号
 * @return 顶点名称字符串
 * @author ts
 */
QString Graph::getVexName(int type, int id)
{
    if(type==1)
        return vexsName1[id];
    else if(type==2)
        return vexsName2[id];
    else return "";
}

/*
 * @usage 返回序号对应顶点类型
 * @brief QString Graph::getVexType
 * @param type 校区类型
 * @param id 顶点序号
 * @return 顶点类型字符串
 * @author ts
 */
QString Graph::getVexType(int type, int id)
{
    if(type==1)
        return vexsType1[id];
    else if(type==2)
        return vexsType2[id];
    else return "";
}

/*
 * @usage 获取点坐标
 * @brief QPointF Graph::getPoint
 * @param type 校区类型
 * @param id 序号
 * @return 坐标
 * @author ts
 */
QPointF Graph::getPoint(int type, int id)
{
    if(type==1)
        return qpoint1[id];
    else return qpoint2[id];
}

/*
 * @usage 获取坐标点名称
 * @brief QString Graph::getPointName
 * @param type 校区类型
 * @param point 坐标点
 * @return 坐标点名称字符串
 * @author ts
 */
QString Graph::getPointName(int type, QPointF point)
{
    if(type==1)
    {
        for(int i = 0; i < qpoint1.size(); i++)
        {
            if(point==qpoint1[i])
                return getVexName(1,i);
        }
    }
    else
    {
        for(int i = 0; i < qpoint2.size(); i++)
        {
            if(point==qpoint2[i])
                return getVexName(2,i);
        }
    }
    return "";
}

/*
 * @usage 打印邻接矩阵
 * @brief void Graph::printMatrix
 * @param type 校区类型
 * @author ts
 */
void Graph::printMatrix(int type)
{
    if(type==1)
    {
        for (int i = 0; i < vexnum1; i++)
        {
            qDebug() << vexsName1[i] << ":";
            for(int j = 0; j < vexnum1; j++)
            {
                if(adjMatrix1[i][j].length!=32767)
                {
                    qDebug() << vexsName1[j];
                    qDebug() << adjMatrix1[i][j].length << adjMatrix1[i][j].congestion;
                }

            }
        }
    }

    else if(type==2)
    {
        qDebug()<<vexsName2.size();
        for (int i = 0; i < vexnum2; i++)
        {
            qDebug()<<"!";
            qDebug() << vexsName2[i] << ":";
            for(int j = 0; j < vexnum2; j++)
            {
                if(adjMatrix2[i][j].length!=32767)
                {
                    qDebug() << vexsName2[j];
                    qDebug() << adjMatrix2[i][j].length;
                }
            }
        }
    }
}

/*
 * @usage 查询周围服务设施
 * @brief QList<QString> Graph::search
 * @param type 校区类型
 * @param vName 地点名称
 * @return 查询结果名称表
 * @author ts
 */
QList<QString> Graph::search(int type, QString vName)
{
    QList<QString> list;
    int r = 100;
    int id = locateVex(type, vName);
    if(id==-1) //找不到该点
        return list;
    if(type==1)
    {
        int curX = qpoint1[id].x();
        int curY = qpoint1[id].y();
        for(int i = 0; i < qpoint1.size(); i++)
        {
            double distance = sqrt(pow(curX-qpoint1[i].x(),2) + pow(curY-qpoint1[i].y(),2));
            if(distance <= r && (vexsType1[i]=="service" || vexsType1[i]=="dormitory"
                                 || vexsType1[i]=="teaching"))
            {
//                qDebug()<<vexsName1[i];
                list.append(vexsName1[i]);
            }
        }
    }
    else if(type==2)
    {
        int curX = qpoint2[id].x();
        int curY = qpoint2[id].y();
        for(int i = 0; i < qpoint2.size(); i++)
        {
            double distance = sqrt(pow(curX-qpoint2[i].x(),2) + pow(curY-qpoint2[i].y(),2));
            if(distance <= r && (vexsType2[i]=="service" || vexsType2[i]=="dormitory"
                                 || vexsType2[i]=="teaching"))
            {
//                qDebug()<<vexsName2[i];
                list.append(vexsName2[i]);
            }
        }
    }
    else
        qDebug()<<"search() type error";

    return list;
}

