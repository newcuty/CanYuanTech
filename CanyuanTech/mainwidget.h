#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <thread>
#include <QStackedWidget>
#include "topwidgetelement.h"
#include "cysignalwidget.h"
#include "cyvoicebackstagebtn.h"
#include "cypaintcircle.h"
#include "cylogin.h"
#include "cyusertowerwidget.h"


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

    //顶部区域变量
    QWidget* top_status_widget_;     //顶层蓝色背景区域
    //右边区域变量
    QStackedWidget* right_stacked_widget_;    //用堆栈控件来装右边的区域
    cyLogin* login_widget_;    //登录界面
    cyUserTowerWidget* user_tower_widget_; //用户信息与塔吊信息

    //设置界面

    //左边区域变量
    QWidget* camera_widget_;         //摄像头区域
    QWidget* buttom_tower_detail_info_wiget_;   //底部塔吊详细信息区域

    //布局变量
    QGridLayout* main_grid_layout_;     //主布局
    QHBoxLayout* horizon_top_status_layout_;    //顶部状态布局
private:
    void initTopStatusArea();   //初始化顶部状态栏
    void initCameraArea();      //初始化摄像头区域
    void initUserInfoArea();    //初始化用户信息区域
    void initLoginArea();       //初始化登录区域
    void initSettingArea();     //初始化设置区域
    void initButtonDetailInfoArea();    //初始化塔吊底部详细信息区域

private:
    std::thread thread_get_time_;   //获取时间线程
    bool exit_thread_flag_;     //退出线程表示 true为退出，false 为不退出

    /* 重设大小 */
    void resizeEvent(QResizeEvent *event);
private slots:
    void onChangeCurrentWidget();
};
#endif // MAINWIDGET_H
