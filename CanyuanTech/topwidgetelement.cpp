#include "topwidgetelement.h"

topWidgetElement::topWidgetElement(QWidget *parent) :
    QWidget(parent),
    icon_label_(nullptr),
    type_name_label_(nullptr),
    type_detail_label_(nullptr),
    gridLayout_(nullptr)
{
}

void topWidgetElement::init(const QString& name, const QString& info)
{

    gridLayout_ = new QGridLayout();

    //图标标签
    icon_label_ = new QLabel();
    QPixmap pixmap(":/pictures/main_page_pics/vertical_mark_pic_2x.png");
    icon_label_->setPixmap(pixmap);

    //顶部类型标签
    type_name_label_ = new QLabel();
    type_name_label_->setFrameShape(QFrame::NoFrame);
    type_name_label_->setText(name);

    //详细信息标签
    type_detail_label_ = new QLabel();
    type_detail_label_->setFrameShape(QFrame::NoFrame);
    type_detail_label_->setText(info);

    //水平布局图标与当前选项名字
    QHBoxLayout* horizon_layout_ = new QHBoxLayout();
    horizon_layout_->addWidget(icon_label_);
    horizon_layout_->addWidget(type_name_label_);

    gridLayout_->addLayout(horizon_layout_, 0, 0, 1,1);
    gridLayout_->addWidget(type_detail_label_, 1, 0, 1, 2);

    this->setLayout(gridLayout_);
}

void topWidgetElement::setInfo(const QString &strInfo)
{
    if (type_detail_label_)
    {
        type_detail_label_->setText(strInfo);
    }
}
