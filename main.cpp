#include <QApplication>
#include <QQmlApplicationEngine>
#include "mything.h"
#include "mylistener.h"
#include <QtQml>
#include <QDebug>

int main(int argc, char *argv[])
{
//    QApplication app(argc, argv);
//    QQmlApplicationEngine engine;
//    MyThing mything;
//    engine.rootContext()->setContextProperty("mything", &mything);
//    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
//    component.create();
//    qDebug() << component.errors();

//    return app.exec();

    MyListener me;
    QApplication app(argc, argv);
    qmlRegisterType<MyListener>("dh1tw.shack", 1, 0, "MyListener");
    qmlRegisterType<MyThing>("dh1tw.shack", 1, 0, "MyThing");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
