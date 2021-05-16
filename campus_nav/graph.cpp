#include "graph.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <set>
#include <string>
#include <QDir>
using namespace std;

Graph::Graph(int num)
{
    vexnum = num;

    /* 动态申请内存*/
    adjMatrix = new Path *[vexnum];
    for (int i = 0; i < vexnum; i++)
        adjMatrix[i] = new Path[vexnum];

    //不用初始化值，因为Path类构造时已经赋值MAXINT

}

Graph::~Graph()
{
    for (int i = 0; i < vexnum; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

/*
 * @brief Graph::loadGraph
 * @param vTable 坐标表
 * @param Table 距离表
 * @authors ts
 *
 * 加载地图数据（路径+地点）
 */
void Graph::loadGraph(const QString vtable,const QString dtable)
{
    /* 连接数据库 */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath() + QString("/campusMap.db"));
    if (!db.open())
        qDebug() << "Failed to connect to database";

    /*配置接口*/
    QSqlQuery vQuery(db),dQuery(db);
    QString str1= QString("select * from %1").arg(vtable);
    vQuery.exec(str1);
    QString str2= QString("select * from %1").arg(dtable);
    dQuery.exec(str2);

    /*读取地点名称和类型*/
    string vName,vType;

    while (vQuery.next())
    {
        vName = vQuery.value(1).toString().toStdString();
        vType = vQuery.value(4).toString().toStdString();
        vexsName.push_back(vName);
        vexsType.push_back(vType);
    }

    /*修改邻接矩阵*/
    int i = 0, j = 0;
    while(dQuery.next())
    {
        i = dQuery.value(0).toInt(); //src
        j = dQuery.value(1).toInt(); //dest
        adjMatrix[i][j].length = dQuery.value(3).toInt(); //distance
        adjMatrix[i][j].congestion = dQuery.value(4).toFloat(); //congestion
        //无向图
        adjMatrix[j][i].length = dQuery.value(3).toInt();
        adjMatrix[j][i].congestion = dQuery.value(4).toFloat();
    }

    db.close();
}

int Graph::locateVex(string vexName)
{
    vector<string>::iterator itr;
    for (itr = vexsName.begin(); itr != vexsName.end(); itr++)
    {
        if(*itr == vexName)
            return (itr - vexsName.begin());
    }
    return -1;
}

string Graph::getVexName(int id)//返回序号对应顶点名
{
    return vexsName[id];
}
string Graph::getVexType(int id)//返回序号对应顶点类型
{
    return vexsType[id];
}

int Graph::getLength(string v1, string v2)
{
    int i = locateVex(v1);
    int j = locateVex(v2);
    return adjMatrix[i][j].length;
}



//void Graph::shortestPathDJ(string src, string dest, vector<Path> &route)
//{

    
//}


void Graph::printMatrix()
{
    for (int i = 0; i < this->vexnum; i++)
    {
        cout << vexsName[i] << "\t";
        for(int j = 0; j < this->vexnum; j++)
        {
            cout << vexsName[j] << "\t";
            cout << adjMatrix[i][j].length << endl;
        }
    }
}
