#include "mymainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
    w.move((a.desktop()->width() - w.width()) / 2, (a.desktop()->height() - w.height()) / 2);
    w.show();

    return a.exec();
}
