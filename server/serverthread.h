#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H


#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class ServerThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerThread(qintptr ID, QObject *parent = 0);

    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};


#endif // SERVERTHREAD_H
