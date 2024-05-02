#ifndef POLYLINE_H
#define POLYLINE_H

#include <QPoint>
#include <string>
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
 * @brief The polyline class represents a polyline shape.
 */
class polyline : public shape {
public:
    /**
     * @brief Constructor for the polyline class.
     * @param device The paint device.
     * @param id The identifier for the polyline.
     */
    polyline(QPaintDevice* device = nullptr, int id = -1) : shape(device, id, shapeType::polyline) {}

    /**
     * @brief Destructor for the polyline class.
     */
    ~polyline() {}

    /**
     * @brief Sets a point of the polyline.
     * @param point The point to set.
     */
    void set_point(const QPoint& point);

    /**
     * @brief Draws the polyline.
     * @param p The QPainter object.
     * @param device The paint device.
     */
    void draw(QPainter &p, QPaintDevice* device);

    /**
     * @brief Moves the polyline to a new position.
     * @param newX The new x-coordinate.
     * @param newY The new y-coordinate.
     */
    void move(const int newX, const int newY);

    /**
     * @brief Calculates the area of the polyline (always 0 for a polyline).
     * @return The area.
     */
    double area() const;

    /**
     * @brief Calculates the perimeter of the polyline.
     * @return The perimeter.
     */
    double perimeter() const;

private:
    Vector::vector<QPoint> points; /**< The points of the polyline. */
};

} // namespace Shapes

#endif // POLYLINE_H
