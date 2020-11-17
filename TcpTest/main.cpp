#include <QtCore/QCoreApplication>
#include "TcpTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TcpTest* tcpTest = new TcpTest;

    return a.exec();
}
