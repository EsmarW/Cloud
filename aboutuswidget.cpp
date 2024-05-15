#include "aboutuswidget.h"
#include "ui_aboutuswidget.h"
#include <QCoreApplication>
#include <QDir>
#include <iostream>

aboutuswidget::aboutuswidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aboutuswidget)
{
    ui->setupUi(this);
    setWindowTitle(tr("Contact Us")); //Sets name to window
    ui->imageCloud->setScaledContents(true);
    //ui->imageCloud->setPixmap(QPixmap("C:/Users/localuser/Desktop/Cloud-main/images/logo.png"));

    QDir d(QDir::currentPath());
    d.cdUp();
    d.cdUp();
    d.cdUp();
    QString parentPath = d.path();
    QString imagePath = parentPath + "/images/logo.png";
    std::cout << imagePath.toStdString() << std::endl << std::endl;
    ui->imageCloud->setPixmap(QPixmap(imagePath)); //Sets image path to /Cloud-main/images/logo.png
}

aboutuswidget::~aboutuswidget()
{
    delete ui;
}

void aboutuswidget::on_exitButton_clicked(){
    this->close();
}
