#include "cybackstagesystemsettingswidget.h"

cyBackStageSystemSettingsWidget::cyBackStageSystemSettingsWidget()
{
    init();
}

void cyBackStageSystemSettingsWidget::init()
{
    lookup_history_button_ = new QPushButton();
    system_settings_top_layout_ = initTopLayout(":/pictures/backstage_icon/system_setting_pic.png", "系统设置",
                                                lookup_history_button_, ":/pictures/backstage_icon/lookup_history.png");

    system_settings_main_layout_ = new QVBoxLayout(this);

    QVector<cyLineEdit*> tmp_vector;
    cyLineEdit* device_id = new cyLineEdit("设备ID", line_edit_size_);
    cyLineEdit* ethernet_port = new cyLineEdit("局域网端口", line_edit_size_);
    cyLineEdit* public_net_ip = new cyLineEdit("公网IP", line_edit_size_);
    cyLineEdit* camera_ip = new cyLineEdit("可视化摄像头IP", line_edit_size_);
    cyLineEdit* public_net_port = new cyLineEdit("公网端口", line_edit_size_);
    cyLineEdit* camera_password = new cyLineEdit("可视化摄像头密码", line_edit_size_);
    cyLineEdit* public_domin_name = new cyLineEdit("公网域名", line_edit_size_);
    cyLineEdit* other_camera_ip = new cyLineEdit("其他摄像头IP", line_edit_size_);
    cyLineEdit* ethernet_ip = new cyLineEdit("局域网IP", line_edit_size_);
    cyLineEdit* other_camera_password = new cyLineEdit("其他摄像头密码", line_edit_size_);
    cyLineEdit* time_sync = new cyLineEdit("时间校准", line_edit_size_);
    cyLineEdit* total_runtime = new cyLineEdit("累计运行时间设定", line_edit_size_);

    system_info_map_["设备ID"] = device_id;
    system_info_map_["局域网端口"] = ethernet_port;
    system_info_map_["公网IP"] = public_net_ip;
    system_info_map_["可视化摄像头IP"] = camera_ip;
    system_info_map_["公网端口"] = public_net_port;
    system_info_map_["可视化摄像头密码"] = camera_password;
    system_info_map_["公网域名"] = public_domin_name;
    system_info_map_["其他摄像头IP"] = other_camera_ip;
    system_info_map_["局域网IP"] = ethernet_ip;
    system_info_map_["其他摄像头密码"] = other_camera_password;
    system_info_map_["时间校准"] = time_sync;
    system_info_map_["累计运行时间设定"] = total_runtime;

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->addWidget(device_id, 0, 0);
    gridLayout->addWidget(ethernet_port, 0, 1);
    gridLayout->addWidget(public_net_ip, 1, 0);
    gridLayout->addWidget(camera_ip, 1, 1);
    gridLayout->addWidget(public_net_port, 2, 0);
    gridLayout->addWidget(camera_password, 2, 1);
    gridLayout->addWidget(public_domin_name, 3, 0);
    gridLayout->addWidget(other_camera_ip, 3, 1);
    gridLayout->addWidget(ethernet_ip, 4, 0);
    gridLayout->addWidget(other_camera_password, 4, 1);
    gridLayout->addWidget(time_sync, 5, 0);
    gridLayout->addWidget(total_runtime, 5, 1);

    system_settings_main_layout_->addLayout(system_settings_top_layout_);
    system_settings_main_layout_->addLayout(gridLayout);
}

