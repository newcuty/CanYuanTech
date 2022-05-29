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
    QPixmap pixmapVoice(":/pictures/main_page_pics/voice_button_pic.png");
    voice_btn_->setStyleSheet("QPushButton{border-image:url(:/pictures/main_page_pics/voice_button_pic.png);"
                              "border:0px;"
                              "text-align: center;"
                              "padding-right:20px;"
                              "font-size: 16px;"
                              "color: #FFFFFF;}");
    voice_btn_->setFixedSize(188, 66);
    voice_btn_->setText("声音");

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


