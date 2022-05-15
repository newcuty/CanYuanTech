
//后台塔吊信息
#ifndef CYBACKSTAGETOWERINFO_H
#define CYBACKSTAGETOWERINFO_H

#include "cybackstagewidgets.h"
#include "cylineedit.h"

class cyBackStageTowerInfo : public cyBackStageWidgets
{
    Q_OBJECT
public:
    cyBackStageTowerInfo();
    void init();

private:
    QVBoxLayout* tower_info_main_layout_;   //主布局
    QHBoxLayout* tower_info_title_layout_;  //顶部布局
    QMap<QString, QVector<cyLineEdit*>> tower_info_map_; //存放塔机具体信息

    const int editor_size_1 = 175;
};

#endif // CYBACKSTAGETOWERINFO_H
