#ifndef ABOUTUSWIDGET_H
#define ABOUTUSWIDGET_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class aboutuswidget;
}

class aboutuswidget : public QDialog
{
    Q_OBJECT

public:
    explicit aboutuswidget(QWidget *parent = nullptr);
    ~aboutuswidget();

private slots:
    void on_exitButton_clicked();

private:
    Ui::aboutuswidget *ui;
    QLabel *descriptionLabel;
    QLabel *imageLabel;
    QLabel *nameLabel;
};

#endif // ABOUTUSWIDGET_H
