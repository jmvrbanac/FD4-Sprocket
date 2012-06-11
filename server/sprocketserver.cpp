#include "sprocketserver.h"

SprocketServer::SprocketServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    clients = new QList<SprocketClientConnection*>();
    active = false;
}
SprocketServer::~SprocketServer()
{
    stopServer();
    delete server;
}

/**
 * Activates the server.
 * Currently it will auto seek an ip address to use.
 */
void SprocketServer::startServer(QHostAddress ipAddress, quint16 port)
{
    qDebug() << "Starting Server";
    QHostAddress address = QHostAddress::LocalHost;//getCurrentAddress();

    active = server->listen(address, port);

    if (!active){
        qDebug() << "Cannot start server";
        stopServer();
    }

    connect(server, SIGNAL(newConnection()), this, SLOT(newClientActive()));
}
bool SprocketServer::isActive()
{
    return active;
}

void SprocketServer::stopServer()
{
    qDebug() << "Stopping Server";

    for (int i=0; i < clients->length(); i++)
    {
        clients->at(i)->forceDisconnectClient();
    }

    server->close();
    active = false;
}

void SprocketServer::newClientActive()
{
    qDebug() << "New Client Connected!";
    SprocketClientConnection *client = new SprocketClientConnection(this);
    client->setSocket(server->nextPendingConnection());
    client->connectSignals();
    clients->append(client);
}


/**
 * Retrives the current remote ip address.
 * The fallback is to use a local address.
 */
QHostAddress SprocketServer::getCurrentAddress()
{
    QHostAddress current = QHostAddress::Null;
    QList<QHostAddress> addresses = QNetworkInterface::allAddresses();

    // Retrieve remote address
    for (int i=0; i < addresses.size(); i++)
    {
        QHostAddress checkAddress = addresses.at(i);
        if (checkAddress != QHostAddress::LocalHost)
        {
            current = checkAddress;
        }
    }

    // Using fallback local address if needed
    if (current == QHostAddress::Null)
    {
        current = QHostAddress::LocalHost;
    }
    return current;
}
