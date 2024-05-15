#include "aboutuswidget.h"
#include "ui_aboutuswidget.h"

aboutuswidget::aboutuswidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aboutuswidget)
{
    ui->setupUi(this);
    setWindowTitle(tr("Contact Us")); //Sets name to window
    ui->imageCloud->setScaledContents(true);
    ui->imageCloud->setPixmap(QPixmap("C:/Users/localuser/Desktop/Cloud-main/images/logo.png"));
}

aboutuswidget::~aboutuswidget()
{
    delete ui;
}

void aboutuswidget::on_exitButton_clicked(){
    this->close();
}
