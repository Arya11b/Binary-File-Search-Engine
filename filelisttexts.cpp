#include "filelisttexts.h"


FileListTexts::FileListTexts()
{

}
//void FileListTexts::getAllWords(){
//    if(!dirPath.isEmpty() && !allFilesList.isEmpty()){;
//        for(int fileNumber=0;fileNumber<allFilesList.size();++fileNumber){
//        address=(dirPath+"/"+allFilesList[fileNumber]);
//        QFile file(address);
//        file.open(QIODevice::ReadOnly | QIODevice::Text);
//        text=file.readAll().toLower();
//        QStringList list = text.split(QRegExp("\\s+"), QString::SkipEmptyParts);
//        for(int i=0;i<list.size();i++)
//                bstFile.add(list[i].toStdString());
//        file.close();
//        }
//        Terminal::getInstance().writeLine("the tree was built in "+QString::number(t.elapsed())+" mSeconds");
//    }
//    else
//        Terminal::getInstance().writeLine("specify a path");
//}

