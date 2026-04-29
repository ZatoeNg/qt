#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QPalette>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1 = startTimer(1000);
    id2 = startTimer(1500);
    id3 = startTimer(2000);

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::slot_update_led);
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

//定时器事件回调函数
void Widget::timerEvent(QTimerEvent* event){
    if(event->timerId() == id1){
        qDebug() << "id1 timer triggerd" << Qt::endl;
    }

    if(event->timerId() == id2){
        qDebug() << "id2 timer triggerd" << Qt::endl;
    }

    if(event->timerId() == id3){
        qDebug() << "id3 timer triggerd" << Qt::endl;
    }
}

void Widget::slot_update_led(){
      QTime time = QTime::currentTime();
      QString text = time.toString("hh:mm:ss");
      if(time.second()%2 == 0){
        text[5] = ' ';
      }

      QPalette palette = ui->lcdNumber->palette();
      palette.setColor(QPalette::Normal,QPalette::WindowText,Qt::red);
      ui->lcdNumber->setPalette(palette);
      ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
      ui->lcdNumber->setDigitCount(text.length());
      ui->lcdNumber->display(text);
}
