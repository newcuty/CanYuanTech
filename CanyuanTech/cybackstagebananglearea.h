//角禁行区
#ifndef CYBACKSTAGEBANANGLEAREA_H
#define CYBACKSTAGEBANANGLEAREA_H

#include "cybackstagewidgets.h"
#include "cylineedit.h"


class cyBackStageBanAngleAreaElement: public QWidget
{
    Q_OBJECT
 public:
    cyBackStageBanAngleAreaElement();
    void setDeleteButtonShow(const bool& isShow);   //是否显示删除按钮，1：显示，0：不显示

private:
    const int editor_size_ = 110;   //编辑框固定大小
    QVector<cyLineEdit*> ban_angle_area_elements_;  //角禁行区元素
    QPushButton* delete_button_;                    //删除按钮

public slots:
    void delete_element();  //删除整个控件
};

class cyBackStageBanAngleArea : public cyBackStageWidgets
{
    Q_OBJECT
public:
    cyBackStageBanAngleArea();
    void init();


private:
    QHBoxLayout* ban_angle_area_top_hlayout_;       //顶部布局
    QVBoxLayout* ban_angle_area_main_vlayout_;      //整体主布局
    QPushButton* add_new_button_;                   //新增按钮

    QVector<cyBackStageBanAngleAreaElement* >elements_vector_;  //角禁行区元素容器


public slots:

    void add_element();
};

#endif // CYBACKSTAGEBANANGLEAREA_H
