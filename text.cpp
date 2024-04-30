#include "text.h"

namespace Shapes {

text::text(QPaintDevice* device, int id, shapeType s, QString txt) : shape(device, id, s)
{
    str = txt;
}

text::~text()
{

}

void text::draw(QPainter &p, QPaintDevice* device)
{
    QString idString;
    int i = getId();
    idString = (char)i;
    p.drawText(getX()-10,getY()-10,QString::number(getId()));

    p.begin(device);
    getQpainter().setPen(Qt::red);
    getQpainter().setFont(font);
    setStyle(QFont::Style::StyleItalic);
    setWeight(QFont::Weight::Normal);
    setAlignment(Qt::AlignmentFlag::AlignCenter);
    setFont(QString("Impact")); //Font
    QRect rect;
    rect.setX(getX());
    rect.setY(getY());
    rect.setWidth(w);
    rect.setHeight(h);
    getQpainter().save();
    getQpainter().drawText(rect, alignment, str);
    getQpainter().restore();
}

void text::move(const int newX, const int newY)
{
    setCoords(newX, newY);
}

double text::perimeter()const
{
    return 0;
}

double text::area()const
{
    return 0;
}

void text::setAlignment(Qt::AlignmentFlag)
{
    alignment = Qt::AlignmentFlag();
}

void text::setSize(int size)
{
    pointSize = size;
    font.setPointSize(size);
    getQpainter().setFont(font);
}

void text::setFont(QString fontFamily)
{
    font.setFamily(fontFamily);
    getQpainter().setFont(font);
}

void text::setStyle(QFont::Style)
{
    font.setStyle(QFont::Style());
    getQpainter().setFont(font);
}

void text::setWeight(QFont::Weight)
{
    font.setWeight(QFont::Weight());
    getQpainter().setFont(font);
}

void text::setWidth(int width)
{
    w = width;
}

void text::setHeight(int height)
{
    h = height;
}

void text::setString(QString txt)
{
    str = txt;
}
}
