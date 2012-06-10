#ifndef ICLIENTCOMMUNICATION_H
#define ICLIENTCOMMUNICATION_H

#include <QObject>

class IClientCommunication
{
public:
    virtual ~IClientCommunication(){}
    virtual void sendString(QString data) = 0;
    virtual void processComplete()=0;
};
Q_DECLARE_INTERFACE(IClientCommunication, "com.VerticalCue.Sprocket.IClientCommunication/1.0")
#endif // CLIENTCOMMUNICATION_H
