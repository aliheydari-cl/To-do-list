#include "mainwindow.h"
#include "qjsonobject.h"
#include "taskitemwidget.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addDialog = new AddDialog(this);

    connect(addDialog, &AddDialog::newTextRecived, this, &MainWindow::onNewTextRecived);

    QFont font;
    font.setPixelSize(20);

    ui->listWidget->setFont(font);

    loadTask();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddBtn_clicked()
{
    addDialog->exec();
}

void MainWindow::onNewTextRecived(QString text, QString subject, QString state)
{
    if(!ui->listWidget->isEnabled())
        ui->listWidget->setEnabled(true);

    TaskItemWidget *taskItemWidget = new TaskItemWidget(this, text, subject, state);
    connect(taskItemWidget, &TaskItemWidget::checkBoxStateChanged, this, &MainWindow::onDoneCheckBoxClicked);



    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    item->setSizeHint(taskItemWidget->sizeHint());


    ui->listWidget->setItemWidget(item, taskItemWidget);


    saveTask();
}


void MainWindow::on_deleteBtn_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());

    if (ui->listWidget->count() < 1)
        ui->listWidget->setEnabled(false);

    saveTask();
}

void MainWindow::onDoneCheckBoxClicked()
{
    saveTask();
}

void MainWindow::saveTask()
{
    filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/data.json";

    QFile file(filePath);

    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error of open file!";
        return;
    }
    QJsonArray jsonArray;

    for(int i = 0 ; i < ui->listWidget->count() ; i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        TaskItemWidget *widget = qobject_cast<TaskItemWidget*>(ui->listWidget->itemWidget(item));

        if(widget)
        {
            QJsonObject jsonObject;
            jsonObject["text"] = widget->getText();
            jsonObject["subject"] = widget->getSubject();
            jsonObject["state"] = widget->getState();

            jsonArray.append(jsonObject);

        }
    }


    QJsonDocument jsonDocument(jsonArray);

    if(!file.write(jsonDocument.toJson()))
    {
        qDebug() << "Error of write json to file";
        return;
    }

    file.close();
}

void MainWindow::loadTask()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/data.json";

    QFile file;
    file.setFileName(path);

    if(!file.exists())
    {
        qDebug() << "file is not exit";
        return;
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error of read file";
        return;
    }

    QByteArray data = file.readAll();

    QJsonDocument jd = QJsonDocument::fromJson(data);

    QJsonArray jsonArray;

    jsonArray = jd.array();

    for(auto json : std::as_const(jsonArray))
    {
        QJsonObject ob = json.toObject();

        TaskItemWidget *taskItemWidget = new TaskItemWidget(this, ob["text"].toString(), ob["subject"].toString(), ob["state"].toString());
        connect(taskItemWidget, &TaskItemWidget::checkBoxStateChanged, this, &MainWindow::onDoneCheckBoxClicked);

        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(taskItemWidget->sizeHint());

        ui->listWidget->setItemWidget(item, taskItemWidget);
        if(!ui->listWidget->isEnabled())
            ui->listWidget->setEnabled(true);

    }


}
