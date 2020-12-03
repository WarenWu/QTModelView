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
    void SetShowType(SHOW_TYPE type) override;
    SHOW_TYPE GetShowType()override;
    QString DisplayValue() const override;

    bool SetCurrentID(int id);
    int GetCurrentID();
    bool SetCurrentName(QString name);
    QString GetCurrentName();

private:
    static void updateInfo();

private:
    int m_currentID;
    QString m_currentName;
public:
    static QMap<int,QString> s_mapInfo;
};
Q_DECLARE_METATYPE(CPlatformInfo)
#endif // CPLATFORMINFO_H
