#include "cyswitchbutton.h"
#include <QPainter>
#include <QMouseEvent>

cySwitchButton::cySwitchButton(QWidget *parent)
    :QWidget(parent),
      checked_(false),
      background_color_(QColor(242,242,242)),
      checked_color_(QColor(22,68,128)),
      disabled_colo_(QColor(242,242,242)),
      thumb_color_(QColor(102,102,102)),
      radius_(19.0),
      height_(38),
      margin_(4)
{
    //鼠标滑过光标形状-手型
    setCursor(Qt::PointingHandCursor);

    //连接信号槽
    connect(&timer_,SIGNAL(timeout()),this,SLOT(onTimeout()));
}

void cySwitchButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    QColor background;
    QColor thumbColor;
    qreal dOpacity;
    if(isEnabled()){    //可用状态
        if(checked_){    //打开状态
            background = background_color_;
            thumbColor = checked_color_;
            dOpacity = 0.600;
        }else{      //关闭状态
            background = background_color_;
            thumbColor = thumb_color_;
            dOpacity = 0.800;
        }
    }else{  //不可用状态
        background = background_color_;
        dOpacity = 0.260;
        thumbColor = disabled_colo_;
    }
    //绘制大椭圆
    painter.setBrush(background);
    painter.setOpacity(dOpacity);
    path.addRoundedRect(QRectF(margin_, margin_, width() - 2 * margin_, height() - 2 * margin_), radius_, radius_);
    painter.drawPath(path.simplified());

    //绘制小椭圆
    painter.setBrush(thumbColor);
    painter.setOpacity(1.0);
    painter.drawEllipse(QRectF(nX_ - (height_ / 5), nY_ - (height_ / 3.3), height() / 1.5, height() / 1.5));
}

//鼠标按下事件
void cySwitchButton::mousePressEvent(QMouseEvent *event)
{
    if(isEnabled()){
        if(event -> buttons() & Qt::LeftButton){
            event -> accept();
        }else{
            event -> ignore();
        }
    }
}

//鼠标释放事件-切换开关状态、发射toggled()信号
void cySwitchButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(isEnabled()){
        if((event->type() == QMouseEvent::MouseButtonRelease) && (event->button() == Qt::LeftButton)){
            event->accept();
            checked_ = !checked_;
            emit toggled(checked_);
            timer_.start(10);
        }else{
            event->ignore();
        }
    }
}

//大小改变事件
void cySwitchButton::resizeEvent(QResizeEvent *event)
{
    nX_ = height_ / 2;
    nY_ = height_ / 2;
    QWidget::resizeEvent(event);
}

//默认大小
QSize cySwitchButton::sizeHint() const
{
    return minimumSizeHint();
}

//最小大小
QSize cySwitchButton::minimumSizeHint() const
{
    return QSize(2 * (height_ + margin_),height_ + 2 * margin_);
}

//切换状态-滑动
void cySwitchButton::onTimeout()
{
    if(checked_){
        nX_ += 1;
        if(nX_ >= width() - height_)
            timer_.stop();
    }else{
        nX_ -= 1;
        if(nX_ <= height_ / 2)
            timer_.stop();
    }
    update();
}

//返回开关状态-打开：true 关闭：false
bool cySwitchButton::isToggled() const
{
    return checked_;
}

//设置开关状态
void cySwitchButton::setToggled(bool checked)
{
    checked_ = checked;
    timer_.start(10);
}

//设置背景颜色
void cySwitchButton::setBackgroundColor(QColor color)
{
    background_color_ = color;
}

//设置选中颜色
void cySwitchButton::setCheckedColor(QColor color)
{
    checked_color_ = color;
}

//设置不可用颜色
void cySwitchButton::setDisabledColor(QColor color)
{
    disabled_colo_ = color;
}
