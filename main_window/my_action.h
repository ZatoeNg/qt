#ifndef MY_ACTION_H
#define MY_ACTION_H
#include <QWidgetAction>
#include <QLineEdit>
#include <QString>

class MyAction:public QWidgetAction
{
    Q_OBJECT
public:
    MyAction(QObject* parent =nullptr);

private slots:
    void sent_text();
signals:
    void get_text(const QString& string);

protected:
    virtual QWidget* createWidget(QWidget* parent);
private:
    QLineEdit * _line_edit;

};

#endif // MY_ACTION_H
