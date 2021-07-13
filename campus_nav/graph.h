#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <QString>
#include <QList>
#include "path.h"

class Graph
{

public:
    int vexnum1;
    int vexnum2;

    QList<QString> vexsName1; //顶点名称表
    QList<QString> vexsName2;
    QList<QString> vexsType1; //顶点类型表
    QList<QString> vexsType2;
    Path **adjMatrix1;//沙河邻接矩阵
    Path **adjMatrix2;//本部邻接矩阵
    QList<QPointF> qpoint1;
    QList<QPointF> qpoint2;

    Graph(int num1, int num2);
    ~Graph();

    void loadGraph();//读取路径信息
    void readMap();//读取坐标
    void setMatrix();//修改邻接矩阵
    void printMatrix(int type);//打印邻接矩阵
    QList<QString> search(int type, QString vName);//查询周边

    /* getter */
    int locateVex(int type, QString vexName); //返回顶点对应序号
    QString getVexName(int type, int id);     //返回序号对应顶点名称
    QString getVexType(int type, int id);     //返回序号对应顶点类型
    QPointF getPoint(int type, int id);       //返回序号对应坐标
    QString getPointName(int type, QPointF point); //返回坐标对应顶点名称
};



#endif // GRAPH_H
