#include "cybackstageinputidwidget.h"

cyBackStageInputIDWidget::cyBackStageInputIDWidget()
{
    init();
}

void cyBackStageInputIDWidget::init()
{
    input_ID_top_layout_ = initTopLayout(":/pictures/backstage_icon/ID_input_pic.png", "身份录入");

    work_number_label_ = new QLabel();
    work_number_label_->setStyleSheet("QLabel{width:100px;"
                                      "height:34px;"
                                      "border-radius: 11px;"
                                      "font-size:15px;"
                                      "color:#445975;}");
    work_number_label_->setText("工号");

    name_label_ = new QLabel();
    name_label_->setStyleSheet("QLabel{width:75px;"
                                      "height:34px;"
                                      "border-radius: 11px;"
                                      "font-size:15px;"
                                      "color:#445975;}");
    name_label_->setText("姓名");

    ID_number_label_ = new QLabel();
    ID_number_label_->setStyleSheet("QLabel{width:170px;"
                                      "height:34px;"
                                      "border-radius: 11px;"
                                      "font-size:15px;"
                                      "color:#445975;}");
    ID_number_label_->setText("身份证");

    driver_number_label_ = new QLabel();
    driver_number_label_->setStyleSheet("QLabel{width:135px;"
                                      "height:34px;"
                                      "border-radius: 11px;"
                                      "font-size:15px;"
                                      "color:#445975;}");
    driver_number_label_->setText("驾驶证");

    label_layout_ = new QHBoxLayout();
    label_layout_->addWidget(work_number_label_);
    label_layout_->addWidget(name_label_);
    label_layout_->addWidget(ID_number_label_);
    label_layout_->addWidget(driver_number_label_);

    //line_edit_ = new cyInputLineEditWidget();

    main_layout_ = new QVBoxLayout(this);
    main_layout_->addLayout(input_ID_top_layout_);
    main_layout_->addLayout(label_layout_);
    //main_layout_->addWidget(line_edit_);
    main_layout_->addStretch();

    //该类有double free or corruption (out) 这个错误，还未排查出问题
}
