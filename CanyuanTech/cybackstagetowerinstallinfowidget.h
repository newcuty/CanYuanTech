//塔吊安装信息

#ifndef CYBACKSTAGETOWERINSTALLINFOWIDGET_H
#define CYBACKSTAGETOWERINSTALLINFOWIDGET_H

#include "cybackstagewidgets.h"
#include "cylineedit.h"

class cyBackStageTowerInstallInfoWidget : public cyBackStageWidgets
{
public:
    cyBackStageTowerInstallInfoWidget();

    void init();

private:
    //塔吊安装信息顶部布局
    QHBoxLayout* tower_install_info_title_layout_;
    //塔吊安装信息主布局
    QVBoxLayout* tower_install_info_main_layout_;

    const int editor_size_2 = 159;

    QMap<QString, QVector<cyLineEdit*>> tower_install_info_map_; //存放塔机具体信息
};

#endif // CYBACKSTAGETOWERINSTALLINFOWIDGET_H
