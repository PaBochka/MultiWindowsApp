#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *getUi();
    QString FullName;
public slots:
    void onNextButtonClicked();
    void onBackButtonClicked();
    void send_data(const QString &str);
private:
    Ui::MainWindow *ui;
    uint32_t windIndex;
};
#endif // MAINWINDOW_H
