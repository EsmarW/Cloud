#include "mainw.h"
#include "ui_mainw.h"
#include <QPainter>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>

mainw::mainw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainw)
{
    ui->setupUi(this);

    // Get the existing widget from the "About Us" tab
    QWidget* aboutUsTabWidget = ui->tabWidget->findChild<QWidget*>("aboutUsWidget");

    // Create an instance of AboutUsWidget
    AboutUsWidget* aboutUsWidget = new AboutUsWidget(this);

    // Set the layout of the existing widget to a layout containing the AboutUsWidget
    if (aboutUsTabWidget) {
        QVBoxLayout* layout = new QVBoxLayout(aboutUsTabWidget);
        layout->addWidget(aboutUsWidget);
        aboutUsTabWidget->setLayout(layout);
    }
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

