#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <thread>
#include "topwidgetelement.h"
#include "cysignalwidget.h"
#include "cyvoicebackstagebtn.h"
#include "cypaintcircle.h"

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
    topWidgetElement* topwidget_[5];     //顶层元素变量
    cySignalWidget* signalWidget_[2];    //顶层信号控件
    cyVoiceBackstageBtn* voice_backagestage_btn_;   //后台声音按钮

    //区域控件变量
    QWidget* background_widget_;     //背景图控件
    QWidget* top_status_widget_;     //顶层蓝色背景区域
    QWidget* camera_widget_;         //摄像头区域
    QWidget* user_info_widget_;     //用户信息区域
    QWidget* buttom_tower_detail_info_wiget_;   //底部塔吊详细信息区域
    QWidget* right_tower_status_widget_;  //右边塔吊略缩图区域
    QWidget* right_tower_chart_widget_; //右边塔吊图表

    //布局变量
    QGridLayout* main_grid_layout_;     //主布局
    QHBoxLayout* horizon_top_status_layout_;    //顶部状态布局
private:
    void initTopStatusArea();   //初始化顶部状态栏
    void initCameraArea();      //初始化摄像头区域
    void initUserInfoArea();    //初始化用户信息区域
    void initButtonDetailInfoArea();    //初始化塔吊底部详细信息区域
    void initRightTowerStatusArea();    //初始化右边塔吊略缩图区域

private:
    std::thread thread_get_time_;   //获取时间线程
    bool exit_thread_flag_;     //退出线程表示 true为退出，false 为不退出

    /* 重设大小 */
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWIDGET_H
