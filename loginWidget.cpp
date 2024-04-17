#include "loginWidget.h"
#include <QVBoxLayout>

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
        // Assuming 'MainWindow' is your main class handling the 2D modeler
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    } else {
        // Handle wrong credentials
    }
}
