#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "highlighter.h"

#include <QMainWindow>
#include "code_editor.h"
QT_BEGIN_NAMESPACE
class QTextEdit;
QT_END_NAMESPACE

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    QSize sizeHint() const;
public slots:
    void about();
    void newFile();
    void openFile(const QString &path = QString());

private:
    void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();

    CodeEditor *editor;
    Highlighter *highlighter;
};
//! [0]

#endif // MAIN_WINDOW_H
