#include "cylogin.h"

cyLogin::cyLogin(QWidget *parent) : QWidget(parent)
{

}

void cyLogin::init()
{

    //初始化背景图
    background_widget_ = new QWidget(this);
    background_widget_->setObjectName("background_widget_");
    background_widget_->setStyleSheet("#background_widget_{border-image:url(:/pictures/main_page_pics/login_pic.png);}");

    //初始化编辑框
    account_line_edit_ = new QLineEdit();
    account_line_edit_->setStyleSheet("QLineEdit{width: 368px; \
                                      height: 65px; \
                                      background-color: yellow;\
                                      background:#002EAF; \
                                      border: 2px groove #FFFFFF; \
                                      border-radius:10px;padding:2px 4px; \
                                      qproperty-alignment:AlignHCenter; \
                                      font-size:24px; \
                                      color: #CFE2FF; \
                                      font-weight: 400; \
                                      line-height: 33px;}");
    account_line_edit_->setText(QString("请填写账号"));

    //连接获取账号信号槽
    connect(account_line_edit_, &QLineEdit::textChanged, this, &cyLogin::slotGetAccountStr);
    //connect(account_line_edit_, &QLineEdit::, this, &cyLogin::slotGetAccountStr);

    //密码编辑框
    password_line_edit_ = new QLineEdit();
    password_line_edit_->setStyleSheet("QLineEdit{width: 368px; \
                                     height: 65px; \
                                     background-color: yellow;\
                                     background:#002EAF; \
                                     border: 2px groove #FFFFFF; \
                                     border-radius:10px;padding:2px 4px; \
                                     qproperty-alignment:AlignHCenter; \
                                     font-size:24px; \
                                     color: #CFE2FF; \
                                     font-weight: 400; \
                                     line-height: 33px;}");
    password_line_edit_->setText(QString("请填写密码"));

    //密码显示格式
    password_line_edit_->setEchoMode(QLineEdit::Password);

    //连接获取密码信号槽
    connect(password_line_edit_, &QLineEdit::textChanged, this, &cyLogin::slotGetPasswordStr);


    //初始化按钮
    login_button_ = new QPushButton();
    login_button_->setText(QString("登陆"));
    login_button_->setMinimumSize(416, 115);
    login_button_->setStyleSheet("QPushButton{border-image:url(:/pictures/main_page_pics/login_button_pic.png); \
                               font-size:24px;color:#2359DB; \
                                text-align:center;}");
    //登录验证信号
    connect(login_button_, &QPushButton::clicked, this, &cyLogin::slotLogin);

    //取消登录按钮
    cancle_login_pushButton_ = new cyPushButton();
    cancle_login_pushButton_->init(":/pictures/main_page_pics/login_cancel_pic.png", QString("取消登陆"));
    connect(cancle_login_pushButton_, &cyPushButton::sigSendMouseMove, this, &cyLogin::slotCancleLogin);

    //系统重启按钮
    system_reboot_pushbutton_ = new cyPushButton();
    system_reboot_pushbutton_->init(":/pictures/main_page_pics/login_reboot_pic.png", QString("重启系统"));
    connect(system_reboot_pushbutton_, &cyPushButton::sigSendMouseMove, this, &cyLogin::slotSystemReboot);

    //初始化分割线
    splite_line_ = new QFrame();
    splite_line_->setStyleSheet("QFrame{background:#FFFFFF;min-width:2px}");

    //底部水平布局
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
    Q_UNUSED(event);
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

void cyLogin::slotclearEditor()
{
    account_line_edit_->clear();
    password_line_edit_->clear();
}

void cyLogin::slotGetAccountStr(const QString &account_str)
{
    //赋值账号信息
    //if(account_str.size() > 0)
    {
       account_ = account_str;
     }

}

void cyLogin::slotGetPasswordStr(const QString &password_str)
{
    //赋值密码信息
    //if (password_str.size() > 0)
    {
        password_ = password_str;
    }

}

void cyLogin::slotLogin()
{
    //验证登录
    if (account_ == "admin" && ((password_ == "canyuan") || (password_ == "yx123456")))
    {
        //验证成功，发送信号
        emit sigVerifySuccess();
    }
}
