#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
//#include "window.h"
//#include "mainwindow.h"
#include "mainw.h"

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = nullptr);
    // mainw *mainW = new mainw();


private slots:
    void onLoginClicked();
    void onGuestLoginClicked();

private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *guestButton;

};

#endif // LOGWIDGET_H
