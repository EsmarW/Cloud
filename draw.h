#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <QPainter>
#include "vector.h"
#include "shapes.h"
#include "rectangle.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "ellipse.h"
#include "text.h"

/**
 * @brief Namespace containing classes for drawing shapes.
 */
namespace Draw {

/**
 * @brief The draw class is a QWidget subclass for drawing various shapes.
 */
class draw : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the draw class.
     * @param parent The parent widget.
     */
    explicit draw(QWidget *parent) : QWidget(parent) {}

    /**
     * @brief Draws the shapes stored in the shape list.
     */
    void drawShapes();

    /**
     * @brief Sets the list of shapes to be drawn.
     * @param shapeList The list of shapes.
     */
    void setShapeList(Vector::vector<Shapes::shape*> shapeList);

    /**
     * @brief Gets the list of shapes to be drawn.
     * @return The list of shapes.
     */
    Vector::vector<Shapes::shape*>& getShapeList();

protected:
    /**
     * @brief Paints the widget and its child widgets if needed.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event) override;

public:
    Vector::vector<Shapes::shape*> shapes; /**< The list of shapes. */
    Shapes::shape* shapePtr; /**< Pointer to a shape. */
    QPainter* shp; /**< Pointer to a QPainter object. */
    Vector::vector<Shapes::shape*> shapeList; /**< The list of shapes to be drawn. */
};

} // namespace Draw

#endif // DRAW_H
