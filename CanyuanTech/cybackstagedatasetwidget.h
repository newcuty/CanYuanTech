#ifndef CYBACKSTAGEDATASETWIDGET_H
#define CYBACKSTAGEDATASETWIDGET_H

#include "cybackstagewidgets.h"
#include "cylineedit.h"

class cyBackStageDataSetWidget : public cyBackStageWidgets
{
    Q_OBJECT
public:
    cyBackStageDataSetWidget();
    void init();

private:
    QVBoxLayout* main_layout_;      //主布局
    QHBoxLayout* data_standard_top_layout_; //

    QHBoxLayout* weight_standard_top_layout_; //重量标定布局
    QHBoxLayout* weight_edit_layout_;    //重量编辑框布局
    QVBoxLayout* weight_main_layout_;    //重量主布局

    QHBoxLayout* range_standard_top_layout_;  //幅度标定顶部布局
    QHBoxLayout* range_edit_layout_;    //幅度编辑框布局
    QVBoxLayout* range_main_layout_;     //幅度主布局

    QHBoxLayout* heigth_standard_top_layout_;  //高度标定顶部布局
    QHBoxLayout* heigth_edit_layout_;    //高度编辑框布局
    QVBoxLayout* heigth_main_layout_;    //高度主布局

    QHBoxLayout* rotate_standard_top_layout_;  //回转标定顶部布局
    QHBoxLayout* rotate_edit_layout_;    //回转编辑框布局
    QVBoxLayout* rotate_main_layout_;    //回转布局


    QHBoxLayout* dip_angle_standard_top_layout_;  //倾角标定布局
    QHBoxLayout* dip_angle_edit_layout_;    //倾角编辑框布局
    QVBoxLayout* dip_angle_main_layout_; //倾角布局


    QHBoxLayout* hook_standard_top_layout_;  //挂钩标定布局
    QHBoxLayout* hook_edit_layout_;    //挂钩编辑框布局
    QHBoxLayout* hook_editdot_layout_;   //点位编辑狂
    QVBoxLayout* hook_main_layout_;      //吊钩可视化布局

    QMap<QString , cyLineEdit*> weight_standard_map_;       //重量编辑框
    QMap<QString , cyLineEdit*> range_standard_map_;        //幅度编辑框
    QMap<QString , cyLineEdit*> heigth_standard_map_;       //高度编辑框
    QMap<QString , cyLineEdit*> rotate_standard_map_;       //回转编辑框
    QMap<QString , cyLineEdit*> dip_angle_standard_map_;    //倾角编辑框
    QMap<QString , cyLineEdit*> hook_standard_map_;         //吊钩可视化编辑框

    const int editor_size_ = 90;
    const int editor_hook_size = 186;
};

#endif // CYBACKSTAGEDATASETWIDGET_H
