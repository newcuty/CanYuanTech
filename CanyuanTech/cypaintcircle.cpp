#include "cypaintcircle.h"

cyPaintCircle::cyPaintCircle(QWidget *parent) : QWidget(parent)
{

}

//重写绘制事件，绘制圆圈
void cyPaintCircle::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::blue,5));
    painter.drawEllipse(10, -15,100,100);
}
