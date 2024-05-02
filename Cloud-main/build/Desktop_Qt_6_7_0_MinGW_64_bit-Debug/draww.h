#ifndef DRAWW_H
#define DRAWW_H

#include <QWidget>
#include <QPainter>
#include "vector.h"
#include "shapes.h"
#include "rectangle.h"

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
    void setShapeList(vector<shape*>);
    vector<shape*>& getShapeList();

    //draw(QWidget *parent = nullptr);
    //QSize minimumSizeHint() const override;
    //QSize sizeHint() const override;
    //void addShape(shape *shapes);
    //void clearShapes();

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    vector<shape*> shapes;
    shape* shapePtr;
    QPainter* shp;
    vector<shape*> shapeList;
};
}


#endif // DRAWW_H