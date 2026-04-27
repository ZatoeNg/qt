#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QPrinter;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void DoPrint();
    void DoPrintPreview();
    void PrintPreview(QPrinter* printer);
    void CreatePdf();

};

#endif // MAIN_WINDOW_H
