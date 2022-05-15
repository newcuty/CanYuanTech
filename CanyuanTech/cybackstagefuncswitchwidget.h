
//功能按钮开关组件
#ifndef CYBACKSTAGEFUNCSWITCHWIDGET_H
#define CYBACKSTAGEFUNCSWITCHWIDGET_H

#include "cybackstagewidgets.h"
#include "cyswitchbuttonwidget.h"

class cyBackStageFuncSwitchWidget : public cyBackStageWidgets
{
public:
    cyBackStageFuncSwitchWidget();
    void init();

private:
    QVBoxLayout* switch_main_layout_;//= new QVBoxLayout();
     QHBoxLayout* switch_top_layout_;
    QVector<cySwitchButtonWidget*> switch_button_vector_;


};

#endif // CYBACKSTAGEFUNCSWITCHWIDGET_H
