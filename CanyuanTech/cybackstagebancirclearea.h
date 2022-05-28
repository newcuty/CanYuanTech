
//圆形禁行区

#ifndef CYBACKSTAGEBANCIRCLEAREA_H
#define CYBACKSTAGEBANCIRCLEAREA_H

#include "cybackstagewidgets.h"
#include "cylineedit.h"

class cyBackStageBanCircleAreaElement: public QWidget
{
    Q_OBJECT
 public:
    cyBackStageBanCircleAreaElement();
    void setDeleteButtonShow(const bool& isShow);   //是否显示删除按钮，1：显示，0：不显示

private:
    const int editor_size_ = 75;   //编辑框固定大小
    QVector<cyLineEdit*> ban_circle_area_elements_;  //圆形禁行区元素
    QPushButton* delete_button_;                    //删除按钮

public slots:
    void delete_element();  //删除整个控件
};

class cyBackStageBanCircleArea : public cyBackStageWidgets
{
    Q_OBJECT
public:
    cyBackStageBanCircleArea();
    void init();

private:
    QHBoxLayout* ban_circle_area_top_hlayout_;       //顶部布局
    QVBoxLayout* ban_circle_area_main_vlayout_;      //整体主布局
    QPushButton* add_new_button_;                   //新增按钮

    QVector<cyBackStageBanCircleAreaElement* > elements_vector_;  //圆形禁行区元素容器


public slots:
    void add_element();
};

#endif // CYBACKSTAGEBANCIRCLEAREA_H
