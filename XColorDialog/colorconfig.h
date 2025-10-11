#ifndef COLOR_CONFIG_H
#define COLOR_CONFIG_H

#include <QColor>
#include <QString>
#include <QList>
#include <QMap>

const QString COLOR_CONFIG_FILE = "colors.xml";

class ColorConfig
{
public:
    ColorConfig(){}
    ~ColorConfig(){}
public:
    bool loadConfig(QString file = COLOR_CONFIG_FILE);
    bool saveConfig(QString file = COLOR_CONFIG_FILE);
    QList<int> getColorSet();  //获取颜色集类别
    QList<QColor> getColorList(int nSetIndex);  //获取指定颜色集下所有颜色
    bool addColor(int nSetIndex, QColor& c);  //指定颜色集下添加颜色
    bool setColor(int nSetIndex, int nIndex, QColor& c); //变更集合中指定的颜色

private:
    QString m_fileName;
    //QList<int> m_lstColorSet;
    QMap<int, QList<QColor>> m_mapColor;
};
#endif
