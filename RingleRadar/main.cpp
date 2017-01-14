#include "mainwindow.h"
#include "form.h"
#include <QTextCodec>
#include "myplot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForUtfText("UTF-8"));
    Form w;
    w.resize(800,700);
    w.show();

    return a.exec();
}
