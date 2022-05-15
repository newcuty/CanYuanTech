#include "cybackstagewidgets.h"

cyBackStageWidgets::cyBackStageWidgets(QWidget *parent) : QWidget(parent)
{

}

QHBoxLayout *cyBackStageWidgets::initTopLayout(const QString &icon_path, const QString &title)

{
    //顶部布局
    QHBoxLayout* return_layout = new QHBoxLayout();
    //图标与文字
    QLabel* icon_label = new QLabel();
    icon_label->setPixmap(icon_path);
    QLabel* text_label = new QLabel();
    text_label->setStyleSheet("font-size:16px;color:#2A84FF;");
    text_label->setText(title);

    return_layout->addWidget(icon_label);
    return_layout->addWidget(text_label);
    return_layout->addStretch();

    return return_layout;
}

QHBoxLayout *cyBackStageWidgets::initTopLayout(const QString &icon_path, const QString &title,
                                               QPushButton *button, const QString &button_name,
                                               const QString& button_icon)
{
    //顶部布局
    QHBoxLayout* return_layout = new QHBoxLayout();
    //图标与文字
    QLabel* icon_label = new QLabel();
    icon_label->setPixmap(icon_path);
    QLabel* text_label = new QLabel();
    text_label->setStyleSheet("font-size:16px;color:#2A84FF;");
    text_label->setText(title);

    button = new QPushButton();
    QString styleSheet("border-image:url(");
    styleSheet += button_icon;
    styleSheet += (");");

    button->setStyleSheet(styleSheet);

    return_layout->addWidget(icon_label);
    return_layout->addWidget(text_label);
    return_layout->addStretch();
    return_layout->addWidget(button);

    return return_layout;

}
