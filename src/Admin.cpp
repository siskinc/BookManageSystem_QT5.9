#include "../include/Admin.h"

Admin::Admin()
{
    Admin("","");
}

Admin::Admin(std::string id,std::string passwd)
{
    this->m_id          =     id;
    this->m_passwd      =     passwd;
}



void Admin::input(Book book,std::map<std::string,Book> & books)
{
    auto it = books.find(book.getId());
    if(it != books.end()){
        (it->second).setNum(book.getNum());
        (it->second).setStatus(book.getNum());
    }else{
        books[book.getId()] = book;
    }
}

void Admin::logon(Reader reader,std::map<std::string,Reader> & readers)
{
    auto it = readers.find(reader.getId());
    if(it == readers.end())
        readers[reader.getId()] = reader;
}

void Admin::deleteBook(std::string bookId,std::map<std::string,Book> & books)
{
    for(auto it = books.begin(); it != books.end(); it++){
        if(it->first == bookId){
            books.erase(it);
            return;
        }
    }
    std::cout<<"对不起，找不到这本书，删除失败！"<<std::endl;
}

void Admin::deleteReader(std::string readerId, std::map<std::string,Reader> & readers)
{
    for(auto it = readers.begin(); it != readers.end(); it++){
        if( it->first == readerId ){
            readers.erase(it);
            return;
        }
    }
    std::cout<<"对不起，找不到这位读者，删除失败！"<<std::endl;
}

void Admin::retBook(std::string readerId,std::map<std::string,Reader> & readers,std::string bookId,std::map<std::string,Book> & books)
{
    auto it = readers.find(readerId);
    auto it3 = books.find(bookId);
    std::vector<std::string> & bookIds = it->second.getRecord();
    std::vector<std::string> & readerIds = it3->second.getReaderIds();
    if(it == readers.end())
        return;

    if(it3 == books.end())
        return;

    for(auto it2 = bookIds.begin(); it2 != bookIds.end();it2++){
        if(*it2 == bookId){
            bookIds.erase(it2);
            break;
        }
    }

    it3->second.setStatus(1);

    for(auto it4 = readerIds.begin(); it4 != readerIds.end(); it4++){
        if(*it4 == readerId){
            readerIds.erase(it4);
            break;
        }
    }
}

void Admin::lendBook(std::string & reader_Id,std::map<std::string,Reader> & readers,std::string bookId,std::map<std::string,Book> & books)
{
    auto it = readers.find(reader_Id);
    if(it == readers.end())
        return;
    auto it3 = books.find(bookId);
    if(it3 == books.end())
        return;
    std::vector<std::string> & bookIds = it->second.getRecord();
    bookIds.push_back(bookId);
    it3->second.setStatus(-1);
    std::vector<std::string> & readerIds = it3->second.getReaderIds();
    readerIds.push_back(reader_Id);
}

std::string Admin::getId()
{
    return this->m_id;
}

bool Admin::login(std::string passwd)
{
    bool b = true;
    if(this->m_passwd != passwd)
        b = false;
    return b;
}

std::string Admin::getPasswd()
{
    return this->m_passwd;
}
