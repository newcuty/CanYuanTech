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

    enum VOICELEVEL{VOLICE_SLIENCE = 0, VOICE_MAX = 255, VOICE_LEVEL_1 = 1};    //声音预留

    VOICELEVEL voice_level_;   //声音等级
signals:
    void sigVoiceLevel(VOICELEVEL& level);   //发送声音等级信号改变

public slots:
    void slotVoiceChange(VOICELEVEL& level);       //处理声音改变


};

#endif // CYVOICEBACKSTAGEBTN_H
