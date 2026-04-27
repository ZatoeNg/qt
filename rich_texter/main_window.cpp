#include "main_window.h"
#include "ui_main_window.h"
#include "syntax_highlighter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_ligher = new MySyntaxHighlighter(ui->textEdit->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}
