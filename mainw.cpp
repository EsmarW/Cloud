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
    if (admin){ std::cout << "Admin" << std::endl;}
}

mainw::~mainw()
{
    delete ui;
}

void mainw::setParent (QWidget *p){
    parent = p;
}

void mainw::on_exitButton_clicked(){
    this->close();
}

void mainw::on_loginButton_clicked(){
    parent->show();
    this->close();
}

void mainw::on_updateButton_clicked(){
    if (admin){
    class add *a = new add();
    a->setShapeList(ui->canvas->getShapeList());
    a->show();
    }
    else{
        QMessageBox::warning(this, "Admin Credentials Not Detected", \
            "Not logged in as an Administrator. Please log in and try again.");
    }
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
    if (admin){
        class move *m = new class move();
        m->setShapeList(ui->canvas->getShapeList());
        m->show();
    }
    else{
        QMessageBox::warning(this, "Admin Credentials Not Detected", \
                             "Not logged in as an Administrator. Please log in and try again.");
    }
}

void mainw::on_contactButton_clicked(){
    class aboutuswidget *w = new class aboutuswidget();
    w->show();
}
void mainw::on_testimonialButton_clicked(){
    class testimonials *w = new class testimonials();
    w->show();
}


