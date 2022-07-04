#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , windIndex(0)
    , FullName("")
{
    ui->setupUi(this);
    ui->Exit->setEnabled(false);
    QObject::connect(ui->checkBox, &QCheckBox::toggled, ui->Exit, &QPushButton::setEnabled);

    QObject::connect(ui->StartButton, &QPushButton::clicked, this, &MainWindow::onNextButtonClicked);

    QObject::connect(ui->Wind1Next, &QPushButton::clicked, this, &MainWindow::onNextButtonClicked);
    QObject::connect(ui->Wind2Next, &QPushButton::clicked, this, &MainWindow::onNextButtonClicked);
    QObject::connect(ui->Wind3Next, &QPushButton::clicked, this, &MainWindow::onNextButtonClicked);

    QObject::connect(ui->Wind4Back, &QPushButton::clicked, this, &MainWindow::onBackButtonClicked);
    QObject::connect(ui->Wind3Back, &QPushButton::clicked, this, &MainWindow::onBackButtonClicked);
    QObject::connect(ui->Wind2Back, &QPushButton::clicked, this, &MainWindow::onBackButtonClicked);

    QObject::connect(ui->FirstName, &QLineEdit::editingFinished, this, [this](){this->FullName += ui->FirstName->text();});
    QObject::connect(ui->SecondName, &QLineEdit::editingFinished, this, [this](){this->FullName = (!ui->FirstName->text().isEmpty()) ?
                                                                                                ui->SecondName->text() + " " + this->FullName : "";});
    QObject::connect(ui->Exit, &QPushButton::clicked, this, [this](){send_data(this->FullName);});

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onNextButtonClicked() {
    ui->stackedWidget->setCurrentIndex(++windIndex);
}

void MainWindow::onBackButtonClicked() {
    ui->stackedWidget->setCurrentIndex(--windIndex);
}

Ui::MainWindow *MainWindow::getUi() {
    return ui;
}

void MainWindow::send_data(const QString &str) {
    if (!str.isEmpty()) {
        QString filename = "./Data.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << str << endl;
            file.close();
        }
    }
}
