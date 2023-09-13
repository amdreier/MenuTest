#include "mainwindow.h"
#include "mymodel.h"
#include "headerCpp.h"
#include "player.h"
#include "pages.h"



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

//    MyModel myModel(nullptr, 3, 3);

    QTableView tableView;

    w.setTableView(tableView);

    w.tableDisplay(&tableView);
  //  tableView.setModel(&myModel);

    w.setCentralWidget(&tableView);
    tableView.show();

    w.show();
   // QObject::connect(&tableView, SIGNAL(clicked(QModelIndex)), &w, SLOT(onTableClicked(QModelIndex)));

    return a.exec();

}
