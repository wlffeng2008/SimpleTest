#include "colorconfig.h"
#include <QDomElement>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


bool ColorConfig::loadConfig(QString file)
{
    m_fileName = file;
    // open file
    QFile xmlFile(m_fileName);
    if (!xmlFile.open(QFile::ReadOnly))
        return false;

    QDomDocument doc;
    if (!doc.setContent(&xmlFile))
    {
        xmlFile.close();
        return false;
    }
    xmlFile.close();

    QDomElement root = doc.documentElement();
    if (root.tagName() != "colors")
        return false;

    QDomNodeList itemList = root.childNodes();
    for(int i = 0; i < itemList.count(); i++)
    {
        QDomElement item = itemList.at(i).toElement();
        int nSetIndex = item.attribute("type").toInt();

        QDomNodeList colorList = item.childNodes();
        QList<QColor> lstColor;
        for(int c = 0; c < colorList.count(); c++)
        {
            QDomElement element = colorList.at(c).toElement();

            QColor color;
            color.setRed(element.attribute("red").toInt());
            color.setGreen(element.attribute("green").toInt());
            color.setBlue(element.attribute("blue").toInt());

            //QMessageBox::information(NULL, "color", QString("%1,%2,%3").arg(color.red()).arg(color.green()).arg(color.blue()));

            lstColor.append(color);
        }
        m_mapColor.insert(nSetIndex, lstColor);
    }

    return true;
}

bool ColorConfig::saveConfig(QString file)
{
    QString csSaveFile = m_fileName;
    if((file != m_fileName)&&("") != file) csSaveFile = file;

    QFile xmlFile(m_fileName);
    if (xmlFile.exists())
        xmlFile.remove();

    QDomDocument doc;

    //写入xml头部
    QDomProcessingInstruction instruction; //添加处理命令
    instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    QDomElement rootElement = doc.createElement("colors");
    doc.appendChild(rootElement);

    for (auto iter = m_mapColor.begin(); iter != m_mapColor.end(); ++iter)
    {
        QDomElement item = doc.createElement("item");
        item.setAttribute("type", iter.key());
        QList<QColor> lstColor = iter.value();
        for(auto it = lstColor.begin(); it != lstColor.end(); ++it)
        {
            QDomElement c = doc.createElement("color");

            c.setAttribute("red", it->red());
            c.setAttribute("green", it->green());
            c.setAttribute("blue", it->blue());

            item.appendChild(c);
        }

        rootElement.appendChild(item);
    }

    QFile xmlSaveFile(csSaveFile);
    xmlSaveFile.open(QFile::WriteOnly);
    QTextStream out_stream(&xmlSaveFile);
    doc.save(out_stream, 4);
    xmlSaveFile.close();
    return true;
}

QList<int> ColorConfig::getColorSet()  //获取颜色集类别
{
    return m_mapColor.keys();
}

QList<QColor> ColorConfig::getColorList(int nSetIndex)  //获取指定颜色集下所有颜色
{
    QList<QColor> lsdtColors;
    QMap<int, QList<QColor>>::iterator it = m_mapColor.find(nSetIndex);
    if(m_mapColor.end() == it) return lsdtColors;

    return it.value();
}
bool ColorConfig::addColor(int nSetIndex, QColor& c)  //指定颜色集下添加颜色
{
    m_mapColor[nSetIndex].append(c);
    return true;
}
bool ColorConfig::setColor(int nSetIndex, int nIndex, QColor& c) //变更集合中指定的颜色
{
    m_mapColor[nSetIndex][nIndex] = c;
    return true;
}

