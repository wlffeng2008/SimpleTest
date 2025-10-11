#include "language.h"
#include <QFile>
#include <QTextStream>

Language* Language::instance = NULL;

bool Language::readFile(EM_LANGUAGE type, QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //qDebug() << "无法打开文件" << fileName;
        return false;
     }

    QTextStream in(&file);
    while (!in.atEnd()) {
       QString line = in.readLine();
       //qDebug() << line;

       int pos = line.indexOf(',');
       int key = atoi(line.left(pos).toStdString().c_str());
       QString value = line.mid(pos+1);

       switch (type) {
         case EML_CHN: m_mapChn[key]= value; break;
         case EML_ENG: m_mapEng[key]= value; break;
       }
    }

    file.close();

    return true;
}

bool Language::loadLanguageFile(EM_LANGUAGE type)
{
    m_type = type;
    readFile(EML_CHN, "language/cn.txt");
    readFile(EML_ENG, "language/en.txt");

    return true;
}
QString Language::getString(int ID)
{
    QString strRet = "";
    switch (m_type) {
      case EML_CHN: strRet = m_mapChn.value(ID); break;
      case EML_ENG: strRet = m_mapEng.value(ID); break;
    }

    return strRet;
}
