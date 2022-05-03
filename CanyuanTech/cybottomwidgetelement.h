#ifndef CYBOTTOMWIDGETELEMENT_H
#define CYBOTTOMWIDGETELEMENT_H

#include "global.h"

class cyBottomWidgetElement : public QWidget
{
    Q_OBJECT
public:
    explicit cyBottomWidgetElement(QWidget *parent = nullptr);

    //初始化控件
    void init(const QString& icon_path, const QString& info);

private:
    QLabel* icon_label_;    //显示图标
    QLabel* info_label_;    //信息

    QLabel* data_row_2_;   //第二行的数据
    QLabel* data_row_3_;    //第三行的数据



signals:

};

#endif // CYBOTTOMWIDGETELEMENT_H
