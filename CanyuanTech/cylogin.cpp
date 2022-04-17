#include "cylogin.h"

cyLogin::cyLogin(QWidget *parent) : QWidget(parent)
{

}

void cyLogin::init()
{
    //初始化背景图
    background_widget_ = new QWidget(this);
    background_widget_->setStyleSheet("border-image:url(:/pictures/main_page_pics/login_pic.png);");

    //初始化编辑框
    account_line_edit_ = new QLineEdit();
    account_line_edit_->setStyleSheet("QLineEdit {width: 368px; \
                                      height: 65px; \
                                      background: rgba(0, 46, 175, 0.55); \
                                      border-radius: 5px; \
                                      border: 1px solid #FFFFFF;}");

    password_line_edit_ = new QLineEdit();
    password_line_edit_->setStyleSheet("QLineEdit {width: 368px; \
                                       height: 65px; \
                                       background: rgba(0, 46, 175, 0.55); \
                                       border-radius: 5px; \
                                       border: 1px solid #FFFFFF;}");

    //初始化按钮
    login_button_ = new QPushButton();
    login_button_->setStyleSheet("border-image:url(:/pictures/main_page_pics/login_button_pic.png);");

    cancel_login_button_ = new QPushButton();
    cancel_login_button_->setStyleSheet("border-image:url(:/pictures/main_page_pics/login_cancel_pic.png);");
    system_reboot_button_ = new QPushButton();
    system_reboot_button_->setStyleSheet("border-image:url(:/pictures/main_page_pics/login_reboot_pic.png);");

    //初始化分割线
    splite_line_ = new QFrame();
    splite_line_->setStyleSheet("QFrame{background:#8EBBFF;min-width:1px}");

//    //底部水平布局
    horzion_button_layout_ = new QHBoxLayout();
    horzion_button_layout_->addWidget(cancel_login_button_);
    horzion_button_layout_->addWidget(splite_line_);
    horzion_button_layout_->addWidget(system_reboot_button_);

//    //整体布局
    vertical_layout_ = new QVBoxLayout();
    vertical_layout_ ->addWidget(account_line_edit_);
    vertical_layout_ ->addWidget(password_line_edit_);
    vertical_layout_ ->addWidget(login_button_);
    vertical_layout_->addLayout(horzion_button_layout_);
    background_widget_->setLayout(vertical_layout_);
}

void cyLogin::resizeEvent(QResizeEvent *event)
{
    background_widget_->resize(589, 820);

}
