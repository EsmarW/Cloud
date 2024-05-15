#ifndef LINE_H
#define LINE_H
#include "shapes.h"

namespace Shapes {
class line : public shape //Public inheritance
{
public:
    //Line();
    line(QPaintDevice* device = nullptr, int id = -1);
    ~line();

    void setEnd(int endX, int endY);
    void setStart(int startX, int startY);

    void move(const int x, const int y) override;
    void draw(QPainter &p, QPaintDevice* device) override;
    double area()const override;
    double perimeter()const override;

private:
    int startX;
    int startY;
    int endX;
    int endY;

};
}
#endif // LINE_H
