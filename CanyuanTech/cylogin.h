//登录界面
#ifndef CYLOGIN_H
#define CYLOGIN_H

#include "global.h"
#include "cypushbutton.h"

class cyLogin : public QWidget
{
    Q_OBJECT
public:
    explicit cyLogin(QWidget *parent = nullptr);
    void init();    //初始化

    QPushButton* getButton(){
        if (!login_button_){
            return nullptr;
        }
        return login_button_;
    };

private:
    //背景界面
    QWidget* background_widget_;    //背景界面
    QLineEdit* account_line_edit_;   //账户编辑框
    QLineEdit* password_line_edit_;  //密码编辑框
    QPushButton* login_button_;     //登录按钮
    cyPushButton* cancle_login_pushButton_;  //取消登录按钮
    cyPushButton* system_reboot_pushbutton_;    //系统重启按钮
    QFrame* splite_line_;   //分割线

    QVBoxLayout* vertical_layout_;  //登录界面主布局
    QHBoxLayout* horzion_button_layout_;    //布局按钮

    //用户账户密码
    QString account_;       //账户
    QString password_;       //密码

private:
    void resizeEvent(QResizeEvent *event);    

public slots:
    void slotCancleLogin(); //取消登录槽函数
    void slotSystemReboot();    //重启系统槽函数
    void slotclearEditor();     //输入框点击之后，清空数据
    void slotGetAccountStr(const QString& account_str);   //获取编辑框的输入的账户信息
    void slotGetPasswordStr(const QString& password_str);   //获取密码框信息
    void slotLogin();

signals:
    void sigVerifySuccess();    //账号密码验证成功信号



};

#endif // CYLOGIN_H
