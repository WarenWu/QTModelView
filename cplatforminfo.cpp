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
    if (m_currentID != -1){
        return  s_mapInfo[m_currentID];
    }
    return "";
}

void CPlatformInfo::updateInfo()
{
    s_mapInfo.insert(1,"车站1");
    s_mapInfo.insert(2,"车站2");
    s_mapInfo.insert(3,"车站3");
    s_mapInfo.insert(4,"车站4");
    s_mapInfo.insert(5,"车站5");
}
