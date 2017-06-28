#ifndef DELBOOKDIALOG_H
#define DELBOOKDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 * 删除图书
 */
namespace Ui {
class DelBookDialog;
}

class DelBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DelBookDialog(QWidget *parent = 0);
    ~DelBookDialog();

private slots:
    void on_exit_clicked();

    void on_reset_clicked();

    void on_del_clicked();

private:
    Ui::DelBookDialog *ui;
    BMSopt * opt;
};

#endif // DELBOOKDIALOG_H
