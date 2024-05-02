#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

/**
 * @brief The RenderArea class represents a custom rendering area widget.
 */
class RenderArea : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Enumeration representing different shapes that can be drawn.
     */
    enum Shape {
        Line, /**< Line shape. */
        Points, /**< Points shape. */
        Polyline, /**< Polyline shape. */
        Polygon, /**< Polygon shape. */
        Rect, /**< Rectangle shape. */
        RoundedRect, /**< Rounded rectangle shape. */
        Ellipse, /**< Ellipse shape. */
        Arc, /**< Arc shape. */
        Chord, /**< Chord shape. */
        Pie, /**< Pie shape. */
        Path, /**< Path shape. */
        Text, /**< Text shape. */
        Pixmap /**< Pixmap shape. */
    };

    /**
     * @brief Constructor for the RenderArea class.
     * @param parent The parent widget.
     */
    explicit RenderArea(QWidget *parent = nullptr);

    /**
     * @brief Returns the minimum size hint for the widget.
     * @return The minimum size hint.
     */
    QSize minimumSizeHint() const override;

    /**
     * @brief Returns the preferred size hint for the widget.
     * @return The preferred size hint.
     */
    QSize sizeHint() const override;

public slots:
    /**
     * @brief Sets the shape to be drawn.
     * @param shape The shape to set.
     */
    void setShape(Shape shape);

    /**
     * @brief Sets the pen for drawing.
     * @param pen The pen to set.
     */
    void setPen(const QPen &pen);

    /**
     * @brief Sets the brush for filling shapes.
     * @param brush The brush to set.
     */
    void setBrush(const QBrush &brush);

    /**
     * @brief Sets whether antialiasing is enabled.
     * @param antialiased True to enable antialiasing, false otherwise.
     */
    void setAntialiased(bool antialiased);

    /**
     * @brief Sets whether transformations are applied.
     * @param transformed True to apply transformations, false otherwise.
     */
    void setTransformed(bool transformed);

protected:
    /**
     * @brief Paints the widget and its child widgets if needed.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event) override;

private:
    Shape shape; /**< The shape to be drawn. */
    QPen pen; /**< The pen for drawing. */
    QBrush brush; /**< The brush for filling shapes. */
    bool antialiased; /**< Flag indicating whether antialiasing is enabled. */
    bool transformed; /**< Flag indicating whether transformations are applied. */
    QPixmap pixmap; /**< The pixmap for drawing. */
};

#endif // RENDERAREA_H
