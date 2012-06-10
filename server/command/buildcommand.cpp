#include "buildcommand.h"

BuildCommand::BuildCommand(QObject *parent) : QObject(parent)
{
}
BuildCommand::~BuildCommand()
{

}

QString BuildCommand::getName()
{
    return "build";
}
void BuildCommand::process(QByteArray data, IClientCommunication *client)
{
    // Storing client comm object so we can call processComplete after file I/O
    clientComm = client;

    client->sendString("dmess Starting Remote Build...");
    qDebug() << "Build Process Started...";

    // Telling the client connect that we are done.
    client->processComplete();
}
