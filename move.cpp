#include "move.h"
#include "ui_move.h"

using namespace Shapes;
using namespace std;

move::move(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::move)
{
    ui->setupUi(this);
}

move::~move()
{
    delete ui;
}

void move::on_exitButton_clicked(){
    this->close();
}

void move::on_updateButton_clicked(){
    //LogWidget::mainW->update();
    //int id;
    QString temp;
    temp = ui->idInput->text();
    //id = temp.split(" ")[0].toInt();
    id = temp.toInt();
    //int x,y;
    x = ui->xBox->value();
    y = ui->yBox->value();
    std::cout << id << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    int i = 0;
    while(id != shapes[i]->getId()){
        i++;}
    cout << i << endl ;
    shapes[i]->move(x,y);

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


