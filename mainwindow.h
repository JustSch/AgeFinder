#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int GetYear();
    int GetSysYear();
    int SolveAge(int, int, int, int, int, int);
    int GetSysMonth();
    bool SolveMonth(int, int);
    int GetSysDay();
    bool SolveDay(int, int);
};

#endif // MAINWINDOW_H
