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
    account_line_edit_->setStyleSheet("QLineEdit{width: 368px; \
                                      height: 65px; \
                                      background: rgba(0, 46, 175, 1); \
                                      border-radius: 35px; \
                                      border: 1px solid #FFFFFF; \
                                      background-color:transparent; \
                                      qproperty-alignment:AlignHCenter; \
                                      font-size:24px; \
                                      font-weight: 400; \
                                      color: #CFE2FF; \
                                      line-height: 33px;}");
    account_line_edit_->setText(QString("请填写账号"));

    password_line_edit_ = new QLineEdit();
    password_line_edit_->setStyleSheet("QLineEdit {width: 368px; \
                                       height: 65px; \
                                       background: rgba(0, 46, 175, 0.55); \
                                       border-radius: 35px; \
                                       border: 1px solid #FFFFFF;\
                                       background-color:transparent;                                      qproperty-alignment:AlignHCenter; \
                                       font-size:24px; \
                                       font-weight: 400; \
                                       color: #CFE2FF; \
                                       line-height: 33px;}");
    password_line_edit_->setText(QString("请填写密码"));



    //初始化按钮
    login_button_ = new QPushButton();
    login_button_->setText(QString("登陆"));
    login_button_->setMinimumSize(416, 115);
    login_button_->setStyleSheet("QPushButton{border-image:url(:/pictures/main_page_pics/login_button_pic.png); \
                               font-size:24px;color:#2359DB; \
                            text-align:center;}");

    cancle_login_pushButton_ = new cyPushButton();
    cancle_login_pushButton_->init(":/pictures/main_page_pics/login_cancel_pic.png", QString("取消登陆"));
    connect(cancle_login_pushButton_, &cyPushButton::sigSendMouseMove, this, &cyLogin::slotCancleLogin);

    system_reboot_pushbutton_ = new cyPushButton();
    system_reboot_pushbutton_->init(":/pictures/main_page_pics/login_reboot_pic.png", QString("重启系统"));
    connect(system_reboot_pushbutton_, &cyPushButton::sigSendMouseMove, this, &cyLogin::slotSystemReboot);

    //初始化分割线
    splite_line_ = new QFrame();
    splite_line_->setStyleSheet("QFrame{background:#FFFFFF;min-width:2px}");

//    //底部水平布局
    horzion_button_layout_ = new QHBoxLayout();
    horzion_button_layout_->addStretch();
    horzion_button_layout_->addWidget(cancle_login_pushButton_);
    horzion_button_layout_->addSpacing(50);
    horzion_button_layout_->addWidget(splite_line_);
    horzion_button_layout_->addSpacing(50);
    horzion_button_layout_->addWidget(system_reboot_pushbutton_);
    horzion_button_layout_->addStretch();

//    //整体布局
    vertical_layout_ = new QVBoxLayout();
    vertical_layout_->addStretch();
    vertical_layout_ ->addWidget(account_line_edit_, 0, Qt::AlignCenter);
    vertical_layout_->addSpacing(50);
    vertical_layout_ ->addWidget(password_line_edit_, 0, Qt::AlignCenter);
    vertical_layout_->addSpacing(50);
    vertical_layout_ ->addWidget(login_button_, 0, Qt::AlignCenter);
    vertical_layout_->addSpacing(50);
    vertical_layout_->addLayout(horzion_button_layout_);
    vertical_layout_->addStretch();
    background_widget_->setLayout(vertical_layout_);
}

void cyLogin::resizeEvent(QResizeEvent *event)
{
    background_widget_->resize(589, 820);

}

void cyLogin::slotCancleLogin()
{
    qDebug() << "cancel login";
}

void cyLogin::slotSystemReboot()
{
    qDebug() << "system reboot";
}
