#include "cyvoicebackstagebtn.h"

cyVoiceBackstageBtn::cyVoiceBackstageBtn(QWidget *parent)
    : QWidget(parent),
      voice_btn_(nullptr),
      backstage_btn_(nullptr)
{

}

cyVoiceBackstageBtn::~cyVoiceBackstageBtn()
{
    if(voice_btn_)
    {
        delete voice_btn_;
        voice_btn_ = nullptr;
    }

    if(backstage_btn_)
    {
        delete voice_btn_;
        voice_btn_ = nullptr;
    }

}

void cyVoiceBackstageBtn::init()
{

    voice_btn_ = new QPushButton(this);

    //设置声音按钮背景图片
    //初始化声音等级为max， 图片对应为最大
    voice_level_ = VOICE_MAX;
    voice_btn_->setStyleSheet("QPushButton{border-image:url(:/pictures/main_page_pics/voice_button_max.png);"
                              "border:0px;"
                              "text-align: right;"
                              "padding-right:20px;"
                              "font-size: 16px;"
                              "color: #FFFFFF;}");
    voice_btn_->setFixedSize(188, 66);
    voice_btn_->setText("声音:开");

    connect(this, &cyVoiceBackstageBtn::sigVoiceLevel, this, &cyVoiceBackstageBtn::slotVoiceChange);
    connect(voice_btn_, &QPushButton::clicked, this,
            [this](){
                if (voice_level_ == VOICE_MAX)
                {
                    voice_level_ = VOLICE_SLIENCE;
                }
                else
                {
                    voice_level_ = VOICE_MAX;
                }
                emit sigVoiceLevel(voice_level_);
            });



    backstage_btn_ = new QPushButton(this);
    //设置后台按钮背景图片
    backstage_btn_->setStyleSheet("QPushButton{ border-image:url(:/pictures/main_page_pics/back_stage_pic.png);"
                                  "text-align: right;"
                                  "padding-right:20px;"
                                  "font-size: 16px;"
                                  "color: #FFFFFF;}");
    backstage_btn_->setFixedSize(120, 66);
    backstage_btn_->setText("后台");

    //布局按钮
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->addWidget(voice_btn_);
    hLayout->setSpacing(15);
    hLayout->addWidget(backstage_btn_);

    this->setLayout(hLayout);
}

void cyVoiceBackstageBtn::slotVoiceChange(cyVoiceBackstageBtn::VOICELEVEL &level)
{
    if (level == VOICE_MAX)
    {
        //修改button 图片为最大
        voice_btn_->setStyleSheet("QPushButton{border-image:url(:/pictures/main_page_pics/voice_button_max.png);"
                                  "border:0px;"
                                  "text-align: right;"
                                  "padding-right:20px;"
                                  "font-size: 16px;"
                                  "color: #FFFFFF;}");
        voice_btn_->setText("声音:开");
    }
    else
    {
        //修改botton 图片为静音
        voice_btn_->setStyleSheet("QPushButton{border-image:url(:/pictures/main_page_pics/voice_button_silence.png);"
                                  "border:0px;"
                                  "text-align: right;"
                                  "padding-right:20px;"
                                  "font-size: 16px;"
                                  "color: #FFFFFF;}");

        voice_btn_->setText("声音:关");
    }
}


