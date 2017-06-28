#ifndef ROOT_H
#define ROOT_H
#include "Admin.h"
/*
 * 超级管理员类
 * Admin的子类
 * 主要对管理员的注册和注销操作
 * 但是管理员的功能，作为子类的它也有
 */
class Root:public Admin
{
public:
    Root();
    Root(std::string id,std::string passwd);
    //注册管理员
    void logon(Admin admin,std::map<std::string,Admin> & admins);
    //注销管理员
    void deleteAdmin(std::string adminId,std::map<std::string,Admin>  admins);
};

#endif //ROOT_A
