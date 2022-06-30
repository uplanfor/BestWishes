#include "widget.h"
#include "customframe.h"
#include <QIcon>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomFrame f(new Widget);
    Widget* w = static_cast<Widget*>(f.container());
    f.show();
    f.setWindowIcon(w->icon);
    f.setResizable(false);
    w->setFrame(&f);

//    f.setMovable(false);
    return a.exec();
}
