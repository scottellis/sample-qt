/*
 * Copyright 2012, Pansenti, LLC
 *
 */

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <qfileinfo.h>
#include <qdebug.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->hbButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));

    initButtonState();

#ifdef Q_WS_QWS
    // remove title bar
    setWindowFlags(Qt::CustomizeWindowHint);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClick()
{
    char buff[16];

    int fd = open("/sys/class/leds/overo:red:gpio21/trigger", O_WRONLY);

    if (fd < 0) {
        qDebug() << "Error: " << strerror(errno);
        return;
    }

    if (m_ledState)
        strcpy(buff, "none");
    else
        strcpy(buff, "heartbeat");

    int len = write(fd, buff, strlen(buff));

    if (len != (int)strlen(buff)) {
        qDebug() << "Error: " << strerror(errno);
    }
    else {
        m_ledState = !m_ledState;
        ui->hbButton->setText(m_ledState ? "Turn Off" : "Turn On");
    }

    ::close(fd);
}

void MainWindow::initButtonState()
{
    QFileInfo info;
    char buff[128];
    int fd = -1;

    strcpy(buff, "/sys/class/leds/overo:red:gpio21");

    info.setFile(buff);

    if (!info.exists() || !info.isDir()) {
        ui->hbButton->setText("Not Available");
        ui->hbButton->setEnabled(false);
        return;
    }

    strcat(buff, "/trigger");

    fd = open(buff, O_RDONLY);

    if (fd < 0)
        goto init_error;

    memset(buff, 0, sizeof(buff));

    if (read(fd, buff, sizeof(buff) - 1) < 0)
        goto init_error;

    if (strstr(buff, "[none]")) {
        m_ledState = false;
        ui->hbButton->setText("Turn On");
    }
    else {
        m_ledState = true;
        ui->hbButton->setText("Turn Off");
    }

    ::close(fd);

    return;

init_error:
    qDebug() << "Error: " << strerror(errno);
    ui->hbButton->setText("Not Available");
    ui->hbButton->setEnabled(false);

    if (fd)
        ::close(fd);
}
