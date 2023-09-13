#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QApplication>
#include "mymodel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTableView(QTableView&);
    void tableDisplay(QTableView*);
    void triggerAccept();



private slots:
    void on_actionTest_triggered();
    void onTableClicked(QModelIndex);

private:
    Ui::MainWindow *ui;
    QTableView* tableViewP;
};
#endif // MAINWINDOW_H
