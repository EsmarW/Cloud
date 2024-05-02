#ifndef SHAPES_H
#define SHAPES_H

#include <cmath>
#include <QBrush>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>

/**
 * @brief Namespace containing classes for various shapes.
 */
namespace Shapes {

/**
 * @brief The shape class is an abstract base class for different shapes.
 */
class shape {
public:
    /**
     * @brief Enumeration representing different types of shapes.
     */
    enum shapeType {noShape, line, polyline, polygon, rectangle, ellipse, text};

    /**
     * @brief Constructor for the shape class.
     * @param device The paint device.
     * @param id The identifier for the shape.
     * @param s The type of the shape.
     */
    shape(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::noShape);

    /**
     * @brief Virtual destructor for the shape class.
     */
    virtual ~shape();

    /**
     * @brief Gets the identifier of the shape.
     * @return The identifier.
     */
    int getId() const;

    /**
     * @brief Gets the type of the shape.
     * @return The type.
     */
    shapeType getShape() const;

    /**
     * @brief Gets the pen of the shape.
     * @return A reference to the QPen.
     */
    const QPen& getPen() const;

    /**
     * @brief Gets the brush of the shape.
     * @return A reference to the QBrush.
     */
    const QBrush& getBrush() const;

    /**
     * @brief Sets the type of the shape.
     * @param shape The type to set.
     */
    void setShape(shapeType shape);

    /**
     * @brief Sets the pen properties.
     * @param color The color of the pen.
     * @param width The width of the pen.
     * @param style The style of the pen.
     * @param cap The cap style of the pen.
     * @param join The join style of the pen.
     */
    void setPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);

    /**
     * @brief Sets the brush properties.
     * @param color The color of the brush.
     * @param style The style of the brush.
     */
    void setBrush(Qt::GlobalColor color, Qt::BrushStyle style);

    // Additional methods...

protected:
    /**
     * @brief Gets the QPainter object.
     * @return A reference to the QPainter.
     */
    QPainter& getQpainter();

    // Additional methods...

private:
    QPaintDevice* device; /**< The paint device. */
    shapeType s; /**< The type of the shape. */
    int id; /**< The identifier of the shape. */
};

} // namespace Shapes

#endif // SHAPES_H
