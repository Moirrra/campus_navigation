#include "graph.h"
using namespace std;


Graph::Graph(int num)
{
    this->vexnum = num;

    this->adjMatrix = new Path *[this->vexnum];
    for (int i = 0; i < this->vexnum; i++)
        this->adjMatrix[i] = new Path[this->vexnum];

}

Graph::~Graph()
{
    for (int i = 0; i < this->vexnum; i++)
        delete[] this->adjMatrix[i];
    delete[] this->adjMatrix;
}

int Graph::locateVex(string vex)
{
    vector<string>::iterator itr;
    for (itr = vexs.begin(); itr != vexs.end(); itr++)
    {
        if(*itr == vex)
            return (itr - vexs.begin());
    }
    return -1;
}

string Graph::getVex(int id)//返回序号对应顶点
{
    return vexs[id];
}

int Graph::getLength(string v1, string v2)
{
    int i = locateVex(v1);
    int j = locateVex(v2);
    return adjMatrix[i][j].length;
}

void Graph::setLength(string v1, string v2, int length)
{
    int i = locateVex(v1);
    int j = locateVex(v2);
    adjMatrix[i][j].length = length;
}

void Graph::setVexList(vector<string> list)
{
    vexs = list;
}

void Graph::shortestPathDJ(string src, string dest, vector<Path> &route)
{

    
}


void Graph::printMatrix()
{
    for (int i = 0; i < this->vexnum; i++)
    {
        cout << vexs[i] << "\t";
        for(int j = 0; j < this->vexnum; j++)
        {
            cout << vexs[j] << "\t";
            cout << adjMatrix[i][j].length << endl;
        }
    }
}
