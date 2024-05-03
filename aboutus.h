
// aboutuswidget.h
#ifndef ABOUTUSWIDGET_H
#define ABOUTUSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class AboutUsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AboutUsWidget(QWidget* parent = nullptr);

private:
    QLabel* titleLabel;
    QLabel* descriptionLabel;
    QLabel* imageLabel;
};

#endif // ABOUTUSWIDGET_H