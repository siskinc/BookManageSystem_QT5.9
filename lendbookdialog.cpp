#include "lendbookdialog.h"
#include "ui_lendbookdialog.h"

LendBookDialog::LendBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LendBookDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("借书");
    this->opt = BMSopt::Instance();
}

LendBookDialog::~LendBookDialog()
{
    this->opt = NULL;
    delete ui;
}

void LendBookDialog::on_exit_clicked()
{
    this->close();
}

void LendBookDialog::on_reset_clicked()
{
    ui->bookId->clear();
    ui->readId->clear();
    ui->bookId->setFocus();
}

void LendBookDialog::on_sureBookId_clicked()
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
    if(it != books.end()){
        if(it->second.isExist()){
            QMessageBox::information(this,tr("Successful"),
                                     tr("查询成功，图书编号为:")+tr(it->second.getId().c_str())
                                     +tr(" 的图书库存还有")+tr(std::to_string(it->second.getStatus()).c_str())
                                     +tr("本"),QMessageBox::Yes);
            return;
        }else{
            QMessageBox::information(this,tr("Successful"),
                                     tr("查询成功，图书编号为:")+tr(it->second.getId().c_str())
                                     +tr(" 的图书库存没有了!!!"),QMessageBox::Yes);
            return ;
        }
    }else{
        QMessageBox::information(this,tr("warning"),
                                 tr("查询成功，图书编号为:")+tr(it->second.getId().c_str())
                                 +tr(" 没有!!!"),QMessageBox::Yes);
        return;
    }
}

void LendBookDialog::on_sureReaderId_clicked()
{
    std::string readerId = ui->readId->text().trimmed().toStdString();
    if(readerId == ""){
        QMessageBox::information(this,tr("warning"),
                    tr("请输入读者编号"),QMessageBox::Yes);
        ui->readId->clear();
        ui->readId->setFocus();
        return;
    }
    std::map<std::string,Reader> & readers = this->opt->getReaders();
    auto it = readers.find(readerId);
    if(it != readers.end()){
        QMessageBox::information(this,tr("warning"),
                                 tr("查询成功，该读者可以进行借书"),QMessageBox::Yes);
    }else{
        QMessageBox::information(this,tr("warning"),
                                 tr("查询成功，读者编号为:")+
                                 tr(readerId.c_str())+
                                 tr("没有！！！"),QMessageBox::Yes);
    }
}

void LendBookDialog::on_lend_clicked()
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
    if(it != books.end()){
        if(!it->second.isExist()){
            QMessageBox::information(this,tr("warning"),
                                     tr("图书编号为:")+tr(it->second.getId().c_str())
                                     +tr(" 的图书库存没有了!!!"),QMessageBox::Yes);
            return ;
        }
    }else{
        QMessageBox::information(this,tr("warning"),
                                 tr("图书编号为:")+tr(it->second.getId().c_str())
                                 +tr(" 没有!!!"),QMessageBox::Yes);
        return;
    }
    std::string readerId = ui->readId->text().trimmed().toStdString();
    if(readerId == ""){
        QMessageBox::information(this,tr("warning"),
                    tr("请输入读者编号"),QMessageBox::Yes);
        ui->readId->clear();
        ui->readId->setFocus();
        return;
    }
    std::map<std::string,Reader> & readers = this->opt->getReaders();
    auto it2 = readers.find(readerId);
    if(it2 == readers.end()){
        QMessageBox::information(this,tr("warning"),
                                 tr("读者编号为:")+
                                 tr(readerId.c_str())+
                                 tr("没有！！！"),QMessageBox::Yes);
        return;
    }
    this->opt->lendBook(bookId,readerId);
    QMessageBox::information(this,tr("Successful"),
                             tr("借书成功"),QMessageBox::Yes);
    this->on_reset_clicked();
}
