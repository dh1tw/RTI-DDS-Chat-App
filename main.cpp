#include <QApplication>
#include <QQmlApplicationEngine>
#include "commshandler.h"
#include <QtQml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<CommsHandler>("org.myChat", 1, 0, "CommsHandler");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
