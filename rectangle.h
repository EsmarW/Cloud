#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapes.h"
#include <QBrush>
#include <QPen>

/**
 * @brief Namespace containing classes for various shapes.
 */
namespace Shapes {

/**
 * @brief The rectangle class represents a rectangle shape.
 */
class rectangle : public shape {
public:
    /**
     * @brief Constructor for the rectangle class.
     * @param device The paint device.
     * @param id The identifier for the rectangle.
     */
    rectangle(QPaintDevice* device = nullptr, int id = 0);    //default constructor

    /**
     * @brief Sets the bounding rectangle of the rectangle.
     * @param rect The bounding rectangle.
     */
    void set_rect(const QRect& rect);

    /**
     * @brief Sets the width of the rectangle.
     * @param width The width.
     */
    void setWidth(int width);

    /**
     * @brief Sets the height of the rectangle.
     * @param height The height.
     */
    void setHeight(int height);

    /**
     * @brief Draws the rectangle.
     * @param p The QPainter object.
     * @param device The paint device.
     */
    void draw(QPainter &p, QPaintDevice* device) override;

    /**
     * @brief Moves the rectangle to a new position.
     * @param x2 The new x-coordinate.
     * @param y2 The new y-coordinate.
     */
    void move(int x2, int y2) override;

    /**
     * @brief Calculates the perimeter of the rectangle.
     * @return The perimeter.
     */
    double perimeter() const override;

    /**
     * @brief Calculates the area of the rectangle.
     * @return The area.
     */
    double area() const override;

private:
    QRect rect; /**< The bounding rectangle of the rectangle. */
    int w; /**< The width of the rectangle. */
    int h; /**< The height of the rectangle. */
};

} // namespace Shapes

#endif // RECTANGLE_H
