#ifndef CTABLEMODEL_H
#define CTABLEMODEL_H
#include <QAbstractTableModel>
#include "cplatforminfo.h"
#include "iplatinfo.h"
#include <QVector>
#include <QSharedPointer>

class CTableModel:public QAbstractTableModel
{

public:
    CTableModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
    //bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    //bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

private:
    int insertRow(int index, QString rowName = "");
    int insertCol(int index,  QString colName = "");
    int insert( Qt::Orientation orientation, int index,  QString colName = "");
    void initColInfo();

private:


private:
    int m_rowCount;
    int m_colCount;
    QVector<QString> m_vecColHeadName;
    QVector<QString> m_vecRowHeadName;
    QMap<QString, QMap<QString,QSharedPointer<IPlatInfo> > > m_mapCols;
};

#endif // CTABLEMODEL_H
