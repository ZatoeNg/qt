#include "register.h"
#include "login.h"
#include "ui_register.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    //现在界面大小
    this->setMaximumSize(QSize(400,550));
    this->setMinimumSize(QSize(400,550));

    //垂直布局
    auto vbox_layout = new QVBoxLayout();
    auto ver_spacer_1 =new QSpacerItem(40,20,QSizePolicy::Minimum,QSizePolicy::Expanding);
    vbox_layout->addItem(ver_spacer_1); // 加入弹簧

    QLabel* name_label = new QLabel();
    QSpacerItem* name_item_1 =new QSpacerItem(80,20,QSizePolicy::Fixed
                                               ,QSizePolicy::Minimum);
    QSpacerItem* name_item_2 =new QSpacerItem(80,20,QSizePolicy::Fixed
                                               ,QSizePolicy::Minimum);
    name_label->setText(tr("邮箱："));
    QLineEdit* name_edit = new QLineEdit();
    auto name_layout = new QHBoxLayout();
    name_layout->addItem(name_item_1);
    name_layout->addWidget(name_label);
    name_layout->addWidget(name_edit);
    name_layout->addItem(name_item_2);
    vbox_layout->addLayout(name_layout);

    this->setLayout(vbox_layout);
    auto ver_spacer_2 = new QSpacerItem(40,20,QSizePolicy::Maximum
                                        ,QSizePolicy::Maximum);
     vbox_layout->addItem(ver_spacer_2);

    QSpacerItem* pwd_item_1 =new QSpacerItem(80,20,QSizePolicy::Fixed
                                               ,QSizePolicy::Minimum);
    QSpacerItem* pwd_item_2 =new QSpacerItem(80,20,QSizePolicy::Fixed
                                               ,QSizePolicy::Minimum);

    auto pwd_layout = new QHBoxLayout();
    QLabel* pwd_lab = new QLabel();
    pwd_lab->setText(tr("密码："));
    QLineEdit* pwd_edit = new QLineEdit();

    pwd_layout->addItem(pwd_item_1);
    pwd_layout->addWidget(pwd_lab);
    pwd_layout->addWidget(pwd_edit);
    pwd_layout->addItem(pwd_item_2);
    vbox_layout->addLayout(pwd_layout);

    auto ver_spacer_3 = new QSpacerItem(40,20,QSizePolicy::Fixed
                                        ,QSizePolicy::Expanding);
    QSpacerItem* reg_item_1 =new QSpacerItem(150,20,QSizePolicy::Fixed
                                               ,QSizePolicy::Minimum);
    QSpacerItem* reg_item_2 =new QSpacerItem(150,20,QSizePolicy::Fixed
                                               ,QSizePolicy::Minimum);
    vbox_layout->addItem(ver_spacer_3);

    auto reg_btn = new QPushButton();
    reg_btn->setText("注册");
    auto reg_lay = new QHBoxLayout();

    reg_lay->addItem(reg_item_1);
    reg_lay->addWidget(reg_btn,5);
    reg_lay->addItem(reg_item_2);
    vbox_layout->addLayout(reg_lay);

    auto ver_spacer_4 = new QSpacerItem(40,20,QSizePolicy::Fixed
                                        ,QSizePolicy::Expanding);
    vbox_layout->addItem(ver_spacer_4);

    connect(reg_btn,&QPushButton::clicked,this,&Register::on_reg_btn_clicked);
}

Register::~Register()
{
    delete ui;
}

void Register::set_login(const std::weak_ptr<Login> &login)
{
    _login = login;
}

void Register::on_reg_btn_clicked()
{
    this->close();
    auto shared_login = _login.lock();
    if(shared_login)shared_login->show();
}
