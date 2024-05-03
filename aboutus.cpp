// aboutuswidget.cpp
#include "aboutus.h"
#include "window.h"
#include "mainwindow.h"
#include "mainw.h"

AboutUsWidget::AboutUsWidget(QWidget *parent) : QWidget(parent)
{
    // Create UI elements
    titleLabel = new QLabel("Team Description:", this);
    descriptionLabel = new QLabel("We are team cloud", this);
    imageLabel = new QLabel(this);
    imageLabel->setPixmap(QPixmap("/home/cs1c/Pictures/logo.png")); // Replace ":/path/to/your/image.png" with the actual path to your PNG file

    // Set the label to scale its contents to fit
    imageLabel->setScaledContents(true);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(imageLabel);

    setLayout(layout);
}