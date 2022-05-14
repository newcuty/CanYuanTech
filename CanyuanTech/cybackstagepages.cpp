#include "cybackstagepages.h"
#include <QTableWidget>     //表格控件


const int editor_size_1 = 175;
const int editor_size_2 = 159;
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

    //添加主布局
    initMainLayout();
}

void cyBackStagePages::initMainLayout()
{
    //先设置滑动区域的布局
    scroll_main_page_ = new QScrollArea;
    scroll_main_page_->setWidgetResizable(true);
    //scroll_main_page_->setVisible(false);
    QSizePolicy scroll_sizepolicy;
    scroll_sizepolicy.setVerticalPolicy(QSizePolicy::Expanding);
    scroll_sizepolicy.setHorizontalPolicy(QSizePolicy::Ignored);
    scroll_main_page_->setSizePolicy(scroll_sizepolicy);


    //当主布局有值之后，再显示
    if (main_layout_->count() > 0)
    {
        qDebug()<< "set layout";

//        QHBoxLayout* main_hlayout = new QHBoxLayout();
//        main_hlayout->addLayout(main_layout_);
//        main_hlayout->addStretch(2);

        tower_info_wiget_->setLayout(main_layout_);
        //scroll_main_page_->setVisible(true);
        scroll_main_page_->setWidget(tower_info_wiget_);
    }

    //再设置整体布局，不然外部调用该类不显示任何内容
    QVBoxLayout* scroll_layout = new QVBoxLayout(this);
    scroll_layout->addWidget(scroll_main_page_);
    scroll_layout->addStretch();
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
    tower_info_wiget_ = new QWidget;
    tower_info_wiget_->setStyleSheet("background:#FFFFFF;");

    //塔吊信息顶部布局
    QHBoxLayout* tower_info_title_layout = new QHBoxLayout();
    //塔吊信息主布局
    QVBoxLayout* tower_info_main_layout = new QVBoxLayout();
    //塔吊信息图标与文字
    QLabel* tower_info_icon = new QLabel();
    tower_info_icon->setPixmap(QPixmap(":/pictures/backstage_icon/tower_info_pic.png"));
    QLabel* tower_info_text = new QLabel();
    tower_info_text->setStyleSheet("font-size:16px;color:#2A84FF;");
    tower_info_text->setText("塔机信息");
    //添加至布局
    tower_info_title_layout->addWidget(tower_info_icon);
    tower_info_title_layout->addWidget(tower_info_text);
    tower_info_title_layout->addStretch();

    QVector<cyLineEdit*> tmp_vector;
    //初始化各个编辑控件
    cyLineEdit* tower_type = new cyLineEdit("塔机型号", editor_size_1);
    cyLineEdit* tower_head_height = new cyLineEdit("塔帽高度", editor_size_1);
    cyLineEdit* tower_body_height = new cyLineEdit("塔身高度", editor_size_1);
    cyLineEdit* tower_max_weidght = new cyLineEdit("最大吊重", editor_size_1);
    cyLineEdit* tower_max_moment = new cyLineEdit("最大力矩", editor_size_1);
    cyLineEdit* tower_jack_up_length = new cyLineEdit("起重臂长", editor_size_1);
    cyLineEdit* tower_balance_arm_length = new cyLineEdit("塔机型号", editor_size_1);
    cyLineEdit* tower_tlifting_rope_power= new cyLineEdit("吊绳倍率", editor_size_1);
    cyLineEdit* tower_max_wind_speed = new cyLineEdit("最大风速", editor_size_1);
    cyLineEdit* tower_max_dip_angle = new cyLineEdit("最大倾角", editor_size_1);


    //保存变量至map容器，方便后续读取
    tmp_vector.push_back(tower_type);
    tmp_vector.push_back(tower_tlifting_rope_power);
    tmp_vector.push_back(tower_head_height);
    tmp_vector.push_back(tower_body_height);
    tmp_vector.push_back(tower_max_weidght);
    tmp_vector.push_back(tower_max_moment);
    tmp_vector.push_back(tower_jack_up_length);
    tmp_vector.push_back(tower_balance_arm_length);
    tmp_vector.push_back(tower_max_wind_speed);
    tmp_vector.push_back(tower_max_dip_angle);
    tower_info_map_["塔机信息"] = tmp_vector;


    //添加布局，将所有控件添加到布局中
    QGridLayout* tower_info_layout = new QGridLayout();
    tower_info_layout->addWidget(tower_type, 0, 0);
    tower_info_layout->addWidget(tower_tlifting_rope_power, 0, 1);
    tower_info_layout->addWidget(tower_head_height, 1, 0);
    tower_info_layout->addWidget(tower_body_height, 1, 1);
    tower_info_layout->addWidget(tower_max_weidght, 2, 0);
    tower_info_layout->addWidget(tower_max_moment, 2, 1);
    tower_info_layout->addWidget(tower_jack_up_length, 3, 0);
    tower_info_layout->addWidget(tower_balance_arm_length, 3, 1);
    tower_info_layout->addWidget(tower_max_wind_speed, 4, 0);
    tower_info_layout->addWidget(tower_max_dip_angle, 4, 1);

    //水平间距39
    tower_info_layout->setHorizontalSpacing(39);
    //垂直间距
    tower_info_layout->setVerticalSpacing(8);

    tower_info_main_layout->addLayout(tower_info_title_layout);
    tower_info_main_layout->addLayout(tower_info_layout);
    main_layout_->addLayout(tower_info_main_layout);
}

