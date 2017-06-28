#ifndef QUERYREADERDIALOG_H
#define QUERYREADERDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 * 查询读者操作
 */
namespace Ui {
class QueryReaderDialog;
}

class QueryReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryReaderDialog(QWidget *parent = 0);
    ~QueryReaderDialog();

private slots:
    void on_exit_clicked();

    void on_reset_clicked();

    void on_query_clicked();

    void on_queryAll_clicked();

private:
    Ui::QueryReaderDialog *ui;
    BMSopt * opt;
};

#endif // QUERYREADERDIALOG_H
