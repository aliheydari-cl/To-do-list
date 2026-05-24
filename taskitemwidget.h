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
    explicit TaskItemWidget(QWidget *parent = nullptr, const QString &text = "", const QString &subject = "");
    ~TaskItemWidget();

private:
    Ui::TaskItemWidget *ui;
};

#endif // TASKITEMWIDGET_H
