#include "sprocketthread.h"

SprocketThread::SprocketThread(int socketDescriptor, QObject *parent) : QThread(parent), socketDescriptor(socketDescriptor)
{
}

void SprocketThread::run()
{
    SprocketServer *server = new SprocketServer(this);
    server->startServer(QHostAddress::LocalHost, 2213);
}
