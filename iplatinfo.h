#ifndef IINFO_H
#define IINFO_H
#include <QString>

class IPlatInfo
{
public:
    typedef enum enum_SHOW_TYPE {
        NO = 0,
        ID = 1,
        NAME = 2
    }SHOW_TYPE;
public:
    IPlatInfo();
    virtual void Init()= 0;
    virtual QString DisplayValue() const= 0;
    virtual void SetShowType(SHOW_TYPE type)=0;
    virtual SHOW_TYPE GetShowType()=0;
    virtual ~IPlatInfo();
protected:
    SHOW_TYPE m_showType = NO;
};

#endif // IINFO_H
