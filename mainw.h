#ifndef MAINW_H
#define MAINW_H

#include <QDialog>
#include "draw.h"
#include "vector.h"
#include "shapes.h"
#include "move.h"
#include "add.h"
#include"loginwidget.h"
#include"aboutuswidget.h"


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
    explicit mainw(QWidget *parent = nullptr);
    ~mainw();
    void setParent (QWidget *parent);
    void setAdmin(bool b){ admin = b; }

private slots:
    void on_exitButton_clicked();
    void on_updateButton_clicked();
    void on_moveButton_clicked();
    void on_resetButton_clicked();
    void on_clearButton_clicked();
    void on_loginButton_clicked();
    void on_contactButton_clicked();

    void update();
//    void on_widget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::mainw *ui;
    vector<shape*> shapeList;
    QWidget *parent;
    bool admin;
    void createTestimonialTab();
    void createAboutUsTab();
};

#endif // MAINW_H
