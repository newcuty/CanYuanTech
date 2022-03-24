#include "mainwidget.h"
#include <QTime>

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
      //topwidget(nullptr)
{
    this->setParent(parent);
    this->setGeometry(0, 0, 800, 480);
    this->setMinimumSize(800, 480);

    background_widget = new QWidget(this);
    background_widget->setStyleSheet("border-image:url(:/pictures/main_page_pics/background_pic.png)");

    top_status_widget = new QWidget(this);
    top_status_widget->setGeometry(0, 0, 800, 130);
    top_status_widget->setStyleSheet("border-image:url(:/pictures/main_page_pics/top_widget_background_pic.png)");

    topwidget[0] = new topWidgetElement(this);
    topwidget[0] ->initTopStatusWidget(QString("type"), QString("CY-TW-2"));
    topwidget[0] ->setGeometry(0,0,149,80);

    topwidget[1] = new topWidgetElement(this);
    topwidget[1] ->initTopStatusWidget(QString("ID"), QString("123456789"));
    topwidget[1] ->setGeometry(149, 0,149,80);

    topwidget[2] = new topWidgetElement(this);
    topwidget[2] ->initTopStatusWidget(QString("ICCID"), QString("89765431"));
    topwidget[2] ->setGeometry(298, 0, 149,80);

    QTime time = QTime::currentTime();
    QString str = time.toString("hh:mm:ss");

    topwidget[3] = new topWidgetElement(this);
    topwidget[3] ->initTopStatusWidget(QString("date"), str);
    topwidget[3] ->setGeometry(447, 0, 149, 80);



}

mainWidget::~mainWidget()
{
}

void mainWidget::resizeEvent(QResizeEvent *event)
{
    background_widget->resize(this->size());
    top_status_widget->resize(this->width(), 130);
}

