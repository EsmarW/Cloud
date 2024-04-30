#include "mainw.h"
#include "ui_mainw.h"
#include <QPainter>
#include <QtWidgets>

mainw::mainw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainw)
{
    ui->setupUi(this);
}

mainw::~mainw()
{
    delete ui;
}

void mainw::on_exitButton_clicked(){
    this->close();
}

void mainw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);
    //dw->drawShapes();
 //   painter.drawLine(QPoint(50,60), QPoint(100,100));

    painter.setBrush(Qt::BDiagPattern);
   // painter.drawRect(QRect(250,20,80,180));

}

void mainw::on_widget_customContextMenuRequested(const QPoint &pos)
{

}

