#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <view.h>
#include <paintball.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    qmlRegisterType<View>("Backend",1,0,"View");
    qmlRegisterType<PaintBall>("Paint",1,0,"PaintBall");

    engine.loadFromModule("ThreeBody", "Main");

    return app.exec();
}
