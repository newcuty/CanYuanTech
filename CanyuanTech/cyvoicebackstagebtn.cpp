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


//该类当前问题：图片大小不对；按钮上面需要添加文字
void cyVoiceBackstageBtn::init()
{
    if (!voice_btn_)
    {
        voice_btn_ = new QPushButton(this);
    }
    //设置声音按钮背景图片
    QPixmap pixmapVoice(":/pictures/main_page_pics/voice_button_pic.png");
    voice_btn_->setStyleSheet("border-image:url(:/pictures/main_page_pics/voice_button_pic.png);border:0px");
    voice_btn_->setFixedSize(188, 66);
    //voice_btn_->setText("声音");


    if(!backstage_btn_)
    {
        backstage_btn_ = new QPushButton(this);
    }

    //设置后台按钮背景图片
    QPixmap pixmapBackStage(":/pictures/main_page_pics/back_stage_pic.png");
    backstage_btn_->setStyleSheet("border-image:url(:/pictures/main_page_pics/back_stage_pic.png)");
    backstage_btn_->setFixedSize(120, 66);

    //布局按钮
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->addWidget(voice_btn_);
    hLayout->setSpacing(5);
    hLayout->addWidget(backstage_btn_);

    this->setLayout(hLayout);
}


