#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QColor>

#include "draw.h"
#include "vector.h"
#include "shapes.h"

using namespace Draw;
using namespace Vector;
using namespace Shapes;

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();
    void setShapeList(vector<shape*> &);

private slots:
    void on_exitButton_clicked();
    void on_updateButton_clicked();

private:
    Ui::add *ui;
    vector<shape*> *shapes; //pointer to shapes vector in draw.h
};

#endif // ADD
