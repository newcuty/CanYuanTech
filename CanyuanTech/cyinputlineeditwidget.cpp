#include "cyinputlineeditwidget.h"

cyInputLineEditWidget::cyInputLineEditWidget(QWidget *parent) : QWidget(parent)
{
    //构建四个编辑框
    work_number_ = new QLineEdit();
    work_number_->setStyleSheet("QLineEdit{width:100px;"
                                "height:34px;"
                                "border-radius: 11px;"
                                "font-size:15px;"
                                "color:#445975}");
    name_edit_ = new QLineEdit();
    name_edit_->setStyleSheet("QLineEdit{width:100px;"
                                "height:34px;"
                                "border-radius: 11px;"
                                "font-size:15px;"
                                "color:#445975}");
    ID_number_ = new QLineEdit();
    ID_number_->setStyleSheet("QLineEdit{width:100px;"
                                "height:34px;"
                                "border-radius: 11px;"
                                "font-size:15px;"
                                "color:#445975}");
    driver_number = new QLineEdit();
    driver_number->setStyleSheet("QLineEdit{width:100px;"
                                "height:34px;"
                                "border-radius: 11px;"
                                "font-size:15px;"
                                "color:#445975}");

    delete_button = new QPushButton();
    delete_button->setStyleSheet("border-image:url(:/pictures/backstage_icon/del_pic.png;)");
    connect(delete_button, &QPushButton::clicked, this, &cyInputLineEditWidget::slotDeletCurrentWidget);

    main_hlayout_ = new QHBoxLayout(this);
    main_hlayout_->addWidget(work_number_);
    main_hlayout_->addWidget(name_edit_);
    main_hlayout_->addWidget(ID_number_);
    main_hlayout_->addWidget(driver_number);
    main_hlayout_->addWidget(delete_button);
}

//相应删除按钮点击事件
void cyInputLineEditWidget::slotDeletCurrentWidget()
{
    qDebug() << "button clicked \n";
}
