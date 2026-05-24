#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <adddialog.h>
#include <taskitemwidget.h>

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

    void onNewTextRecived(QString text, QString subject);

    void on_deleteBtn_clicked();

private:
    Ui::MainWindow *ui;

    AddDialog *addDialog;
};
#endif // MAINWINDOW_H
