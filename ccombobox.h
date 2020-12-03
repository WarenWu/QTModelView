#ifndef CCOMBOBOX_H
#define CCOMBOBOX_H

#include<QComboBox>
#include "cplatforminfo.h"
class CComboBox:public QComboBox
{
public:
    CComboBox(QWidget* parent = nullptr);
public:
    CPlatformInfo m_platformInfo;
};

#endif // CCOMBOBOX_H
