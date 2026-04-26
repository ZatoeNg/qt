#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
class Login;
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void set_login(const std::weak_ptr<Login>& login);

public slots:
    void on_reg_btn_clicked();

private:
    Ui::Register *ui;
    std::weak_ptr<Login> _login;
};

#endif // REGISTER_H
