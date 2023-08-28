#include "FirstWidget.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("./resource/i18n/zh_CN.qm");
    a.installTranslator(&translator);
    FirstWidget w;
    w.show();
    return a.exec();
}