
//荷载特性表

#ifndef CYBACKSTAGEOVERLOADWIDGET_H
#define CYBACKSTAGEOVERLOADWIDGET_H

#include "cybackstagewidgets.h"
#include <QTableWidget>

class cyBackStageOverloadWidget : public cyBackStageWidgets
{
public:
    cyBackStageOverloadWidget();
    void init();

private:
    //载荷特性表顶部布局
    QHBoxLayout* overload_table_title_layout_;// = new QHBoxLayout();
    //载荷特性表表格主布局
    QVBoxLayout* overload_table_main_layout_;// = new QVBoxLayout();
};

#endif // CYBACKSTAGEOVERLOADWIDGET_H
