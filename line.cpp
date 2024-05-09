#include "line.h"

namespace Shapes {

line::line(QPaintDevice* device, int id)
    :shape{device, id, shapeType::line} {}

line::~line(){}

void line::setEnd(int X, int Y)
{
    endX = X;
    endY = Y;
}

void line::setStart(int X, int Y)
{
    startX = X;
    startY = Y;
}

void line::draw(QPainter &p, QPaintDevice* device)
{
    p.setPen(penType);
    p.setBrush(brushType);
    p.drawText(getX(),getY()-20,QString::number(getId()));
    p.drawLine(startX,startY,endX,endY);
}

double line::area() const
{
    return 0;
}

double line::perimeter()const
{
    return 0;
}


void line::move(const int x, const int y)
{
    moveCoords(x,y);
    endX += x;
    endY += y;
    startX += x;
    startY += y;
}


}
