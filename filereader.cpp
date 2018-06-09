#include <iostream>
#include <string>
#include "filereader.h"
#include "binarysearchtree.h"
#include "ternarysearchtree.h"
#include "terminal.h"
#include <QStringList>
#include <QFile>
#include<QTime>

//
// Created by Arya on 11/30/2016.
//

void FileReader::fileAdder(){
    
    if(!dirPath.isEmpty() && !currFilesList.isEmpty()){
        for(int fileNumber=0;fileNumber<currFilesList.size();++fileNumber){
            address=(dirPath+"/"+currFilesList[fileNumber]);
            QFile file(address);
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            text=file.readAll().toLower();
            for (int i = 48; i < 57; ++i) {
                text.remove(i);
            }
            filesText.push_back(text.split(QRegExp("\\W+"), QString::SkipEmptyParts));
            file.close();
        }
    }
    else if(allFilesList.empty())
        Terminal::getInstance().writeError("specify a path");
    else
        Terminal::getInstance().writeError("specify at least a file");
}
void FileReader::addDelFileinBst(QString fileName,int add){
    QStringList fileText;
    QString fAddress=(dirPath+"/"+fileName+".txt");
    QFile file(fAddress);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    text=file.readAll().toLower();
    fileText=text.split(QRegExp("\\W+"), QString::SkipEmptyParts);
    file.close();
    switch(add){
    case 0:
        for (int i = 0; i < fileText.length(); ++i) {
            bstFile.add(fileText[i].toStdString());
            bstFile.searchN(bstFile.root,fileText[i].toStdString())->occur.append(fileName);
        }
        break;
    case 1:
        for (int i = 0; i < fileText.length(); ++i) {
            bstFile.del(fileText[i].toStdString());
        }
        break;
    case 2:
        for (int i = 0; i < fileText.length(); ++i) {
            avlBstFile.add(fileText[i].toStdString());
            avlBstFile.searchN(avlBstFile.root,fileText[i].toStdString())->occur.append(fileName);
        }
        break;
    case 3:
        for (int i = 0; i < fileText.length(); ++i) {
            avlBstFile.searchN(avlBstFile.root,fileText[i].toStdString())->occur.takeAt(
                        avlBstFile.searchN(avlBstFile.root,fileText[i].toStdString())->occur.indexOf(fileText[i]));
            if(avlBstFile.searchN(avlBstFile.root,fileText[i].toStdString())->occur.isEmpty())
                avlBstFile.del(fileText[i].toStdString());
        }
        break;
    }

}
void FileReader::addDelFileinTst(QString fileName,int add){
    QStringList fileText;
    QString fAddress=(dirPath+"/"+fileName+".txt");
    QFile file(fAddress);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    text=file.readAll().toLower();
    fileText=text.split(QRegExp("\\W+"), QString::SkipEmptyParts);
    file.close();
    switch(add){
    case 0:
        for (int i = 0; i < fileText.length(); ++i) {
            tstFile.add(fileText[i].toStdString());
            tstFile.searchN(tstFile.root,fileText[i].toStdString())->occur.append(fileName);
        }
        break;
    case 1:
        for (int i = 0; i < fileText.length(); ++i) {
            tstFile.searchN(tstFile.root,fileText[i].toStdString())->occur.takeAt(
                        tstFile.searchN(tstFile.root,fileText[i].toStdString())->occur.indexOf(fileText[i]));
            if(tstFile.searchN(tstFile.root,fileText[i].toStdString())->occur.isEmpty())
                tstFile.del(fileText[i].toStdString());
        }
        break;
    case 2:
        for (int i = 0; i < fileText.length(); ++i) {
            avlTstFile.add(fileText[i].toStdString());
            avlTstFile.searchN(avlTstFile.root,fileText[i].toStdString())->occur.append(fileName);
        }
        break;
    case 3:
        for (int i = 0; i < fileText.length(); ++i) {
            avlTstFile.searchN(avlTstFile.root,fileText[i].toStdString())->occur.takeAt(
                        avlTstFile.searchN(avlTstFile.root,fileText[i].toStdString())->occur.indexOf(fileText[i]));
            if(avlTstFile.searchN(avlTstFile.root,fileText[i].toStdString())->occur.isEmpty())
                avlTstFile.del(fileText[i].toStdString());
        }
        break;
    }

}
void FileReader::addDelFileinTrie(QString fileName,int add){
    QStringList fileText;
    QString fAddress=(dirPath+"/"+fileName+".txt");
    QFile file(fAddress);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    text=file.readAll().toLower();
    fileText=text.split(QRegExp("\\W+"), QString::SkipEmptyParts);
    file.close();
    switch(add){
    case 0:
        for (int i = 0; i < fileText.length(); ++i) {
            tFile.add(fileText[i].toStdString());
            tFile.searchN(tFile.root,fileText[i].toStdString())->occur.append(fileName);
        }
        break;
    case 1:
        for (int i = 0; i < fileText.length(); ++i) {
            tFile.searchN(tFile.root,fileText[i].toStdString())->occur.takeAt(
                        tFile.searchN(tFile.root,fileText[i].toStdString())->occur.indexOf(fileText[i]));
            if(tFile.searchN(tFile.root,fileText[i].toStdString())->occur.isEmpty())
                tFile.del(fileText[i].toStdString());
        }
        break;
    }

}
void FileReader::addDelFileinHash(QString fileName,int add){
    QStringList fileText;
    QString fAddress=(dirPath+"/"+fileName+".txt");
    QFile file(fAddress);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    text=file.readAll().toLower();
    fileText=text.split(QRegExp("\\W+"), QString::SkipEmptyParts);
    file.close();
    switch(add){
    case 0:
        for (int i = 0; i < fileText.length(); ++i) {
            hFile.add(fileText[i].toStdString());
        }
        break;
    case 1:
        for (int i = 0; i < fileText.length(); ++i) {
            hFile.del(fileText[i].toStdString());
        }
        break;
    }

}


