#include "draw.h"
using namespace Draw;

void draw::paintEvent(QPaintEvent * /* event */)
{
 //   painter.setRenderHint(QPainter::Antialiasing, true);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    line* l = new line(this);
    l->setId(1);
    l->setCoords(20,50);
    l->setStart(20,100);
    l->setEnd(100,20);
    l->setPen(Qt::GlobalColor::black, 2 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::MiterJoin);
    l->setBrush(Qt::GlobalColor::red, Qt::VerPattern);
    l->draw(painter, this);

    polyline* pl = new polyline(this);
    pl->setId(2);
    //pl->setCoords(100,50);
    pl->set_point(QPoint(460,90));
    pl->set_point(QPoint(470,20));
    pl->set_point(QPoint(530,40));
    pl->set_point(QPoint(540,80));
    pl->set_point(QPoint(500,100));
    pl->setPen(Qt::GlobalColor::black, 6 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    pl->setBrush(Qt::GlobalColor::red, Qt::VerPattern);
    shapeList.push_back(pl);
    pl->move(-300,0); //Translates shape next to shape 1
    pl->draw(painter, this);

    polygon* p = new polygon(this);
    p->setId(3);
    p->set_point(QPoint(100,100));
    p->set_point(QPoint(250,100));
    p->set_point(QPoint(200,200));
    p->set_point(QPoint(50,200));
    p->setPen(Qt::GlobalColor::black, 3 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    p->setBrush(Qt::GlobalColor::red, Qt::SolidPattern);
    shapeList.push_back(p);
    p->move(200,-70); //Translates shape next to shape 2
    p->draw(painter, this);

    rectangle* r = new rectangle(this);
    r->setId(4);
    r->setCoords(20,200);
    r->setWidth(200);
    r->setHeight(100);
    r->setPen(Qt::GlobalColor::black, 1 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin);
    r->setBrush(Qt::GlobalColor::darkRed, Qt::CrossPattern);
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
