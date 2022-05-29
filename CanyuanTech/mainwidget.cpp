#include "mainwidget.h"
#include "global.h"

#include <QTime>
#include <chrono>
const int top_element_spcing = 40;
const int bottom_element_spacing = 0;

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setParent(parent);
    //this->setMinimumSize(1600, 900);
    //this->setMaximumSize(1600, 900);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    //构建背景图片
    background_widget_ = new QWidget(this);
    background_widget_->setObjectName("background_widget");
    background_widget_->setStyleSheet("#background_widget{border-image:url(:/pictures/main_page_pics/background_pic.png);}");

    //堆栈控件变量
    right_stacked_widget_ = new QStackedWidget(this);

    //初始化各个部分
    initTopStatusArea();
    initCameraArea();
    initUserInfoArea();
    initLoginArea();
    initBottomDetailInfoArea();
    initBackagePage();

    //初始化界面为登录界面
    current_page_ = CY_LOGIN;

    //左边摄像头与底部状态布局
    QVBoxLayout* leftWidgetLayout = new QVBoxLayout;
    leftWidgetLayout->addWidget(camera_widget_);
    leftWidgetLayout->addWidget(buttom_tower_detail_info_wiget_);
    leftWidgetLayout->setStretchFactor(camera_widget_, 6);
    leftWidgetLayout->setStretchFactor(buttom_tower_detail_info_wiget_, 1);

    //右边用户信息垂直布局
    QVBoxLayout* rightWidgetLayout = new QVBoxLayout;
    rightWidgetLayout->addWidget(right_stacked_widget_);
    right_stacked_widget_->setCurrentWidget(login_widget_);

    //中间水平布局，左边部分和右边部分
    QHBoxLayout* middleLayout = new QHBoxLayout;
    middleLayout->addLayout(leftWidgetLayout);
    middleLayout->addLayout(rightWidgetLayout);
    middleLayout->setStretchFactor(leftWidgetLayout, 2);
    middleLayout->setStretchFactor(rightWidgetLayout, 1);

    // 主界面布局，上下两部分
    QVBoxLayout* mainHorizonLayout = new QVBoxLayout(this);
    mainHorizonLayout->addWidget(top_status_widget_);
    mainHorizonLayout->addLayout(middleLayout);
    mainHorizonLayout->setMargin(0);
    mainHorizonLayout->setStretch(2, 1);
    mainHorizonLayout->setStretchFactor(top_status_widget_, 1);
    mainHorizonLayout->setStretchFactor(middleLayout, 6);
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
    //构建顶层蓝色背景， 并初始化该区域
    top_status_widget_ = new QWidget(this);
    top_status_widget_->setObjectName("top_status_widget");
    top_status_widget_->setStyleSheet("#top_status_widget{"
                                      "border-image:url(:/pictures/main_page_pics/top_widget_background_pic.png);}");

    //构建状态栏图标信息
    topWidgetElement* type = new topWidgetElement();
    type->init(QString("型号"), QString("CY-TW-2"));

    topWidgetElement* device = new topWidgetElement();
    device->init(QString("设备ID"), QString("123456789"));

    topWidgetElement* iccid = new topWidgetElement();
    iccid->init(QString("ICCID"), QString("89765431"));

    topWidgetElement* date = new topWidgetElement();
    date->init(QString("日期"), QString(""));

    //累计运行时间控件
    topWidgetElement* totalTime = new topWidgetElement();
    totalTime->init(QString("累计运行时间"), QString(""));

    topwidget_map_.insert("型号", type);
    topwidget_map_.insert("设备ID", device);
    topwidget_map_.insert("ICCID", iccid);
    topwidget_map_.insert("日期", date);
    topwidget_map_.insert("累计运行时间", totalTime);


    exit_thread_flag_ = false;
    thread_get_time_ = std::thread(std::bind([&](){
        while(!exit_thread_flag_){
            //获取时间线程
            QDateTime date = QDateTime::currentDateTime();
            QString strDate = date.toString("yyyy-MM-dd hh:mm:ss");
            topwidget_map_["日期"]->setInfo(strDate);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }));


    //构建GPS信号显示控件
    cySignalWidget* gpsSignal = new cySignalWidget();
    gpsSignal->init(":/pictures/main_page_pics/GPS_button_pic.png", "GPS信号强度");

    //构建4G信号显示控件
    cySignalWidget* _4GSignal = new cySignalWidget();
    _4GSignal->init(":/pictures/main_page_pics/4G_signal_pic.png", "4G信号强度");

    signale_.insert("GPS", gpsSignal);
    signale_.insert("4G", _4GSignal);

    voice_backagestage_btn_ = new cyVoiceBackstageBtn();
    voice_backagestage_btn_->init();

    //顶部状态栏布局
    //添加各个组件
    horizon_top_status_layout_ = new QHBoxLayout(top_status_widget_);
    horizon_top_status_layout_->addWidget(type);
    horizon_top_status_layout_->addSpacing(top_element_spcing);
    horizon_top_status_layout_->addWidget(device);
    horizon_top_status_layout_->addSpacing(top_element_spcing);
    horizon_top_status_layout_->addWidget(iccid);
    horizon_top_status_layout_->addSpacing(top_element_spcing);
    horizon_top_status_layout_->addWidget(date);
    horizon_top_status_layout_->addSpacing(top_element_spcing);
    horizon_top_status_layout_->addWidget(totalTime);
    horizon_top_status_layout_->addSpacing(50);
    horizon_top_status_layout_->addWidget(gpsSignal);
    horizon_top_status_layout_->addWidget(_4GSignal);

    //添加信号组件
    horizon_top_status_layout_->addSpacing(top_element_spcing);
    //添加后台按钮组件
    horizon_top_status_layout_->addWidget(voice_backagestage_btn_);
    //connect(voice_backagestage_btn_->getBackageBtn(), &QPushButton::clicked, this, &mainWidget::onChangeToBackStageWidget);

    /******顶部布局添加控件结束*********/

    horizon_top_status_layout_->addSpacing(top_element_spcing);
    //设置顶部布局
    top_status_widget_->setLayout(horizon_top_status_layout_);

}

