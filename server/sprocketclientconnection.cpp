#include "sprocketclientconnection.h"
#include "command/buildcommand.h"

/**
 * Valid Commands: build, pro_p
 */
SprocketClientConnection::SprocketClientConnection(QObject *parent) :
    QObject(parent)
{
    clientSocket = NULL;
    availableCommands = new QList<ICommand*>();

    // Add Commands
    availableCommands->append(new BuildCommand());
}
void SprocketClientConnection::forceDisconnectClient()
{
    clientSocket->disconnectFromHost();
    clientSocket->waitForDisconnected();
}

/**
 * Processes the commands based on the command classes added to the constructor
 */
void SprocketClientConnection::processCommand(QByteArray data)
{
    QByteArray header = data.left(5);
    QString headerStr = QString::fromAscii(header);

    ICommand *command;
    for(int i=0; i<availableCommands->length(); i++)
    {
        if (availableCommands->at(i)->getName() == headerStr)
        {
            command = availableCommands->at(i);
        }
    }

    if (command->getName() != "")
    {
        command->process(data, this);
    }
}

void SprocketClientConnection::processComplete()
{
    qDebug() << "Complete!";
}

void SprocketClientConnection::sendString(QString data)
{
    clientSocket->write(data.toAscii());
}

void SprocketClientConnection::connectSignals()
{
    Q_ASSERT(clientSocket != NULL);

    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    connect(clientSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(dataWritten(qint64)));

    sendString("connected");
}
void SprocketClientConnection::dataWritten(qint64 size)
{
    QByteArray data = clientSocket->read(size);

    if (data.length() >= 5) {
        processCommand(data);
    } else {
        data.clear();
    }
}

void SprocketClientConnection::setSocket(QTcpSocket* socket)
{
    clientSocket = socket;
}
QTcpSocket* SprocketClientConnection::getSocket()
{
    return clientSocket;
}
