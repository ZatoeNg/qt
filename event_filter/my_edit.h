#ifndef EDIT_H
#define EDIT_H

#include <QObject>
#include <QLineEdit>
#include <QKeyEvent>
class MyEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyEdit(QWidget *parent = nullptr);

protected:
   void keyPressEvent(QKeyEvent *);
   bool event(QEvent * event);
};

#endif // EDIT_H
