#include "ellipse.h"


namespace Shapes {

void ellipse::setHeight(int newH)
{
    h = newH;
}

void ellipse::setWidth(int newW)
{
    w = newW;
}

void ellipse::draw(QPainter &p, QPaintDevice* device)
{
    p.setFont(QString("Times"));
    p.setPen(Qt::black);
    QString idString;
    int i = getId();
    idString = (char)i;
    p.drawText(getX(),getY()-5,QString::number(getId()));

    p.setPen(penType);
    p.setBrush(brushType);
    p.drawEllipse(getX(),getY(),w,h);
}

void ellipse::move(const int newX, const int newY)
{
    rect.setRect(newX,newY,rect.height(),rect.width());
    moveCoords(newX, newY);
}

double ellipse::area()const
{
    double area;
    area = 3.14*(static_cast<double>(rect.width())/2)*(static_cast<double>(rect.height())/2);
    return area;
}

double ellipse::perimeter()const
{
    double perim;
    perim =2*3.14*sqrt((pow(static_cast<double>(rect.width()),2)+pow(static_cast<double>(rect.height()),2))/2);
    return perim;
}
}
