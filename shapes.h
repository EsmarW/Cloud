#ifndef SHAPES_H
#define SHAPES_H

#include <cmath>
#include <QBrush>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>

/**
 * @brief Namespace containing classes for geometric shapes.
 */
namespace Shapes {

/**
 * @brief The shape class is an abstract base class for geometric shapes.
 */
class shape {
public:
    /**
     * @brief Enumeration representing the types of shapes.
     */
    enum shapeType {noShape, line, polyline, polygon, rectangle, ellipse, text};

    /**
     * @brief Constructor for the shape class.
     * @param device The paint device.
     * @param id The ID of the shape.
     * @param s The type of the shape.
     */
    shape(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::noShape);

    /**
     * @brief Virtual destructor for the shape class.
     */
    virtual ~shape();

    /**
     * @brief Gets the ID of the shape.
     * @return The ID of the shape.
     */
    int getId() const;

    /**
     * @brief Gets the type of the shape.
     * @return The type of the shape.
     */
    shapeType getShape() const;

    /**
     * @brief Gets the pen used for drawing the shape.
     * @return A reference to the QPen.
     */
    const QPen& getPen() const;

    /**
     * @brief Gets the brush used for filling the shape.
     * @return A reference to the QBrush.
     */
    const QBrush& getBrush() const;

    /**
     * @brief Sets the type of the shape.
     * @param shape The type of the shape.
     */
    void setShape(shapeType shape);

    /**
     * @brief Sets the properties of the pen.
     * @param color The color of the pen.
     * @param width The width of the pen.
     * @param style The style of the pen.
     * @param cap The cap style of the pen.
     * @param join The join style of the pen.
     */
    void setPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);

    /**
     * @brief Sets the properties of the brush.
     * @param color The color of the brush.
     * @param style The style of the brush.
     */
    void setBrush(Qt::GlobalColor color, Qt::BrushStyle style);

    /**
     * @brief Draws a rectangle.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     */
    void drawRect(int width, int height);

    /**
     * @brief Draws the shape.
     * @param p The QPainter object.
     * @param device The paint device.
     */
    virtual void draw(QPainter &p, QPaintDevice* device) = 0;

    /**
     * @brief Moves the shape to a new position.
     * @param newX The new x-coordinate.
     * @param newY The new y-coordinate.
     */
    virtual void move(const int newX, const int newY) = 0;

    /**
     * @brief Calculates the perimeter of the shape.
     * @return The perimeter of the shape.
     */
    virtual double perimeter() const = 0;

    /**
     * @brief Calculates the area of the shape.
     * @return The area of the shape.
     */
    virtual double area() const = 0;

    /**
     * @brief Sets the ID of the shape.
     * @param id The ID of the shape.
     */
    void setId(int id);

    /**
     * @brief Sets the color of the pen and text.
     * @param color The color of the pen and text.
     */
    void setPenColor(Qt::GlobalColor color);

    /**
     * @brief Sets the style of the pen.
     * @param style The style of the pen.
     */
    void setPenStyle(Qt::PenStyle style);

    /**
     * @brief Sets the width of the pen.
     * @param width The width of the pen.
     */
    void setPenWidth(int width);

    /**
     * @brief Sets the cap style of the pen.
     * @param cap The cap style of the pen.
     */
    void setPenCap(Qt::PenCapStyle cap);

    /**
     * @brief Sets the join style of the pen.
     * @param join The join style of the pen.
     */
    void setPenJoint(Qt::PenJoinStyle join);

    /**
     * @brief Sets the color of the brush.
     * @param color The color of the brush.
     */
    void setBrushColor(Qt::GlobalColor color);

    /**
     * @brief Sets the style of the brush.
     * @param style The style of the brush.
     */
    void setBrushStyle(Qt::BrushStyle style);

    /**
     * @brief Sets the coordinates of the shape.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void setCoords(int x, int y);

    /**
     * @brief Gets the x-coordinate of the shape.
     * @return The x-coordinate of the shape.
     */
    int getX();

    /**
     * @brief Gets the y-coordinate of the shape.
     * @return The y-coordinate of the shape.
     */
    int getY();

protected:
    /**
     * @brief Gets the QPainter object.
     * @return A reference to the QPainter.
     */
    QPainter& getQpainter();

private:
    QPaintDevice* device; /**< The paint device. */
    shapeType s; /**< The type of the shape. */
    int x1; /**< The x-coordinate of the shape. */
    int y1; /**< The y-coordinate of the shape. */
    int id; /**< The ID of the shape. */
    QPainter paintType; /**< The QPainter object. */
    QPen penType; /**< The QPen object. */
    QBrush brushType; /**< The QBrush object. */
};

} // namespace Shapes

#endif // SHAPES_H
