#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shapes.h"

/**
 * @brief Namespace containing classes for various shapes.
 */
namespace Shapes {

/**
 * @brief The ellipse class represents an ellipse shape.
 */
class ellipse : public shape {
public:
    /**
     * @brief Constructor for the ellipse class.
     * @param device The paint device.
     * @param id The identifier for the ellipse.
     */
    ellipse(QPaintDevice* device = nullptr, int id = -1) : shape(device, id, shapeType::ellipse) {} //default constructor

    /**
     * @brief Destructor for the ellipse class.
     */
    ~ellipse() {}

    /**
     * @brief Sets the bounding rectangle of the ellipse.
     * @param rect The bounding rectangle.
     */
    void set_rect(const QRect& rect) {
        this->rect = rect;
    }

    /**
     * @brief Sets the height of the ellipse.
     * @param height The height.
     */
    void setHeight(int height);

    /**
     * @brief Sets the width of the ellipse.
     * @param width The width.
     */
    void setWidth(int width);

    /**
     * @brief Draws the ellipse.
     * @param p The QPainter object.
     * @param device The paint device.
     */
    void draw(QPainter &p, QPaintDevice* device);

    /**
     * @brief Moves the ellipse to a new position.
     * @param x2 The new x-coordinate.
     * @param y2 The new y-coordinate.
     */
    void move(int x2, int y2);

    /**
     * @brief Calculates the perimeter of the ellipse.
     * @return The perimeter.
     */
    double perimeter() const;

    /**
     * @brief Calculates the area of the ellipse.
     * @return The area.
     */
    double area() const;

private:
    QRect rect; /**< The bounding rectangle of the ellipse. */
    int h; /**< The height of the ellipse. */
    int w; /**< The width of the ellipse. */
};

} // namespace Shapes

#endif // ELLIPSE_H
