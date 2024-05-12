#include "move.h"
#include "ui_move.h"

using namespace Shapes;
using namespace std;

move::move(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::move)
{
    ui->setupUi(this);
    setWindowTitle(tr("Move Shape")); //Sets name to window

}

move::~move()
{
    delete ui;
}

void move::on_exitButton_clicked(){
    this->close();
}

void move::on_updateButton_clicked(){

    QString temp;
    temp = ui->idInput->text();
    id = temp.toInt();
    x = ui->xBox->value();
    y = ui->yBox->value();
    // std::cout << id << std::endl;
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;

    //int i = 0;
    //while(id != shapes[i]->getId()){
    //    ++i;}
    //cout << i << endl ; //one less than ID, for vector index

    if (id <= shapes.size() && id > 0 ){
        shapes[--id]->move(x,y);}
    else{
        //Invalid Shape Id Entered Pop up
        QMessageBox::warning(this, "Invalid Shape ID", "Invalid Shape ID. Please try again.");
    }

    this->close();
}

void move::setShapeList(Vector::vector<shape *> old)
{
    shapes = old;
}

Vector::vector<shape*>& move::getShapeList()
{
    return this->shapes;
}


