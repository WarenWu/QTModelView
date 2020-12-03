#include "cplatinfomodel.h"


CTableModel::CTableModel()
{    
    m_colCount = 0;
    m_rowCount = 0;
    insertCol(0,"车站ID");
    insertCol(1,"车站Name");
    insertRow(0,"row1");
    insertRow(1,"row2");
    insertRow(2,"row3");
    initColInfo();
}

int CTableModel::rowCount(const QModelIndex &parent ) const
{
    Q_UNUSED(parent);
    return m_rowCount;
}

int CTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  m_colCount;
}

QVariant CTableModel::data(const QModelIndex &index, int role) const
{
//    if(!index.isValid())
//    {
//        return QVariant();
//    }

    int col = index.column();
    int row = index.row();
    QString colName = m_vecColHeadName[col];
    QString rowName = m_vecRowHeadName[row];
    if(role == Qt::DisplayRole)
    {
        CPlatformInfo* info = static_cast<CPlatformInfo*>(m_mapCols[colName][rowName].data()) ;
        QString ret = info->DisplayValue();
        return ret;
    }
    else if(role == Qt::EditRole)
    {
        CPlatformInfo info = *(static_cast<CPlatformInfo*>(m_mapCols[colName][rowName].data())) ;
        //return QVariant::fromValue(CPlatformInfo());
        return QVariant::fromValue(info);
        //return "";
    };

    return QVariant();
}

QVariant CTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            return m_vecColHeadName[section];
        }
        else if(orientation == Qt::Vertical)
        {
            return m_vecRowHeadName[section];
        }
    }
    else
    {
        return QVariant();
    }
    return QVariant();
}

Qt::ItemFlags CTableModel::flags(const QModelIndex &index) const
{
//    if(!index.isValid())
//    {
//        return Qt::NoItemFlags;
//    }
    Q_UNUSED(index);
    return Qt::ItemIsEditable|Qt::ItemIsSelectable|Qt::ItemIsEnabled;
}

bool CTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //    if(!index.isValid())
    //    {
    //        return false;
    //    }

    int col = index.column();
    int row = index.row();
    QString colName = m_vecColHeadName[col];
    QString rowName = m_vecRowHeadName[row];
    if(role == Qt::EditRole)
    {
        CPlatformInfo platformInfo;
        if (value.canConvert<CPlatformInfo>())
        {
            CPlatformInfo*  platformInfo = new CPlatformInfo(value.value<CPlatformInfo>());
            m_mapCols[colName][rowName] =  QSharedPointer<IPlatInfo>(platformInfo);
        }

    }
    return true;
}

bool CTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return true;
}

int CTableModel::insertRow(int index, QString rowName)
{
    return insert(Qt::Vertical,index,rowName);
}

int CTableModel::insertCol(int index, QString colName)
{
    return insert(Qt::Horizontal,index,colName);
}

int CTableModel::insert(Qt::Orientation orientation, int index, QString name)
{
    if(name == "")
        name = QString::number(index + 1);

    QVector<QString> obj;

    if(orientation == Qt::Horizontal){
        obj = m_vecColHeadName;
    }else if(orientation == Qt::Vertical){
        obj = m_vecRowHeadName;
    }

    int retIndex = -1;

    if(index >= obj.size())
    {
        obj.push_back(name);
        retIndex = obj.size() - 1;
    }
    else if(index < 0)
    {
        obj.prepend(name);
        retIndex = 0;
    }
    else
    {
        obj.insert(index,name);
        retIndex = index;
    }

    if(orientation == Qt::Horizontal){
        m_vecColHeadName = obj;
        m_colCount = obj.size();
    }else if(orientation == Qt::Vertical){
        m_vecRowHeadName = obj;
        m_rowCount = obj.size();
    }
    return retIndex;
}



void CTableModel::initColInfo()
{
    QMap<QString,QSharedPointer<IPlatInfo>> vecColPlatformInfo;
    for(int i = 0; i < m_colCount; ++ i)
    {
        for(int j = 0; j < m_rowCount; ++ j)
        {
            IPlatInfo* pPlatformInfo = new CPlatformInfo();
            if(i == 0)
            {
                pPlatformInfo->SetShowType(IPlatInfo::ID);
            }
            else
            {
                pPlatformInfo->SetShowType(IPlatInfo::NAME);
            }

            vecColPlatformInfo.insert(m_vecRowHeadName[j],QSharedPointer<IPlatInfo>(pPlatformInfo));
        }

        m_mapCols.insert(m_vecColHeadName[i],vecColPlatformInfo);
    }

}

