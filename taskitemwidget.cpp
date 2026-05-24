#include "taskitemwidget.h"
#include "ui_taskitemwidget.h"

TaskItemWidget::TaskItemWidget(QWidget *parent, const QString &text, const QString &subject)
    : QWidget(parent)
    , ui(new Ui::TaskItemWidget)
{
    ui->setupUi(this);
    ui->textBrowser->setText(text);
    ui->subject->setText(subject);

    ui->textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->textBrowser->setFrameShape(QFrame::NoFrame);

    ui->textBrowser->document()->setTextWidth(ui->textBrowser->viewport()->width());

    QSizeF docSize = ui->textBrowser->document()->size();

    ui->textBrowser->setFixedHeight(docSize.height());

}

TaskItemWidget::~TaskItemWidget()
{
    delete ui;
}
