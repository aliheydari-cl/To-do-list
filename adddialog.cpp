#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    connect(ui->subjectLineEdit, &QLineEdit::textChanged, this, &AddDialog::checkInput);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &AddDialog::checkInput);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_addBtn_clicked()
{
    QString text;
    QString subject;

    text = ui->textEdit->toPlainText();
    subject = ui->subjectLineEdit->text();

    if (text.length() > 0)
        emit newTextRecived(text, subject);

    ui->textEdit->setText("");
    ui->subjectLineEdit->setText("");

    this->close();
}


void AddDialog::on_cancelBtn_clicked()
{
    this->close();
}

void AddDialog::checkInput()
{
    if (ui->subjectLineEdit->text().length() > 0 && ui->textEdit->toPlainText().length() > 0)
        ui->addBtn->setEnabled(true);
    else
        ui->addBtn->setEnabled(false);
}

