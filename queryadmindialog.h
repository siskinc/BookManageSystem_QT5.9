#ifndef QUERYADMINDIALOG_H
#define QUERYADMINDIALOG_H

#include <QDialog>
#include <QString>
#include "include/BMSopt.h"
/*
 * 查询管理员及其密码，只有超级管理员可以操作
 */
namespace Ui {
class QueryAdminDialog;
}

class QueryAdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryAdminDialog(QWidget *parent = 0);
    ~QueryAdminDialog();

private slots:
    void on_exit_clicked();

    void on_query_clicked();

    void on_reset_clicked();

    void on_queryAll_clicked();

private:
    Ui::QueryAdminDialog *ui;
    BMSopt * opt;
};

#endif // QUERYADMINDIALOG_H
