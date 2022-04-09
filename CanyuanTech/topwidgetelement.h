
//this class is for the widget on the top of main widget
#ifndef TOPWIDGETELEMENT_H
#define TOPWIDGETELEMENT_H

#include "global.h"

class topWidgetElement : public QWidget
{
    Q_OBJECT
public:
    explicit topWidgetElement(QWidget *parent = nullptr);


public:
    void init(const QString& name, const QString& info);
    void setInfo(const QString& strInfo);
private:

    QGroupBox* top_status_groupbox_;
    QWidget* contain_icon_widget_;
    QLabel* icon_label_;   //
    QLabel*  type_name_label_;     //
    QLabel*  type_detail_label_;  //
    QGridLayout* gridLayout_;

//    QHBoxLayout* horizon_layout_;
//    QVBoxLayout* vertical_layout_;


signals:

};

#endif // TOPWIDGETELEMENT_H
