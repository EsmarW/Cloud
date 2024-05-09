#include "shapes.h"

namespace Shapes {

shape::shape(QPaintDevice* device, int id, shapeType s) : paintType(device), s{s}, id{id}
{

}

shape::~shape() {}

int shape::getId() const
{
    return id;
}

const QPen& shape::getPen() const
{
    return paintType.pen();
}

const QBrush& shape::getBrush() const
{
    return paintType.brush();
}


void shape::setShape(shapeType shape)
{
    s = shape;
}

void shape::setPen(Qt::GlobalColor c, int width, Qt::PenStyle s, Qt::PenCapStyle cs, Qt::PenJoinStyle js)
{
    penType.setColor(c);
    penType.setWidth(width);
    penType.setStyle(s);
    penType.setCapStyle(cs);
    penType.setJoinStyle(js);
    paintType.setPen(penType);
    return;
}

void shape::setBrush(Qt::GlobalColor c, Qt::BrushStyle s)
{
    brushType.setColor(c);
    brushType.setStyle(s);
    paintType.setBrush(brushType);
    return;
}

shape::shapeType shape::getShape() const
{
    return s;
}

void shape::setId(int i)
{
    id = i;
}

void shape::setPenColor(Qt::GlobalColor)
{
    penType.setColor(Qt::GlobalColor());
}

void shape::setPenStyle(Qt::PenStyle)
{
    penType.setStyle(Qt::PenStyle());
}

void shape::setPenWidth(int w)
{
    penType.setWidth(w);
}

void shape::setPenCap(Qt::PenCapStyle)
{
    penType.setCapStyle(Qt::PenCapStyle());
}


void shape::setPenJoint(Qt::PenJoinStyle)
{
    penType.setJoinStyle(Qt::PenJoinStyle());
}

void shape::setBrushColor(Qt::GlobalColor)
{
    brushType.setColor(Qt::GlobalColor());
}

void shape::setBrushStyle(Qt::BrushStyle)
{
    brushType.setStyle(Qt::BrushStyle());
}

void shape::setCoords(int x, int y)
{
    x1 = x;
    y1 = y;
}

void shape::moveCoords(int x, int y)
{
    x1 += x;
    y1 += y;
}


int shape::getX()
{
    return x1;
}

int shape::getY()
{
    return y1;
}

QPainter& shape::getQpainter()
{
    return paintType;
}
}
