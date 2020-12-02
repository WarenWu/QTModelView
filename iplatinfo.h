#ifndef IINFO_H
#define IINFO_H
#include <QString>

class IPlatInfo
{
public:
    IPlatInfo();
    virtual void Init()= 0;
    virtual QString CurrentName() const= 0;
    virtual QString CurrentID() const= 0;
    //virtual ~IPlatInfo(){};
};


#endif // IINFO_H
