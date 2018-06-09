//
// Created by Arya on 12/9/2016.
//

#ifndef DSPROJECT_TERNARYSEARCHTREE_H
#define DSPROJECT_TERNARYSEARCHTREE_H

#include <string>
#include<vector>
#include <QStringList>


class tstNode{
public:
    char context=0;
    tstNode *leftChild=0;
    tstNode *equalChild=0;
    tstNode *rightChild=0;
    QStringList occur;
    int isComplete= 0;
    tstNode(char context);
    ~tstNode();
};
class TernarySearchTree {
public:
    tstNode *curentNode;
    tstNode *root=0;
    int search(tstNode *p,const char* search);
    tstNode* searchN(tstNode *p,std::string text);
    int search(std::string text);
    void add(tstNode* &p, const char *word);
    void add(tstNode* &p, tstNode* q);
    void add(std::string text);
    void del(tstNode* &p,const char* word);
    void del(std::string text);
    void inorderTraverse(tstNode *p);
    void traverseTSTUtil(tstNode *p, char* buffer, int depth);
    tstNode* lRotation(tstNode *p);
    tstNode* rRotation(tstNode *p);
    tstNode* avlDel(tstNode* p,const char* word);
    tstNode* avlAdd(tstNode* p,const char* word);
    void avlAdd(std::string word);
    void avlDel(std::string word);
    int height(tstNode *p);
    int avlValue(tstNode *p);
    tstNode* findMinNodeChild(tstNode * &p);
} ;


#endif //DSPROJECT_TERNARYSEARCHTREE_H
