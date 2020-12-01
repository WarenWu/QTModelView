#include "cplatinfomodel.h"

CTableModel::CTableModel()
{    
    m_columcount = 1;
    updateRowCount(10);
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
            case 0 : return m_vecColPlatformInfo[row].CurrentName();
            default:break;
        }
    }else if(role == Qt::EditRole){
        return QVariant::fromValue(m_vecColPlatformInfo[row]);
    }

    return QVariant();
}

void CTableModel::initColInfo()
{
    for(int i = 0; i < m_rowcount; ++ i)
    {
        m_vecColPlatformInfo.push_back(CPlatformInfo());
    }

}

void CTableModel::updateRowCount(int cnt)
{   
    m_rowcount = cnt;
}

