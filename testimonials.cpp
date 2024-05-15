#include "testimonials.h"
#include "ui_testimonials.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>

testimonials::testimonials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testimonials)
{
    ui->setupUi(this);

    // Create UI elements
    entryWidget = new QTextEdit(this);
    submitWidget = new QPushButton("submit", this);
    displayWidget = new QTextBrowser(this);

    // Layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(entryWidget);
    layout->addWidget(submitWidget);
    layout->addWidget(displayWidget);

    setLayout(layout);

    // Load existing testimonials from file
    QFile file("testimonials.txt");
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            displayWidget->append(line);
        }
        file.close();
    } else {
        // File doesn't exist or couldn't be opened, provide default testimonial
        QString defaultTestimonial = "This product works great!";
        displayWidget->append(defaultTestimonial);

        // Save default testimonial to file
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << defaultTestimonial << '\n';
            file.close();
        } else {
            qWarning() << "Failed to open testimonials file for writing!";
        }
    }

    connect(submitWidget, &QPushButton::clicked, this, &testimonials::onSubmitClicked);
}

testimonials::~testimonials()
{
    delete ui;
}

void testimonials::onSubmitClicked()
{
    QString entry = entryWidget->toPlainText();
    displayWidget->append(entry);

    // Save the entry to file
    QFile file("testimonials.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << entry << '\n';
        file.close();
    }
    else {
        qWarning() << "Failed to open testimonials file for writing!";
    }

    entryWidget->clear();
}

void testimonials::on_exitButton_clicked(){
    this->close();
}
