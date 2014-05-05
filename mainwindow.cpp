/*
 * Copyright (c) 2014 Jumpnow Technologies, LLC
 */

#include <qboxlayout.h>
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent)
{
    layoutWindow();

    connect(m_exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(m_change, SIGNAL(clicked()), this, SLOT(onClickColor()));

#ifdef Q_WS_QWS
    // remove title bar
    setWindowFlags(Qt::CustomizeWindowHint);
#endif

    m_currentColor = m_colors.count();
    onClickColor();
}

void MainWindow::onClickColor()
{
    m_currentColor = (m_currentColor + 1) % m_colors.count();
    m_label->setStyleSheet(m_colors[m_currentColor]);
}    

void MainWindow::layoutWindow()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *vLayout = new QVBoxLayout(centralWidget);

    m_change = new QPushButton("Click Me");
    vLayout->addWidget(m_change);

    QHBoxLayout *hLayout = new QHBoxLayout;

    m_label = new QLabel;
    m_label->setFixedSize(100, 100);
    hLayout->addStretch();
    hLayout->addWidget(m_label);
    hLayout->addStretch();	
    vLayout->addLayout(hLayout);

    m_exit = new QPushButton("Exit");
    vLayout->addWidget(m_exit);

    setCentralWidget(centralWidget);

    m_colors.append("background-color:red");
    m_colors.append("background-color:green");
    m_colors.append("background-color:blue");
}

