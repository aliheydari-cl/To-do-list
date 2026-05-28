#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <adddialog.h>
#include <taskitemwidget.h>
#include <QStandardPaths>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_AddBtn_clicked();
    void onNewTextRecived(QString text, QString subject, QString state = "false");
    void on_deleteBtn_clicked();
    void onDoneCheckBoxClicked();
    void saveTask();
    void loadTask();

private:
    Ui::MainWindow *ui;

    AddDialog *addDialog;
    QString filePath;
};

#endif // MAINWINDOW_H