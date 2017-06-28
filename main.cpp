#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(700,400);
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }else
        return 0;
}
