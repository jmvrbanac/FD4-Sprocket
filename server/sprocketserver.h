#ifndef SPROCKETSERVER_H
#define SPROCKETSERVER_H

#include <QDebug>
#include <QObject>
#include <QtGlobal>
#include <QTcpServer>
#include <QNetworkInterface>
#include "sprocketclientconnection.h"

class SprocketServer : public QObject
{
    Q_OBJECT
public:
    explicit SprocketServer(QObject *parent = 0);
    ~SprocketServer();
    void startServer(QHostAddress ipAddress, quint16 port);
    void stopServer();
    bool isActive();
    
signals:
    
public slots:

private:
    bool active;
    QHostAddress getCurrentAddress();
    QTcpServer *server;
    QList<SprocketClientConnection*> *clients;

private slots:
    void newClientActive();
};

#endif // SPROCKETSERVER_H
