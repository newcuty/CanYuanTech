#include "cypushbutton.h"
#include <QMouseEvent>

cyPushButton::cyPushButton(QWidget *parent) : QWidget(parent)
{
    icon_button_ = new QLabel();
    info_lable_ = new QLabel();

}

void cyPushButton::init(const QString &icon_path, const QString &info)
{

    //设置按钮图标与信息
    QPixmap pixmap(icon_path);
    icon_button_->setPixmap(pixmap);

    info_lable_->setText(info);
    info_lable_->setStyleSheet("font-size:20px;color:#FFFFFF;");

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(icon_button_);
    mainLayout->addWidget(info_lable_);
}

void cyPushButton::mousePressEvent(QMouseEvent *ev)
{
    if (!ev)
    {
        return;
    }
    //鼠标点击之后，发送点击信号，其他类订阅该信号即可实现功能
    emit sigSendMouseMove();
}
