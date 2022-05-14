#include "cyswitchbuttonwidget.h"

cySwitchButtonWidget::cySwitchButtonWidget(const QString &button_name)
{
    button_label_ = new QLabel();
    button_label_->setStyleSheet("font-size:15px; color: #445975;");
    button_label_->setText(button_name);

    button_body_ = new cySwitchButton();

    QHBoxLayout* main_layout = new QHBoxLayout(this);
    main_layout->addWidget(button_label_);
    main_layout->addWidget(button_body_);
    main_layout->addStretch();
}
