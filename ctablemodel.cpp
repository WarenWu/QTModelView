#include "ctablemodel.h"

CTableModel::CTableModel()
{
    m_colPlatform.emplace_back(CPlatform{1,"站台1"});
    m_colPlatform.emplace_back(CPlatform{2,"站台2"});
    m_colPlatform.emplace_back(CPlatform{3,"站台3"});

    m_colStation.emplace_back(CStation{1,"车站1"});
    m_colStation.emplace_back(CStation{2,"车站2"});

    m_colTask.emplace_back(CTask{1,"任务1"});
    m_colTask.emplace_back(CTask{2,"任务2"});

    m_columcount = 3;
    setRowCount();
}

int CTableModel::rowCount(const QModelIndex &parent ) const
{
    Q_UNUSED(parent);
    return m_rowcount;
}

int CTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  m_columcount;
}

QVariant CTableModel::data(const QModelIndex &index, int role) const
{
    int column = index.column();
    int row = index.row();
    if(role == Qt::DisplayRole)
    {
        switch (column) {
            case 0 : return getPlatformData(row);
            case 1 : return getStationData(row);
            case 2 : return getTaskData(row);
            default:break;
        }
    }

    return QVariant();
}


void CTableModel::setRowCount()
{
    std::vector<uint> rowCounts;
    rowCounts.push_back(m_colPlatform.size());
    rowCounts.push_back(m_colStation.size());
    rowCounts.push_back(m_colTask.size());

    std::sort(rowCounts.begin(),rowCounts.end());

    m_rowcount = rowCounts.back();
}

QVariant CTableModel::getPlatformData(int row) const
{
    int rows = m_colPlatform.size();
    if(row < rows)
        return m_colPlatform[row].name;
    return QVariant();
}

QVariant CTableModel::getStationData(int row) const
{
    int rows = m_colStation.size();
    if(row < rows)
        return m_colStation[row].name;;
    return QVariant();
}

QVariant CTableModel::getTaskData(int row) const
{
    int rows = m_colTask.size();
    if(row < rows)
        return m_colTask[row].name;
    return QVariant();
}



