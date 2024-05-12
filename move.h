#ifndef MOVE_H
#define MOVE_H

#include <QDialog>
#include <QMessageBox>
//#include "mainw.h"
//#include "loginwidget.h"
#include "shapes.h"
#include "vector.h"
#include "draw.h"
#include "line.h"


using namespace Shapes;
using namespace Vector;
using namespace Draw;


namespace Ui {
class move;

}
//using namespace Ui;
class move : public QDialog
{
    Q_OBJECT

public:
    explicit move(QWidget *parent = nullptr);
    ~move();
    void setShapeList(vector<shape *> old);
    vector<shape*>& getShapeList();
    int getX(){return x;}
    int getY(){return y;}
    int getID(){return id;}
    vector<shape*> shapes;

private slots:
    void on_exitButton_clicked();
    void on_updateButton_clicked();

private:
    Ui::move *ui;
    int x,y;
    int id;

};

#endif // MOVE_H
