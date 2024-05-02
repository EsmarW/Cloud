#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE

class RenderArea;

/**
 * @brief The mainwindow class represents the main window of the application.
 */
class mainwindow : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the mainwindow class.
     */
    mainwindow();

private slots:
    /**
     * @brief Slot called when the shape is changed.
     */
    void shapeChanged();

    /**
     * @brief Slot called when the pen is changed.
     */
    void penChanged();

    /**
     * @brief Slot called when the brush is changed.
     */
    void brushChanged();

private:
    RenderArea *renderArea; /**< The render area widget. */
    QLabel *shapeLabel; /**< Label for the shape. */
    QLabel *penWidthLabel; /**< Label for the pen width. */
    QLabel *penStyleLabel; /**< Label for the pen style. */
    QLabel *penCapLabel; /**< Label for the pen cap. */
    QLabel *penJoinLabel; /**< Label for the pen join. */
    QLabel *brushStyleLabel; /**< Label for the brush style. */
    QLabel *otherOptionsLabel; /**< Label for other options. */
    QComboBox *shapeComboBox; /**< Combo box for selecting shapes. */
    QSpinBox *penWidthSpinBox; /**< Spin box for pen width. */
    QComboBox *penStyleComboBox; /**< Combo box for pen style. */
    QComboBox *penCapComboBox; /**< Combo box for pen cap. */
    QComboBox *penJoinComboBox; /**< Combo box for pen join. */
    QComboBox *brushStyleComboBox; /**< Combo box for brush style. */
    QCheckBox *antialiasingCheckBox; /**< Check box for enabling antialiasing. */
    QCheckBox *transformationsCheckBox; /**< Check box for enabling transformations. */
};

#endif // MAINWINDOW_H
