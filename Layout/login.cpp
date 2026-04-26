#include "login.h"
#include "ui_login.h"
#include "register.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::init_signals()
{
    _reg = std::make_shared<Register>();
    _reg->set_login(shared_from_this());

}

void Login::on_sign_up_clicked()
{
    this->close();
    _reg->show();
}

