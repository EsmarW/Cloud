#include "loginwidget.h"
#include "window.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

LogWidget::LogWidget(QWidget *parent) : QWidget(parent)
{
    // Create UI elements
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Username:"));
    layout->addWidget(usernameLineEdit);
    layout->addWidget(new QLabel("Password:"));
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);

    setLayout(layout);

    // Connect the login button to the onLoginClicked slot
    connect(loginButton, &QPushButton::clicked, this, &LogWidget::onLoginClicked);
}

void LogWidget::onLoginClicked()
{
    // Example: Validate username and password
    if (usernameLineEdit->text() == "admin" && passwordLineEdit->text() == "password") {
        // On success, hide login and show main window
        Window *mainWindow = new Window();
        mainWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid credentials. Please try again.");
    }
}
