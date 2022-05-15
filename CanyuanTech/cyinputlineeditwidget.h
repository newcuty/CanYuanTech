#ifndef CYINPUTLINEEDITWIDGET_H
#define CYINPUTLINEEDITWIDGET_H

#include "global.h"

class cyInputLineEditWidget : public QWidget
{
    Q_OBJECT
public:
    explicit cyInputLineEditWidget(QWidget *parent = nullptr);

private:
    QHBoxLayout* main_hlayout_;
    QLineEdit* work_number_;  //工号编辑框
    QLineEdit* name_edit_;  //姓名编辑框
    QLineEdit* ID_number_;  //身份证号编辑框
    QLineEdit* driver_number;   //驾驶证

    QPushButton* delete_button;

signals:

private slots:
    void slotDeletCurrentWidget();

};

#endif // CYINPUTLINEEDITWIDGET_H
