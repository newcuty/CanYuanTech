//定义需要包含的头文件，其他类只需要调用这一个头文件就行
#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QFile>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMutex>
#include <QDateTime>
#include <QTextStream>
#include <QPushButton>
#include <QPainter>
#include <QLineEdit>
#include <QScrollArea>


#include <QLine>
#include <QGroupBox>
#include <stdio.h>
#include <stdlib.h>

//堆栈控件容器枚举
enum enum_current_widget{
    CY_LOGIN,       //登录界面
    CY_USERINFO,    //用户信息
    CY_SETTINGS     //设置界面
};

enum enum_backstage_widget{
    CY_EDIT = 3,       //一般编辑界面
    CY_SWITCH = 4,    //开关界面
    CY_FORM = 5     //表格编辑界面
};




#endif // GLOBAL_H
