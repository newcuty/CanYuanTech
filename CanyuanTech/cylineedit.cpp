#include "cylineedit.h"

const int textEditorHeight = 34;
cyLineEdit::cyLineEdit(QWidget *parent) : QWidget(parent)
{

}

cyLineEdit::cyLineEdit(const QString &title, const int& length)
{
    title_label_ = new QLabel();
    title_label_->setStyleSheet("QLabel{width:40px;"
                                "height:21px;"
                                "font-size:15px;"
                                "color:#445975}");
    title_label_->setText(title);

    text_editor_ = new QLineEdit();
    text_editor_->setMaximumSize(length, textEditorHeight); //设置文本编辑框的大小
    text_editor_->setStyleSheet("QLineEdit{background: #E5ECF6;border-radius: 11px;}");

    //设置布局
    QHBoxLayout* h_layout = new QHBoxLayout(this);
    h_layout->addWidget(title_label_);
    h_layout->addWidget(text_editor_);

    connect(text_editor_, &QLineEdit::returnPressed, this, &cyLineEdit::setTitleInfo);
}

QString cyLineEdit::getTitleInfo()
{

    return QString("");
}

void cyLineEdit::setTitleInfo()
{
    //text_editor_->setText(info);
}
