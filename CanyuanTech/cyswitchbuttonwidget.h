#ifndef CYSWITCHBUTTONWIDGET_H
#define CYSWITCHBUTTONWIDGET_H

#include "global.h"
#include "cyswitchbutton.h"

class cySwitchButtonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit cySwitchButtonWidget(const QString& button_name);
    bool getSwitchButtonState();

private:
    QLabel* button_label_;      //控件名字
    QPushButton* button_body_;  //按钮主体
    bool is_clicked;    //是否被点击

private slots:
    void changeButtonImage();
    //cySwitchButton* button_body_;   //控件主体

signals:

};

#endif // CYSWITCHBUTTONWIDGET_H
