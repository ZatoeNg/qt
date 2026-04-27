#ifndef MY_DIALOG_H
#define MY_DIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyDialog *ui;
};

#endif // MY_DIALOG_H
