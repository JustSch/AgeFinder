//Justin Schreiber 2016

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QDate>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::GetSysYear()   //Gets System Year and puts it to integer
{
    QDate year = QDate::currentDate();
    QString yearString = year.toString("yyyy");
    int yearNum2 = yearString.toInt();
    return yearNum2;

}
int MainWindow::GetSysMonth()  //Gets System Month and puts it to integers
{
    QDate month = QDate::currentDate();
    QString monthString = month.toString("MM");
    int m2 = monthString.toInt();
    return  m2;
}
int MainWindow::GetSysDay()  //Gets System Day and puts it to integer
{
    QDate day = QDate::currentDate();
    QString dayString = day.toString("d");
    int d2 = dayString.toInt();
    return d2;
}
bool MainWindow::SolveMonth(int SysMonthA, int AgeMonthA) // Finds if the month of the birthday has passed
{
    if (SysMonthA >= AgeMonthA) return true;
    return false;
}
bool MainWindow::SolveDay(int SysDayA, int AgeDayA)
{
    if (SysDayA >= AgeDayA) return true;
    return false;
}
int MainWindow::SolveAge(int AgeYear, int AgeMonth, int AgeDay, int SysMonth, int SysYear, int SysDay)
{
    int y = SysYear - AgeYear;                                              // -1 if bithday has not passed yet
    if (MainWindow::SolveMonth(SysMonth, AgeMonth) == false) return y - 1;
    if (MainWindow::SolveDay(SysDay, AgeDay) == false) return y - 1;

    return y;
}
void MainWindow::on_pushButton_clicked()
{

    int age;
    QString ageMonthNum = ui->lineEdit->text();  // Retrieves month of Birthday as a QString
    QString ageYearNum = ui->lineEdit_2->text(); //Retrieves year of Birthday as a QString
    QString ageDayNum = ui->lineEdit_3->text();  // Retrieves day of Birthday as a QSting
    int ageYear = ageYearNum.toInt(); // Changes year of Birthday to int
    int ageMonth = ageMonthNum.toInt(); // Changes month of Birthday to int
    int ageDay = ageDayNum.toInt();   //Changes day of Birthday to int
    int sysMonth = GetSysMonth(); //put system month to int variable
    int sysYear = GetSysYear();  // puts system year to int variable
    int sysDay = GetSysDay();  //Puts system day to int variable
    age = MainWindow::SolveAge(ageYear, ageMonth, ageDay, sysMonth, sysYear, sysDay); // Finds age
    QMessageBox msgBox;
    msgBox.setText("Your age is: ");
    msgBox.setInformativeText(QString("").append(QVariant(age).toString())); //Puts age in MessageBox
    msgBox.exec();

}


