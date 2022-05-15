#include "cybackstagedatasetwidget.h"

cyBackStageDataSetWidget::cyBackStageDataSetWidget()
{
    init();
}

void cyBackStageDataSetWidget::init()
{
    main_layout_ = new QVBoxLayout(this);

    data_standard_top_layout_ = initTopLayout(":/pictures/backstage_icon/data_standard_pic.png", "数据标定");
    main_layout_->addLayout(data_standard_top_layout_);

    //重量布局开始
    weight_standard_top_layout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "重量标定");

    //重量编辑框布局
    weight_edit_layout_ = new QHBoxLayout();
    cyLineEdit* weight_volite_edit = new cyLineEdit("实时电压", editor_size_);
    cyLineEdit* weight_edit1 = new cyLineEdit("实际重量1", editor_size_);
    cyLineEdit* weight_edit2 = new cyLineEdit("实际重量2", editor_size_);
    weight_edit_layout_->addWidget(weight_volite_edit);
    weight_edit_layout_->addWidget(weight_edit1);
    weight_edit_layout_->addWidget(weight_edit2);

    weight_standard_map_["实时电压"] = weight_volite_edit;
    weight_standard_map_["实际重量1"] = weight_edit1;
    weight_standard_map_["实际重量2"] = weight_edit2;

    //重量标定主布局
    weight_main_layout_ = new QVBoxLayout();
    weight_main_layout_->addLayout(weight_standard_top_layout_);
    weight_main_layout_->addLayout(weight_edit_layout_);

    main_layout_->addLayout(weight_main_layout_);
    //重量布局结束

/////////////////////////////////////////////////////////////////////////

    //幅度标定布局开始
    range_standard_top_layout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "幅度标定");

    //幅度编辑框布局
    range_edit_layout_ = new QHBoxLayout();
    cyLineEdit* range_volite_edit = new cyLineEdit("实时电压", editor_size_);
    cyLineEdit* range_edit1 = new cyLineEdit("实际幅度1", editor_size_);
    cyLineEdit* range_edit2 = new cyLineEdit("实际幅度2", editor_size_);
    range_edit_layout_->addWidget(range_volite_edit);
    range_edit_layout_->addWidget(range_edit1);
    range_edit_layout_->addWidget(range_edit2);

    range_standard_map_["实时电压"] = range_volite_edit;
    range_standard_map_["实际幅度1"] = range_edit1;
    range_standard_map_["实际幅度2"] = range_edit2;

    range_main_layout_ = new QVBoxLayout();
    //幅度标定主布局
    range_main_layout_->addLayout(range_standard_top_layout_);
    range_main_layout_->addLayout(range_edit_layout_);
    main_layout_->addLayout(range_main_layout_);
    //幅度标定布局结束

//////////////////////////////////////////////////////////////////////////////
    //高度标定布局开始
    heigth_standard_top_layout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "高度标定");

    //高度编辑框布局
    heigth_edit_layout_ = new QHBoxLayout();
    cyLineEdit* heigth_volite_edit = new cyLineEdit("实时电压", editor_size_);
    cyLineEdit* heigth_edit1 = new cyLineEdit("实际高度1", editor_size_);
    cyLineEdit* heigth_edit2 = new cyLineEdit("实际高度2", editor_size_);
    heigth_edit_layout_->addWidget(heigth_volite_edit);
    heigth_edit_layout_->addWidget(heigth_edit1);
    heigth_edit_layout_->addWidget(heigth_edit2);

    heigth_standard_map_["实时电压"] = heigth_volite_edit;
    heigth_standard_map_["实际高度1"] = heigth_edit1;
    heigth_standard_map_["实际高度2"] = heigth_edit2;

    heigth_main_layout_ = new QVBoxLayout();
    //高度标定主布局
    heigth_main_layout_->addLayout(heigth_standard_top_layout_);
    heigth_main_layout_->addLayout(heigth_edit_layout_);

    main_layout_->addLayout(heigth_main_layout_);
    //高度标定布局结束
