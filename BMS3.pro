#-------------------------------------------------
#
# Project created by QtCreator 2017-06-26T14:45:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BMS3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    src/Admin.cpp \
    src/BMSopt.cpp \
    src/Book.cpp \
    src/Reader.cpp \
    src/Root.cpp \
    logindialog.cpp \
    addadmindialog.cpp \
    resetadmindialog.cpp \
    addreaderdialog.cpp \
    delreaderdialog.cpp \
    queryreaderdialog.cpp \
    queryadmindialog.cpp \
    addbookdialog.cpp \
    delbookdialog.cpp \
    lendbookdialog.cpp \
    retbookdialog.cpp \
    sbbooksdialog.cpp \
    bookreadersdialog.cpp \
    removelastzero.cpp

HEADERS += \
        mainwindow.h \
    include/Admin.h \
    include/BMSopt.h \
    include/Book.h \
    include/Reader.h \
    include/Root.h \
    logindialog.h \
    addadmindialog.h \
    resetadmindialog.h \
    addreaderdialog.h \
    delreaderdialog.h \
    queryreaderdialog.h \
    queryadmindialog.h \
    addbookdialog.h \
    delbookdialog.h \
    lendbookdialog.h \
    retbookdialog.h \
    sbbooksdialog.h \
    bookreadersdialog.h \
    removelastzero.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    addadmindialog.ui \
    resetadmindialog.ui \
    addreaderdialog.ui \
    delreaderdialog.ui \
    queryreaderdialog.ui \
    queryadmindialog.ui \
    addbookdialog.ui \
    delbookdialog.ui \
    lendbookdialog.ui \
    retbookdialog.ui \
    sbbooksdialog.ui \
    bookreadersdialog.ui

