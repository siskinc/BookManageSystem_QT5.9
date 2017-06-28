#include "queryreaderdialog.h"
#include "ui_queryreaderdialog.h"

QueryReaderDialog::QueryReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryReaderDialog)
{
    ui->setupUi(this);
    this->opt = BMSopt::Instance();
}

QueryReaderDialog::~QueryReaderDialog()
{
    delete ui;
}

void QueryReaderDialog::on_exit_clicked()
{
    this->close();
}

void QueryReaderDialog::on_reset_clicked()
{
    ui->name->clear();
    ui->gender->clear();
    ui->ID->clear();
    ui->readerText->clear();
}

void QueryReaderDialog::on_query_clicked()
{
    QString name = ui->name->text().trimmed();
    QString gender = ui->gender->text().trimmed();
    QString ID = ui->ID->text().trimmed();
    bool male = true;
    bool haveGender  = false;
    if(name == ""  && gender == "" && ID == "")
        return ;
    if(gender != ""){
        if(gender != "男" && gender != "女"){
            QMessageBox::information(this,tr("warning"),
                                     tr("性别处只能输入 男 或者 女"),QMessageBox::Yes);
            this->on_reset_clicked();
            return;
        }
        if(gender == "男")
            male = true;
        else
            male = false;
        haveGender = true;
    }
    QString html = tr("<table border=\"1\">")+
            tr("<tr>")+
            tr("<td>姓名</td>")+
            tr("<td>性别</td>")+
            tr("<td>ID</td>")+
            tr("</tr>");
    std::map<std::string,Reader> readers = this->opt->getReaders();
    for(auto it = readers.begin(); it != readers.end(); it++){
        Reader & temp = it->second;
        if(temp.getName().find(name.toStdString()) != std::string::npos&&
                temp.getId().find(ID.toStdString())!= std::string::npos){
            if(haveGender){
                if(male != temp.getGender())
                    continue;
            }
            html += tr("<tr>")+
                    tr("<td>")+tr(temp.getName().c_str())+tr("</td>")+
                    tr("<td>")+tr(std::to_string(temp.getGender()).c_str())+tr("</td>")+
                    tr("<td>")+tr(temp.getId().c_str())+tr("</td>")+
                    tr("</tr>");
        }
    }
    html += tr("</table>");
    ui->readerText->setText(html);
}

void QueryReaderDialog::on_queryAll_clicked()
{
    QString html = tr("<table border=\"1\">")+
            tr("<tr>")+
            tr("<td>姓名</td>")+
            tr("<td>性别</td>")+
            tr("<td>ID</td>")+
            tr("</tr>");
    std::map<std::string,Reader> readers = this->opt->getReaders();
    for(auto it = readers.begin(); it != readers.end(); it++){
        Reader & temp = it->second;
        html += tr("<tr>")+
                tr("<td>")+tr(temp.getName().c_str())+tr("</td>")+
                tr("<td>")+tr(std::to_string(temp.getGender()).c_str())+tr("</td>")+
                tr("<td>")+tr(temp.getId().c_str())+tr("</td>")+
                tr("</tr>");
    }
    html += tr("</table>");
    ui->readerText->setText(html);
}
