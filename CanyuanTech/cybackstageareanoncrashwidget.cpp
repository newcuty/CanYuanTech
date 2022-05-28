#include "cybackstageareanoncrashwidget.h"


cyBackStageAreaNonCrashWidget::cyBackStageAreaNonCrashWidget()
{
    init();
}

void cyBackStageAreaNonCrashWidget::init()
{
    area_non_crash_top_hlayout_ = initTopLayout(":/pictures/backstage_icon/tower_area_pic.png", "区域防碰撞");

    //构建角禁行区域，圆形禁行区域
    ban_angle_area_widget_ = new cyBackStageBanAngleArea();
    ban_circle_area_widget_ = new cyBackStageBanCircleArea();
    ban_square_area_widget_  = new cyBackStageBanSquareArea();

    //整体布局
    area_non_crash_main_vlayout_ = new QVBoxLayout(this);
    area_non_crash_main_vlayout_->addLayout(area_non_crash_top_hlayout_);
    area_non_crash_main_vlayout_->addWidget(ban_angle_area_widget_);
    area_non_crash_main_vlayout_->addWidget(ban_circle_area_widget_);
    area_non_crash_main_vlayout_->addWidget(ban_square_area_widget_);

    area_non_crash_main_vlayout_->addStretch();
}
