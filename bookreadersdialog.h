#ifndef BOOKREADERSDIALOG_H
#define BOOKREADERSDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "include/BMSopt.h"
/*
 * 查询某一本书被哪些人借了
 */
namespace Ui {
class BookReadersDialog;
}

class BookReadersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookReadersDialog(QWidget *parent = 0);
    ~BookReadersDialog();

private slots:
    void on_exit_clicked();

    void on_reset_clicked();

    void on_query_clicked();

    void on_bookId_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::BookReadersDialog *ui;
    BMSopt * opt;
};

#endif // BOOKREADERSDIALOG_H
