#include "delbookdialog.h"
#include "ui_delbookdialog.h"

DelBookDialog::DelBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelBookDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("删除图书");
    this->opt = BMSopt::Instance();
}

DelBookDialog::~DelBookDialog()
{
    this->opt = NULL;
    delete ui;
}

void DelBookDialog::on_exit_clicked()
{
    this->close();
}

void DelBookDialog::on_reset_clicked()
{
    ui->bookId->clear();
    ui->bookId->setFocus();
}

void DelBookDialog::on_del_clicked()
{
    std::string bookId = ui->bookId->text().trimmed().toStdString();
    auto it = this->opt->getBooks().find(bookId);
    if(it == this->opt->getBooks().end()){
        QMessageBox::information(this,tr("warning"),
                                 tr("删除失败，库存没有这本书"),QMessageBox::Yes);
        ui->bookId->clear();
        ui->bookId->setFocus();
        return;
    }
    if(!it->second.getReaderIds().empty()){
        QMessageBox::information(this,tr("warning"),
                                 tr("编号为:")+tr(bookId.c_str())+tr("的书有借出，无法删除"),
                                 QMessageBox::Yes);
        ui->bookId->clear();
        ui->bookId->setFocus();
        return;
    }
    this->opt->deleteBook(bookId);
    QMessageBox::information(this,tr("Successful"),
                             tr("删除图书成功"),QMessageBox::Yes);
    ui->bookId->clear();
    ui->bookId->setFocus();
}
