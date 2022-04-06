#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <thread>
#include "topwidgetelement.h"

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
    topWidgetElement* topwidget[5];     //顶层元素变量
    QWidget* background_widget;     //背景图控件
    QWidget* top_status_widget;     //顶层蓝色背景控件

private:
    std::thread thread_get_time_;   //获取时间线程
    bool exit_thread_flag_;     //退出线程表示 true为退出，false 为不退出

    /* 重设大小 */
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWIDGET_H
