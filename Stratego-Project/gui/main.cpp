#include "Stratego_gui.h"
#include <QApplication>
#include "Controller.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Stratego_gui w;
    w.show();
    return a.exec();
}
