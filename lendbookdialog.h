#ifndef LENDBOOKDIALOG_H
#define LENDBOOKDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 * 借书操作
 */
namespace Ui {
class LendBookDialog;
}

class LendBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LendBookDialog(QWidget *parent = 0);
    ~LendBookDialog();

private slots:
    void on_exit_clicked();

    void on_reset_clicked();

    void on_sureBookId_clicked();

    void on_sureReaderId_clicked();

    void on_lend_clicked();

private:
    Ui::LendBookDialog *ui;
    BMSopt * opt;
};

#endif // LENDBOOKDIALOG_H
