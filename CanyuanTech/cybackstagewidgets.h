
//所有后台组件的基类
#ifndef CYBACKSTAGEWIDGETS_H
#define CYBACKSTAGEWIDGETS_H

#include "global.h"

class cyBackStageWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit cyBackStageWidgets(QWidget *parent = nullptr);

    virtual void init() = 0;

    //初始化顶部控件,顶部控件抽象成图标和文字这一大类
    //将界面分成需要按钮和不需要按钮的两类，默认不需要按钮
    virtual QHBoxLayout* initTopLayout(const QString& icon_path, const QString& title);
    virtual QHBoxLayout* initTopLayout(const QString& icon_path, const QString& title,
                                       QPushButton* button, const QString& button_icon);


signals:

};

#endif // CYBACKSTAGEWIDGETS_H
