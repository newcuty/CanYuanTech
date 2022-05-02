//自定义按钮

#ifndef CYPUSHBUTTON_H
#define CYPUSHBUTTON_H

#include "global.h"

class cyPushButton : public QWidget
{
    Q_OBJECT
public:
    explicit cyPushButton(QWidget *parent = nullptr);
    void init(const QString& icon_path, const QString& info);
    void mousePressEvent(QMouseEvent *ev) override;

private:
    QLabel* icon_button_;    //存放图标的按钮
    QLabel* info_lable_;          //存放信息


signals:
    void sigSendMouseMove();

};

#endif // CYPUSHBUTTON_H
