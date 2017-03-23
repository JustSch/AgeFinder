// When a user puts in the month, date and year they were born the program
//compares to system date and month and shows age in messagebox
//Justin Schreiber 2016
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
