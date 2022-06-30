#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), icon(":/BestWishes.jpg")
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    ui->setupUi(this);
    trayicon = new QSystemTrayIcon(this);
    trayicon->setIcon(icon);
    trayicon->show();
    trayicon->showMessage(NAME, "安安正在初始化中", icon, 2500);
    this->setContextMenuPolicy(Qt::DefaultContextMenu);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::contextMenuEvent(QContextMenuEvent *ev)
{
    QMenu menu;
    QAction* act_quit = menu.addAction("离开安安");
    QAction* act_about = menu.addAction("了解安安");
    QAction* act_hide = menu.addAction("隐藏安安");
    menu.addSeparator();
    QAction* act_talk = menu.addAction("励志鸡汤");
    connect(act_quit, &QAction::triggered, this, [=]()
    {
        if (IDOK == MessageBox(NULL, TEXT("安安这么可爱，你真的想离开安安吗？"), TEXT("安安"), MB_OKCANCEL | MB_ICONINFORMATION) )
        {
            qApp->quit();
        }
        else
        {
            trayicon->showMessage(NAME, "十分感谢你没有离开!", icon, 3000);
        }

    });
    connect(act_about, &QAction::triggered, this, [=]()
    {
        trayicon->showMessage(NAME, "星光是安安的生命！\n期待与漫天繁星的相遇！", icon, 3000);
        ShellExecute(NULL, TEXT("open"), TEXT("https://www.ixigua.com/home/108901792538/?source=pgc_author_name&list_entrance=anyVideo"), NULL, NULL, SW_SHOW);
    });
    connect(act_talk, &QAction::triggered, this, [=]
    {
        trayicon->showMessage(NAME, SAYINGS[qrand()%10], icon, 3000);
    });
    connect(act_hide, &QAction::triggered, this, [=]()
    {
        frame->showMinimized();
    });
    menu.exec(QCursor::pos());
}


void Widget::setFrame(QWidget* f)
{
    frame = f;
}
