#ifndef TESTIMONIALS_H
#define TESTIMONIALS_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QTextBrowser>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

namespace Ui {
class testimonials;
}

class testimonials : public QDialog
{
    Q_OBJECT

public:
    explicit testimonials(QWidget *parent = nullptr);
    ~testimonials();

private slots:
    void onSubmitClicked();
    void on_exitButton_clicked();

private:
    Ui::testimonials *ui;
    QTextEdit *entryWidget;
    QPushButton *submitWidget;
    QTextBrowser *displayWidget;
};

#endif // TESTIMONIALS_H
