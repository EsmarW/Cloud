#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapes.h"
#include <QBrush>
#include <QPen>

namespace Shapes {

class rectangle : public shape
{
public:
    rectangle(QPaintDevice* device = nullptr,int id = -1);
    //    ~rectangle();

    void set_rect(const QRect& rect);
    void setWidth(int);
    void setHeight(int);

    void draw(QPainter &p, QPaintDevice* device) override;
    void move(int x2,int y2) override;
    double perimeter()const override;
    double area()const override;

private:
    QRect rect;
    int w;
    int h;
};
}
#endif
