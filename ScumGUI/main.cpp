#include "scumgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScumGUI w;
    w.show();
    return a.exec();
}
