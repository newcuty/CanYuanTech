#include "mainwidget.h"
#include "global.h"

#include <QTime>
#include <chrono>

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setParent(parent);
   // this->setMinimumSize(1600, 900);
    //this->setMaximumSize(1600, 900);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    //主界面整体布局
    main_grid_layout_ = new QGridLayout(this);

    //构建背景图片
    background_widget_ = new QWidget(this);
    background_widget_->setStyleSheet("border-image:url(:/pictures/main_page_pics/background_pic.png)");


    //构建顶层蓝色背景， 并初始化该区域
    top_status_widget_ = new QWidget(this);
    top_status_widget_->setStyleSheet("border-image:url(:/pictures/main_page_pics/top_widget_background_pic.png);");
    initTopStatusArea();

    //构建摄像头区域
    camera_widget_ = new QWidget(this);
    camera_widget_->setStyleSheet("border-image:url(:/pictures/main_page_pics/camera_init.png);");
    initCameraArea();

    user_info_widget_ = new QWidget(this);
    user_info_widget_->setStyleSheet("background-color:#F9FBFF;");
    initUserInfoArea();

    buttom_tower_detail_info_wiget_ = new QWidget(this);
    buttom_tower_detail_info_wiget_->setStyleSheet("border-image:url(:/pictures/main_page_pics/bottom_widget_background_pic.png);");

    right_tower_status_widget_ = new QWidget(this);
    right_tower_status_widget_->setStyleSheet("border-image:url(:/pictures/main_page_pics/tower_crane_pic.png);");

    right_tower_chart_widget_ = new QWidget(this);
    right_tower_chart_widget_ ->setStyleSheet("background-color:#E9EEFA;");

    //左边摄像头与底部状态布局
    QVBoxLayout* leftWidgetLayout = new QVBoxLayout;
    leftWidgetLayout->addWidget(camera_widget_);
    leftWidgetLayout->addWidget(buttom_tower_detail_info_wiget_);
    leftWidgetLayout->setStretchFactor(camera_widget_, 6);
    leftWidgetLayout->setStretchFactor(buttom_tower_detail_info_wiget_, 1);

    //右边用户信息垂直布局
    QVBoxLayout* rightWidgetLayout = new QVBoxLayout;
    rightWidgetLayout->addWidget(user_info_widget_);
    //底部塔吊信息与塔吊图标水平布局
    QHBoxLayout* bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(right_tower_status_widget_);
    bottomLayout->addWidget(right_tower_chart_widget_);
    rightWidgetLayout->addLayout(bottomLayout);
    rightWidgetLayout->setStretchFactor(user_info_widget_, 2);
    rightWidgetLayout->setStretchFactor(bottomLayout, 1);

    //中间水平布局
    QHBoxLayout* middleLayout = new QHBoxLayout;
    middleLayout->addLayout(leftWidgetLayout);
    middleLayout->addLayout(rightWidgetLayout);
    middleLayout->setStretchFactor(leftWidgetLayout, 2);
    middleLayout->setStretchFactor(rightWidgetLayout, 1);


    //构建主界面布局，主界面分成两个区域
    main_grid_layout_->addWidget(top_status_widget_, 0, 0, 1, 2);
    main_grid_layout_->addLayout(middleLayout,1, 0, 1, 2);
    //main_grid_layout_->addLayout(rightWidgetLayout, 1, 1, 1, 1);

    main_grid_layout_->setRowStretch(0, 1);
    main_grid_layout_->setRowStretch(1, 7);
    //main_grid_layout_->setRowStretch(2, 1);
}

mainWidget::~mainWidget()
{
    if (thread_get_time_.joinable())
    {
        exit_thread_flag_ = true;
        thread_get_time_.join();
    }
}

void mainWidget::initTopStatusArea()
{
    //构建状态栏图标信息
    topwidget_[0] = new topWidgetElement();
    topwidget_[0] ->init(QString("型号"), QString("CY-TW-2"));

    topwidget_[1] = new topWidgetElement();
    topwidget_[1] ->init(QString("设备ID"), QString("123456789"));

    topwidget_[2] = new topWidgetElement();
    topwidget_[2] ->init(QString("ICCID"), QString("89765431"));

    topwidget_[3] = new topWidgetElement();
    topwidget_[3] ->init(QString("日期"), QString(""));
    //topwidget_[3] ->setGeometry(447, 0, 155, 80);

    exit_thread_flag_ = false;
    thread_get_time_ = std::thread(std::bind([this](){
        while(!exit_thread_flag_){
            //获取时间线程
            QDateTime date = QDateTime::currentDateTime();
            QString strDate = date.toString("yyyy-MM-dd hh:mm:ss");
            topwidget_[3]->setInfo(strDate);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }));

    //累计运行时间控件
    topwidget_[4] = new topWidgetElement();
    topwidget_[4] ->init(QString("累计运行时间"), QString(""));

    //构建GPS信号显示控件
    signalWidget_[0] = new cySignalWidget();
    signalWidget_[0]->init(":/pictures/main_page_pics/GPS_button_pic.png", "GPS信号强度");

    //构建4G信号显示控件
    signalWidget_[1] = new cySignalWidget();
    signalWidget_[1]->init(":/pictures/main_page_pics/4G_signal_pic.png", "4G信号强度");

    voice_backagestage_btn_ = new cyVoiceBackstageBtn();
    voice_backagestage_btn_->init();

    //顶部状态栏布局
    horizon_top_status_layout_ = new QHBoxLayout(top_status_widget_);
    /******顶部布局添加控件*******/

    for(int i = 0; i < 5; i++)
    {
        horizon_top_status_layout_->addWidget(topwidget_[i]);
    }

    for(int i = 0; i < 2; i++)
    {
        horizon_top_status_layout_->addWidget(signalWidget_[i]);
    }

    horizon_top_status_layout_->addWidget(voice_backagestage_btn_);
    /******顶部布局添加控件结束*********/
    horizon_top_status_layout_->addStretch();
    //设置顶部布局
    top_status_widget_->setLayout(horizon_top_status_layout_);

}

void mainWidget::initCameraArea()
{

}

void mainWidget::initUserInfoArea()
{
    //添加两个圆形
    cyPaintCircle* circle = new cyPaintCircle(user_info_widget_);
}

void mainWidget::resizeEvent(QResizeEvent *event)
{
    if (event == nullptr)
    {
        return;
    }

    background_widget_->resize(this->size());
    top_status_widget_->resize(this->width(), 130);
    camera_widget_->resize(1015,680);       //数值大小来源于蓝湖原型图
    user_info_widget_->resize(569, 515);
    buttom_tower_detail_info_wiget_->resize(1035, 124);
    right_tower_status_widget_->resize(569, 264);
}

