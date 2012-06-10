#ifndef SPROCKETTHREAD_H
#define SPROCKETTHREAD_H

#include <QThread>
#include <QtNetwork>
#include "sprocketserver.h"

class SprocketThread : public QThread
{
    Q_OBJECT
public:
     SprocketThread(int socketDescriptor, QObject *parent);
     void run();
signals:
    
public slots:

private:
     int socketDescriptor;
};

#endif // SPROCKETTHREAD_H
