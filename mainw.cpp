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

}

mainw::~mainw()
{
    delete ui;
}

void mainw::on_exitButton_clicked(){
    this->close();
}

void mainw::on_updateButton_clicked(){
    //this->close();
    //ui->canvas->update();
    //ui->canvas->initializeShapes();
    // ui->canvas->clearShapes();
    // ui->canvas->drawShapes();
    // ui->canvas->update();
    int id = (ui->canvas->shapes.size());
    ++id;

    rectangle* r = new rectangle(this);
    r->setId(id);
    r->setCoords(400,350);
    r->setWidth(100);
    r->setHeight(100);
    r->setPen(Qt::GlobalColor::darkBlue, 2 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin);
    r->setBrush(Qt::GlobalColor::green, Qt::HorPattern);

    ui->canvas->addShape(r);
    ui->canvas->update();
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
    ui->canvas->getShapeList();
    class move *m = new class move();
    //m->move(ui->canvas->getShapeList());
    m->setShapeList(ui->canvas->getShapeList());
    m->show();

}
/*
void mainw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);
    //dw->drawShapes();
 //   painter.drawLine(QPoint(50,60), QPoint(100,100));

    painter.setBrush(Qt::BDiagPattern);
   // painter.drawRect(QRect(250,20,80,180));

}*/


