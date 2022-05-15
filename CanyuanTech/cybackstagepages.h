//显示

#ifndef CYBACKSTAGEPAGES_H
#define CYBACKSTAGEPAGES_H

#include "global.h"
#include "cylineedit.h"
#include "cyswitchbuttonwidget.h"
#include "cybackstagetowerinfo.h"
#include "cybackstageoverloadwidget.h"
#include "cybackstagetowerinstallinfowidget.h"
#include "cybackstagefuncswitchwidget.h"
#include "cybackstagesystemsettingswidget.h"
#include "cybackstagedatasetwidget.h"
#include "cybackstagealarmvaluewidget.h"
#include "cybackstageinputidwidget.h"

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
    void initSystemSettings();
    void initDataStandard();
    void initAlarmValue();
    void initInputID();

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
    cyBackStageTowerInfo* tower_info_widget_;   //塔机安装信息组件
    cyBackStageOverloadWidget* overload_widget_;    //荷载特性表组件
    cyBackStageTowerInstallInfoWidget* tower_install_info_widget_;  //塔吊安装信息组件
    cyBackStageFuncSwitchWidget* func_switch_widget_;       //功能按钮组件
    cyBackStageSystemSettingsWidget* system_settings_widget_;   //系统设置组件
    cyBackStageDataSetWidget* data_standard_widget_;    //数据标定组件
    cyBackStageAlarmValueWidget* alarm_value_widget_;   //报警阀值组件
    cyBackStageInputIDWidget* input_ID_widget_;     //身份录入组件



signals:

public:
     void resizeEvent(QResizeEvent *event);
};

#endif // CYBACKSTAGEPAGES_H
