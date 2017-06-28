#include "logindialog.h"
#include "ui_logindialog.h"
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
}

LoginDialog::~LoginDialog()
{
    this->opt = NULL;
    delete ui;
}

void LoginDialog::on_exit_clicked()
{
    this->close();
}

void LoginDialog::on_login_clicked()
{
    QString user = ui->userlineEdit->text().trimmed();
    QString passwd = ui->pwdlineEdit->text().trimmed();
    if(user.toStdString() == ""){
        QMessageBox::information(this,tr("warning"),tr("请输入用户名"),QMessageBox::Yes);
        ui->userlineEdit->setText("");
        ui->userlineEdit->setFocus();
        return;
    }
    if(passwd.toStdString() == ""){
        QMessageBox::information(this,tr("warning"),tr("请输入密码"),QMessageBox::Yes);
        ui->pwdlineEdit->setFocus();
        return;
    }

    this->opt = BMSopt::Instance();
    if(user.toStdString() == "root" && passwd.toStdString() == this->opt->getRootpasswd()){
        QMessageBox::information(this,tr("Successful"),
                                 tr("Login Successful!!!"),QMessageBox::Yes);
        this->opt->setOperator(user.toStdString());
        accept();
        return;
    }else if(user.toStdString() == "root" && passwd.toStdString() == this->opt->getRootpasswd()){
        QMessageBox::information(this,tr("warning"),tr("用户名或密码错误"),QMessageBox::Yes);
        ui->userlineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->userlineEdit->setFocus();
        return;
    }
    std::map<std::string,Admin>::iterator it = this->opt->getAdmins().find(user.toStdString());
    qDebug()<<user<<" "<<passwd;
    if(it->second.login(passwd.toStdString())){
        QMessageBox::information(this,tr("Successful"),
                                 tr("Login Successful!!!"),QMessageBox::Yes);
        this->opt->setOperator(user.toStdString());
        accept();
        return;
    }else{
        QMessageBox::information(this,tr("warning"),tr("用户名或密码错误"),QMessageBox::Yes);
        ui->userlineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->userlineEdit->setFocus();
        return;
    }
    return;
}
