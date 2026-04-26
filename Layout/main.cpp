#include "login.h"
#include "register.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<Login> w = std::make_shared<Login>();
    w->init_signals();
    w->show();

    // Register w;
    // w.show();
    return QCoreApplication::exec();
}
