#include "cybackstagealarmvaluewidget.h"

cyBackStageAlarmValueWidget::cyBackStageAlarmValueWidget()
{
    init();
}

void cyBackStageAlarmValueWidget::init()
{
    alarm_value_top_layout_ = initTopLayout(":/pictures/backstage_icon/alarm_pic.png", "报警阀值");

    cyLineEdit* weight_warning_edit = new cyLineEdit("重量预警", editor_size);
    cyLineEdit* weight_alarm_edit = new cyLineEdit("重量报警", editor_size);
    cyLineEdit* range_near_warning_edit = new cyLineEdit("幅度近端预警", editor_size);
    cyLineEdit* range_near_alarm_edit = new cyLineEdit("幅度近端报警", editor_size);
    cyLineEdit* range_far_warning_edit = new cyLineEdit("幅度远端预警", editor_size);
    cyLineEdit* range_far_alarm_edit = new cyLineEdit("幅度远端报警", editor_size);
    cyLineEdit* rotate_warning_edit = new cyLineEdit("回转预警", editor_size);
    cyLineEdit* rotate_alarm_edit = new cyLineEdit("回转报警", editor_size);
    cyLineEdit* heigth_warning_edit = new cyLineEdit("高度预警", editor_size);
    cyLineEdit* heigth_alarm_edit = new cyLineEdit("高度报警", editor_size);
    cyLineEdit* moment_warning_edit = new cyLineEdit("力矩预警", editor_size);
    cyLineEdit* moment_alarm_edit = new cyLineEdit("力矩报警", editor_size);
    cyLineEdit* wind_warning_edit = new cyLineEdit("风速预警", editor_size);
    cyLineEdit* wind_alarm_edit = new cyLineEdit("风速报警", editor_size);
    cyLineEdit* dip_angle_warning_edit = new cyLineEdit("倾角预警", editor_size);
    cyLineEdit* dip_angle_alarm_edit = new cyLineEdit("倾角报警", editor_size);

    alarm_value_map_["重量预警"] = weight_warning_edit;
    alarm_value_map_["重量报警"] = weight_alarm_edit;
    alarm_value_map_["幅度近端预警"] = range_near_warning_edit;
    alarm_value_map_["幅度近端报警"] = range_near_alarm_edit;
    alarm_value_map_["幅度远端预警"] = range_far_warning_edit;
    alarm_value_map_["幅度远端报警"] = range_far_alarm_edit;
    alarm_value_map_["回转预警"] = rotate_warning_edit;
    alarm_value_map_["回转报警"] = rotate_alarm_edit;
    alarm_value_map_["高度预警"] = heigth_warning_edit;
    alarm_value_map_["高度报警"] = heigth_alarm_edit;
    alarm_value_map_["力矩预警"] = moment_warning_edit;
    alarm_value_map_["力矩报警"] = moment_alarm_edit;
    alarm_value_map_["风速预警"] = wind_warning_edit;
    alarm_value_map_["风速报警"] = wind_alarm_edit;
    alarm_value_map_["倾角预警"] = dip_angle_warning_edit;
    alarm_value_map_["倾角报警"] = dip_angle_alarm_edit;

    QGridLayout* gridlayout = new QGridLayout();
    gridlayout->addWidget(weight_warning_edit, 0,0);
    gridlayout->addWidget(weight_alarm_edit, 0,1);
    gridlayout->addWidget(range_near_warning_edit, 1,0);
    gridlayout->addWidget(range_near_alarm_edit, 1,1);

    gridlayout->addWidget(range_far_warning_edit, 2,0);
    gridlayout->addWidget(range_far_alarm_edit, 2,1);

    gridlayout->addWidget(rotate_warning_edit, 3,0);
    gridlayout->addWidget(rotate_alarm_edit, 3,1);

    gridlayout->addWidget(heigth_warning_edit, 4,0);
    gridlayout->addWidget(heigth_alarm_edit, 4,1);

    gridlayout->addWidget(moment_warning_edit, 5,0);
    gridlayout->addWidget(moment_alarm_edit, 5,1);

    gridlayout->addWidget(wind_warning_edit, 6,0);
    gridlayout->addWidget(wind_alarm_edit, 6,1);

    gridlayout->addWidget(dip_angle_warning_edit, 7,0);
    gridlayout->addWidget(dip_angle_alarm_edit, 7,1);

    alarm_value_main_layout = new QVBoxLayout(this);
    alarm_value_main_layout->addLayout(alarm_value_top_layout_);
    alarm_value_main_layout->addLayout(gridlayout);

}
