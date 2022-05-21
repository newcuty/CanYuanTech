#ifndef CYBACKSTAGEBANSQUAREAREA_H
#define CYBACKSTAGEBANSQUAREAREA_H

#include "cybackstagewidgets.h"
#include "cylineedit.h"

class cyBackStageBanSquareAreaElement: public QWidget
{
    Q_OBJECT
 public:
    cyBackStageBanSquareAreaElement();
    void setDeleteButtonShow(const bool& isShow);   //是否显示删除按钮，1：显示，0：不显示

private:
    const int editor_size_ = 110;   //编辑框固定大小
    QVector<cyLineEdit*> ban_square_area_elements_;  //四边形禁行区元素
    QPushButton* delete_button_;                    //删除按钮

public slots:
    void delete_element();  //删除整个控件
};

class cyBackStageBanSquareArea : public cyBackStageWidgets
{
    Q_OBJECT
public:
    cyBackStageBanSquareArea();
    void init();

private:
    QHBoxLayout* ban_square_area_top_hlayout_;       //顶部布局
    QVBoxLayout* ban_square_area_main_vlayout_;      //整体主布局
    QPushButton* add_new_button_;                   //新增按钮

    QVector<cyBackStageBanSquareAreaElement* > elements_vector_;  //四边形禁行区元素容器


public slots:
    void add_element();

};

#endif // CYBACKSTAGEBANSQUAREAREA_H
