#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/Retroville-NC-1.ttf");
    MainWindow w;
    w.show();
    return a.exec();
}
