#ifndef RETBOOKDIALOG_H
#define RETBOOKDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include "include/BMSopt.h"
/*
 * 还书操作
 */
namespace Ui {
class RetBookDialog;
}

class RetBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RetBookDialog(QWidget *parent = 0);
    ~RetBookDialog();

private slots:
    void on_exit_clicked();

    void on_reset_clicked();

    void on_check1_clicked();

    void on_check2_clicked();

    void on_ret_clicked();

private:
    Ui::RetBookDialog *ui;
    BMSopt * opt;
};

#endif // RETBOOKDIALOG_H
