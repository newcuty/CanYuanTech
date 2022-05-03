#include "cybottomwidgetelement.h"

cyBottomWidgetElement::cyBottomWidgetElement(QWidget *parent)
    : QWidget(parent),
      icon_label_(nullptr),
      info_label_(nullptr),
      data_row_2_(nullptr),
      data_row_3_(nullptr)
{

}

void cyBottomWidgetElement::init(const QString &icon_path, const QString &info)
{
    //显示图标
    icon_label_ = new QLabel();
    QPixmap pixmap(icon_path);
    icon_label_->setPixmap(pixmap);

    //信息图标
    info_label_ = new QLabel();
    info_label_->setText(info);

    //初始化数据显示控件
    data_row_2_ = new QLabel();
    data_row_3_ = new QLabel();

    //布局控件
    //水平布局
    QHBoxLayout* hLabelLayout = new QHBoxLayout();
    hLabelLayout->addWidget(icon_label_);
    hLabelLayout->addWidget(info_label_);

    //垂直主布局
    QVBoxLayout* mainVLayout = new QVBoxLayout(this);
    mainVLayout->addLayout(hLabelLayout);
    mainVLayout->addWidget(data_row_2_);
    mainVLayout->addWidget(data_row_3_);
}


