//
// Created by Arya on 11/30/2016.
//

#ifndef DSPROJECT_BINARYSEARCHTREE_H
#define DSPROJECT_BINARYSEARCHTREE_H

#include <string>
#include<vector>
#include<QStringList>

class node{
public:
    ~node();
    std::string context;
    node *leftChild=0;
    node *rightChild=0;
    QStringList occur;
    bool isFull();
    bool isLeaf();
};
class BinarySearchTree {
public:
    int i=0;
    node *root=0;
    std::string findMinNodeChild(node* &p);
    void add(std::string word);
    void add(node* newNode,node* &p);
    void avlAdd(std::string word);
    void avlDel(std::string word);
    void del(std::string word,node* &p);
    void del(node* &p);
    void del(std::string word);
    void inorderTraverse(node * p);
    int height(node *p);
    int avlValue(node *p);
    int search(node* p,std::string context);
    int search(std::string context);
    node* searchN(node* p,std::string context);
    node* rRotation(node *p);
    node* lRotation(node *p);
    node* avlAdd(node* p,std::string text);
    node* avlDel(node* &p,std::string text);
} ;



#endif //DSPROJECT_BINARYSEARCHTREE_H
