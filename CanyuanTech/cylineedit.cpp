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
    h_layout->addWidget(text_editor_, Qt::AlignRight);

    //文本框内容改变，
    connect(text_editor_, &QLineEdit::textChanged, this, &cyLineEdit::setTitleInfo);
}

QString cyLineEdit::getTitleInfo()
{
    return input_str;
}

//清空文本框内容
void cyLineEdit::clearText()
{
    text_editor_->clear();
    input_str = "";
}

void cyLineEdit::setTitleInfo(const QString &str_text)
{
    //获取输入的文本框
    input_str = str_text;
}
