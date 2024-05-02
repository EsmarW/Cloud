#ifndef LINE_H
#define LINE_H

#include "shapes.h"

/**
 * @brief Namespace containing classes for various shapes.
 */
namespace Shapes {

/**
 * @brief The line class represents a line shape.
 */
class line : public shape {
public:
    /**
     * @brief Constructor for the line class.
     * @param device The paint device.
     * @param id The identifier for the line.
     */
    line(QPaintDevice* device = nullptr, int id = -1);

    /**
     * @brief Destructor for the line class.
     */
    ~line();

    /**
     * @brief Sets the end point of the line.
     * @param endX The x-coordinate of the end point.
     * @param endY The y-coordinate of the end point.
     */
    void setEnd(int endX, int endY);

    /**
     * @brief Sets the start point of the line.
     * @param startX The x-coordinate of the start point.
     * @param startY The y-coordinate of the start point.
     */
    void setStart(int startX, int startY);

    /**
     * @brief Moves the line to a new position.
     * @param x The x-coordinate of the new position.
     * @param y The y-coordinate of the new position.
     */
    void move(const int x, const int y);

    /**
     * @brief Draws the line.
     * @param p The QPainter object.
     * @param device The paint device.
     */
    void draw(QPainter &p, QPaintDevice* device);

    /**
     * @brief Calculates the area of the line.
     * @return The area (always 0 for a line).
     */
    double area() const;

    /**
     * @brief Calculates the perimeter of the line.
     * @return The length of the line.
     */
    double perimeter() const;

private:
    int startX; /**< The x-coordinate of the start point. */
    int startY; /**< The y-coordinate of the start point. */
    int endX; /**< The x-coordinate of the end point. */
    int endY; /**< The y-coordinate of the end point. */
};

} // namespace Shapes

#endif // LINE_H
