#include "cybackstagepages.h"
#include <QTableWidget>     //表格控件


const int editor_size_1 = 175;
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
    initMainLayout();
}

void cyBackStagePages::initMainLayout()
{
    //先设置滑动区域的布局
    scroll_main_page_ = new QScrollArea;
    scroll_main_page_->setWidgetResizable(true);
    scroll_main_page_->setVisible(false);

    //当主布局有值之后，再显示
    if (main_layout_->count() > 0)
    {
        qDebug()<< "set layout";
        tower_info_wiget_->setLayout(main_layout_);
        scroll_main_page_->setVisible(true);
        scroll_main_page_->setWidget(tower_info_wiget_);
    }

    //再设置整体布局，不然外部调用该类不显示任何内容
    QVBoxLayout* scroll_layout = new QVBoxLayout(this);
    scroll_layout->addWidget(scroll_main_page_);
    scroll_layout->addStretch();
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

void cyBackStagePages::initTowerInstallInfo()
{
    //ch初始化塔吊安装信息

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

void cyBackStagePages::resizeEvent(QResizeEvent *event)
{
    tower_info_wiget_->resize(550, 4214);
}

