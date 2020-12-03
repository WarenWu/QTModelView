#include "cplatforminfo.h"

CPlatformInfo::CPlatformInfo()
{
    Init();
}

void CPlatformInfo::Init()
{
    m_currentID = -1;
    m_currentName = "";
    updateInfo();    
}

void CPlatformInfo::SetShowType(IPlatInfo::SHOW_TYPE type)
{
    m_showType = type;
}

IPlatInfo::SHOW_TYPE CPlatformInfo::GetShowType()
{
    return m_showType;
}

QString CPlatformInfo::DisplayValue() const
{
    if(m_showType == IPlatInfo::ID && m_currentID >= 0)
    {
        return QString::number(m_currentID);
    }
    else if(m_showType == IPlatInfo::NAME)
    {
        return m_currentName;
    }
    return "";
}

bool CPlatformInfo::SetCurrentID(int id)
{
    if(s_mapInfo.find(id) == s_mapInfo.end())
    {
        return false;
    }
    m_currentID = id;
    m_currentName = s_mapInfo[id];
    return true;
}

int CPlatformInfo::GetCurrentID()
{
    return m_currentID;
}

bool CPlatformInfo::SetCurrentName(QString name)
{
    m_currentName = "";
    for(auto it = s_mapInfo.begin(); it != s_mapInfo.end(); ++it)
    {
        if(it.value() == name)
        {
            m_currentName = name;
            m_currentID = it.key();
        }
    }
    if(m_currentName == "")
        return false;
    return true;
}

QString CPlatformInfo::GetCurrentName()
{
    return m_currentName;
}


QMap<int,QString> CPlatformInfo::s_mapInfo;

void CPlatformInfo::updateInfo()
{
    s_mapInfo.insert(1,"车站1");
    s_mapInfo.insert(2,"车站2");
    s_mapInfo.insert(3,"车站3");
    s_mapInfo.insert(4,"车站4");
    s_mapInfo.insert(5,"车站5");
}
