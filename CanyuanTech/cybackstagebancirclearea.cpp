#include "cybackstagebancirclearea.h"

cyBackStageBanCircleArea::cyBackStageBanCircleArea()
{
    init();
}

void cyBackStageBanCircleArea::init()
{
    add_new_button_ = new QPushButton();
    //初始化顶部控件
    ban_circle_area_top_hlayout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "圆形禁行区",
                                                add_new_button_, ":/pictures/backstage_icon/add_new_pic.png");

     //删除按钮响应事件
    connect(add_new_button_, &QPushButton::clicked, this, &cyBackStageBanCircleArea::add_element);

    //构建元素
    cyBackStageBanCircleAreaElement* element = new cyBackStageBanCircleAreaElement();
    elements_vector_.push_back(element);
    element->setDeleteButtonShow(false);    //第一个按钮不显示删除按键


   //初始化主布局
    ban_circle_area_main_vlayout_ = new QVBoxLayout(this);
    ban_circle_area_main_vlayout_->addLayout(ban_circle_area_top_hlayout_);
    ban_circle_area_main_vlayout_->addWidget(element);
    ban_circle_area_main_vlayout_->addStretch();

}

void cyBackStageBanCircleArea::add_element()
{
    cyBackStageBanCircleAreaElement* element = new cyBackStageBanCircleAreaElement();
    elements_vector_.push_back(element);
    element->setDeleteButtonShow(true);

    ban_circle_area_main_vlayout_->addWidget(element);
}

cyBackStageBanCircleAreaElement::cyBackStageBanCircleAreaElement()
{
    QGridLayout* grid_layout = new QGridLayout(this);
    delete_button_ = new QPushButton;
    delete_button_->setStyleSheet("border-image:url(:/pictures/backstage_icon/del_pic.png);");
    connect(delete_button_, &QPushButton::clicked, this,
            &cyBackStageBanCircleAreaElement::delete_element);

    //初始化编辑框元素
    cyLineEdit* id_number = new cyLineEdit("序号", editor_size_);
    cyLineEdit* area_name = new cyLineEdit("区域名称", 107);
    cyLineEdit* circle_center_X = new cyLineEdit("圆心X", editor_size_);
    cyLineEdit* circle_center_Y = new cyLineEdit("圆心Y", editor_size_);
    cyLineEdit* circle_center_Z = new cyLineEdit("圆心Z", editor_size_);
    cyLineEdit* circle_raduis = new cyLineEdit("半径R", editor_size_);

    ban_circle_area_elements_.push_back(id_number);
    ban_circle_area_elements_.push_back(area_name);
    ban_circle_area_elements_.push_back(circle_center_X);
    ban_circle_area_elements_.push_back(circle_center_Y);
    ban_circle_area_elements_.push_back(circle_center_Z);
    ban_circle_area_elements_.push_back(circle_raduis);

    //初始化编辑框布局
    grid_layout->addWidget(id_number, 0, 0);
    grid_layout->addWidget(area_name, 0, 1);
    grid_layout->addWidget(delete_button_, 0, 3, Qt::AlignRight);
    grid_layout->addWidget(circle_center_X, 1, 0);
    grid_layout->addWidget(circle_center_Y, 1, 1);
    grid_layout->addWidget(circle_center_Z, 1, 2);
    grid_layout->addWidget(circle_raduis, 1, 3);
}

void cyBackStageBanCircleAreaElement::setDeleteButtonShow(const bool &isShow)
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


//删除按钮直接删除该类
void cyBackStageBanCircleAreaElement::delete_element()
{
    delete this;

}
