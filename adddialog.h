#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();\

signals:
    void newTextRecived(QString, QString);

private slots:
    void on_addBtn_clicked();

    void on_cancelBtn_clicked();

    void checkInput();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
