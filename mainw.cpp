#include "mainw.h"
#include "ui_mainw.h"
#include <QPainter>
#include <QtWidgets>

mainw::mainw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainw)
{
    ui->setupUi(this);
    ui->canvas->drawShapes();
    setWindowTitle(tr("2D Shape Modeler")); //Sets name to window
}

mainw::~mainw()
{
    delete ui;
}

void mainw::on_exitButton_clicked(){
    this->close();
}

void mainw::on_updateButton_clicked(){
    class add *a = new add();
    a->setShapeList(ui->canvas->getShapeList());
    a->show();
    //ui->canvas->update();
}

void mainw::on_resetButton_clicked(){
    //ui->canvas->drawShapes();
    ui->canvas->clearShapes();
    ui->canvas->drawShapes();
    ui->canvas->update();
}

void mainw::on_clearButton_clicked(){
    ui->canvas->clearShapes();
    ui->canvas->update();
}

void mainw::update(){
    ui->canvas->update();
}

void mainw::on_moveButton_clicked(){
    class move *m = new class move();
    //m->move(ui->canvas->getShapeList());
    m->setShapeList(ui->canvas->getShapeList());
    m->show();
}

