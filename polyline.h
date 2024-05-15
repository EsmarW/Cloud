#ifndef POLYLINE_H
#define POLYLINE_H
#include <QPoint>
#include <string>
#include <QBrush>
#include <QPoint>
#include <QPen>
#include <QPainter>
#include "vector.h"
#include "shapes.h"

namespace Shapes {

class polyline : public shape
{
public:
    polyline(QPaintDevice* device = nullptr,int id=-1) : shape(device,id,shapeType::polyline){}
    ~polyline() {}

    void set_point(const QPoint& point);

    void draw(QPainter &p, QPaintDevice* device) override;
    void move(const int newX, const int newY) override;
    double area()const override;
    double perimeter()const override;

private:
    Vector::vector<QPoint> points;
};
}

#endif // POLYLINE_H
