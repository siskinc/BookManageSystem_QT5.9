#include "queryadmindialog.h"
#include "ui_queryadmindialog.h"

QueryAdminDialog::QueryAdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryAdminDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员查询");
    this->opt = BMSopt::Instance();
}

QueryAdminDialog::~QueryAdminDialog()
{
    this->opt = NULL;
    delete ui;
}

void QueryAdminDialog::on_exit_clicked()
{
    this->close();
}

void QueryAdminDialog::on_query_clicked()
{
    QString user = ui->userlineEdit->text();
    if(user == "")
        return;
    QString html = tr("<table border=\"1\">")+
                          tr("<tr>")+
                          tr("<td>用户名</td>")+
                          tr("<td>密码</td>")+
                          tr("</tr>");
    std::map<std::string,Admin> & admins = this->opt->getAdmins();
    for(auto it = admins.cbegin(); it != admins.cend(); it++){
        if(it->first.find(user.toStdString()) != std::string::npos){
            Admin temp = it->second;
            html += tr("<tr>")+
                    tr("<td>")+tr(temp.getId().c_str())+tr("</td>")+
                    tr("<td>")+tr(temp.getPasswd().c_str())+tr("</td>")+
                    tr("</tr>");
        }
    }

    html += tr("</table>");
    ui->adminstext->setText(html);
}

void QueryAdminDialog::on_reset_clicked()
{
    ui->adminstext->clear();
    ui->userlineEdit->clear();
}

void QueryAdminDialog::on_queryAll_clicked()
{
    QString html = tr("<table border=\"1\">")+
                          tr("<tr>")+
                          tr("<td>用户名</td>")+
                          tr("<td>密码</td>")+
                          tr("</tr>");
    std::map<std::string,Admin> & admins = this->opt->getAdmins();
    for(auto it = admins.cbegin(); it != admins.cend(); it++){
        Admin temp = it->second;
        html += tr("<tr>")+
                tr("<td>")+tr(temp.getId().c_str())+tr("</td>")+
                tr("<td>")+tr(temp.getPasswd().c_str())+tr("</td>")+
                tr("</tr>");
    }

    html += tr("</table>");
    ui->adminstext->setText(html);
}
