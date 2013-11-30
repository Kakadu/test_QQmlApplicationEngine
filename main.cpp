#include <QtQml/QQmlApplicationEngine>
#include <QtWidgets/QApplication>
#include <QtQuick/QQuickWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(":/main.qml"));

    QList<QObject*> xs = engine.rootObjects();
    if (xs.length()==0) {
        return 1;
    }
    QQuickWindow *window = qobject_cast<QQuickWindow*>(xs.at(0));
    window->show();

    return app.exec();
}
