#include "mainwidget.h"

#include <QApplication>
#include "global.h"

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex_log;

    //调用日志打印需要加锁，达到数据同步的目的
    mutex_log.lock();

    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }

    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString strMessage = QString("Message:%1 File:%2  Line:%3  Function:%4  DateTime:%5")
            .arg(localMsg.constData())
            .arg(context.file)
            .arg(context.line)
            .arg(context.function)
            .arg(strDateTime);

        // 输出信息至文件中（读写、追加形式）
        QFile output_file("log.txt");
        //output_file.open(QIODevice::ReadWrite | QIODevice::Append);
        output_file.open(QIODevice::ReadWrite | QIODevice::Append);
        QTextStream output_stream(&output_file);
        output_stream << strMessage << "\n";
        output_file.flush();
        output_file.close();

        // 解锁
        mutex_log.unlock();
}

int main(int argc, char *argv[])
{
    //注册logger 写入函数
    qInstallMessageHandler(myMessageOutput);

    qDebug() << "test debug info";
    QApplication a(argc, argv);

    qApp->setStyleSheet("file:///:/qss/daytime.qss");

    //read qss files
    //        QFile file(":/qss/daytime.qss");
    //        /* 判断文件是否存在 */
    //        if (file.exists() ) {
    //          printf("read qss files");
    //         /* 以只读的方式打开 */
    //         file.open(QFile::ReadOnly);
    //         /* 以字符串的方式保存读出的结果 */
    //         QString styleSheet = QLatin1String(file.readAll());
    //         /* 设置全局样式 */
    //         //qApp->setStyleSheet(styleSheet);
    //         /* 关闭文件 */
    //         file.close();
    //       }

    mainWidget w;
    w.show();
    return a.exec();
}