void FileReader::fileInBst() {
//    bstFile=new BinarySearchTree();
    if(bstFile.root==0){
    Terminal::getInstance().writeLine("building the bst ...");
    for(int fileNumber=0;fileNumber<filesText.size();++fileNumber)
        for(int i=0;i<filesText.at(fileNumber).size();i++){
            std::string word=filesText.at(fileNumber).at(i).toStdString();
            if(!stopWordBst.search(word)){
                bstFile.add(word);
                if(currFilesList.last()!=currFilesList.at(fileNumber))
                    bstFile.searchN(bstFile.root,word)->occur.append(currFilesList.at(fileNumber));
            }
       }
    }
    else if(!dirPath.isEmpty())
    Terminal::getInstance().writeError("the bst has already been built!");
}
void FileReader::fileInHash() {
    Terminal::getInstance().writeLine("building Hash ...");
    for(int fileNumber=0;fileNumber<filesText.size();++fileNumber)
        for(int i=0;i<filesText.at(fileNumber).size();i++){
            std::string word=filesText.at(fileNumber).at(i).toStdString();
            if(swHash.search(word)){
                hFile.add(word);
            }
        }
}
void FileReader::fileInAvlBst() {
    if(avlBstFile.root==0){
    Terminal::getInstance().writeLine("building the Avl bst ...");
    for(int fileNumber=0;fileNumber<filesText.size();++fileNumber)
        for(int i=0;i<filesText.at(fileNumber).size();i++){
            std::string word=filesText.at(fileNumber).at(i).toStdString();
            if(!stopWordBst.search(word)){
                avlBstFile.avlAdd(word);
                if(currFilesList.last()!=currFilesList.at(fileNumber))
                    avlBstFile.searchN(avlBstFile.root,word)->occur.append(currFilesList.at(fileNumber));
            }
        }
    }
    else if(!dirPath.isEmpty())
        Terminal::getInstance().writeError("the bst has already been built!");
}

void FileReader::getStopWords(QString stopWordPath){
    this->stopWordPath=stopWordPath;
}
void FileReader::fileInTst() {
//    tstFile=new TernarySearchTree();
    if(tstFile.root==0){
    Terminal::getInstance().writeLine("building the tst ...");
    for(int fileNumber=0;fileNumber<filesText.size();++fileNumber)
        for(int i=0;i<filesText.at(fileNumber).size();i++){
            std::string word=filesText.at(fileNumber).at(i).toStdString();
            if(!stopWordTst.search(word)){
                tstFile.add(word);
                if(currFilesList.last()!=currFilesList.at(fileNumber))
                tstFile.searchN(tstFile.root,word)->occur.append(currFilesList.at(fileNumber));
            }
        }
    }
    else if(!dirPath.isEmpty())
    Terminal::getInstance().writeError("the bst has already been built!");
}

void FileReader::fileInAvlTst() {
//    tstFile=new TernarySearchTree();
    if(avlTstFile.root==0){
    Terminal::getInstance().writeLine("building the Avl tst ...");
    for(int fileNumber=0;fileNumber<filesText.size();++fileNumber)
        for(int i=0;i<filesText.at(fileNumber).size();i++){
            std::string word=filesText.at(fileNumber).at(i).toStdString();
            if(!stopWordTst.search(word)){
                avlTstFile.add(word);
                if(currFilesList.last()!=currFilesList.at(fileNumber))
                avlTstFile.searchN(avlTstFile.root,word)->occur.append(currFilesList.at(fileNumber));
            }
        }
    }
    else if(!dirPath.isEmpty())
    Terminal::getInstance().writeError("the bst has already been built!");
}

void FileReader::fileInTrie() {
    Terminal::getInstance().writeLine("building the trie ...");
    for(int fileNumber=0;fileNumber<filesText.size();++fileNumber)
        for(int i=0;i<filesText.at(fileNumber).size();i++){
            std::string word=filesText.at(fileNumber).at(i).toStdString();
            if(!stopWordT.search(word)){
                tFile.add(word);
                if(currFilesList.last()!=currFilesList.at(fileNumber))
                tFile.searchN(tFile.root,word)->occur.append(currFilesList.at(fileNumber));
            }
    }
    if(!dirPath.isEmpty())
    Terminal::getInstance().writeError("the trie has already been built!");
}

void FileReader::swInTrees() {
    if(!stopWordPath.isEmpty()){
        QFile file(stopWordPath);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        text=file.readAll().toLower();
        QStringList swList=text.split(QRegExp("\\W+"), QString::SkipEmptyParts);
        for(int i=0;i<swList.size();i++){
            stopWordBst.add(swList[i].toStdString());
            stopWordTst.add(swList[i].toStdString());
            stopWordT.add(swList[i].toStdString());
            swHash.add(swList[i].toStdString());
        }
    }
}

