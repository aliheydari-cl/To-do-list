#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

// هدرهای پروژه‌ی خودت
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
    // این اسلات سیگنال Dialog را دریافت می‌کند
    void onNewTextRecived(QString text, QString subject, QString state = "false");
    void on_deleteBtn_clicked();
    // این اسلات تغییرات چک‌باکس را متوجه می‌شود
    void onDoneCheckBoxClicked();

private:
    Ui::MainWindow *ui;
    AddDialog *addDialog;
    QString filePath;

    // --- توابع کمکی ---

    // ۱. این تابع مسئول ساخت ویجت و تنظیم دقیقِ اندازه آن در لیست است
    void addTask(const QString &text, const QString &subject, const QString &state);

    // ۲. توابع کار با فایل
    void saveTask();
    void loadTask();
};

#endif // MAINWINDOW_H
