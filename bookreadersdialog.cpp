#include "bookreadersdialog.h"
#include "ui_bookreadersdialog.h"

BookReadersDialog::BookReadersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookReadersDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("读者借阅查询");
    this->opt = BMSopt::Instance();
}

BookReadersDialog::~BookReadersDialog()
{
    this->opt = NULL;
    delete ui;
}

void BookReadersDialog::on_exit_clicked()
{
    this->close();
}

void BookReadersDialog::on_reset_clicked()
{
    ui->bookId->clear();
    ui->information->clear();
    ui->bookId->setFocus();
}

void BookReadersDialog::on_query_clicked()
{
    QString bookId = ui->bookId->text().trimmed();
    QString html = tr("<table border=\"1\">")+
            tr("<tr>")+
            tr("<td>图书名称</td>")+
            tr("<td>图书作者</td>")+
            tr("<td>图书编号</td>")+
            tr("<td>图书单价</td>")+
            tr("<td>读者编号</td>")+
            tr("<td>读者名称</td>")+
            tr("<td>读者性别</td>")+
            tr("</tr>");
    auto readers = this->opt->getReaders();
    auto books = this->opt->getBooks();
    for(auto it = books.begin(); it != books.end(); it++){
        Book & book = it->second;
        if(book.getId().find(bookId.toStdString()) == std::string::npos)
            continue;
        std::vector<std::string> & theBookReaders = book.getReaderIds();
        for(auto it2 = theBookReaders.begin(); it2 != theBookReaders.end(); it2++){
            auto reader = readers.find(*it2);
            html += tr("<tr>")+
                    tr("<td>")+book.getName().c_str()+("</td>")+
                    tr("<td>")+book.getAuthor().c_str()+("</td>")+
                    tr("<td>")+book.getId().c_str()+("</td>")+
                    tr("<td>")+std::to_string(book.getPrice()).c_str()+("</td>")+
                    tr("<td>")+reader->second.getId().c_str()+("</td>")+
                    tr("<td>")+reader->second.getName().c_str()+("</td>")+
                    tr("<td>")+std::to_string(reader->second.getGender()).c_str()+("</td>")+
                    tr("</tr>");
        }
    }
    html += tr("</table>");
    ui->information->setText(html);
}

void BookReadersDialog::on_bookId_cursorPositionChanged(int arg1, int arg2)
{
    arg1,arg2;
    this->on_query_clicked();
}
