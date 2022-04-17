//主界面用户信息与塔吊信息控件

#ifndef CYUSERTOWERWIDGET_H
#define CYUSERTOWERWIDGET_H

#include "global.h"

class cyUserTowerWidget : public QWidget
{
    Q_OBJECT


public:
    explicit cyUserTowerWidget(QWidget *parent = nullptr);
    void init();

private:
    QWidget* user_info_widget_;     //用户信息区域
    QWidget* right_tower_status_widget_;  //右边塔吊略缩图区域
    QWidget* right_tower_chart_widget_; //右边塔吊图表

    QVBoxLayout* main_vertical_layout_;  //主垂直布局
    QHBoxLayout* horizon_layout_;        //水平布局

signals:

};

#endif // CYUSERTOWERWIDGET_H
