//显示

#ifndef CYBACKSTAGEPAGES_H
#define CYBACKSTAGEPAGES_H

#include "global.h"
#include "cylineedit.h"
#include "cyswitchbuttonwidget.h"

class cyBackStagePages : public QWidget
{
    Q_OBJECT
public:
    explicit cyBackStagePages(QWidget *parent = nullptr);

    void initTowerInfoLayout();
    void initOverloadTable();
    void addTips(const QString& info);
    void initTowerInstallInfo();
    void addSplite();
    void initFuntionSwitch();

    void initMainLayout();

private:
    QHBoxLayout* initTopLayout(const QString& icon_path, const QString& title);

private:
//    QWidget* background_widget; //背景图片
    QVBoxLayout* main_layout_;      //主布局，用于防止所有滑动布局控件
    QScrollArea* scroll_main_page_; //滑动界面

    //塔机信息选项卡
    QWidget* tower_info_wiget_; //塔机信息控件
    QMap<QString, QVector<cyLineEdit*>> tower_info_map_; //存放塔机具体信息
    QVector<cySwitchButtonWidget*> switch_button_vector_;   //

    //塔机安装信息
    //QWidget* tower_install_info_widget_;    //塔机安装信息控件


signals:

public:
     void resizeEvent(QResizeEvent *event);
};

#endif // CYBACKSTAGEPAGES_H
