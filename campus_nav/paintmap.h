#ifndef PAINTMAP_H
#define PAINTMAP_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QGraphicsView>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QPoint>
#include <QGraphicsScene>
#include "graph.h"
class PaintMap:public QGraphicsView
{
    Q_OBJECT
public:
    PaintMap();
    void drawBackground(QPainter *painter);
//    void drawBackground(QPainter *painter,const int type);
    QPixmap map1;
    QPixmap map2;
    QList<QPoint> qpoint1;
    QList<QPoint> qpoint2;
    void readMap(const int type);
private:
    double x1,x2,y1,y2;
};

#endif // PAINTMAP_H
