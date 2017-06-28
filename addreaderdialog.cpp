#include "addreaderdialog.h"
#include "ui_addreaderdialog.h"

AddReaderDialog::AddReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReaderDialog)
{
    ui->setupUi(this);
    this->opt =  BMSopt::Instance();
    this->setWindowTitle("读者注册");
}

AddReaderDialog::~AddReaderDialog()
{
    this->opt = NULL;
    delete ui;
}

void AddReaderDialog::on_reset_clicked()
{
    ui->readerID->clear();
    ui->readerName->clear();
    ui->male->setChecked(true);
}

void AddReaderDialog::on_registered_clicked()
{
    std::string readerName = ui->readerName->text().trimmed().toStdString();
    std::string readerId = ui->readerID->text().trimmed().toStdString();
    if(readerName == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入读者姓名"),QMessageBox::Yes);
        ui->readerName->clear();
        ui->readerName->setFocus();
        return;
    }
    if(readerId  == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入读者ID"),QMessageBox::Yes);
        ui->readerID->clear();
        ui->readerID->setFocus();
        return;
    }
    bool gender = ui->male->isChecked();
    this->opt->addReader(Reader(readerName,gender,readerId));
    QMessageBox::information(this,tr("Successful"),
                             tr("读者注册成功"),QMessageBox::Yes);
    this->close();
}
