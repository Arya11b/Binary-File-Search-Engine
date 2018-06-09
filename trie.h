//
// Created by arya11 on 12/13/16.
//

#ifndef DSPROJECT_TRIE_H
#define DSPROJECT_TRIE_H
#define ALPHABET_NUMBERS 26

#include<string>
#include<vector>
#include<QStringList>

class TrieNode{
public:
    char context=0;
    int isComplete=0;
    TrieNode *child[ALPHABET_NUMBERS]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    TrieNode(char context);
    QStringList occur;
};
class Trie {
public:
    TrieNode *root;
    void add(TrieNode* &p,const char *word);
    void add(std::string text);
    void del(std::string text);
    int search(std::string text);
    void del(TrieNode* &p,const char *word);
    int search(TrieNode* &p,const char *word);
    TrieNode* searchN(TrieNode* &p, std::string text);
    void inorderTraverse(TrieNode *p);
    void traverseUtil(TrieNode *p, char* buffer, int depth);
    Trie();
};



#endif //DSPROJECT_TRIE_H
