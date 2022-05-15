#include "cybackstageoverloadwidget.h"

cyBackStageOverloadWidget::cyBackStageOverloadWidget()
{
    init();
}

void cyBackStageOverloadWidget::init()
{
    overload_table_title_layout_ =
            initTopLayout(":/pictures/backstage_icon/tower_load_pic.png", "荷载特性表");
    overload_table_main_layout_ = new QVBoxLayout(this);

    QTableWidget* overload_table = new QTableWidget();

    //添加表头
    QStringList header;
    header << "幅度/m" << "重量/t";
    overload_table->setVerticalHeaderLabels(header);
    overload_table->show();

    QVBoxLayout* table_layout = new QVBoxLayout();
    table_layout->addWidget(overload_table);


    overload_table_main_layout_->addLayout(overload_table_title_layout_);
    overload_table_main_layout_->addLayout(table_layout);
}
