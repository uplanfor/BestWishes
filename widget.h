#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QMenu>
#include <QAction>
#include <QSystemTrayIcon>
#include <windows.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void contextMenuEvent(QContextMenuEvent *ev);
    void setFrame(QWidget*);
    const QIcon icon;

private:
    Ui::Widget *ui;
    QWidget *frame;
    QSystemTrayIcon *trayicon;
};

static const char* NAME = "安安";
static const char* SAYINGS[] =
{
    "世间所有不尽人意之事，全靠硬扛。常常一个人崩溃，又一个人自愈。！",
    "上天不会亏待努力的人，也不会同情假勤奋的人，你有多努力，时光它知道。",
    "千江有水千江月，万里无云万里天。相信自己，相信明天，别再浪费生命。。",
    "要紧握那些有风的日子，它们吹来你的笑脸，吹来你的善良，带走你的黑暗。",
    "不管事情变得多坏，在不远的地方，请相信总会有一些美好即将来临。",
    "今天的我，之所以要比别人加倍的努力，因为我发现别人有背景，我只有背影。",
    "人生苦短，用心生活。而是来自于自己的奋斗和坚持，是要靠自己争取的。",
    "有的人生来就不需要任何原谅，因为他们不论有多少次机会都没点改进。",
    "痛苦的记忆是泪水洗不净的，只有汗水才能把它冲掉，所以必须好好努力。",
    "成功就是将平凡的事情做到不平凡，要为成功找方法，不要为失败找理由。"
};
#endif // WIDGET_H
