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
    data_row_2_->setStyleSheet("font-size:18px; color: #568EFF;");
    data_row_3_ = new QLabel();
    data_row_3_->setStyleSheet("font-size:14px; color: #568EFF;");

    //布局控件
    //水平布局
    QHBoxLayout* hLabelLayout = new QHBoxLayout();
    hLabelLayout->addWidget(icon_label_);
    hLabelLayout->addWidget(info_label_);
    hLabelLayout->addStretch();

    //垂直主布局
    QVBoxLayout* mainVLayout = new QVBoxLayout(this);
    mainVLayout->addLayout(hLabelLayout);
    mainVLayout->addWidget(data_row_2_);
    mainVLayout->addWidget(data_row_3_);
    mainVLayout->addStretch();

    setSecondRowData("12.5KG");
    setThirdRowData("(20.5%)");
}

void cyBottomWidgetElement::init(const QString &icon_path, const QString &info,
                                 const QString &second_row_info1, const QString &second_row_info2)
{

    //显示图标
    icon_label_ = new QLabel();
    QPixmap pixmap(icon_path);
    icon_label_->setPixmap(pixmap);

    //信息图标
    info_label_ = new QLabel();
    info_label_->setText(info);

    //初始化数据显示控件

    //第二行数据
    data_row_label_2_1_ = new QLabel();
    data_row_label_2_1_->setStyleSheet("font-size:18px; color: #568EFF;");
    data_row_label_2_2_ = new QLabel();
    data_row_label_2_2_->setStyleSheet("font-size:18px; color: #568EFF;");
    second_row_name_2_1_ = new QLabel();
    second_row_name_2_1_->setText(second_row_info1);
    second_row_name_2_2_ = new QLabel();
    second_row_name_2_2_->setText(second_row_info2);

    //第三行数据
    data_row_label_3_1_ = new QLabel();
    data_row_label_3_1_->setStyleSheet("font-size:14px; color: #568EFF;");
    data_row_label_3_2_ = new QLabel();
    data_row_label_3_2_->setStyleSheet("font-size:14px; color: #568EFF;");

    //布局控件
    //水平布局
    QHBoxLayout* hLabelLayout = new QHBoxLayout();
    hLabelLayout->addWidget(icon_label_);
    hLabelLayout->addWidget(info_label_);
    hLabelLayout->addStretch();

    //采用全新布局
    QGridLayout* data1_layout = new QGridLayout();  //数据1布局
    QGridLayout* data2_layout = new QGridLayout();  //数据2布局

    data1_layout->addWidget(second_row_name_2_1_, 0, 0);
    data1_layout->addWidget(data_row_label_2_1_, 0, 1);
    data1_layout->addWidget(data_row_label_3_1_, 1, 1);

    data2_layout->addWidget(second_row_name_2_2_, 0, 0);
    data2_layout->addWidget(data_row_label_2_2_, 0, 1);
    data2_layout->addWidget(data_row_label_3_2_, 1, 1);

    QHBoxLayout* data_main_hlayout = new QHBoxLayout();
    data_main_hlayout->addLayout(data1_layout);
    data_main_hlayout->addLayout(data2_layout);
    data_main_hlayout->addStretch();

    QVBoxLayout* mainVLayout = new QVBoxLayout(this);
    mainVLayout->addLayout(hLabelLayout, Qt::AlignCenter);
    mainVLayout->addLayout(data_main_hlayout);
    mainVLayout->addStretch();

    setSecondRowDatas("12.5m", "231");
    setThirdRowDatas("(20.5%)", "(20.5%)");

}

//第二行数据
void cyBottomWidgetElement::setSecondRowData(const QString &data)
{
    //设置数据
    second_row_data_1_ = data;
    data_row_2_->setText(second_row_data_1_);
}

//第二行两个数据
void cyBottomWidgetElement::setSecondRowDatas(const QString &data1, const QString &data2)
{
    if (!second_row_name_2_1_)
    {
        qDebug() << "函数引用错误\n";
        return;
    }

    second_row_data_1_ = data1;
    second_row_data_2_ = data2;

    data_row_label_2_1_->setText(second_row_data_1_);
    data_row_label_2_2_->setText(second_row_data_2_);
}

//第三行单数据
void cyBottomWidgetElement::setThirdRowData(const QString &data)
{
    third_row_data_1_ = data;
    data_row_3_->setText(third_row_data_1_);
}

//设置第三行双数据
void cyBottomWidgetElement::setThirdRowDatas(const QString &data1, const QString &data2)
{

    third_row_data_1_ = data1;
    data_row_label_3_1_->setText(third_row_data_1_);

    third_row_data_2_ = data2;
    data_row_label_3_2_->setText(third_row_data_2_);
}




