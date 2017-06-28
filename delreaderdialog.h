#ifndef DELREADERDIALOG_H
#define DELREADERDIALOG_H

#include <QDialog>
#include <QString>
#include "include/BMSopt.h"
#include <QMessageBox>
/*
 * 注销读者
 */
namespace Ui {
class DelReaderDialog;
}

class DelReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DelReaderDialog(QWidget *parent = 0);
    ~DelReaderDialog();

private slots:
    void on_exit_clicked();

    void on_ok_clicked();

private:
    Ui::DelReaderDialog *ui;
    BMSopt * opt;
};

#endif // DELREADERDIALOG_H
