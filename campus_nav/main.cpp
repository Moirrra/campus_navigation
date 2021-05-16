#include "mainwindow.h"
#include <Windows.h>
#include <WinUser.h>
#include <wingdi.h>
#include <QApplication>

int main(int argc, char *argv[])
{
//    //控制图片缩放质量
//    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
//    //这个是Windows平台用来获取屏幕宽度的代码，
//    //因为在qApplication实例初始化之前，QGuiApplication::screens();无法使用。
//    qreal  cx = GetSystemMetrics(SM_CXSCREEN);
//    qreal scale = cx / 960;				// 960 = 1920 / 2
//    qputenv("QT_SCALE_FACTOR", QString::number(scale).toLatin1());


//    #if (QT_VERSION >= QT_VERSION_CHECK(5,9,0))
//    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    #endif
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
