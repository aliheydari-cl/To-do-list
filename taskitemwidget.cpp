#include "taskitemwidget.h"
#include "ui_taskitemwidget.h"

TaskItemWidget::TaskItemWidget(QWidget *parent, const QString &text, const QString &subject, const QString &state)
    : QWidget(parent)
    , ui(new Ui::TaskItemWidget)
{
    ui->setupUi(this);

    ui->textLabel->setText(text);
    ui->subject->setText(subject);

    if(state == "false")
        ui->checkBox->setCheckState(Qt::Unchecked);
    else
        ui->checkBox->setCheckState(Qt::Checked);

    ui->textLabel->setWordWrap(true);
}

TaskItemWidget::~TaskItemWidget()
{
    delete ui;
}

void TaskItemWidget::on_checkBox_checkStateChanged(const Qt::CheckState &arg1)
{
    emit checkBoxStateChanged(arg1);
}

QString TaskItemWidget::getText()
{
    return ui->textLabel->text();
}

QString TaskItemWidget::getSubject()
{
    return ui->subject->text();
}

QString TaskItemWidget::getState()
{
    if(ui->checkBox->isChecked())
        return "true";
    else
        return "false";
}

QSize TaskItemWidget::sizeHint() const
{
    if (layout()) {
        layout()->activate();

        QSize s = layout()->sizeHint();

        return QSize(s.width(), s.height() + 15);
    }
    return QSize(400, 100);
}



