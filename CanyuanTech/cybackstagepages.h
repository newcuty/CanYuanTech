#ifndef CYBACKSTAGEPAGES_H
#define CYBACKSTAGEPAGES_H

#include "global.h"

class cyBackStagePages : public QWidget
{
    Q_OBJECT
public:
    explicit cyBackStagePages(QWidget *parent = nullptr);

private:
    QWidget* background_widget; //背景图片


signals:

};

#endif // CYBACKSTAGEPAGES_H
