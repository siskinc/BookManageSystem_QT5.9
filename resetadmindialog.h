#ifndef RESETADMINDIALOG_H
#define RESETADMINDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 * 管理员修改密码
 */
namespace Ui {
class resetAdminDialog;
}

class resetAdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit resetAdminDialog(QWidget *parent = 0);
    ~resetAdminDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_determine_clicked();

private:
    Ui::resetAdminDialog *ui;
    BMSopt * opt;
};

#endif // RESETADMINDIALOG_H
