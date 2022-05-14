//声音按钮与后台按钮类
#ifndef CYVOICEBACKSTAGEBTN_H
#define CYVOICEBACKSTAGEBTN_H

#include "global.h"

class cyVoiceBackstageBtn : public QWidget
{
    Q_OBJECT
public:
    explicit cyVoiceBackstageBtn(QWidget *parent = nullptr);
    ~cyVoiceBackstageBtn();

    void init(); //初始化按钮
    QPushButton* getBackageBtn(){
        if (!backstage_btn_){
            return nullptr;
        }
        return backstage_btn_;
    }
private:
    QPushButton* voice_btn_;    //声音按钮
    QPushButton* backstage_btn_;    //后台按钮


signals:

};

#endif // CYVOICEBACKSTAGEBTN_H
