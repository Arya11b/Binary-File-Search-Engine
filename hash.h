//
// Created by arya11 on 1/11/17.
//
#ifndef HASH_H
#define HASH_H



#include <string>
#include<QStringList>
class HashNode{
public:
    HashNode(std::string text);
    std::string text;
    HashNode* link;
    QStringList occur;

};
class Hash {
public:
    HashNode *hashTable[23][23];
    Hash();
    int __1stCode(std::string text);
    int __2stCode(std::string text);
    void add(HashNode* q,HashNode *&p);
    void add(std::string text);
    bool search(std::string text,HashNode* p);
    bool search(std::string text);
    void del(std::string text,HashNode* &p);
    void del(std::string text);
    void printList();
    void printNode(HashNode* hn);
};
#endif // HASH_H

