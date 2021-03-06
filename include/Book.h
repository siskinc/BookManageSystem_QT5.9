#ifndef BOOK_H
#define BOOK_H
#include "Reader.h"

/*
 * 图书类
 */
class Book
{
public:
    Book(std::string name , std::string id, float price , std::string author , unsigned int num,unsigned int status);
    Book();
    ~Book();
    //从文件获取借书人ID
    void init();
    //将借书人ID写入文件
    void toFile();
    //获取图书名称
    std::string getName();
    //获取图书编号
    std::string getId();
    //获取图书单价
    float getPrice();
    //获取图书作者名
    std::string getAuthor();
    //图书是否在库，若在库，则返回true，反之返回false
    bool isExist();
    //获取借书人编号
    std::vector<std::string> & getReaderIds();
    //设置图书的数量
    //change是图书改变的数量，可以是正是负
    //如果是负，其绝对值不可大于图书在库的数量
    void setNum(int change);
    //设置图书的在库数量
    void setStatus(int change);
    //获取图书的数量
    int getNum();
    //获取图书的在库数量
    int getStatus();
private:
    //图书名称
    std::string m_name;
    //图书编号
    std::string m_id;
    //图书的单价，注意小数位数
    float m_price;
    //图书的作者
    std::string m_author;
    //图书在库数量
    int m_status;
    //借书人的id，如果没有，默认为Null
    std::vector<std::string> m_reader_ids;
    //图书的数量
    int m_num;
};

#endif // BOOK_H
