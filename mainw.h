#ifndef MAINW_H
#define MAINW_H

#include <QDialog>
#include <QTabWidget>
#include <QWidget>
#include "draw.h"
#include "vector.h"
#include "shapes.h"
#include "aboutus.h"

using namespace Draw;
using namespace Vector;
using namespace Shapes;

namespace Ui {
class mainw;
}

/**
 * @brief The mainw class represents the main window of the application.
 */
class mainw : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the mainw class.
     * @param parent The parent widget.
     */
    explicit mainw(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the mainw class.
     */
    ~mainw();

    /**
     * @brief Reimplemented paint event to handle painting.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event);

private slots:
    /**
     * @brief Slot called when the exit button is clicked.
     */
    void on_exitButton_clicked();

    /**
     * @brief Slot called when the widget's custom context menu is requested.
     * @param pos The position of the context menu request.
     */
    void on_widget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::mainw *ui; /**< The UI object. */
    draw* dw; /**< Pointer to the draw object. */
    shape* s; /**< Pointer to the shape object. */
    vector<shape*> shapeList; /**< The list of shapes. */
    bool admin; /**< Flag indicating admin status. */
    AboutUsWidget* aboutUsWidget;
};

#endif // MAINW_H
