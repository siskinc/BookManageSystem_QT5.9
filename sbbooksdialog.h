#ifndef SBBOOKSDIALOG_H
#define SBBOOKSDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 * 查询某个人借了哪些书
 */
namespace Ui {
class SbBooksDialog;
}

class SbBooksDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SbBooksDialog(QWidget *parent = 0);
    ~SbBooksDialog();

private slots:
    void on_exit_clicked();

    void on_reset_clicked();

    void on_query_clicked();

    void on_readerId_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::SbBooksDialog *ui;
    BMSopt * opt;
};

#endif // SBBOOKSDIALOG_H
