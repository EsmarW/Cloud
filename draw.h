#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <QPainter>
#include "vector.h"
#include "shapes.h"
//#include "fileparser.h"
#include "rectangle.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "ellipse.h"
#include "text.h"

// Types of Shapes: Line, Polyline, Polygon, Rectangle, Ellipse, Text

using namespace Vector;
using namespace Shapes;
namespace Draw{

class draw : public QWidget
{
    Q_OBJECT

public:
   // explicit draw(QWidget *parent = 0);
    explicit draw(QWidget *parent): QWidget(parent)
    {
    }

    void drawShapes();
    void clearShapes();
    void addShape(shape *shapePtr);
    void initializeShapes();
    void setShapeList(vector<shape*>);
    vector<shape*>& getShapeList();

    vector<shape*> shapes;
    vector<shape*> &shapesListPtr = shapes;
    shape* shapePtr;
    QPainter* shp;

protected:
    void paintEvent(QPaintEvent *event) override;

};
}
#endif // DRAW_H
