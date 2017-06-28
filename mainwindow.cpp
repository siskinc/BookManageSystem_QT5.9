#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    opt = BMSopt::Instance();
    this->setWindowTitle("四川理工学院图书管理系统");
    ui->bookName->setFocus();
}

MainWindow::~MainWindow()
{
    this->opt = NULL;
    delete ui;
}


void MainWindow::on_help_triggered()
{
    QMessageBox::information(this,tr("help"),tr("制作人:\n")+
                                                tr("陈纪宏,熊杰,刘小平"),QMessageBox::Yes);
}

void MainWindow::on_exit_clicked()
{
    this->close();
}

void MainWindow::on_viewAll_clicked()
{
    std::map<std::string,Book> & books = this->opt->getBooks();
    QString html = tr("<table border=\"1\">")+
                          tr("<tr>")+
                          tr("<td>图书名称</td>")+
                          tr("<td>图书作者</td>")+
                          tr("<td>图书编号</td>")+
                          tr("<td>图书单价</td>")+
                          tr("<td>在库数量</td>")+
                          tr("<td>所有数量</td>")+
                          tr("</tr>");

    for(auto it = books.begin(); it != books.end(); it++){
        html += tr("<tr>")+
                tr("<td>")+it->second.getName().c_str()+("</td>")+
                tr("<td>")+it->second.getAuthor().c_str()+("</td>")+
                tr("<td>")+it->second.getId().c_str()+("</td>")+
                tr("<td>")+tr(std::to_string(it->second.getPrice()).c_str())+("</td>")+
                tr("<td>")+tr(std::to_string(it->second.getStatus()).c_str())+("</td>")+
                tr("<td>")+tr(std::to_string(it->second.getNum()).c_str())+("</td>")+
                tr("</tr>");
    }
    html += tr("</table>");
    ui->BooksText->setText(html);
}

void MainWindow::on_reset_clicked()
{
    ui->bookName->setText("");
    ui->authorName->setText("");
    ui->bookNum->setText("");
    ui->BooksText->setText("");
    ui->bookName->setFocus();
}

void MainWindow::on_Inquire_clicked()
{
    std::map<std::string,Book> & books = this->opt->getBooks();
    std::vector<Book> rightBooks;
    std::string bookName = ui->bookName->text().trimmed().toStdString();
    std::string authorName = ui->authorName->text().trimmed().toStdString();
    std::string bookNum = ui->bookNum->text().trimmed().toStdString();
    if(bookName == "" &&
       authorName == "" &&
       bookNum == "")
        return;
//    std::string tt = "123";
//    if(tt.find(std::string("")) != std::string::npos){
//        qDebug()<<"OK";
//    }
    Book * tempBook;
    std::string temp_Id,temp_Author,temp_Name;
    QString html = tr("<table border=\"1\">")+
                          tr("<tr>")+
                          tr("<td>图书名称</td>")+
                          tr("<td>图书作者</td>")+
                          tr("<td>图书编号</td>")+
                          tr("<td>图书单价</td>")+
                          tr("<td>在库数量</td>")+
                          tr("<td>所有数量</td>")+
                          tr("</tr>");
    for(auto it = books.begin(); it != books.end(); it++){
        tempBook = &it->second;
        temp_Author = tempBook->getAuthor();
        temp_Id = tempBook->getId();
        temp_Name = tempBook->getName();
        if((temp_Name.find(bookName) != std::string::npos)&&
                    (temp_Author.find(authorName) != std::string::npos)&&
                    (temp_Id.find(bookNum) != std::string::npos))
            html += tr("<tr>")+
                        tr("<td>")+tempBook->getName().c_str()+("</td>")+
                        tr("<td>")+tempBook->getAuthor().c_str()+("</td>")+
                        tr("<td>")+tempBook->getId().c_str()+("</td>")+
                        tr("<td>")+tr(std::to_string(tempBook->getPrice()).c_str())+("</td>")+
                        tr("<td>")+tr(std::to_string(tempBook->getStatus()).c_str())+("</td>")+
                        tr("<td>")+tr(std::to_string(tempBook->getNum()).c_str())+("</td>")+
                        tr("</tr>");

    }



    html += tr("</table>");
    ui->BooksText->setText(html);
}

void MainWindow::on_logAdmin_triggered()
{
    if(this->opt->getOperator() != "root"){
        QMessageBox::information(this,tr("warning"),
                                 tr("您不是超级管理员，无权此操作"),QMessageBox::Yes);
        return;
    }
    AddAdminDialog AddAdmin;
    AddAdmin.exec();
}

void MainWindow::on_resetAdmin_triggered()
{
    resetAdminDialog resetAdmin;
    resetAdmin.exec();
}

void MainWindow::on_logReader_triggered()
{
    AddReaderDialog addReader;
    addReader.exec();
}

void MainWindow::on_delReader_triggered()
{
    DelReaderDialog delReader;
    delReader.exec();
}

void MainWindow::on_queryReader_triggered()
{
    QueryReaderDialog queryReader;
    queryReader.exec();
}

void MainWindow::on_queryAdmin_triggered()
{

    if(this->opt->getOperator() != "root"){
        QMessageBox::information(this,tr("warning"),
                                 tr("您不是超级管理员，无权此操作"),QMessageBox::Yes);
        return;
    }
    QueryAdminDialog queryAdmin;
    queryAdmin.exec();
}

void MainWindow::on_addBook_triggered()
{
    AddBookDialog addBook;
    addBook.exec();
}

void MainWindow::on_delBook_triggered()
{
    DelBookDialog delBook;
    delBook.exec();
}

void MainWindow::on_lendBook_triggered()
{
    LendBookDialog lendBook;
    lendBook.exec();
}

void MainWindow::on_retBook_triggered()
{
    RetBookDialog retBook;
    retBook.exec();
}

void MainWindow::on_bookName_cursorPositionChanged(int arg1, int arg2)
{
    this->on_Inquire_clicked();
}

void MainWindow::on_queryBooks_triggered()
{
    SbBooksDialog sbBooks;
    sbBooks.exec();
}

void MainWindow::on_queryReaders_triggered()
{
    BookReadersDialog bookReaders;
    bookReaders.exec();
}

void MainWindow::on_authorName_cursorPositionChanged(int arg1, int arg2)
{
    this->on_Inquire_clicked();
}

void MainWindow::on_bookNum_cursorPositionChanged(int arg1, int arg2)
{
    this->on_Inquire_clicked();
}
