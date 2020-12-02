#include "cplatforminfo.h"

CPlatformInfo::CPlatformInfo()
{
    Init();
}

void CPlatformInfo::Init()
{
    updateInfo();
    m_currentID = -1;
}

QString CPlatformInfo::CurrentName() const
{
     return  "车站1";
}

QString CPlatformInfo::CurrentID() const
{
    if(m_currentID < 0)
    {
        return "";
    }
    return QString::number(m_currentID);
}

//CPlatformInfo::~CPlatformInfo()
//{
//}

QMap<int,QString> CPlatformInfo::s_mapInfo;

void CPlatformInfo::updateInfo()
{
    s_mapInfo.insert(1,"车站1");
    s_mapInfo.insert(2,"车站2");
    s_mapInfo.insert(3,"车站3");
    s_mapInfo.insert(4,"车站4");
    s_mapInfo.insert(5,"车站5");
}
