//
// Created by Arya on 11/30/2016.
//

#ifndef DSPROJECT_FILEREADER_H
#define DSPROJECT_FILEREADER_H

#include <fstream>
#include "binarysearchtree.h"
#include "ternarysearchtree.h"
#include "trie.h"
#include "hash.h"

#include <vector>
#include <string>
#include<QFile>
#include<QString>
#include<QStringList>


class FileReader {
public:
    QString stopWordPath;
    QString dirPath;
    QString address;
    QStringList allFilesList;
    QStringList currFilesList;
    BinarySearchTree bstFile,stopWordBst,avlBstFile;
    TernarySearchTree tstFile,stopWordTst,avlTstFile;
    Hash hFile,swHash;
    Trie tFile,stopWordT;
    QString text;
    std::vector<QStringList> filesText;
    std::ifstream stopWords;
    void getStopWords(QString stopWords);

    void fileInBst();
    void fileInTst();
    void fileInTrie();

    void fileInAvlBst();
    void fileInAvlTst();

    void fileInHash();

    void fileAdder();

    void swInTrees();

    void addDelFileinBst(QString fileName,int add);
    void addDelFileinTst(QString fileName,int add);
    void addDelFileinTrie(QString fileName,int add);
    void addDelFileinHash(QString fileName,int add);


    std::string removeIndent(char* &text);
};


#endif //DSPROJECT_FILEREADER_H
