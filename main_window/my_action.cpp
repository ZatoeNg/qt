#include "my_action.h"
#include <QSplitter>
#include <QLabel>

MyAction::MyAction(QObject *parent):QWidgetAction(parent)
{
    _line_edit = new QLineEdit();
    connect(_line_edit,&QLineEdit::returnPressed,this,&MyAction::sent_text);
}

void MyAction::sent_text()
{
    emit get_text(_line_edit->text());
    _line_edit->clear();
}

QWidget *MyAction::createWidget(QWidget *parent)
{
    if(!(parent->inherits("QMenu")) && !(parent->inherits("QToolBar"))) return 0;

    QSplitter* splitter = new QSplitter(parent);
    QLabel* lab = new QLabel();
    lab->setText(tr("插入文本"));
    splitter->addWidget(lab);
    splitter->addWidget(_line_edit);
    return splitter;

}
