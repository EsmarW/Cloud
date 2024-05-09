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

    // Get the existing widget from the "Testimonial" tab
       QWidget *testimonialTabWidget = ui->tabWidget->findChild<QWidget*>("testimonialWidget_2");

       // Create an instance of TestimonialWidget
       TestimonialWidget *testimonialWidget_2 = new TestimonialWidget(this);

       // Set the layout of the existing widget to a layout containing the TestimonialWidget
       if (testimonialTabWidget) {
           // Check if the layout is already set, if so, delete it
           if (testimonialTabWidget->layout())
               delete testimonialTabWidget->layout(); // Delete existing layout to avoid memory leaks

           QVBoxLayout *layout = new QVBoxLayout(testimonialTabWidget);
           layout->addWidget(testimonialWidget_2);
           testimonialTabWidget->setLayout(layout);
       } else {
           // If the "Testimonial" tab widget doesn't exist, delete the instance of TestimonialWidget
           delete testimonialWidget_2;
       }

       // Get the existing widget from the "About Us" tab
           QWidget *aboutUsTabWidget = ui->tabWidget->findChild<QWidget*>("aboutUsWidget_2");

           // Create an instance of AboutUsWidget
           AboutUsWidget *aboutUsWidget_2 = new AboutUsWidget(this);

           // Set the layout of the existing widget to a layout containing the AboutUsWidget
           if (aboutUsTabWidget) {
               // Check if the layout is already set, if so, delete it
               if (aboutUsTabWidget->layout())
                   delete aboutUsTabWidget->layout(); // Delete existing layout to avoid memory leaks

               QVBoxLayout *layout = new QVBoxLayout(aboutUsTabWidget);
               layout->addWidget(aboutUsWidget_2);
               aboutUsTabWidget->setLayout(layout);
           } else {
               // If the "About Us" tab widget doesn't exist, delete the instance of AboutUsWidget
               delete aboutUsWidget_2;
           }


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


