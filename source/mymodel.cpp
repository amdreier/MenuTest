#include "mymodel.h"
#include "headerCpp.h"
#include "pages.h"
#include "player.h"
#include "mainwindow.h"

QVector<QVector<QString>> modelMap;



MyModel::MyModel(QObject *parent, int newRows, int newColumns) : QAbstractTableModel(parent)
{
    rows = newRows;
    columns = newColumns;
  //  connect(ui->actionTest, &QAction::triggered, this,  &MainWindow::triggerAccept);
}

int MyModel::rowCount(const QModelIndex & /*parent*/) const
{
   return rows;
}

int MyModel::columnCount(const QModelIndex & /*parent*/) const
{
    return columns;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
       return QString("%1")
               .arg(modelMap[index.column()][index.row()]);

    QModelIndex topLeft = createIndex(0,0);
    QModelIndex bottomRight = createIndex(rows, columns);

    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal && pages[page].headers != emptyVec) {
        if (section == 0 && columns > 0)
        {
            return QString(pages[page].headers[0]);
        } else if (section == 1 && columns > 1)
        {
            return QString(pages[page].headers[1]);
        } else if ((section == 2 && columns > 2))
        {
            return QString(pages[page].headers[2]);
        }
    }

    return QVariant();
}


void MyModel::updateDisp()
{

}
