#include "topwidgetelement.h"

topWidgetElement::topWidgetElement(QWidget *parent) :
    QWidget(parent),
    icon_label_(nullptr),
    type_name_label_(nullptr),
    type_detail_label_(nullptr),
    main_layout_(nullptr)
{
}

void topWidgetElement::init(const QString& name, const QString& info)
{

    main_layout_ = new QVBoxLayout(this);
    //图标标签
    icon_label_ = new QLabel();
    QPixmap pixmap(":/pictures/main_page_pics/vertical_mark_pic_2x.png");
    icon_label_->setPixmap(pixmap);

    //顶部类型标签
    type_name_label_ = new QLabel();
    type_name_label_->setFrameShape(QFrame::NoFrame);
    type_name_label_->setStyleSheet("font-size:16px;color:#D4EBFF;");
    type_name_label_->setText(name);

    //详细信息标签
    type_detail_label_ = new QLabel();
    type_detail_label_->setFrameShape(QFrame::NoFrame);
    type_detail_label_->setStyleSheet("font-size:18px;color:#DFFAFF;");
    type_detail_label_->setText(info);

    //水平布局图标与当前选项名字
    QHBoxLayout* horizon_layout_ = new QHBoxLayout();
    horizon_layout_->addWidget(icon_label_);
    horizon_layout_->addWidget(type_name_label_);
    horizon_layout_->addStretch();

    main_layout_->addLayout(horizon_layout_);
    main_layout_->addWidget(type_detail_label_);
    main_layout_->addStretch();
}

void topWidgetElement::setInfo(const QString &strInfo)
{
    //外部设置信息接口
    if (type_detail_label_)
    {
        type_detail_label_->setText(strInfo);
    }
}
