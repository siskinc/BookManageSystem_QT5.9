#ifndef READER_H
#define READER_H
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
/*
 * 读者类
 *
 */
class Reader
{
private:
    //读者姓名
    std::string                 m_name;
    //读者性别，男性为true，女性为false
    bool                        m_gender;
    //读者学号
    std::string    m_id;
    //读者已借书籍
    std::vector<std::string>    m_record;
public:
    Reader();
    Reader(std::string name,bool gender,std::string id);
    ~Reader();
    //init()函数用于从文件读取信息初始化读者的m_record成员，返回值为bool，如果成功返回true，失败则返回false
    void init();
    //将图书ID写入文件
    void toFile();
    //获取读者姓名
    std::string getName();
    //获取读者性别
    bool getGender();
    //获取读者学号
    std::string getId();
    //获取已接书籍名称
    std::vector<std::string> & getRecord();

    //友元函数 重载 << >>
    //friend std::ostream & operator<< (std::ostream &out, Reader & reader);
    //friend std::istream & operator>> (std::istream &in, Reader &reader);
};

#endif // READER_H
