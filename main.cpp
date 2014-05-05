/*
 * Copyright (c) 2014 Jumpnow Technologies, LLC
 */

#include "mainwindow.h"
#include <qapplication.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
#ifdef Q_WS_QWS
    w.showFullScreen();
#endif

    return a.exec();
}
