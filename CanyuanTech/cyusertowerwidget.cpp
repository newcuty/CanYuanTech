#include "cyusertowerwidget.h"

cyUserTowerWidget::cyUserTowerWidget(QWidget *parent) : QWidget(parent)
{

}

void cyUserTowerWidget::init()
{
    //初始化用户信息
    user_info_widget_ = new QWidget();
    user_info_widget_->setStyleSheet("background-color:#F9FBFF;");

    //初始化状态栏
    right_tower_status_widget_ = new QWidget();
    right_tower_status_widget_->setStyleSheet("border-image:url(:/pictures/main_page_pics/tower_crane_pic.png);");
    right_tower_chart_widget_ = new QWidget();
    right_tower_chart_widget_ ->setStyleSheet("background-color:#E9EEFA;");

    //初始水平化布局
    horizon_layout_ = new QHBoxLayout();
    horizon_layout_->addWidget(right_tower_status_widget_);
    horizon_layout_->addWidget(right_tower_chart_widget_);

    //初始化主布局
    main_vertical_layout_ = new QVBoxLayout(this);
    main_vertical_layout_->addWidget(user_info_widget_);
    main_vertical_layout_->addSpacing(10);
    main_vertical_layout_->addLayout(horizon_layout_);
    main_vertical_layout_->setStretchFactor(user_info_widget_, 2);
    main_vertical_layout_->setStretchFactor(horizon_layout_, 1);
}