void cyBackStagePages::initOverloadTable()
{
    //载荷特性表顶部布局
    QHBoxLayout* overload_table_title_layout = new QHBoxLayout();
    //载荷特性表表格主布局
    QVBoxLayout* overload_table_layout = new QVBoxLayout();

    //载荷特性表图标与文字
    QLabel* overload_table_icon = new QLabel();
    overload_table_icon->setPixmap(QPixmap(":/pictures/backstage_icon/tower_load_pic.png"));
    QLabel* overload_tabl_text = new QLabel();
    overload_tabl_text->setStyleSheet("font-size:16px;color:#2A84FF;");
    overload_tabl_text->setText("荷载特性表");

    overload_table_title_layout->addWidget(overload_table_icon);
    overload_table_title_layout->addWidget(overload_tabl_text);
    overload_table_title_layout->addStretch();

    QTableWidget* overload_table = new QTableWidget();

    //添加表头
    QStringList header;
    header << "幅度/m" << "重量/t";
    overload_table->setVerticalHeaderLabels(header);
    overload_table->show();

    QVBoxLayout* table_layout = new QVBoxLayout();
    table_layout->addWidget(overload_table);


    overload_table_layout->addLayout(overload_table_title_layout);
    overload_table_layout->addLayout(table_layout);

    main_layout_->addLayout(overload_table_layout);
    main_layout_->addSpacing(widget_spacing);
}

 //初始化塔吊安装信息
