#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_show_dock_triggered();

    void on_new_file_triggered();

    void on_action_open_triggered();

    void set_text_slot(const QString& string);

private:
    Ui::MainWindow *ui;
};
#endif // MAIN_WINDOW_H
