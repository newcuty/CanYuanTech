#ifndef CYBACKSTAGEINPUTIDWIDGET_H
#define CYBACKSTAGEINPUTIDWIDGET_H

#include "cybackstagewidgets.h"
#include "cyinputlineeditwidget.h"

class cyBackStageInputIDWidget : public cyBackStageWidgets
{
    Q_OBJECT
public:
    cyBackStageInputIDWidget();
    void init();

    QLabel* work_number_label_;
    QLabel* name_label_;
    QLabel* ID_number_label_;
    QLabel* driver_number_label_;

    cyInputLineEditWidget* line_edit_;

    QHBoxLayout* input_ID_top_layout_;
    QHBoxLayout* label_layout_;
    QVBoxLayout* main_layout_;

};

#endif // CYBACKSTAGEINPUTIDWIDGET_H
