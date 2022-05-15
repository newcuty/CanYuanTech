#ifndef CYBACKSTAGEALARMVALUEWIDGET_H
#define CYBACKSTAGEALARMVALUEWIDGET_H

#include "cybackstagewidgets.h"
#include "cylineedit.h"

class cyBackStageAlarmValueWidget : public cyBackStageWidgets
{
    Q_OBJECT
public:
    cyBackStageAlarmValueWidget();
    void init();

private:
    QHBoxLayout* alarm_value_top_layout_;   //报警阀值顶部布局
    QVBoxLayout* alarm_value_main_layout;   //主布局

    QMap<QString, cyLineEdit*> alarm_value_map_;    //预警值
    const int editor_size = 130;
};

#endif // CYBACKSTAGEALARMVALUEWIDGET_H
