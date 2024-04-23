#include "loginWidget.h"
#include <QVBoxLayout>
#include <QMessageBox>  // Include for showing message boxes
#include "window.h"     // Ensure this include is correct based on your project structure

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent) {
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
    // Here you'd check credentials probably against a stored hash or a database
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Dummy check for example
    if (username == "user" && password == "pass") {
        Window *window = new Window();  // Assuming 'Window' is your main class
        window->show();
        this->close();  // Optionally, handle this differently depending on your app's needs
    } else {
        // Handle wrong credentials
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password. Please try again.");
    }
}
