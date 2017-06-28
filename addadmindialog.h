#ifndef ADDADMINDIALOG_H
#define ADDADMINDIALOG_H
#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 * 管理员的注册
 */
namespace Ui {
class AddAdminDialog;
}

class AddAdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAdminDialog(QWidget *parent = 0);
    ~AddAdminDialog();

private slots:
    void on_reset_clicked();

    void on_registe_clicked();

private:
    Ui::AddAdminDialog *ui;
    BMSopt * opt;
};

#endif // ADDADMINDIALOG_H
