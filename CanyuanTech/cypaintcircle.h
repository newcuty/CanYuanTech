//绘制圆圈类
#ifndef CYPAINTCIRCLE_H
#define CYPAINTCIRCLE_H

#include "global.h"

class cyPaintCircle : public QWidget
{
    Q_OBJECT
public:
    explicit cyPaintCircle(QWidget *parent = nullptr);

    void paintCircle();

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // CYPAINTCIRCLE_H
