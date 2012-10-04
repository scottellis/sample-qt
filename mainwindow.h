/*
 * Copyright 2012, Pansenti, LLC
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    

public slots:
    void onButtonClick();

private:
    void initButtonState();

    Ui::MainWindow *ui;

    bool m_ledState;
};

#endif // MAINWINDOW_H
