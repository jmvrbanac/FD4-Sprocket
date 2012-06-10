#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include <QObject>
#include <QDebug>
#include "icommand.h"

class BuildCommand : public QObject, public ICommand
{
    Q_OBJECT
    Q_INTERFACES(ICommand)
public:
    explicit BuildCommand(QObject *parent = 0);
    ~BuildCommand();
    QString getName();
   void process(QByteArray data, IClientCommunication *client);
private:
   IClientCommunication *clientComm;
};

#endif // BUILDCOMMAND_H
