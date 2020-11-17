#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QTimer>

#include <memory>

class TcpTest : public QObject
{
    Q_OBJECT

public:
    TcpTest(QObject *parent = nullptr);

private:
    std::unique_ptr < QTcpSocket > tcpSocket_;
    std::unique_ptr < QTimer > timer_;

private slots:
    void onSocketConnected();// Notify connection to TCP server
    void onSocketDisconnected();// Notify disconnection from TCP server
    void onSocketReconnect();// Notify disconnection from TCP server

};
