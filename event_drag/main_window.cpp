#include "main_window.h"
#include "ui_main_window.h"
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true); //允许控件拖到
    ui->textEdit->setAcceptDrops(false);//防止控件，拖动文件，打印的是文件的路径
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //判断是否包含url
    if(event->mimeData()->hasUrls()) event->acceptProposedAction();//接收动作
    else event->ignore(); //放弃事件
}

void MainWindow::dropEvent(QDropEvent * event)
{
    const QMimeData * mimeData = event->mimeData();

    qDebug()<<"mimeData url is:" << mimeData->hasUrls()<<Qt::endl;

    //判断是否包含url
    if(!mimeData->hasUrls())
    {
        event->ignore();
        return;
    }


    QList<QUrl> urlList = mimeData->urls();
    qDebug()<<"event url is:" << urlList<<Qt::endl;

    //将第一个匹配为本地文件路径
    QString filename = urlList[0].toLocalFile();
    qDebug()<<"filename is:" << filename<<Qt::endl;

    if(filename.isEmpty())
    {
        event->ignore();
        return;
    }

    QFile file(filename);
    //打开文件失败
    if(!file.open(QIODevice::ReadOnly))return;

    //打开成功
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    ui->textEdit->setText(in.readAll());
}
