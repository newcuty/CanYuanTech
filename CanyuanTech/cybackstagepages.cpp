#include "cybackstagepages.h"
#include <QTableWidget>     //表格控件


//const int editor_size_1 = 175;
//const int editor_size_2 = 159;
const int widget_spacing = 23;

cyBackStagePages::cyBackStagePages(QWidget *parent) : QWidget(parent)
{

    main_layout_ = new QVBoxLayout();

    //初始化顺序，先初始化各个部分的布局，再初始化总体的布局
    //1.初始化塔吊信息
    initTowerInfoLayout();
    //2.添加提示信息
    addTips(QString("当塔帽高度等于0时，认为该塔机是平塔"));
    //3.添加载荷特性表
    initOverloadTable();
    //4.添加安装信息
    initTowerInstallInfo();
    //5.添加分割线
    addSplite();
    //6.添加开关功能那妞
    initFuntionSwitch();
    //7.添加提示信息
    addTips(QString("群塔防碰撞，自动搜索附近可能会发生碰撞的塔机"));
    addSplite();
    //8.添加系统设置
    initSystemSettings();
    addSplite();
    //9.添加数据标定
    initDataStandard();
    addTips("根据传感器反馈的值实时变动，例如 1.3");
    addSplite();

    //10.添加报警阀值
    initAlarmValue();
    addSplite();

    //11.身份录入
    initInputID();
    addSplite();



    //添加主布局
    initMainLayout();
}

void cyBackStagePages::initMainLayout()
{


    //先设置滑动区域的布局
    scroll_main_page_ = new QScrollArea;
    scroll_main_page_->setWidgetResizable(true);
    QSizePolicy scroll_sizepolicy;
    scroll_sizepolicy.setVerticalPolicy(QSizePolicy::Expanding);
    scroll_sizepolicy.setHorizontalPolicy(QSizePolicy::Ignored);
    scroll_main_page_->setSizePolicy(scroll_sizepolicy);


    //当主布局有值之后，再显示
    if (main_layout_->count() > 0)
    {
        qDebug()<< "set layout";
        tower_info_wiget_ = new QWidget;
        tower_info_wiget_->setStyleSheet("background:#FFFFFF;");
        tower_info_wiget_->setLayout(main_layout_);
        scroll_main_page_->setWidget(tower_info_wiget_);
    }

    //再设置整体布局，不然外部调用该类不显示任何内容
    QVBoxLayout* scroll_layout = new QVBoxLayout(this);
    scroll_layout->addWidget(scroll_main_page_);
}

QHBoxLayout *cyBackStagePages::initTopLayout(const QString &icon_path, const QString &title)
{
    //塔吊安装信息顶部布局
    QHBoxLayout* return_layout = new QHBoxLayout();
    //塔吊安装图标与文字
    QLabel* icon_label = new QLabel();
    icon_label->setPixmap(icon_path);
    QLabel* text_label = new QLabel();
    text_label->setStyleSheet("font-size:16px;color:#2A84FF;");
    text_label->setText(title);

    return_layout->addWidget(icon_label);
    return_layout->addWidget(text_label);
    return_layout->addStretch();

    return return_layout;
}

//添加提示信息。
void cyBackStagePages::addTips(const QString &info)
{
    QLabel* tips_label = new QLabel();
    tips_label->setStyleSheet("QLabel {"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                              "stop:0 #2A84FF,stop:1 #57CBFF);"
                              "border-radius: 11px;"
                              "qproperty-alignment:AlignHCenter;"
                              "font-size:17px;"
                              "color:#FFFFFF;}");
    tips_label->setText(info);
    main_layout_->addSpacing(widget_spacing);
    main_layout_->addWidget(tips_label);
    main_layout_->addSpacing(widget_spacing);

}

void cyBackStagePages::initTowerInfoLayout()
{
    //初始塔机信息
    tower_info_widget_ = new cyBackStageTowerInfo();
    main_layout_->addWidget(tower_info_widget_);
}

void cyBackStagePages::initOverloadTable()
{
    //初始化荷载特性表
    overload_widget_ = new cyBackStageOverloadWidget();
    main_layout_->addWidget(overload_widget_);
    main_layout_->addSpacing(widget_spacing);
}

 //初始化塔吊安装信息
void cyBackStagePages::initTowerInstallInfo()
{
    tower_install_info_widget_ = new cyBackStageTowerInstallInfoWidget();
    main_layout_->addWidget(tower_install_info_widget_);
    main_layout_->addSpacing(22);
}

//添加分割线
void cyBackStagePages::addSplite()
{
    QFrame* horizen_line = new QFrame();
    horizen_line->setFrameShape(QFrame::HLine);
    horizen_line->setStyleSheet("QFrame{background:#CED2DE;max-width:569px;max-height:1px;}");

    main_layout_->addWidget(horizen_line);
    main_layout_->addSpacing(20);
}

//添加功能开关
void cyBackStagePages::initFuntionSwitch()
{
    func_switch_widget_ = new cyBackStageFuncSwitchWidget();
    main_layout_->addWidget(func_switch_widget_);
    main_layout_->addSpacing(20);
}

//初始化系统设置
void cyBackStagePages::initSystemSettings()
{
    system_settings_widget_ = new cyBackStageSystemSettingsWidget();
    main_layout_->addWidget(system_settings_widget_);
}

//初始化数据标定
void cyBackStagePages::initDataStandard()
{
    //main_layout_->addSpacing(10);
    data_standard_widget_ = new cyBackStageDataSetWidget();
    main_layout_->addWidget(data_standard_widget_);

}

//初始化报警阀值
void cyBackStagePages::initAlarmValue()
{
    alarm_value_widget_ = new cyBackStageAlarmValueWidget();
    main_layout_->addWidget(alarm_value_widget_);
}

void cyBackStagePages::initInputID()
{
    input_ID_widget_ = new cyBackStageInputIDWidget();
    main_layout_->addWidget(input_ID_widget_);

}


void cyBackStagePages::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
//    scroll_layout_->resize(571, 4214);
}

