#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Register;
class Login : public QDialog,public std::enable_shared_from_this<Login>
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login() override;
    void init_signals();

private:
    Ui::Login *ui;
    std::shared_ptr<Register> _reg;

private slots:
    void on_sign_up_clicked();
};
#endif // LOGIN_H
