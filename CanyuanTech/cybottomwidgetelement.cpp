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

    setSecondRowData(12.5123);
    setThirdRowData(20.51645);
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

    setSecondRowDatas(12.532, 231.111);
    setThirdRowDatas(20.5222, 20.5);

}

//第二行数据
void cyBottomWidgetElement::setSecondRowData(const float &data)
{
    //设置数据
    second_row_data_1_ = QString::asprintf("%.1f", data);
    data_row_2_->setText(second_row_data_1_);
}

//第二行两个数据
void cyBottomWidgetElement::setSecondRowDatas(const float &data1, const float &data2)
{
    if (!second_row_name_2_1_)
    {
        qDebug() << "函数引用错误\n";
        return;
    }

    second_row_data_1_ = QString::asprintf("%.1f", data1);
    second_row_data_2_ = QString::asprintf("%.1f", data2);

    data_row_label_2_1_->setText(second_row_data_1_);
    data_row_label_2_2_->setText(second_row_data_2_);
}

//第三行单数据
void cyBottomWidgetElement::setThirdRowData(const float& data_percentage)
{
    third_row_data_1_ = QString::asprintf("%.1f", data_percentage) + "%";
    third_row_data_1_ = setDataAlarmConlor(third_row_data_1_, -1);
    data_row_3_->setText(third_row_data_1_);
}

//设置第三行双数据
void cyBottomWidgetElement::setThirdRowDatas(const float& data_percentage1, const float& data_percentage2)
{

    //显示第三行左边的数据
    third_row_data_1_ = QString::asprintf("%.1f", data_percentage1) + "%";
    third_row_data_1_ = setDataAlarmConlor(third_row_data_1_, -2);
    data_row_label_3_1_->setText(third_row_data_1_);

    //显示第三行右边的数据
    third_row_data_2_ = QString::asprintf("%.1f", data_percentage2) + "%";
    third_row_data_1_ = setDataAlarmConlor(third_row_data_2_, -2);
    data_row_label_3_2_->setText(third_row_data_2_);
}

QString cyBottomWidgetElement::setDataAlarmConlor(QString &str, int level)
{

    //防止数值太大的情况
    if (level > 10)
    {
        return str;
    }

    QString colored_str;

    //根据不同的等级来区分显示，正常时蓝色， 预警时黄色，报警是红色
    switch(level)
    {
    case 0: //正常
        colored_str = QString("<font color=blue>%1").arg(str);
        break;
    case -1:  //黄色
        colored_str = QString("<font color=yellow>%1").arg(str);
        break;
    case -2:  //预警
        colored_str = QString("<font color=red>%1").arg(str);
        break;
     default:   //默认蓝色
        colored_str = QString("<font color=blue>%1").arg(str);
    }
    return colored_str;
}




