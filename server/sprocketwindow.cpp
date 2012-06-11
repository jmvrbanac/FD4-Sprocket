#include "sprocketwindow.h"
#include "ui_sprocketwindow.h"

SprocketWindow::SprocketWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SprocketWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Server stopped");
    server = new SprocketServer(this);
}

SprocketWindow::~SprocketWindow()
{
    delete ui;
}

void SprocketWindow::on_startButton_clicked()
{
    if (server->isActive()) {
        server->stopServer();

        ui->startButton->setText("Start");
        ui->statusBar->showMessage("Server stopped");
    } else {
        ui->startButton->setText("Stop");
        quint16 port = (quint16) ui->portSpin->value();

        server->startServer(QHostAddress::LocalHost, port);
        ui->statusBar->showMessage("Server started on port " + QString::number(port));
    }
}
