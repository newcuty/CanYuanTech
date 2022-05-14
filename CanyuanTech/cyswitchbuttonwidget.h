#ifndef CYSWITCHBUTTONWIDGET_H
#define CYSWITCHBUTTONWIDGET_H

#include "global.h"
#include "cyswitchbutton.h"

class cySwitchButtonWidget : public QWidget
{
    Q_OBJECT
public:
    //explicit cySwitchButtonWidget(QWidget *parent = nullptr);
    explicit cySwitchButtonWidget(const QString& button_name);

private:
    QLabel* button_label_;      //控件名字
    cySwitchButton* button_body_;   //控件主体

signals:

};

#endif // CYSWITCHBUTTONWIDGET_H
