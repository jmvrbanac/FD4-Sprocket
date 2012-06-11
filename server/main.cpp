#include <QtGui/QApplication>
#include "sprocketwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SprocketWindow w;
    w.show();
    
    return a.exec();
}
