#include "cyswitchbuttonwidget.h"

cySwitchButtonWidget::cySwitchButtonWidget(const QString &button_name)
{
    //初始化未点击
    is_clicked = false;

    button_label_ = new QLabel();
    button_label_->setStyleSheet("font-size:15px; color: #445975;");
    button_label_->setText(button_name);

    //button_body_ = new cySwitchButton();
    button_body_ = new QPushButton();
    button_body_->setStyleSheet("QPushButton{border-image:url(:/pictures/backstage_icon/off_pic.png);}");
    connect(button_body_, &QPushButton::clicked, this, &cySwitchButtonWidget::changeButtonImage);

    QHBoxLayout* main_layout = new QHBoxLayout(this);
    main_layout->addWidget(button_label_, Qt::AlignRight);      //对齐标签
    main_layout->addWidget(button_body_);
    main_layout->addStretch();
}

//获取开关状态
bool cySwitchButtonWidget::getSwitchButtonState()
{
    return is_clicked;
}

void cySwitchButtonWidget::changeButtonImage()
{
    if (!is_clicked)
    {
        is_clicked = true;
        button_body_->setStyleSheet("QPushButton{border-image:url(:/pictures/backstage_icon/on_pic.png);}");
    }
    else
    {
        is_clicked = false;
        button_body_->setStyleSheet("QPushButton{border-image:url(:/pictures/backstage_icon/off_pic.png);}");
    }

}
