#include <iostream>
#include <rustlib.h>
#include <QtWidgets/QApplication>
#include <QQmlApplicationEngine>

void f()
{
  std::cout << "The callback has worked!";
}

int main(int argc, char **argv)
{
#ifdef WIN32
  // ANGLE is a much faster rendering backend for Qt5 on Windows
  // Env vars are the only way I know of to set this
  _putenv("QT_OPENGL=angle");
  _putenv("QT_ANGLEPLATFORM=d3d9");
#endif

  QApplication app(argc, argv);
  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  hello_rust(*f);

  return app.exec();
}