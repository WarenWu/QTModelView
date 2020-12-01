#ifndef CPLATFORMINFO_H
#define CPLATFORMINFO_H
#include "iplatinfo.h"
#include <QMap>
#include <bits/ios_base.h>
#include <QMetaType>

class CPlatformInfo:public IPlatInfo
{
public:
    CPlatformInfo();
    void Init() override;
    QString CurrentName() const override;
private:
    static void updateInfo();
private:
    int m_currentID;
    static QMap<int,QString> s_mapInfo;
};
Q_DECLARE_METATYPE(CPlatformInfo)
#endif // CPLATFORMINFO_H
