/*
 * Copyright (c) 2014, Jumpnow Technologies, LLC
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qmainwindow.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qstringlist.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

public slots:
    void onClickColor();

private:
    void layoutWindow();

    QPushButton *m_change;
    QPushButton *m_exit;

    QStringList m_colors;
    int m_currentColor;

    QLabel *m_label;
};

#endif // MAINWINDOW_H
