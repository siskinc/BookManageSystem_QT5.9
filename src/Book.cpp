#include "../include/Book.h"
#include <QDebug>
Book::Book(std::string name, std::string id, double price,std::string author,  unsigned int num,unsigned int status)
{
   this->m_name        =   name;
   this->m_id          =   id;
   this->m_price       =   price;
   this->m_author      =   author;
   this->m_num         =  num;
   this->m_status      = status;
   this->init();
}
Book::Book()
{
    Book("","",0,"",0,0);
}

Book::~Book()
{
    this->toFile();
}

void Book::init()
{
    std::ifstream in("Books/"+this->getName()+".dat");
    std::string reader;
    if(!in){
        qDebug()<<"打开文件失败1";
        in.close();
    }
    while(in>>reader){
        this->m_reader_ids.push_back(reader);
    }
    in.close();
}

void Book::toFile()
{
    std::ofstream out("Books/"+this->getName()+".dat");
    for(auto it = this->getReaderIds().begin(); it != this->getReaderIds().end(); it++){
        out<<*it<<'\n';
    }
    out.close();
}
std::string Book::getName()
{
    return this->m_name;
}

std::string Book::getId()
{
    return this->m_id;
}

double Book::getPrice()
{
    return this->m_price;
}

std::string Book::getAuthor()
{
    return this->m_author;
}

bool Book::isExist()
{
    return this->m_status;
}

std::vector<std::string> & Book::getReaderIds()
{
    return this->m_reader_ids;
}

void Book::setNum(int change)
{
    auto temp = -change;
    if(temp > (int)this->m_num){
        std::cout<<"改变图书数量失败:图书变化数量大于在库数量"<<std::endl;
        return;
    }
    this->m_num += change;
}

void Book::setStatus(int change)
{
    if(-1*change > this->m_status){
        std::cout<<"改变图书在库数量失败：图书变化数量大于在库数量"<<std::endl;
        return;
    }
    this->m_status += change;
}

int Book::getNum()
{
    return this->m_num;
}

int Book::getStatus()
{
    return this->m_status;
}
