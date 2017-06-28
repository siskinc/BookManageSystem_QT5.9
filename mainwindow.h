#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include "include/BMSopt.h"
#include "addadmindialog.h"
#include "resetadmindialog.h"
#include "addreaderdialog.h"
#include "delreaderdialog.h"
#include "queryadmindialog.h"
#include "queryreaderdialog.h"
#include "addbookdialog.h"
#include "delbookdialog.h"
#include "lendbookdialog.h"
#include "retbookdialog.h"
#include "sbbooksdialog.h"
#include "bookreadersdialog.h"
#include "removelastzero.h"
/*
 * 主界面，主要是对图书的查询
 */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_help_triggered();

    void on_exit_clicked();

    void on_viewAll_clicked();

    void on_reset_clicked();

    void on_Inquire_clicked();

    void on_logAdmin_triggered();

    void on_resetAdmin_triggered();

    void on_logReader_triggered();

    void on_delReader_triggered();

    void on_queryReader_triggered();

    void on_queryAdmin_triggered();

    void on_addBook_triggered();

    void on_delBook_triggered();

    void on_lendBook_triggered();

    void on_retBook_triggered();

    void on_bookName_cursorPositionChanged(int arg1, int arg2);

    void on_queryBooks_triggered();

    void on_queryReaders_triggered();

    void on_authorName_cursorPositionChanged(int arg1, int arg2);

    void on_bookNum_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    BMSopt * opt;
};

#endif // MAINWINDOW_H
