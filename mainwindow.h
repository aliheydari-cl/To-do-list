#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

#include "adddialog.h"

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

private:
    Ui::MainWindow *ui;
    AddDialog *addDialog;
    QString filePath;


    void addTask(const QString &text, const QString &subject, const QString &state);

    void saveTask();
    void loadTask();
};

#endif // MAINWINDOW_H
