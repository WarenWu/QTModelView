#ifndef CTABLEMODEL_H
#define CTABLEMODEL_H
#include <QAbstractTableModel>
#include <cplatforminfo.h>
#include <QVector>

class CTableModel:public QAbstractTableModel
{

public:
    CTableModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    //Qt::ItemFlags flags(const QModelIndex &index) const;
    //bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    //bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
    //bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    //bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

private:
    void initColInfo();
    void updateRowCount(int cnt);

private:


private:
    int m_rowcount;
    int m_columcount;
    QVector<CPlatformInfo> m_vecColPlatformInfo;
};

#endif // CTABLEMODEL_H
