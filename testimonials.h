// testimonials.h
#ifndef TESTIMONIALS_H
#define TESTIMONIALS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QTextBrowser>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

class TestimonialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestimonialWidget(QWidget *parent = nullptr);

private slots:
    void onSubmitClicked();

private:
    QTextEdit *entryWidget;
    QPushButton *submitWidget;
    QTextBrowser *displayWidget;
};

#endif // TESTIMONIALS_H
