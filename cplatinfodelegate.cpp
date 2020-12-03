#include "cplatinfodelegate.h"
#include "ccombobox.h"
#include "cplatforminfo.h"

CTableDelegate::CTableDelegate()
{

}

QWidget *CTableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    CComboBox * comboBox = new CComboBox(parent);
    return comboBox;
}

void CTableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    CComboBox * comboBox = static_cast<CComboBox *>(editor);
    QVariant data = index.data(Qt::EditRole);

    CPlatformInfo platformInfo;
    if (data.canConvert<CPlatformInfo>())
    {
        platformInfo = data.value<CPlatformInfo>();
        comboBox->m_platformInfo = platformInfo;
        QStringList strList;
        IPlatInfo::SHOW_TYPE showType = platformInfo.GetShowType();
        for(auto it = platformInfo.s_mapInfo.begin(); it != platformInfo.s_mapInfo.end(); ++it)
        {
            if(showType == IPlatInfo::ID)
            {
                strList.append(QString::number(it.key()));
            }
            else if(showType == IPlatInfo::NAME)
            {
                strList.append(it.value());
            }
        }
        comboBox->addItems(strList);
    }
}

void CTableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    CComboBox * comboBox = static_cast<CComboBox *>(editor);
    QString text = comboBox->currentText();
    IPlatInfo::SHOW_TYPE showType = comboBox->m_platformInfo.GetShowType();
    if(showType == IPlatInfo::ID)
    {
        comboBox->m_platformInfo.SetCurrentID(text.toInt());
    }
    else if(showType == IPlatInfo::NAME)
    {
        comboBox->m_platformInfo.SetCurrentName(text);
    }

    model->setData(index,QVariant::fromValue(comboBox->m_platformInfo),Qt::EditRole);
}

void CTableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
