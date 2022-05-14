//用于组装文字+文本编辑框的组合控件
#ifndef CYLINEEDIT_H
#define CYLINEEDIT_H

#include "global.h"

class cyLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit cyLineEdit(QWidget *parent = nullptr);
    cyLineEdit(const QString& title, const int& length = 107); //title：选项名称， length：文本编辑框长度

    QString getTitleInfo();
    void setTitleInfo();

private:
    QLabel* title_label_;
    QLineEdit* text_editor_;
    QString title_info_;


signals:

};

#endif // CYLINEEDIT_H