void cyBackStagePages::initTowerInstallInfo()
{
    //顶部布局
    //塔吊安装信息顶部布局
    QHBoxLayout* tower_install_info_title_layout = new QHBoxLayout();
    //塔吊安装信息主布局
    QVBoxLayout* tower_install_info_layout = new QVBoxLayout();

    //塔吊安装图标与文字
    QLabel* tower_install_info_icon = new QLabel();
    tower_install_info_icon->setPixmap(QPixmap(":/pictures/backstage_icon/tower_install_info_pic.png"));
    QLabel* tower_install_info_tabl_text = new QLabel();
    tower_install_info_tabl_text->setStyleSheet("font-size:16px;color:#2A84FF;");
    tower_install_info_tabl_text->setText("塔机安装信息");

    tower_install_info_title_layout->addWidget(tower_install_info_icon);
    tower_install_info_title_layout->addWidget(tower_install_info_tabl_text);
    tower_install_info_title_layout->addStretch();

    //塔吊安装详细信息
    QVector<cyLineEdit*> tmp_vector;
    cyLineEdit* tower_number = new cyLineEdit("塔机编号", editor_size_2);
    cyLineEdit* north_rotate = new cyLineEdit("正北偏转", editor_size_2);
    cyLineEdit* tower_latitude = new cyLineEdit("纬度", editor_size_2);
    cyLineEdit* tower_longitude = new cyLineEdit("经度", editor_size_2);
    cyLineEdit* tower_channel = new cyLineEdit("信道", editor_size_2);
    cyLineEdit* tower_X_axis = new cyLineEdit("坐标X", editor_size_2/2);
    cyLineEdit* tower_Y_axis = new cyLineEdit("坐标Y", editor_size_2/2);

    tmp_vector.push_back(tower_number);
    tmp_vector.push_back(north_rotate);
    tmp_vector.push_back(tower_latitude);
    tmp_vector.push_back(tower_longitude);
    tmp_vector.push_back(tower_X_axis);
    tmp_vector.push_back(tower_Y_axis);
    tmp_vector.push_back(tower_channel);
    tower_info_map_["塔机安装信息"] = tmp_vector;

    //添加布局
    //第一列布局
    QHBoxLayout* tower_install_info_hlayout = new QHBoxLayout();
    tower_install_info_hlayout->addWidget(tower_number);
    tower_install_info_hlayout->addWidget(tower_X_axis);
    tower_install_info_hlayout->addWidget(tower_Y_axis);

    //剩余四个布局
    QGridLayout* tower_install_gridlayout = new QGridLayout();
    tower_install_gridlayout->addWidget(north_rotate, 0, 0);
    tower_install_gridlayout->addWidget(tower_channel, 0, 1);
    tower_install_gridlayout->addWidget(tower_longitude, 1, 0);
    tower_install_gridlayout->addWidget(tower_latitude, 1, 1);
    //栅格布局水平间距39
    tower_install_gridlayout->setHorizontalSpacing(39);
    //栅格布局垂直间距
    tower_install_gridlayout->setVerticalSpacing(8);

    tower_install_info_layout->addLayout(tower_install_info_title_layout);
    tower_install_info_layout->addLayout(tower_install_info_hlayout);
    tower_install_info_layout->addLayout(tower_install_gridlayout);
    main_layout_->addLayout(tower_install_info_layout);
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
    //初始化顶部布局
    QHBoxLayout* switch_top_layout =
            initTopLayout(":/pictures/backstage_icon/tower_install_info_pic.png", "功能开关");

    //塔吊安装信息主布局
    QVBoxLayout* switch_layout = new QVBoxLayout();
    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("重量");
    cySwitchButtonWidget* range_switch_button = new cySwitchButtonWidget("幅度");
    cySwitchButtonWidget* moment_switch_button = new cySwitchButtonWidget("力矩");
    cySwitchButtonWidget* heigth_switch_button = new cySwitchButtonWidget("高度");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("回转");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("风速");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("倾角");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("电子罗盘");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("TF存储");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("制动控制");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("驾驶员识别");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("群塔防碰撞");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("吊钩可视化");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("GPS定位");
//    cySwitchButtonWidget* weight_switch_button = new cySwitchButtonWidget("网络时间同步");

    switch_button_vector_.push_back(weight_switch_button);
    switch_button_vector_.push_back(range_switch_button);
    switch_button_vector_.push_back(moment_switch_button);
    switch_button_vector_.push_back(heigth_switch_button);


    QGridLayout* grid_layout = new QGridLayout;
    grid_layout->addWidget(weight_switch_button, 0, 0);
    grid_layout->addWidget(range_switch_button, 0, 1);
    grid_layout->addWidget(moment_switch_button, 0, 2);
    grid_layout->addWidget(heigth_switch_button, 1, 0);

    switch_layout->addLayout(switch_top_layout);
    switch_layout->addLayout(grid_layout);
    switch_layout->addStretch();

    main_layout_->addLayout(switch_layout);
    main_layout_->addSpacing(22);

}


void cyBackStagePages::resizeEvent(QResizeEvent *event)
{
//    scroll_layout_->resize(571, 4214);
}

