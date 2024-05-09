// aboutuswidget.cpp
#include "aboutuswidget.h"
#include "window.h"
#include "mainwindow.h"
#include "mainw.h"

AboutUsWidget::AboutUsWidget(QWidget *parent) : QWidget(parent)
{
    // Create UI elements
    descriptionLabel = new QLabel("We are team cloud", this);
    imageLabel = new QLabel(this);
    imageLabel->setPixmap(QPixmap("/home/cs1c/Downloads/Cloud-main/images/logo.png")); // Replace ":/path/to/your/image.png" with the actual path to your PNG file
    nameLabel = new QLabel("Names:<br/>Evan Stewart<br/>Esmar Walkman<br/>Josh Baxter<br/>Max Tan<br/>Yu-chen Chung<br/>Kaiass Asadi",this);
    // Set the label to scale its contents to fit
    imageLabel->setScaledContents(true);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(descriptionLabel);
    layout->addWidget(imageLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(nameLabel);


    setLayout(layout);
}
