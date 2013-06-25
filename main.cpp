#include <openwidget.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenWidget wid;
    wid.show();
    wid.showFullScreen();
    
    return a.exec();
}
