#ifndef CYBACKSTAGESYSTEMSETTINGSWIDGET_H
#define CYBACKSTAGESYSTEMSETTINGSWIDGET_H

#include "cybackstagewidgets.h"
#include "cylineedit.h"

class cyBackStageSystemSettingsWidget : public cyBackStageWidgets
{
    Q_OBJECT

public:
    cyBackStageSystemSettingsWidget();
    void init();

private:
    QHBoxLayout* system_settings_top_layout_;
    QVBoxLayout* system_settings_main_layout_;
    QMap<QString, cyLineEdit*> system_info_map_;;

    QPushButton* lookup_history_button_;
    const int line_edit_size_ = 160;
};

#endif // CYBACKSTAGESYSTEMSETTINGSWIDGET_H
