#include "delreaderdialog.h"
#include "ui_delreaderdialog.h"

DelReaderDialog::DelReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelReaderDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("注销读者");
    this->opt = BMSopt::Instance();
}

DelReaderDialog::~DelReaderDialog()
{
    this->opt = NULL;
    delete ui;
}

void DelReaderDialog::on_exit_clicked()
{
    this->close();
}

void DelReaderDialog::on_ok_clicked()
{
    std::string readerId = ui->readerIDlineEdit->text().trimmed().toStdString();
    auto it = this->opt->getReaders().find(readerId);
    if(it == this->opt->getReaders().end()){
        QMessageBox::information(this,tr("warning"),
                                 tr("没有ID为: ")+tr(readerId.c_str())+tr(" 的读者"),
                                 QMessageBox::Yes);
        ui->readerIDlineEdit->clear();
        ui->readerIDlineEdit->setFocus();
        return;
    }
    if(readerId == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入读者ID"),QMessageBox::Yes);
        ui->readerIDlineEdit->clear();
        ui->readerIDlineEdit->setFocus();
        return;
    }
    this->opt->deleteReader(readerId);
    QMessageBox::information(this,tr("Successful"),
                             tr("注销读者成功"),QMessageBox::Yes);
    this->close();
}
