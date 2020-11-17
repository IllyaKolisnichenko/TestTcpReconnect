#include "TcpTest.h"

TcpTest::TcpTest(QObject *parent)
    : QObject(parent)
{
    tcpSocket_ = std::make_unique<QTcpSocket>();
    timer_ = std::make_unique < QTimer >();

    connect( tcpSocket_.get(), &QTcpSocket::connected, this, &TcpTest::onSocketConnected );
    connect( tcpSocket_.get(), &QTcpSocket::disconnected, this, &TcpTest::onSocketDisconnected );

    connect( timer_.get(), &QTimer::timeout, this, &TcpTest::onSocketReconnect);

    tcpSocket_->connectToHost("192.168.0.191", 9761);
    timer_->start(10000);
}

void TcpTest::onSocketConnected()
{
    qDebug() << "Connected!";
}


void TcpTest::onSocketDisconnected()
{
    qDebug() << "Disconnected!";
}

void TcpTest::onSocketReconnect()
{
    if( tcpSocket_->state() != QAbstractSocket::ConnectedState )
    {
        tcpSocket_->abort();
        tcpSocket_->connectToHost("192.168.0.191", 9761);

        // Wait for connection result
        if (!tcpSocket_->waitForConnected(1000))
        {
            qDebug() << "Error: " << tcpSocket_->errorString();
        }
    }
}
