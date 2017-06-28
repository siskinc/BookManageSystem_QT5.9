#include "../include/Reader.h"

Reader::Reader()
{
    Reader("",true,"");
}

Reader::Reader(std::string name,bool gender,std::string id)
{
    this->m_name   =   name;
    this->m_gender =   gender;
    this->m_id     =   id;
    this->init();
}

Reader::~Reader()
{
    this->toFile();
}

void Reader::toFile()
{
    std::string filename = "Readers/"+this->m_name +".dat";
    std::ofstream out(filename,std::ios_base::out|std::ios_base::binary);
    if(!out){
        out.close();
        return;
    }
    for(auto it = this->getRecord().begin(); it != this->getRecord().end(); it++){
        out<<*it<<std::endl;
    }
    out.close();
}

void Reader::init()
{
    std::string filename = "Readers/"+this->m_name + ".dat";
    std::ifstream in(filename,std::ios::binary|std::ios_base::in);
    if(!in){
        in.close();
        return;
    }
    m_record.clear();
    std::string book_name;
    while(in>>book_name){
        this->m_record.push_back(book_name);
    }
    in.close();
    return;
}

bool Reader::getGender()
{
    return this->m_gender;
}

std::string Reader::getId()
{
    return this->m_id;
}

std::vector<std::string> & Reader::getRecord()
{
    return this->m_record;
}

std::string Reader::getName()
{
    return this->m_name;
}

