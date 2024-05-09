#include "rectangle.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::stringstream;
using namespace std;
using namespace Shapes;

namespace Shapes {

rectangle::rectangle(QPaintDevice* device, int id)
    :shape{device, id, shapeType::rectangle}
{
}

void rectangle::set_rect(const QRect& rect)
{
    this->rect=rect;

}

void rectangle::setWidth(int width)
{
    w = width;
}

void rectangle::setHeight(int height)
{
    h = height;
}

void rectangle::draw(QPainter &p, QPaintDevice* device)
{
    p.setBrush(brushType);
    p.setPen(penType);
    p.drawText(getX(),getY()-5,QString::number(getId()));
    p.drawRect(getX(),getY(),w,h);
}

void rectangle::move(const int newX, const int newY)
{
    rect.setRect(newX,newY,rect.height(),rect.width());
    moveCoords(newX, newY);
}

double rectangle::area()const
{
    double area;
    rect.width();
    rect.height();
    area=static_cast<double>(rect.width())*(static_cast<double>(rect.height()));
    return area;
}

double rectangle::perimeter()const
{
    double p;
    p = (rect.width() * 2) + (rect.height()*2);
    p = static_cast<double>(p);

    return p;
}

}
