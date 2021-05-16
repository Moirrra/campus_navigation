#ifndef PAINTMAP_H
#define PAINTMAP_H

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QGraphicsView>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <vector>
#include <QPoint>
#include "graph.h"
class PaintMap
{
public:
    PaintMap();
    void drawBackground(QPainter *painter);
    vector<QPoint> qpoint;
    void readMap(const QString vtable);
private:
    double x1,x2,y1,y2;
};

#endif // PAINTMAP_H
