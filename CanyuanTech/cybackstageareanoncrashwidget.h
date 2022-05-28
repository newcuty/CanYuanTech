//区域防碰撞组件， 由三部分组成 角禁行区
#ifndef CYBACKSTAGEAREANONCRASHWIDGET_H
#define CYBACKSTAGEAREANONCRASHWIDGET_H

#include "cybackstagewidgets.h"
#include "cybackstagebananglearea.h"
#include "cybackstagebancirclearea.h"
#include "cybackstagebansquarearea.h"

class cyBackStageAreaNonCrashWidget : public cyBackStageWidgets
{
    Q_OBJECT
public:
    cyBackStageAreaNonCrashWidget();
    void init();

private:
    cyBackStageBanAngleArea* ban_angle_area_widget_;   //角禁行区
    cyBackStageBanCircleArea* ban_circle_area_widget_;  //圆形禁行区
    cyBackStageBanSquareArea* ban_square_area_widget_;  //四边形区域

    QHBoxLayout* area_non_crash_top_hlayout_;   //顶部布局
    QVBoxLayout* area_non_crash_main_vlayout_;  //主布局


};

#endif // CYBACKSTAGEAREANONCRASHWIDGET_H
