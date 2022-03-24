#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "topwidgetelement.h"

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
    topWidgetElement* topwidget[4];
    QWidget* background_widget;
    QWidget* top_status_widget;

    /* 重设大小 */
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWIDGET_H
