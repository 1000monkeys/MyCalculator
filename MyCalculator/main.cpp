#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    int new_argc = argc + 3;
    char** new_argv = new char* [new_argc];
    for (int i = 0; i < argc; ++i) {
        new_argv[i] = argv[i];
    }

    new_argv[argc] = new char[strlen("Appname") + 1];
    strcpy(new_argv[argc], "Appname");

    new_argv[argc + 1] = new char[strlen("--platform") + 1];
    strcpy(new_argv[argc + 1], "--platform");

    new_argv[argc + 2] = new char[strlen("-app_ver") + 1];
    strcpy(new_argv[argc + 2], "windows:dpiawareness=1");

    QGuiApplication app(new_argc, new_argv);
    //system("C:\\Windows\\System32\\shutdown /s /t 0");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
