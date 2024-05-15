#include "aboutuswidget.h"
#include "ui_aboutuswidget.h"
#include <QCoreApplication>
#include <QDir>

aboutuswidget::aboutuswidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aboutuswidget)
{
    ui->setupUi(this);
    setWindowTitle(tr("Contact Us")); //Sets name to window
    // Create UI elements
        imageLabel = new QLabel(this);

        // Get the directory of the executable
        QString appDir = QCoreApplication::applicationDirPath();

        // Navigate to the parent directory of the executable
        QDir parentDir(appDir);
        parentDir.cdUp();

        // Check if the Cloud-master directory exists
        QDir cloudMasterDir(parentDir.absolutePath() + "/Cloud-main");
        if (cloudMasterDir.exists()) {
            // Construct the path to the image file relative to the "Cloud-main" directory
            QString imagePath = cloudMasterDir.absoluteFilePath("images/logo.png");

            // Set the pixmap to the image label
            ui->imageCloud->setPixmap(QPixmap(imagePath));
        }
    ui->imageCloud->setScaledContents(true);


}

aboutuswidget::~aboutuswidget()
{
    delete ui;
}

void aboutuswidget::on_exitButton_clicked(){
    this->close();
}
