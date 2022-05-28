#include "cybackstagebananglearea.h"

cyBackStageBanAngleArea::cyBackStageBanAngleArea()
{
    init();
}

void cyBackStageBanAngleArea::init()
{
    add_new_button_ = new QPushButton();
    //初始化顶部控件
    ban_angle_area_top_hlayout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "角禁行区",
                                                add_new_button_, ":/pictures/backstage_icon/add_new_pic.png");

    //if (add_new_button_)
    {
        //删除按钮响应事件
        connect(add_new_button_, &QPushButton::clicked, this, &cyBackStageBanAngleArea::add_element);
    }

    //构建元素
    cyBackStageBanAngleAreaElement* element = new cyBackStageBanAngleAreaElement();
    elements_vector_.push_back(element);
    element->setDeleteButtonShow(false);    //第一个按钮不显示删除按键


   //初始化主布局
    ban_angle_area_main_vlayout_ = new QVBoxLayout(this);
    ban_angle_area_main_vlayout_->addLayout(ban_angle_area_top_hlayout_);
    ban_angle_area_main_vlayout_->addWidget(element);
    ban_angle_area_main_vlayout_->addStretch();
}


void cyBackStageBanAngleArea::add_element()
{
    //新增组件，直接往主布局中添加
    cyBackStageBanAngleAreaElement* element = new cyBackStageBanAngleAreaElement();
    elements_vector_.push_back(element);
    element->setDeleteButtonShow(true);    //后续添加的按钮需要显示删除按钮

    ban_angle_area_main_vlayout_->addWidget(element);
}

cyBackStageBanAngleAreaElement::cyBackStageBanAngleAreaElement()
{
    QGridLayout* grid_layout = new QGridLayout(this);
    delete_button_ = new QPushButton;
    delete_button_->setStyleSheet("border-image:url(:/pictures/backstage_icon/del_pic.png);");
    connect(delete_button_, &QPushButton::clicked, this,
            &cyBackStageBanAngleAreaElement::delete_element);

    cyLineEdit* id_number = new cyLineEdit("序号", editor_size_);
    cyLineEdit* area_name = new cyLineEdit("区域名称", editor_size_);
    cyLineEdit* start_point_X = new cyLineEdit("起点X", editor_size_);
    cyLineEdit* start_point_Y = new cyLineEdit("起点Y", editor_size_);
    cyLineEdit* start_point_Z = new cyLineEdit("起点Z", editor_size_);
    cyLineEdit* end_point_X = new cyLineEdit("序号", editor_size_);
    cyLineEdit* end_point_Y = new cyLineEdit("序号", editor_size_);
    cyLineEdit* end_point_Z = new cyLineEdit("序号", editor_size_);

    ban_angle_area_elements_.push_back(id_number);
    ban_angle_area_elements_.push_back(area_name);
    ban_angle_area_elements_.push_back(start_point_X);
    ban_angle_area_elements_.push_back(start_point_Y);
    ban_angle_area_elements_.push_back(start_point_Z);
    ban_angle_area_elements_.push_back(end_point_X);
    ban_angle_area_elements_.push_back(end_point_Y);
    ban_angle_area_elements_.push_back(end_point_Z);

    //初始化各个元素布局
    grid_layout->addWidget(id_number, 0, 0);
    grid_layout->addWidget(area_name, 0, 1);
    grid_layout->addWidget(delete_button_, 0, 2, 1, 1,Qt::AlignRight);
    grid_layout->addWidget(start_point_X, 1, 0);
    grid_layout->addWidget(start_point_Y, 1, 1);
    grid_layout->addWidget(start_point_Z, 1, 2);
    grid_layout->addWidget(end_point_X, 2, 0);
    grid_layout->addWidget(end_point_Y, 2, 1);
    grid_layout->addWidget(end_point_Z, 2, 2);

}

void cyBackStageBanAngleAreaElement::setDeleteButtonShow(const bool &isShow)
{
    if (isShow)
    {
        delete_button_->show();
    }
    else
    {
        delete_button_->hide();
    }
}

void cyBackStageBanAngleAreaElement::delete_element()
{
    delete this;
}
