#include "mainwidget.h"
#include <QTime>
#include <chrono>


mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
      //topwidget(nullptr)
{
    this->setParent(parent);
    this->setGeometry(0, 0, 800, 480);
    this->setMinimumSize(800, 480);
    //构建背景图片
    background_widget = new QWidget(this);
    background_widget->setStyleSheet("border-image:url(:/pictures/main_page_pics/background_pic.png)");

    //构建顶层蓝色背景
    top_status_widget = new QWidget(this);
    top_status_widget->setGeometry(0, 0, 800, 90);
    top_status_widget->setStyleSheet("border-image:url(:/pictures/main_page_pics/top_widget_background_pic.png)");

    //构建状态栏图标信息
    topwidget[0] = new topWidgetElement(this);
    topwidget[0] ->initTopStatusWidget(QString("型号"), QString("CY-TW-2"));
    topwidget[0] ->setGeometry(0,0,149,80);

    topwidget[1] = new topWidgetElement(this);
    topwidget[1] ->initTopStatusWidget(QString("设备ID"), QString("123456789"));
    topwidget[1] ->setGeometry(149, 0,149,80);

    topwidget[2] = new topWidgetElement(this);
    topwidget[2] ->initTopStatusWidget(QString("ICCID"), QString("89765431"));
    topwidget[2] ->setGeometry(298, 0, 149,80);

    topwidget[3] = new topWidgetElement(this);
    topwidget[3] ->initTopStatusWidget(QString("日期"), QString(""));
    topwidget[3] ->setGeometry(447, 0, 155, 80);

    exit_thread_flag_ = false;
    thread_get_time_ = std::thread(std::bind([this](){
        while(!exit_thread_flag_){
            //获取时间线程
            QDateTime date = QDateTime::currentDateTime();
            QString strDate = date.toString("yyyy-MM-dd hh:mm:ss");
            topwidget[3]->setInfo(strDate);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }));

    topwidget[4] = new topWidgetElement(this);
    topwidget[4] ->initTopStatusWidget(QString("累计运行时间"), QString(""));
    topwidget[4] ->setGeometry(596, 0, 152, 80);
}

mainWidget::~mainWidget()
{
    if (thread_get_time_.joinable())
    {
        exit_thread_flag_ = true;
        thread_get_time_.join();
    }
}

void mainWidget::resizeEvent(QResizeEvent *event)
{
    background_widget->resize(this->size());
    top_status_widget->resize(this->width(), 130);
}

