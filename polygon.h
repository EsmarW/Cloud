#ifndef POLYGON_H
#define POLYGON_H

#include <QPoint>
#include <string>
#include <cmath>
#include <QBrush>
#include <QPoint>
#include <QPen>
#include <QPainter>
#include "vector.h"
#include "shapes.h"

/**
 * @brief Namespace containing classes for various shapes.
 */
namespace Shapes {

/**
 * @brief The polygon class represents a polygon shape.
 */
class polygon : public shape {
public:
    /**
     * @brief Constructor for the polygon class.
     * @param device The paint device.
     * @param id The identifier for the polygon.
     */
    polygon(QPaintDevice* device = nullptr, int id = -1) : shape(device, id, shapeType::polygon) {}

    /**
     * @brief Sets a point of the polygon.
     * @param point The point to set.
     */
    void set_point(const QPoint& point);

    /**
     * @brief Draws the polygon.
     * @param p The QPainter object.
     * @param device The paint device.
     */
    void draw(QPainter &p, QPaintDevice* device) override;

    /**
     * @brief Moves the polygon to a new position.
     * @param newX The new x-coordinate.
     * @param newY The new y-coordinate.
     */
    void move(const int newX, const int newY) override;

    /**
     * @brief Calculates the area of the polygon.
     * @return The area.
     */
    double area() const override;

    /**
     * @brief Calculates the perimeter of the polygon.
     * @return The perimeter.
     */
    double perimeter() const override;

private:
    Vector::vector<QPoint> points; /**< The points of the polygon. */
};

} // namespace Shapes

#endif // POLYGON_H
