#include "addbookdialog.h"
#include "ui_addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("添加图书");
    this->opt = BMSopt::Instance();
}

AddBookDialog::~AddBookDialog()
{
    this->opt = NULL;
    delete ui;
}

void AddBookDialog::on_reset_clicked()
{
    ui->bookName->clear();
    ui->bookId->clear();
    ui->price->clear();
    ui->bookAuthor->clear();
    ui->bookNum->clear();
    ui->bookName->setFocus();
}

void AddBookDialog::on_ok_clicked()
{
    QString name = ui->bookName->text().trimmed();
    QString id = ui->bookId->text().trimmed();
    QString price = ui->price->text().trimmed();
    QString author = ui->bookAuthor->text().trimmed();
    QString num = ui->bookNum->text().trimmed();
    if(name == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("图书名称不能为空"),QMessageBox::Yes);
        ui->bookName->setFocus();
        return;
    }
    if(id == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("图书ID不能为空"),QMessageBox::Yes);
        ui->bookId->setFocus();
        return;
    }
    if(price == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("图书价格不能为空"),QMessageBox::Yes);
        ui->price->setFocus();
        return;
    }else{
        bool notIsDigit = false;
        int point = 0;
        std::string stdprice = price.toStdString();
        for(int i = 0; i < stdprice.length(); i++){
            if(stdprice[i]>'9'||stdprice[i]<'0'){
                notIsDigit = true;
                break;
            }
            if(stdprice[i] == '.'){
                point++;
                if(point >= 2){
                    notIsDigit = true;
                    break;
                }
            }
        }
        if(notIsDigit){
            QMessageBox::information(this,tr("warning"),
                                     tr("图书价格只能输入数字"),QMessageBox::Yes);
            ui->price->clear();
            ui->price->setFocus();
            return;
        }
    }
    if(author == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("图书作者不能为空"),QMessageBox::Yes);
        ui->bookAuthor->setFocus();
        return;
    }
    if(num == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("图书数量不能为空"),QMessageBox::Yes);
        ui->bookNum->setFocus();
        return;
    }else{
        std::string stdnum = num.toStdString();
        for(int i =0; i < (int)stdnum.length(); i ++){
            if(stdnum[i]<'0'||stdnum[i]>'9'){
                QMessageBox::information(this,tr("warning"),
                                         tr("图书数量只能输入数字"),QMessageBox::Yes);
                ui->bookNum->clear();
                ui->bookNum->setFocus();
                return;
            }
        }
    }
    this->opt->addBook(Book(name.toStdString(),id.toStdString(),
                            std::stod(price.toStdString()),
                            author.toStdString(),
                            std::stoi(num.toStdString()),std::stoi(num.toStdString())));
    QMessageBox::information(this,tr("Successful"),
                             tr("添加图书成功"),QMessageBox::Yes);
    this->on_reset_clicked();
}
