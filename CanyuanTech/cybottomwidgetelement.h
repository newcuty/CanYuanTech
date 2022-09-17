#ifndef CYBOTTOMWIDGETELEMENT_H
#define CYBOTTOMWIDGETELEMENT_H

#include "global.h"

class cyBottomWidgetElement : public QWidget
{
    Q_OBJECT
public:
    explicit cyBottomWidgetElement(QWidget *parent = nullptr);

    //初始化控件
    void init(const QString& icon_path, const QString& info);
    //构建
    void init(const QString& icon_path, const QString& info,
              const QString& second_row_info1, const QString& second_row_info2);

    //设置第二行数据
//    void setSecondRowData(const QString& data);
//    void setSecondRowDatas(const QString& data1, const QString& data2);

    void setSecondRowData(const float& data);
    void setSecondRowDatas(const float& data1, const float& data2);

    //设置第三行数据  arg:从底层采集到的数据，经过转换之后，只保留一位小数
    void setThirdRowData(const float& data_percentage);
    void setThirdRowDatas(const float& data_percentage1, const float& data_percentage2);

    //设置字体颜色，用于报警 level 使用ALARMLAVEL
    QString setDataAlarmConlor(QString& str, int level);

private:
    QLabel* icon_label_;    //显示图标
    QLabel* info_label_;    //信息

    QLabel* data_row_2_;   //第二行的数据标签
    QLabel* data_row_3_;    //第三行的数据标签

    //针对于第二行没有数据，不使用
    QLabel* second_row_name_2_1_;  //第二行第一个标题标签
    QLabel* data_row_label_2_1_;  //第二行第一个数据标签
    QLabel* second_row_name_2_2_;  //第二行第二个标题标签
    QLabel* data_row_label_2_2_;  //第二行第二个数据标签

    //第三行数据标签
    QLabel* data_row_label_3_1_;  //第三行第一个数据标签
    QLabel* data_row_label_3_2_;  //第三行第二个数据标签

    //第二行的实际数据
    QString second_row_data_1_;          //如果第二行只有一个数据，只使用整一个
    QString second_row_data_2_;

    //第三行的实际数据
    QString third_row_data_1_;  //第三行第一个实际数据， 只有一个数据时只使用这一个
    QString third_row_data_2_;  //第三行第二个实际数据

    //固定间距
    const int second_row_spacing_ = 20;

    //报警等级，正常0，预警-1，报警-2  //实际逻辑中，放到global.h中
    enum ALARMLAVEL{NORMAL = 0, PREALARM = -1, ALARM = -2};


signals:
    //发送报警信息 alarm_name： 报警部分，level报警级别
    void sigAlarm(const QString& alarm_name, const ALARMLAVEL& level);
public slots:
    //获取数据接口,后续传输需要
    void getStaus(float&){};
};

#endif // CYBOTTOMWIDGETELEMENT_H
