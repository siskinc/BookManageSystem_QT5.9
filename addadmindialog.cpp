#include "addadmindialog.h"
#include "ui_addadmindialog.h"

AddAdminDialog::AddAdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAdminDialog)
{
    ui->setupUi(this);
    ui->userlineEdit->setFocus();
    this->setWindowTitle(tr("管理员注册"));
    this->opt = BMSopt::Instance();
}

AddAdminDialog::~AddAdminDialog()
{
    this->opt = NULL;
    delete ui;
}
void AddAdminDialog::on_reset_clicked()
{
    ui->userlineEdit->clear();
    ui->pswlineEdit->clear();
    ui->pswlineEdit2->clear();
    ui->userlineEdit->setFocus();
}

void AddAdminDialog::on_registe_clicked()
{
    QString user = ui->userlineEdit->text().trimmed();
    QString psw = ui->pswlineEdit->text().trimmed();
    QString psw2 = ui->pswlineEdit2->text().trimmed();
    if(user == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("用户名不能为空!!!"),QMessageBox::Yes);
        this->on_reset_clicked();
        return;
    }
    if(psw == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("密码不能为空!!!"),QMessageBox::Yes);
        this->on_reset_clicked();
        return;
    }
    if(psw2 == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("确认密码不能为空!!!"),QMessageBox::Yes);
        this->on_reset_clicked();
        return;
    }
    if(psw != psw2){
        QMessageBox::information(this,tr("warning"),
                                 tr("两次输入的密码不一样!!!"),QMessageBox::Yes);
        this->on_reset_clicked();
        return;
    }
    std::map<std::string,Admin> & admins = this->opt->getAdmins();
    auto it = admins.find(user.toStdString());
    if(it != admins.end()){
        QMessageBox::information(this,tr("warning"),
                                 tr("该用户名已经注册，请勿重复注册!!!"),QMessageBox::Yes);
        this->on_reset_clicked();
        return;
    }
    this->opt->addAdmin(Admin(user.toStdString(),psw.toStdString()));
    QMessageBox::information(this,tr("Successful"),
                             tr("注册成功!!!"),QMessageBox::Yes);
    this->close();
}
