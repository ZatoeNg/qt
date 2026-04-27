#include "main_window.h"
#include "ui_main_window.h"
#include "my_action.h"

#include <QTextEdit>
#include <QMdiSubWindow>
#include <QMenu>
#include <QIcon>
#include <QKeySequence>
#include <QActionGroup>
#include <QToolButton>
#include <QSpinBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu * edit_menu = ui->menubar->addMenu(tr("编辑(&E)"));
    edit_menu->addSeparator();
    QAction* action_open = edit_menu->addAction(QIcon(":/res/list.png"),tr("打开文件(&O)"));
    action_open->setShortcut(QKeySequence("Ctrl+O"));
    connect(action_open,&QAction::toggled,this,&MainWindow::on_action_open_triggered);

    QActionGroup* group = new QActionGroup(this);
    QAction* action_l = group->addAction(tr("左对齐(&L)"));
    action_l->setCheckable(true);
    QAction* action_r = group->addAction(tr("右对齐(&R)"));
    action_r->setCheckable(true);
    QAction* action_c = group->addAction(tr("居中(&C)"));
    action_c->setCheckable(true);
    edit_menu->addSeparator();
    edit_menu->addAction(action_l);
    edit_menu->addAction(action_r);
    edit_menu->addAction(action_c);

    MyAction* action = new MyAction(this);
    edit_menu->addAction(action);
    connect(action,&MyAction::get_text,this,&MainWindow::set_text_slot);

    QToolButton* tool_btn = new QToolButton(this);
    tool_btn->setText(tr("颜色"));
    ui->toolBar->addWidget(tool_btn);
    QMenu* color_menu = new QMenu(this);
    color_menu->addAction(tr("黄色"));
    color_menu->addAction(tr("蓝色"));
    tool_btn->setMenu(color_menu);
    tool_btn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolBar->addSeparator();
    QSpinBox* spinbox = new QSpinBox(this);
    ui->toolBar->addWidget(spinbox);

    ui->statusbar->showMessage(tr("欢迎使用"),5000);
    QLabel* permnant =new QLabel(this);
    permnant->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permnant->setText("Hello");
    ui->statusbar->addPermanentWidget(permnant);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_show_dock_triggered()
{
    qDebug()<<"show dock widget"<<Qt::endl;
    ui->dock->show();
}


void MainWindow::on_new_file_triggered()
{
    QTextEdit* text_edit = new QTextEdit(this);
    auto clild_window = ui->mdi_area->addSubWindow(text_edit);
    clild_window->setWindowTitle(tr("clild_windows"));
    clild_window->show();

}

void MainWindow::on_action_open_triggered()
{
    qDebug()<<"open file"<<Qt::endl;
}

void MainWindow::set_text_slot(const QString &string)
{
    ui->text_edit->setText(string);
}

