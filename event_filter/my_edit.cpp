#include "my_edit.h"
#include <QDebug>
#include <QMessageBox>
MyEdit::MyEdit(QWidget *parent) : QLineEdit(parent)
{

}

void MyEdit::keyPressEvent(QKeyEvent * event){
    qDebug()<<"MyEdit key press event:"<<event->text()
             <<"----"<<event->key() << Qt::endl;
    QLineEdit::keyPressEvent(event);
    event->ignore(); //往父节点抛事件
}

bool MyEdit::event(QEvent *pevent)
{
    if(pevent->type() == QEvent::KeyPress){
        qDebug() << tr("my edit event--KeyPress type") << Qt::endl;
        //false:子节点没处理完成,需要父节点配合,true：子节点已经处理好了,父节点不需要处理了.
        //只要return 特定事件都不会处理
        // return true;

    }

    return  QLineEdit::event(pevent);
}