/////////////////////////////////////////////////////

    //回转标定开始
    rotate_standard_top_layout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "回转标定");

    //回转编辑框布局
    rotate_edit_layout_ = new QHBoxLayout();
    cyLineEdit* rotate_volite_edit = new cyLineEdit("实时电压", editor_size_);
    cyLineEdit* rotate_edit1 = new cyLineEdit("实际回转1", editor_size_);
    cyLineEdit* rotate_edit2 = new cyLineEdit("实际回转2", editor_size_);
    rotate_edit_layout_->addWidget(rotate_volite_edit);
    rotate_edit_layout_->addWidget(rotate_edit1);
    rotate_edit_layout_->addWidget(rotate_edit2);

    rotate_standard_map_["实时电压"] = rotate_volite_edit;
    rotate_standard_map_["实际高度1"] = rotate_edit1;
    rotate_standard_map_["实际高度2"] = rotate_edit2;

    rotate_main_layout_ = new QVBoxLayout();
    //回转标定主布局
    rotate_main_layout_->addLayout(rotate_standard_top_layout_);
    rotate_main_layout_->addLayout(rotate_edit_layout_);

    main_layout_->addLayout(rotate_main_layout_);
    //回转标定结束

 /////////////////////////////

    //倾角标定开始
    dip_angle_standard_top_layout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "倾角标定");

    //倾角编辑框布局
    dip_angle_edit_layout_ = new QHBoxLayout();
    cyLineEdit* dip_angle_volite_edit = new cyLineEdit("原始倾角", editor_size_);
    cyLineEdit* dip_angle_edit1 = new cyLineEdit("实际倾角X", editor_size_);
    cyLineEdit* dip_angle_edit2 = new cyLineEdit("实际倾角Y", editor_size_);
    dip_angle_edit_layout_->addWidget(dip_angle_volite_edit);
    dip_angle_edit_layout_->addWidget(dip_angle_edit1);
    dip_angle_edit_layout_->addWidget(dip_angle_edit2);

    dip_angle_standard_map_["实时电压"] = dip_angle_volite_edit;
    dip_angle_standard_map_["实际倾角X"] = dip_angle_edit1;
    dip_angle_standard_map_["实际倾角Y"] = dip_angle_edit2;

    //倾角标定主布局
    dip_angle_main_layout_ = new QVBoxLayout();
    dip_angle_main_layout_->addLayout(dip_angle_standard_top_layout_);
    dip_angle_main_layout_->addLayout(dip_angle_edit_layout_);

    main_layout_->addLayout(dip_angle_main_layout_);
    //倾角标定结束
///////////////////////////////////////////

    //吊钩可视化布局开始
    hook_standard_top_layout_ = initTopLayout(":/pictures/backstage_icon/dot_pic.png", "吊钩可视化");

    //吊钩编辑框布局
    hook_edit_layout_ = new QHBoxLayout();
    hook_editdot_layout_ = new QHBoxLayout();

    cyLineEdit* hook_longtitude_edit = new cyLineEdit("实时经度", editor_size_);
    cyLineEdit* hook_latitude_edit1 = new cyLineEdit("实时纬度", editor_size_);
    cyLineEdit* hook_times_edit2 = new cyLineEdit("实时变倍", editor_size_);
    cyLineEdit* hook_dot1_edit2 = new cyLineEdit("点位1", editor_hook_size);
    cyLineEdit* hook_dot2_edit2 = new cyLineEdit("点位2", editor_hook_size);

    hook_edit_layout_->addWidget(hook_longtitude_edit);
    hook_edit_layout_->addWidget(hook_latitude_edit1);
    hook_edit_layout_->addWidget(hook_times_edit2);
    hook_editdot_layout_->addWidget(hook_dot1_edit2);
    hook_editdot_layout_->addWidget(hook_dot2_edit2);

    hook_standard_map_["实时经度"] = hook_longtitude_edit;
    hook_standard_map_["实时纬度"] = hook_latitude_edit1;
    hook_standard_map_["实时变倍"] = hook_times_edit2;
    hook_standard_map_["点位1"] = hook_dot1_edit2;
    hook_standard_map_["点位2"] = hook_dot2_edit2;

    //倾角标定主布局
    hook_main_layout_ = new QVBoxLayout();
    hook_main_layout_->addLayout(hook_standard_top_layout_);
    hook_main_layout_->addLayout(hook_edit_layout_);
    hook_main_layout_->addLayout(hook_editdot_layout_);

    main_layout_->addLayout(hook_main_layout_);
    //吊钩可视化布局结束

}
