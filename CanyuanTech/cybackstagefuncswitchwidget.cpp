#include "cybackstagefuncswitchwidget.h"

cyBackStageFuncSwitchWidget::cyBackStageFuncSwitchWidget()
{
    init();
}

void cyBackStageFuncSwitchWidget::init()
{ //初始化顶部布局
    switch_top_layout_ =
            initTopLayout(":/pictures/backstage_icon/tower_install_info_pic.png", "功能开关");

    //塔吊安装信息主布局
    switch_main_layout_ = new QVBoxLayout(this);
    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("重量");
    cySwitchButtonWidget* range_switch_button = new cySwitchButtonWidget("幅度");
    cySwitchButtonWidget* moment_switch_button = new cySwitchButtonWidget("力矩");
    cySwitchButtonWidget* heigth_switch_button = new cySwitchButtonWidget("高度");
    cySwitchButtonWidget* rotate_switch_button = new cySwitchButtonWidget("回转");
    cySwitchButtonWidget* wind_speed_switch_button = new cySwitchButtonWidget("风速");
    cySwitchButtonWidget* dip_angle_switch_button = new cySwitchButtonWidget("倾角");
    cySwitchButtonWidget* electron_compress_switch_button = new cySwitchButtonWidget("电子罗盘");
    cySwitchButtonWidget* TF_storage_switch_button = new cySwitchButtonWidget("TF存储");
    cySwitchButtonWidget* bake_control_switch_button = new cySwitchButtonWidget("制动控制");
    cySwitchButtonWidget* driver_switch_button = new cySwitchButtonWidget("驾驶员识别");
    cySwitchButtonWidget* tower_noncrash_switch_button = new cySwitchButtonWidget("群塔防碰撞");
    cySwitchButtonWidget* hook_visiable_switch_button = new cySwitchButtonWidget("吊钩可视化");
    cySwitchButtonWidget* gps_locate_switch_button = new cySwitchButtonWidget("GPS定位");
    cySwitchButtonWidget* network_time_sync_switch_button = new cySwitchButtonWidget("网络时间同步");

    switch_button_vector_.push_back(weight_switch_button);
    switch_button_vector_.push_back(range_switch_button);
    switch_button_vector_.push_back(moment_switch_button);
    switch_button_vector_.push_back(heigth_switch_button);
    switch_button_vector_.push_back(rotate_switch_button);
    switch_button_vector_.push_back(wind_speed_switch_button);
    switch_button_vector_.push_back(dip_angle_switch_button);
    switch_button_vector_.push_back(electron_compress_switch_button);
    switch_button_vector_.push_back(TF_storage_switch_button);
    switch_button_vector_.push_back(bake_control_switch_button);
    switch_button_vector_.push_back(tower_noncrash_switch_button);
    switch_button_vector_.push_back(hook_visiable_switch_button);
    switch_button_vector_.push_back(gps_locate_switch_button);
    switch_button_vector_.push_back(driver_switch_button);
    switch_button_vector_.push_back(network_time_sync_switch_button);


    QGridLayout* grid_layout = new QGridLayout;
    grid_layout->addWidget(weight_switch_button, 0, 0);
    grid_layout->addWidget(range_switch_button, 0, 1);
    grid_layout->addWidget(moment_switch_button, 0, 2);
    grid_layout->addWidget(heigth_switch_button, 1, 0);
    grid_layout->addWidget(rotate_switch_button, 1, 1);
    grid_layout->addWidget(wind_speed_switch_button, 1, 2);
    grid_layout->addWidget(dip_angle_switch_button, 2, 0);
    grid_layout->addWidget(electron_compress_switch_button, 2, 1);
    grid_layout->addWidget(TF_storage_switch_button, 2, 2);
    grid_layout->addWidget(bake_control_switch_button, 3, 0);
    grid_layout->addWidget(tower_noncrash_switch_button, 3, 1);
    grid_layout->addWidget(hook_visiable_switch_button, 3, 2);
    grid_layout->addWidget(gps_locate_switch_button, 4, 0);
    grid_layout->addWidget(driver_switch_button, 4, 1);
    grid_layout->addWidget(network_time_sync_switch_button, 4, 2);

    switch_main_layout_->addLayout(switch_top_layout_);
    switch_main_layout_->addLayout(grid_layout);
    switch_main_layout_->addStretch();

}
