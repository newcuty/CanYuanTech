#include "cysignalwidget.h"


//主界面顶层信号状态栏 4G与GPS信号图标
cySignalWidget::cySignalWidget(QWidget *parent)
    : QWidget(parent),
      icon_label_(nullptr),
      info_label_(nullptr)
{

}

cySignalWidget::~cySignalWidget()
{
    //析构构建的类
   if(icon_label_)
   {
       delete icon_label_;
       icon_label_ = nullptr;
   }

   if(info_label_)
   {
       delete info_label_;
       icon_label_ = nullptr;
   }

}

void cySignalWidget::init(const QString &icon_path, const QString &info)
{
    if(icon_label_ == nullptr)
    {
        icon_label_ = new QLabel();
    }

    //显示图片
    QPixmap pixmap(icon_path);
    icon_label_->setPixmap(pixmap);

    if(info_label_ == nullptr)
    {
        info_label_ = new QLabel();
    }

    //设置文字
    info_label_->setStyleSheet("QLabel {font-size:12px;color:#D4EBFF;"
                               "border-radius:14px;"
                               "padding:2px 4px;"
                               "border:1px groove #D4EBFF;"
                               "margin:5px;}");
    info_label_->setText(info);

    //构建垂直布局
    QVBoxLayout* vLayout = new QVBoxLayout(this);
     //添加元素
    vLayout->addWidget(icon_label_);
    vLayout->addWidget(info_label_);
    vLayout->addStretch();
     //设置元素在控件中的位置
    vLayout->setAlignment(icon_label_, Qt::AlignCenter);
    vLayout->setAlignment(info_label_, Qt::AlignLeft);
}

void cySignalWidget::setIcon(const QString &icon_path)
{
    if(icon_label_ == nullptr)
    {
        //添加日志
        qWarning() << "信号控件未初始化\n";
        return;
    }

    //修改显示图片
    QPixmap pixmap(icon_path);
    icon_label_->setPixmap(pixmap);
}
