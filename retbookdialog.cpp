#include "retbookdialog.h"
#include "ui_retbookdialog.h"

RetBookDialog::RetBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RetBookDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("还书");
    this->opt = BMSopt::Instance();
}

RetBookDialog::~RetBookDialog()
{
    this->opt = NULL;
    delete ui;
}

void RetBookDialog::on_exit_clicked()
{
    this->close();
}

void RetBookDialog::on_reset_clicked()
{
    ui->bookId->clear();
    ui->readerId->clear();
    ui->bookId->setFocus();
}

void RetBookDialog::on_check1_clicked()
{
    std::string bookId = ui->bookId->text().trimmed().toStdString();
    if(bookId == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入图书编号"),QMessageBox::Yes);
        ui->bookId->clear();
        ui->bookId->setFocus();
        return;
    }
    std::map<std::string,Book> & books = this->opt->getBooks();
    auto it = books.find(bookId);
    if(it == books.end()){
        QMessageBox::information(this,tr("warning"),
                                 tr("没有编号为:")+tr(bookId.c_str())+tr("的书"),
                                 QMessageBox::Yes);
        ui->bookId->clear();
        ui->bookId->setFocus();
        return;
    }else{
        if(it->second.getNum() == it->second.getStatus()){
            QMessageBox::information(this,tr("warning"),
                                     tr("该编号的图书并未被借阅"),QMessageBox::Yes);
            ui->bookId->clear();
            ui->bookId->setFocus();
        }else{
            QMessageBox::information(this,tr("Successful"),
                                     tr("可继续执行"),QMessageBox::Yes);
        }
    }
}

void RetBookDialog::on_check2_clicked()
{
    std::string bookId = ui->bookId->text().trimmed().toStdString();
    std::string readerId = ui->readerId->text().trimmed().toStdString();
    if(bookId == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入图书编号"),QMessageBox::Yes);
        ui->bookId->clear();
        ui->bookId->setFocus();
        return;
    }
    if(readerId == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入读者编号"),QMessageBox::Yes);
        ui->readerId->clear();
        ui->readerId->setFocus();
        return;
    }
    std::map<std::string,Book> & books = this->opt->getBooks();
    auto it = books.find(bookId);
    if(it == books.end()){
        QMessageBox::information(this,tr("warning"),
                                 tr("没有编号为:")+tr(bookId.c_str())+tr("的书"),
                                 QMessageBox::Yes);
        ui->bookId->clear();
        ui->bookId->setFocus();
        return;
    }else{
        if(it->second.getNum() == it->second.getStatus()){
            QMessageBox::information(this,tr("warning"),
                                     tr("该编号的图书并未被借阅"),QMessageBox::Yes);
            ui->bookId->clear();
            ui->bookId->setFocus();
            return;
        }
    }
    std::vector<std::string> & readerIds = it->second.getReaderIds();
    for(auto it2 = readerIds.begin(); it2 != readerIds.end(); it2++){
        if(*it2 == readerId){
            QMessageBox::information(this,tr("Successful"),
                                     tr("可还书"),QMessageBox::Yes);
            return;
        }
    }
    QMessageBox::information(this,tr("Successful"),
                             tr("该读者未借这本书"),QMessageBox::Yes);
}

void RetBookDialog::on_ret_clicked()
{
    std::string bookId = ui->bookId->text().trimmed().toStdString();
    std::string readerId = ui->readerId->text().trimmed().toStdString();
    if(bookId == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入图书编号"),QMessageBox::Yes);
        ui->bookId->clear();
        ui->bookId->setFocus();
        return;
    }
    if(readerId == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入读者编号"),QMessageBox::Yes);
        ui->readerId->clear();
        ui->readerId->setFocus();
        return;
    }
    std::map<std::string,Book> & books = this->opt->getBooks();
    auto it = books.find(bookId);
    if(it == books.end()){
        QMessageBox::information(this,tr("warning"),
                                 tr("没有编号为:")+tr(bookId.c_str())+tr("的书"),
                                 QMessageBox::Yes);
        ui->bookId->clear();
        ui->bookId->setFocus();
        return;
    }else{
        if(it->second.getNum() == it->second.getStatus()){
            QMessageBox::information(this,tr("warning"),
                                     tr("该编号的图书并未被借阅"),QMessageBox::Yes);
            ui->bookId->clear();
            ui->bookId->setFocus();
            return;
        }
    }
    std::vector<std::string> & readerIds = it->second.getReaderIds();
    auto it2 = readerIds.begin();
    for(; it2 != readerIds.end(); it2++){
        if(*it2 == readerId){
            break;
        }
    }
    if(it2 == readerIds.end()){
        QMessageBox::information(this,tr("Successful"),
                                 tr("该读者未借这本书"),QMessageBox::Yes);
        return;
    }
    this->opt->retBook(bookId,readerId);
    QMessageBox::information(this,tr("Successful"),
                             tr("还书成功"),QMessageBox::Yes);
}
