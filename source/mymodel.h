#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <string>
#include <QVector>
#include <QTableView>



class MyModel : public QAbstractTableModel
{
   Q_OBJECT
public:
    MyModel(QObject *parent = nullptr, int newRows = 0, int newColumns = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    int rows;
    int columns;
    void updateDisp();
    QModelIndex topLeft;
    QModelIndex bottomRight;
};

#endif // MYMODEL_H
