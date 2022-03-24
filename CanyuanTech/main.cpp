#include "mainwidget.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    //read qss files
    //    QFile file(":/qss/daytime.qss");
    //    /* 判断文件是否存在 */
    //    if (file.exists() ) {
    //      printf("read qss files");
    //     /* 以只读的方式打开 */
    //     file.open(QFile::ReadOnly);
    //     /* 以字符串的方式保存读出的结果 */
    //     QString styleSheet = QLatin1String(file.readAll());
    //     /* 设置全局样式 */
    //     //qApp->setStyleSheet(styleSheet);
    //     /* 关闭文件 */
    //     file.close();
    //    }

    QApplication a(argc, argv);
    mainWidget w;
    w.show();
    return a.exec();
}
