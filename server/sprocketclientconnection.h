#ifndef SPROCKETCLIENTCONNECTION_H
#define SPROCKETCLIENTCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include "iclientcommunication.h"
#include "command/icommand.h"

class SprocketClientConnection : public QObject, IClientCommunication
{
    Q_OBJECT
    Q_INTERFACES(IClientCommunication)
public:
    explicit SprocketClientConnection(QObject *parent = 0);
    void setSocket(QTcpSocket* socket);
    void connectSignals();
    QTcpSocket* getSocket();
    void sendString(QString data);
    void processComplete();
    void forceDisconnectClient();
signals:
    
public slots:

private:
    QList<ICommand *> *availableCommands;
    QTcpSocket* clientSocket;
    void processCommand(QByteArray data);

private slots:
    void dataWritten(qint64 size);
};

#endif // SPROCKETCLIENTCONNECTION_H
