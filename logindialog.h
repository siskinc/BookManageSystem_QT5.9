#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "include/BMSopt.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>
/*
 * 登录界面
 */
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
private slots:
    void on_exit_clicked();

    void on_login_clicked();

private:
    Ui::LoginDialog *ui;
    BMSopt * opt;
};

#endif // LOGINDIALOG_H
