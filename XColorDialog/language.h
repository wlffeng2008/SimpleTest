#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>
#include <QMap>

#include "languageDef.h"

//单实例
class Language {
private:
    Language() {

    }
    ~Language() {}
    bool readFile(EM_LANGUAGE type, QString filePath);

private:
    static Language* instance; // 静态实例指针
    int m_type;
    QMap<int, QString>  m_mapChn;
    QMap<int, QString>  m_mapEng;

public:
    static Language* getInstance() { // 静态公有方法用于获取实例
        if (instance == NULL) {
            instance = new Language();
        }
        return instance;
    }

    static void destory()
    {
        delete instance;
        instance = NULL;
    }

    bool loadLanguageFile(EM_LANGUAGE type);
    QString getString(int ID);
};




#endif
