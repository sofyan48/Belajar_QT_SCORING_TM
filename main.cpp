#include "wtenismeja.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WTenisMeja w;
    w.show();
    w.showFullScreen();
    return a.exec();
}
