#include "cybackstagetowerinstallinfowidget.h"

cyBackStageTowerInstallInfoWidget::cyBackStageTowerInstallInfoWidget()
{
    init();
}

void cyBackStageTowerInstallInfoWidget::init()
{
    tower_install_info_title_layout_ =
            initTopLayout(":/pictures/backstage_icon/tower_install_info_pic.png", "塔机安装信息");

    tower_install_info_main_layout_ = new QVBoxLayout(this);


    //塔吊安装详细信息
    QVector<cyLineEdit*> tmp_vector;
    cyLineEdit* tower_number = new cyLineEdit("塔机编号", editor_size_2);
    cyLineEdit* north_rotate = new cyLineEdit("正北偏转", editor_size_2);
    cyLineEdit* tower_latitude = new cyLineEdit("纬度", editor_size_2);
    cyLineEdit* tower_longitude = new cyLineEdit("经度", editor_size_2);
    cyLineEdit* tower_channel = new cyLineEdit("信道", editor_size_2);
    cyLineEdit* tower_X_axis = new cyLineEdit("坐标X", editor_size_2/2);
    cyLineEdit* tower_Y_axis = new cyLineEdit("坐标Y", editor_size_2/2);

    tmp_vector.push_back(tower_number);
    tmp_vector.push_back(north_rotate);
    tmp_vector.push_back(tower_latitude);
    tmp_vector.push_back(tower_longitude);
    tmp_vector.push_back(tower_X_axis);
    tmp_vector.push_back(tower_Y_axis);
    tmp_vector.push_back(tower_channel);
    tower_install_info_map_["塔机安装信息"] = tmp_vector;

    //添加布局
    //第一列布局
    QHBoxLayout* tower_install_info_hlayout = new QHBoxLayout();
    tower_install_info_hlayout->addWidget(tower_number);
    tower_install_info_hlayout->addWidget(tower_X_axis);
    tower_install_info_hlayout->addWidget(tower_Y_axis);

    //剩余四个布局
    QGridLayout* tower_install_gridlayout = new QGridLayout();
    tower_install_gridlayout->addWidget(north_rotate, 0, 0);
    tower_install_gridlayout->addWidget(tower_channel, 0, 1);
    tower_install_gridlayout->addWidget(tower_longitude, 1, 0);
    tower_install_gridlayout->addWidget(tower_latitude, 1, 1);
    //栅格布局水平间距39
    tower_install_gridlayout->setHorizontalSpacing(39);
    //栅格布局垂直间距
    tower_install_gridlayout->setVerticalSpacing(8);

    tower_install_info_main_layout_->addLayout(tower_install_info_title_layout_);
    tower_install_info_main_layout_->addLayout(tower_install_info_hlayout);
    tower_install_info_main_layout_->addLayout(tower_install_gridlayout);

}
