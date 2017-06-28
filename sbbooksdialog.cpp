#include "sbbooksdialog.h"
#include "ui_sbbooksdialog.h"

SbBooksDialog::SbBooksDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SbBooksDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("读者借阅查询");
    this->opt = BMSopt::Instance();
}

SbBooksDialog::~SbBooksDialog()
{
    this->opt = NULL;
    delete ui;
}

void SbBooksDialog::on_exit_clicked()
{
    this->close();
}

void SbBooksDialog::on_reset_clicked()
{
    ui->information->clear();
    ui->readerId->clear();
    ui->readerId->setFocus();
}

void SbBooksDialog::on_query_clicked()
{
    QString readerId = ui->readerId->text().trimmed();
    QString html = tr("<table border=\"1\">")+
            tr("<tr>")+
            tr("<td>读者编号</td>")+
            tr("<td>读者名称</td>")+
            tr("<td>读者性别</td>")+
            tr("<td>图书名称</td>")+
            tr("<td>图书作者</td>")+
            tr("<td>图书编号</td>")+
            tr("<td>图书单价</td>")+
            tr("</tr>");
    auto readers = this->opt->getReaders();
    auto books = this->opt->getBooks();
    for(auto it = readers.begin(); it != readers.end(); it++){
        Reader & reader = it->second;
        if(reader.getId().find(readerId.toStdString()) == std::string::npos)
            continue;
        std::vector<std::string> & theReaderBooks = reader.getRecord();
        for(auto it2 = theReaderBooks.begin(); it2 != theReaderBooks.end(); it2++){
            auto book = books.find(*it2);
            html += tr("<tr>")+
                    tr("<td>")+reader.getId().c_str()+("</td>")+
                    tr("<td>")+reader.getName().c_str()+("</td>")+
                    tr("<td>")+std::to_string(reader.getGender()).c_str()+("</td>")+
                    tr("<td>")+book->second.getName().c_str()+("</td>")+
                    tr("<td>")+book->second.getAuthor().c_str()+("</td>")+
                    tr("<td>")+book->second.getId().c_str()+("</td>")+
                    tr("<td>")+std::to_string(book->second.getPrice()).c_str()+("</td>")+
                    tr("</tr>");
        }
    }
    if(html != "")
        html += tr("</table>");
    ui->information->setText(html);
}

void SbBooksDialog::on_readerId_cursorPositionChanged(int arg1, int arg2)
{
    arg1,arg2;
    this->on_query_clicked();
}
