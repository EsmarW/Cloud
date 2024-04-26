#include "loginWidget.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include "window.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent), loginAttempts(0) {
    usernameEdit = new QLineEdit();
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginWidget::on_loginButton_clicked);
}

void LoginWidget::on_loginButton_clicked() {
    // Here you'd check credentials against a stored hash or a database
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    QFile file("credentials.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open credentials database.");
        return;
    }

    QTextStream in(&file);
    bool found = false;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.size() == 2 && parts[0] == username && parts[1] == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        Window *window = new Window();
        window->show();
        this->close();
    } else {
        // Handle wrong credentials
        loginAttempts++;
        if (loginAttempts >= 3) {
            QMessageBox::critical(this, "Login Failed", "You have exceeded the maximum number of login attempts. Please try again later.");
            loginButton->setEnabled(false); // Disable login button
        } else {
            QMessageBox::warning(this, "Login Failed", "Incorrect username or password. Please try again.");
        }
    }
}
