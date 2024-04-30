#include "draw.h"
using namespace Draw;

void draw::paintEvent(QPaintEvent * /* event */)
{
 //   painter.setRenderHint(QPainter::Antialiasing, true);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    line* l = new line(this);
    l->setId(1);
    l->setCoords(20,90);
    l->setStart(20,90);
    l->setEnd(100,20);
    l->setPen(Qt::GlobalColor::blue, 2 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    l->setBrush(Qt::GlobalColor::red, Qt::VerPattern);
    l->draw(painter, this);

    rectangle* r = new rectangle(this);
    r->setId(4);
    r->setCoords(20,200);
    r->setWidth(170);
    r->setHeight(100);
    r->setPen(Qt::GlobalColor::blue, 0 ,Qt::PenStyle::DashDotLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin);
    r->setBrush(Qt::GlobalColor::red, Qt::VerPattern);
    shapes.push_back(r);
    r->draw(painter, this);

}

void draw::setShapeList(vector<shape *> old)
{
    shapeList = old;
}

vector<shape*>& draw::getShapeList()
{
    return this->shapeList;
}

void draw::drawShapes()
{
    QPainter painter(this);
    rectangle r(this);
    r.setCoords(5,5);
    r.setWidth(50);
    r.setHeight(30);
    r.setPen(Qt::GlobalColor::blue, 5, Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin);
}

/*
QSize draw::minimumSizeHint() const
{
    return QSize(1000, 500);
}

QSize draw::sizeHint() const
{
    return QSize(1000, 500);
}

void draw::addShape(shape *s)
{
    shapes.push_back(s);
}

void draw::clearShapes()
{
    shapes.resize(0);
    update();
}
*/
