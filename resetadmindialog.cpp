#include "resetadmindialog.h"
#include "ui_resetadmindialog.h"

resetAdminDialog::resetAdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resetAdminDialog)
{
    ui->setupUi(this);
    this->opt = BMSopt::Instance();
    this->setWindowTitle("修改密码");
}

resetAdminDialog::~resetAdminDialog()
{
    this->opt = NULL;
    delete ui;
}

void resetAdminDialog::on_pushButton_2_clicked()
{
    ui->oldpsw->clear();
    ui->newpsd->clear();
    ui->newpsd2->clear();
    ui->oldpsw->setFocus();
}

void resetAdminDialog::on_determine_clicked()
{
    std::string oldpsw = ui->oldpsw->text().toStdString();
    std::string newpsw = ui->newpsd->text().toStdString();
    std::string newpsw2 = ui->newpsd2->text().toStdString();
    std::string Operator = this->opt->getOperator();

    if(oldpsw == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入旧密码"),QMessageBox::Yes);
        ui->oldpsw->setFocus();
        return;
    }

    if(newpsw == ""){
        QMessageBox::information(this,tr("warning"),
                                 tr("请输入新密码"),QMessageBox::Yes);
        ui->newpsd->setFocus();
        return;
    }

    if(newpsw2 == ""){
        QMessageBox::information(this,tr("warning")
                                 ,tr("请输入确认密码"),QMessageBox::Yes);
        ui->newpsd2->setFocus();
        return;
    }

    if(newpsw != newpsw2){
        QMessageBox::information(this,tr("warning"),
                                 tr("两次密码输入不一致!!!"),QMessageBox::Yes);
        on_pushButton_2_clicked();
        return;
    }

    if(Operator == "root"){
        if(oldpsw == this->opt->getRootpasswd()){
            this->opt->resetRootPasswd(newpsw);
            goto End;
        }else{
            QMessageBox::information(this,tr("warning"),
                                     tr("密码输入错误"),QMessageBox::Yes);
            this->on_pushButton_2_clicked();
            return;
        }
    }

    this->opt->deleteAdmin(this->opt->getOperator());
    this->opt->addAdmin(Admin(this->opt->getOperator(),newpsw));
End:
    QMessageBox::information(this,tr("Successful"),
                             tr("密码修改成功"),QMessageBox::Yes);
    this->close();
}
