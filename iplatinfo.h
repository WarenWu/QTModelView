#ifndef IINFO_H
#define IINFO_H
#include <QString>

class IPlatInfo
{
public:
    IPlatInfo();
    virtual void Init()= 0;
    virtual QString CurrentName() const= 0;
};

#endif // IINFO_H
