#ifndef CYSIGNALWIDGET_H
#define CYSIGNALWIDGET_H

#include <QObject>
#include <QWidget>

class cySignalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit cySignalWidget(QWidget *parent = nullptr);

signals:

};

#endif // CYSIGNALWIDGET_H
