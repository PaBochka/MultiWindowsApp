#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mainWind = new MainWindow;
    QObject::connect(mainWind->getUi()->Wind1Cancel, &QPushButton::clicked, &a, &QApplication::quit);
    QObject::connect(mainWind->getUi()->Wind2Cancel, &QPushButton::clicked, &a, &QApplication::quit);
    QObject::connect(mainWind->getUi()->Wind3Cancel, &QPushButton::clicked, &a, &QApplication::quit);

    QObject::connect(mainWind->getUi()->Exit, &QPushButton::clicked, &a, &QApplication::quit);

    mainWind->show();
    return a.exec();
}
