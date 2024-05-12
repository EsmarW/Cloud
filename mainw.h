#ifndef MAINW_H
#define MAINW_H

#include <QDialog>
#include "draw.h"
#include "vector.h"
#include "shapes.h"
#include "move.h"
#include "add.h"

using namespace Draw;
using namespace Vector;
using namespace Shapes;


namespace Ui {
class mainw;
}

class mainw : public QDialog
{
    Q_OBJECT

public:
    //void paintEvent(QPaintEvent *event);

    explicit mainw(QWidget *parent = nullptr);
    ~mainw();

private slots:
    void on_exitButton_clicked();
    void on_updateButton_clicked();
    void on_moveButton_clicked();
    void on_resetButton_clicked();
    void on_clearButton_clicked();

    void update();
//    void on_widget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::mainw *ui;
    draw* dw;
    shape* s;
    vector<shape*> shapeList;
    bool admin;
};

#endif // MAINW_H
