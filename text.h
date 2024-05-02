#ifndef TEXT_H
#define TEXT_H

#include "shapes.h"

/**
 * @brief Namespace containing classes for various shapes.
 */
namespace Shapes {

/**
 * @brief The text class represents a text shape.
 */
class text : public shape {
private:
    QString str; /**< The text string. */
    QFont font; /**< The font of the text. */
    int alignment; /**< The alignment of the text. */
    int pointSize; /**< The point size of the text. */
    int w; /**< The width of the text. */
    int h; /**< The height of the text. */

public:
    /**
     * @brief Constructor for the text class.
     * @param device The paint device.
     * @param id The identifier for the text.
     * @param s The type of the text.
     * @param str The text string.
     */
    text(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::text, QString str = "Hello");

    /**
     * @brief Destructor for the text class.
     */
    ~text();

    /**
     * @brief Draws the text.
     * @param p The QPainter object.
     * @param device The paint device.
     */
    void draw(QPainter &p, QPaintDevice* device);

    /**
     * @brief Moves the text to a new position.
     * @param newX The new x-coordinate.
     * @param newY The new y-coordinate.
     */
    void move(const int newX, const int newY);

    /**
     * @brief Calculates the perimeter of the text.
     * @return The perimeter.
     */
    double perimeter() const;

    /**
     * @brief Calculates the area of the text (always 0 for text).
     * @return The area.
     */
    double area() const;

    /**
     * @brief Sets the alignment of the text.
     * @param alignment The alignment to set.
     */
    void setAlignment(Qt::AlignmentFlag alignment);

    /**
     * @brief Sets the size of the text.
     * @param size The size to set.
     */
    void setSize(int size);

    /**
     * @brief Sets the font of the text.
     * @param font The font to set.
     */
    void setFont(QString font);

    /**
     * @brief Sets the style of the font.
     * @param style The style to set.
     */
    void setStyle(QFont::Style style);

    /**
     * @brief Sets the weight of the font.
     * @param weight The weight to set.
     */
    void setWeight(QFont::Weight weight);

    /**
     * @brief Sets the width of the text.
     * @param width The width to set.
     */
    void setWidth(int width);

    /**
     * @brief Sets the height of the text.
     * @param height The height to set.
     */
    void setHeight(int height);

    /**
     * @brief Sets the string of the text.
     * @param str The string to set.
     */
    void setString(QString str);
};

} // namespace Shapes

#endif // TEXT_H
