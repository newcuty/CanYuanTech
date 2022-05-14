#ifndef CYSWITCHBUTTON_H
#define CYSWITCHBUTTON_H

#include <QWidget>
#include <QTimer>

class cySwitchButton : public QWidget
{
    Q_OBJECT
public:
    explicit cySwitchButton(QWidget *parent = nullptr);

    //返回开关状态-打开：true 关闭：false
    bool isToggled() const;

    //设置开关状态
    void setToggled(bool checked);

    //设置背景颜色
    void setBackgroundColor(QColor color);

    //设置选中颜色
    void setCheckedColor(QColor color);

    //设置不可用颜色
    void setDisabledColor(QColor color);

protected:
    //绘制开关
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    //鼠标释放事件-切换开关状态、发射toggled()信号
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    //大小改变事件
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

    //缺省大小
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

signals:
    //状态改变时，发射信号
    void toggled(bool checked);

private slots:
    //状态切换时，用于产生滑动效果
    void onTimeout();

private:
    bool checked_;            //是否选中
    QColor background_color_;        //背景颜色
    QColor checked_color_;      //选中颜色
    QColor disabled_colo_;     //不可用颜色
    QColor thumb_color_;        //拇指颜色
    qreal radius_;             //圆角
    qreal nX_;                 //x点坐标
    qreal nY_;                 //y点坐标
    qint16 height_;           //高度
    qint16 margin_;           //外边距
    QTimer timer_;             //定时器


signals:

};

#endif // CYSWITCHBUTTON_H
