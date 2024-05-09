// testimonials.cpp
#include "testimonials.h"
TestimonialWidget::TestimonialWidget(QWidget *parent) : QWidget(parent)
{
    // Create UI elements
    entryWidget = new QTextEdit(this);
    submitWidget = new QPushButton("submit", this);
    displayWidget = new QTextBrowser(this);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(entryWidget);
    layout->addWidget(submitWidget);
    layout->addWidget(displayWidget);

    setLayout(layout);

    // Connect the submit button click signal to the slot for handling it
    connect(submitWidget, &QPushButton::clicked, this, &TestimonialWidget::onSubmitClicked);

    // Load existing testimonials from file
    QFile file("testimonials.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            displayWidget->append(line);
        }
        file.close();
    }
}

void TestimonialWidget::onSubmitClicked()
{
    // Get the text from the entry widget
    QString entry = entryWidget->toPlainText();

    // Append the text to the display widget
    displayWidget->append(entry);

    // Save the entry to file
    QFile file("testimonials.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << entry << '\n';
        file.close();
    }

    // Clear the entry widget after submitting
    entryWidget->clear();
}
