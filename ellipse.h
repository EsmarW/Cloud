#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shapes.h"

namespace Shapes {

class ellipse : public shape
{
public:
    ellipse(QPaintDevice* device = nullptr,int id=-1): shape(device,id,shapeType::ellipse){}    //default constructor
    ~ellipse() {}

    void set_rect(const QRect& rect) {
        this->rect=rect;
    }

    void setHeight(int);
    void setWidth(int);

    void draw(QPainter &p, QPaintDevice* device) override;
    void move(int x2,int y2) override;
    double perimeter()const override;
    double area()const override;

private:
    QRect rect;
    int h;
    int w;

};
}
#endif // ELLIPSE_H