void mainWidget::initCameraArea()
{
    //构建摄像头区域
    camera_widget_ = new QWidget(this);
    camera_widget_->setStyleSheet("border-image:url(:/pictures/main_page_pics/camera_init.png);");

}

void mainWidget::initUserInfoArea()
{
    user_tower_widget_ = new cyUserTowerWidget();
    user_tower_widget_->init();

    right_stacked_widget_->addWidget(user_tower_widget_);
}

void mainWidget::initLoginArea()
{
    login_widget_ = new cyLogin(this);
    login_widget_->init();
    //添加控件到堆栈窗口
    right_stacked_widget_->addWidget(login_widget_);

    //cyLogin 验证成功之后，发送 sigVerifySuccess 信号
    connect(login_widget_, &cyLogin::sigVerifySuccess, this, &mainWidget::onChangeToTowerWidget);

}

void mainWidget::initBottomDetailInfoArea()
{
    //初始化底部控件
    buttom_tower_detail_info_wiget_ = new QWidget(this);
    buttom_tower_detail_info_wiget_->setObjectName("buttom_tower_detail_info_wiget");
    buttom_tower_detail_info_wiget_->setStyleSheet("buttom_tower_detail_info_wiget{border-image:url"
                                                   "(:/pictures/main_page_pics/bottom_widget_background_pic.png);}");

    //重量显示卡
    cyBottomWidgetElement* weightWidget = new cyBottomWidgetElement(this);
    weightWidget->init(":/pictures/main_page_pics/weidget_pic.png", "重量");
    //幅度显示卡
    cyBottomWidgetElement* rangeWidget = new cyBottomWidgetElement(this);
    rangeWidget->init(":/pictures/main_page_pics/range_pic.png", "幅度");
    //力矩显示卡
    cyBottomWidgetElement* momentWidget = new cyBottomWidgetElement(this);
    momentWidget->init(":/pictures/main_page_pics/moment_pic.png", "力矩");
    //高度显示卡
    cyBottomWidgetElement* heightWidget = new cyBottomWidgetElement(this);
    heightWidget->init(":/pictures/main_page_pics/heigth_pic.png", "高度", "起升高度", "下落高度");
    //回转显示卡
    cyBottomWidgetElement* rotateWidget = new cyBottomWidgetElement(this);
    rotateWidget->init(":/pictures/main_page_pics/rotate_pic.png", "回转");
    //倾角显示卡
    cyBottomWidgetElement* dipAngleWidget = new cyBottomWidgetElement(this);
    dipAngleWidget->init(":/pictures/main_page_pics/dip_angle_pic.png", "倾角", "X轴", "Y轴");
    //风速显示卡
    cyBottomWidgetElement* windWidget = new cyBottomWidgetElement(this);
    windWidget->init(":/pictures/main_page_pics/wind_speed_pic.png", "风速");


    QHBoxLayout* hMainLayout = new QHBoxLayout(buttom_tower_detail_info_wiget_);
    hMainLayout->addWidget(weightWidget);
    hMainLayout->addWidget(rangeWidget);
    hMainLayout->addWidget(momentWidget);
    hMainLayout->addWidget(heightWidget);
    hMainLayout->addWidget(rotateWidget);
    hMainLayout->addWidget(dipAngleWidget);
    hMainLayout->addWidget(windWidget);

    //添加底部每个元素至map， 方便管理
    bottomwidget_map_.insert(QString("重量"), weightWidget);
    bottomwidget_map_.insert(QString("幅度"), rangeWidget);
    bottomwidget_map_.insert(QString("力矩"), momentWidget);
    bottomwidget_map_.insert(QString("高度"), heightWidget);
    bottomwidget_map_.insert(QString("回转"), rotateWidget);
    bottomwidget_map_.insert(QString("倾角"), dipAngleWidget);
    bottomwidget_map_.insert(QString("风速"), windWidget);
}

void mainWidget::initBackagePage()
{
    //将后台界面添加至栈控件
    backstage_page_ = new cyBackStagePages(this);
    right_stacked_widget_->addWidget(backstage_page_);
}


void mainWidget::resizeEvent(QResizeEvent *event)
{
    if (event == nullptr)
    {
        return;
    }

    background_widget_->resize(this->size());
    top_status_widget_->resize(1920, 130);
    camera_widget_->resize(1015,680);       //数值大小来源于蓝湖原型图
    buttom_tower_detail_info_wiget_->resize(1035, 124);
    right_stacked_widget_->resize(569, 4214);
}

void mainWidget::onChangeToTowerWidget()
{
    //跳转至用户界面
    current_page_ = CY_USERINFO;
    //设置当前堆栈控件
    right_stacked_widget_->setCurrentWidget(user_tower_widget_);

}

void mainWidget::onChangeToBackStageWidget()
{
    //登录界面无法跳转至该界面
    if (current_page_ == CY_LOGIN)
    {
        return;
    }

    if (current_page_ != CY_SETTINGS)
    {
        current_page_ = CY_SETTINGS;
        //设置当前界面为后台界面
        right_stacked_widget_->setCurrentWidget(backstage_page_);
    }
    else
    {
        current_page_ = CY_USERINFO;
        right_stacked_widget_->setCurrentWidget(user_tower_widget_);
    }
}


