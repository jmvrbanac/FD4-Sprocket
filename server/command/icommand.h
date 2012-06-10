#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <QObject>
#include "../iclientcommunication.h"

class ICommand
{
public:
    virtual ~ICommand(){}
    virtual QString getName() = 0;
    virtual void process(QByteArray data, IClientCommunication *client)=0;
};

Q_DECLARE_INTERFACE(ICommand, "com.VerticalCue.Sprocket.ICommand/1.0")

#endif // ICOMMAND_H
