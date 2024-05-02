#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

/**
 * @brief The LogWidget class represents a login widget.
 */
class LogWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the LogWidget class.
     * @param parent The parent widget.
     */
    explicit LogWidget(QWidget *parent = nullptr);

private slots:
    /**
     * @brief Slot called when the login button is clicked.
     */
    void onLoginClicked();

    /**
     * @brief Slot called when the guest login button is clicked.
     */
    void onGuestLoginClicked();

private:
    QLineEdit *usernameLineEdit; /**< Line edit for entering the username. */
    QLineEdit *passwordLineEdit; /**< Line edit for entering the password. */
    QPushButton *loginButton; /**< Button for logging in. */
    QPushButton *guestButton; /**< Button for guest login. */
};

#endif // LOGWIDGET_H
