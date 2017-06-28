#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H
#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 *增加图书
 */
namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBookDialog(QWidget *parent = 0);
    ~AddBookDialog();

private slots:
    void on_reset_clicked();

    void on_ok_clicked();

private:
    Ui::AddBookDialog *ui;
    BMSopt *opt;
};

#endif // ADDBOOKDIALOG_H
