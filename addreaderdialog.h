#ifndef ADDREADERDIALOG_H
#define ADDREADERDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 * 读者注册
 */
namespace Ui {
class AddReaderDialog;
}

class AddReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddReaderDialog(QWidget *parent = 0);
    ~AddReaderDialog();

private slots:
    void on_reset_clicked();

    void on_registered_clicked();

private:
    Ui::AddReaderDialog *ui;
    BMSopt * opt;
};

#endif // ADDREADERDIALOG_H
