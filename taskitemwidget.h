#ifndef TASKITEMWIDGET_H
#define TASKITEMWIDGET_H

#include <QWidget>

namespace Ui {
class TaskItemWidget;
}

class TaskItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskItemWidget(QWidget *parent = nullptr, const QString &text = "", const QString &subject = "", const QString &state = "false");
    ~TaskItemWidget();

    QString getText();
    QString getSubject();
    QString getState();
    QSize sizeHint() const override;


signals:
    void checkBoxStateChanged(Qt::CheckState);

private slots:
    void on_checkBox_checkStateChanged(const Qt::CheckState &arg1);



private:
    Ui::TaskItemWidget *ui;

};



#endif // TASKITEMWIDGET_H
