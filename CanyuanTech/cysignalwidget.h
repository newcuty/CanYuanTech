//该类用于初始化4G信号与GPS信号控件
//提供一个接口
#ifndef CYSIGNALWIDGET_H
#define CYSIGNALWIDGET_H
#include "global.h"


class cySignalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit cySignalWidget(QWidget *parent = nullptr);
    ~cySignalWidget();

    //初始化控件
    void init(const QString& icon_path, const QString& info);
    //单独设置图片
    void setIcon(const QString& icon_path);
    //单独设置信息
    void setInfo(const QString& info);

private:
    QLabel* icon_label_;    //显示图标标签
    QLabel* info_label_;    //信息标签

signals:

};

#endif // CYSIGNALWIDGET_H
