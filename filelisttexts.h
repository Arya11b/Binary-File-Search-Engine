#ifndef FILELISTTEXTS_H
#define FILELISTTEXTS_H
#include<QString>
#include<QStringList>

class FileListTexts
{
public:
//    std::string[][] allWords;
    QString dirPath;
    QString address;
    QStringList allFilesList;
    QStringList currentFilesList;
    void getAllWords();
    FileListTexts();
};

#endif // FILELISTTEXTS_H
