#include "cybackstagebansquarearea.h"

cyBackStageBanSquareArea::cyBackStageBanSquareArea()
{
    init();
}

void cyBackStageBanSquareArea::init()
{
    add_new_button_ = new QPushButton();
    //初始化顶部控件
    ban_square_area_top_hlayout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "四边形禁行区",
                                                add_new_button_, ":/pictures/backstage_icon/add_new_pic.png");

     //删除按钮响应事件
    connect(add_new_button_, &QPushButton::clicked, this, &cyBackStageBanSquareArea::add_element);

    //构建元素
    cyBackStageBanSquareAreaElement* element = new cyBackStageBanSquareAreaElement();
    elements_vector_.push_back(element);
    element->setDeleteButtonShow(false);    //第一个按钮不显示删除按键


   //初始化主布局
    ban_square_area_main_vlayout_ = new QVBoxLayout(this);
    ban_square_area_main_vlayout_->addLayout(ban_square_area_top_hlayout_);
    ban_square_area_main_vlayout_->addWidget(element);
    ban_square_area_main_vlayout_->addStretch();
}

void cyBackStageBanSquareArea::add_element()
{
    cyBackStageBanSquareAreaElement* element = new cyBackStageBanSquareAreaElement();
    elements_vector_.push_back(element);
    element->setDeleteButtonShow(true);

    ban_square_area_main_vlayout_->addWidget(element);
}

cyBackStageBanSquareAreaElement::cyBackStageBanSquareAreaElement()
{

    QGridLayout* grid_layout = new QGridLayout(this);
    delete_button_ = new QPushButton;
    delete_button_->setStyleSheet("border-image:url(:/pictures/backstage_icon/del_pic.png);");
    connect(delete_button_, &QPushButton::clicked, this,
            &cyBackStageBanSquareAreaElement::delete_element);

    cyLineEdit* id_number = new cyLineEdit("序号", editor_size_);
    cyLineEdit* area_name = new cyLineEdit("区域名称", editor_size_);

    cyLineEdit* edit_X1 = new cyLineEdit("X1", editor_size_);
    cyLineEdit* edit_Y1 = new cyLineEdit("Y1", editor_size_);
    cyLineEdit* edit_Z1 = new cyLineEdit("Z1", editor_size_);

//    cyLineEdit* edit_X2 = new cyLineEdit("X2", editor_size_);
//    cyLineEdit* edit_Y2 = new cyLineEdit("Y2", editor_size_);
//    cyLineEdit* edit_Z2 = new cyLineEdit("Z2", editor_size_);

//    cyLineEdit* edit_X3 = new cyLineEdit("X3", editor_size_);
//    cyLineEdit* edit_Y3 = new cyLineEdit("Y3", editor_size_);
//    cyLineEdit* edit_Z3 = new cyLineEdit("Z3", editor_size_);

//    cyLineEdit* edit_X4 = new cyLineEdit("X4", editor_size_);
//    cyLineEdit* edit_Y4 = new cyLineEdit("Y4", editor_size_);
//    cyLineEdit* edit_Z4 = new cyLineEdit("Z4", editor_size_);

    ban_square_area_elements_.push_back(id_number);
    ban_square_area_elements_.push_back(area_name);
    ban_square_area_elements_.push_back(edit_X1);
    ban_square_area_elements_.push_back(edit_Y1);
    ban_square_area_elements_.push_back(edit_Z1);

//    ban_square_area_elements_.push_back(edit_X2);
//    ban_square_area_elements_.push_back(edit_Y2);
//    ban_square_area_elements_.push_back(edit_Z2);

//    ban_square_area_elements_.push_back(edit_X3);
//    ban_square_area_elements_.push_back(edit_Y3);
//    ban_square_area_elements_.push_back(edit_Z3);

//    ban_square_area_elements_.push_back(edit_X4);
//    ban_square_area_elements_.push_back(edit_Y4);
//    ban_square_area_elements_.push_back(edit_Z4);


    grid_layout->addWidget(id_number, 0, 0);
    grid_layout->addWidget(area_name, 0, 1);
    grid_layout->addWidget(delete_button_, 0, 2, Qt::AlignRight);

    grid_layout->addWidget(edit_X1, 1, 0);
    grid_layout->addWidget(edit_Y1, 1, 1);
    grid_layout->addWidget(edit_Z1, 1, 2);

//    grid_layout->addWidget(edit_X2, 2, 0);
//    grid_layout->addWidget(edit_Y2, 2, 1);
//    grid_layout->addWidget(edit_Z2, 2, 2);

//    grid_layout->addWidget(edit_X3, 3, 0);
//    grid_layout->addWidget(edit_Y3, 3, 1);
//    grid_layout->addWidget(edit_Z3, 3, 2);

//    grid_layout->addWidget(edit_X4, 4, 0);
//    grid_layout->addWidget(edit_Y4, 4, 1);
//    grid_layout->addWidget(edit_Z4, 4, 2);
}

void cyBackStageBanSquareAreaElement::setDeleteButtonShow(const bool &isShow)
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

void cyBackStageBanSquareAreaElement::delete_element()
{
    delete this;

}
