#include "cybackstagetowerinfo.h"

cyBackStageTowerInfo::cyBackStageTowerInfo()
{
    init();
}

void cyBackStageTowerInfo::init()
{
    //初始化顶部
    tower_info_title_layout_ = initTopLayout(":/pictures/backstage_icon/tower_info_pic.png", "塔吊信息");
    tower_info_main_layout_ = new QVBoxLayout(this);

    QVector<cyLineEdit*> tmp_vector;
    //初始化各个编辑控件
    cyLineEdit* tower_type = new cyLineEdit("塔机型号", editor_size_1);
    cyLineEdit* tower_head_height = new cyLineEdit("塔帽高度", editor_size_1);
    cyLineEdit* tower_body_height = new cyLineEdit("塔身高度", editor_size_1);
    cyLineEdit* tower_max_weidght = new cyLineEdit("最大吊重", editor_size_1);
    cyLineEdit* tower_max_moment = new cyLineEdit("最大力矩", editor_size_1);
    cyLineEdit* tower_jack_up_length = new cyLineEdit("起重臂长", editor_size_1);
    cyLineEdit* tower_balance_arm_length = new cyLineEdit("塔机型号", editor_size_1);
    cyLineEdit* tower_tlifting_rope_power= new cyLineEdit("吊绳倍率", editor_size_1);
    cyLineEdit* tower_max_wind_speed = new cyLineEdit("最大风速", editor_size_1);
    cyLineEdit* tower_max_dip_angle = new cyLineEdit("最大倾角", editor_size_1);


    //保存变量至map容器，方便后续读取
    tmp_vector.push_back(tower_type);
    tmp_vector.push_back(tower_tlifting_rope_power);
    tmp_vector.push_back(tower_head_height);
    tmp_vector.push_back(tower_body_height);
    tmp_vector.push_back(tower_max_weidght);
    tmp_vector.push_back(tower_max_moment);
    tmp_vector.push_back(tower_jack_up_length);
    tmp_vector.push_back(tower_balance_arm_length);
    tmp_vector.push_back(tower_max_wind_speed);
    tmp_vector.push_back(tower_max_dip_angle);
    tower_info_map_["塔机信息"] = tmp_vector;


    //添加布局，将所有控件添加到布局中
    QGridLayout* tower_info_layout = new QGridLayout();
    tower_info_layout->addWidget(tower_type, 0, 0);
    tower_info_layout->addWidget(tower_tlifting_rope_power, 0, 1);
    tower_info_layout->addWidget(tower_head_height, 1, 0);
    tower_info_layout->addWidget(tower_body_height, 1, 1);
    tower_info_layout->addWidget(tower_max_weidght, 2, 0);
    tower_info_layout->addWidget(tower_max_moment, 2, 1);
    tower_info_layout->addWidget(tower_jack_up_length, 3, 0);
    tower_info_layout->addWidget(tower_balance_arm_length, 3, 1);
    tower_info_layout->addWidget(tower_max_wind_speed, 4, 0);
    tower_info_layout->addWidget(tower_max_dip_angle, 4, 1);

    //水平间距39
    tower_info_layout->setHorizontalSpacing(39);
    //垂直间距
    tower_info_layout->setVerticalSpacing(8);

    tower_info_main_layout_->addLayout(tower_info_title_layout_);
    tower_info_main_layout_->addLayout(tower_info_layout);
}
