#ifndef SHAPES_H
#define SHAPES_H
#include <cmath>
#include <QBrush>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>

namespace Shapes {

class shape
{
public:
    enum shapeType {noShape, line, polyline, polygon, rectangle, ellipse, text};

    shape(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::noShape);
    virtual ~shape();

    int getId() const;    //returns ID # of shape
    shapeType getShape() const; //returns Enum Shape Type
    const QPen& getPen() const; //returns a reference to QPen
    const QBrush& getBrush() const; //returns a reference to QBrush

    void setShape(shapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setPen(QPen pen) { this->pen = pen; };
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);
    void setBrush(QBrush brush) {this->brush = brush;}
    void setRect(QRect r) { this->rect = r;}

    void drawRect(int, int);

    virtual void draw(QPainter &p, QPaintDevice* device) = 0;   //polymorphically draws the shape
    virtual void move(const int newX, const int newY) = 0;      //moves the shapes
    virtual double perimeter()const = 0;   //calculates the perimeter of the shape
    virtual double area()const = 0;        //calculates the area of the shape

    void setId(int);                        //sets the id
    void setPenColor(Qt::GlobalColor);      //changes the pen/text color
    void setPenStyle(Qt::PenStyle);         //changes the pen style
    void setPenWidth(int);                  //changes the pen width
    void setPenCap(Qt::PenCapStyle);        //changes the pen cap style
    void setPenJoint(Qt::PenJoinStyle);     //changes the pen joint style
    void setBrushColor(Qt::GlobalColor);    //changes the brush color
    void setBrushStyle(Qt::BrushStyle);     //changes the brush style

    void setCoords(int, int);       //sets shape drawing position
    void moveCoords(int, int);      //moves shape position

    int getX();                     // X coordinate
    int getY();                     // Y coordinate

    QPainter paintType;
    QPen penType;
    QBrush brushType;

    QPainter& getQpainter();

    QPaintDevice* getDevice(){return device;}

protected:
    //QPainter& getQpainter();

private:

    QPaintDevice* device;
        QPen pen;
        QBrush brush;
        QRect rect;
    shapeType s;
    int x1;
    int y1;
    int id;
};
}
#endif // SHAPES_H
