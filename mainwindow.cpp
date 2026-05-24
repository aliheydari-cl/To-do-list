#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddBtn_clicked()
{
    addDialog->exec();
}

void MainWindow::onNewTextRecived(QString text, QString subject)
{
    if(!ui->listWidget->isEnabled())
        ui->listWidget->setEnabled(true);

    TaskItemWidget *taskItemWidget = new TaskItemWidget(this, QString(text), QString(subject));

    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    item->setSizeHint(taskItemWidget->sizeHint());

    ui->listWidget->setItemWidget(item, taskItemWidget);
}


void MainWindow::on_deleteBtn_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());

    if (ui->listWidget->count() < 1)
        ui->listWidget->setEnabled(false);
}

