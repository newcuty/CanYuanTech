#include "topwidgetelement.h"

topWidgetElement::topWidgetElement(QWidget *parent) :
    QWidget(parent)
//    top_status_groupbox_(nullptr),
//    contain_icon_widget_(nullptr),
//    icon_label_(nullptr),
//    type_name_label_(nullptr),
//    type_detail_label_(nullptr),
//    horizon_layout_(nullptr),
//    vertical_layout_(nullptr)
{
    //initTopStatusWidget();

    //QGridLayout* mainGridLayout = new QGridLayout();
    //mainGridLayout->addWidget(top_status_groupbox_, 0, 0);

    //this->setLayout(mainGridLayout);
}

void topWidgetElement::initTopStatusWidget(const QString& name, const QString& info)
{
    QGridLayout* gridLayout = new QGridLayout();
    QLabel* icon_label_ = new QLabel();
    //icon_label_->resize(32,32);
//    QImage Image;
//    Image.load(":/pictures/main_page_pics/vertical_mark_pic.png");
//    QPixmap pixmap = QPixmap::fromImage(Image);
//    QPixmap fitpixmap = pixmap.scaled(icon_label_->width(), icon_label_->height(),
//                                      Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充

//    icon_label_->setPixmap(fitpixmap);

    QPixmap pixmap(":/pictures/main_page_pics/vertical_mark_pic_2x.png");
    icon_label_->setPixmap(pixmap);

    QLabel* type_name_label_ = new QLabel();
    type_name_label_->setText(name);

    QLabel* type_detail_label_ = new QLabel();
    type_detail_label_->setText(info);

    QHBoxLayout* horizon_layout_ = new QHBoxLayout();
    horizon_layout_->addWidget(icon_label_);
    horizon_layout_->addWidget(type_name_label_);

    gridLayout->addLayout(horizon_layout_, 0, 0, 1,1);
    //gridLayout->setHorizontalSpacing(-1);
    //gridLayout->addWidget(icon_label_, 0, 0, 1, 1);
    //gridLayout->addWidget(type_name_label_, 0, 1, 1, 1);
    //gridLayout->set
    gridLayout->addWidget(type_detail_label_, 1, 0, 1, 2);
    gridLayout->setRowStretch(0, 1);
    this->setLayout(gridLayout);
}
