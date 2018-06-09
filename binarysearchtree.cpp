//
// Created by Arya on 11/30/2016.
//

#include "binarysearchtree.h"
#include <iostream>
#include "terminal.h"
#include <QString>
#include<QStringList>
// node methods

bool node::isLeaf(){
    if(!leftChild && !rightChild)
        return true;
    else
        return false;

}
bool node::isFull() {
    if (context.empty())
        return false;
    else
        return true;
}
node::~node() {
    leftChild=0;
    rightChild=0;
    context="";
}

/*...........*/

// BinarySearchTree add/delete/traverse
void BinarySearchTree::add(node* newNode,node* &p) {
    if(p==0)
        p=newNode;
    else if(p->context < newNode->context)
        add(newNode,p->rightChild); //using recursive may cause stack overflow
    else if(p->context > newNode->context)
        add(newNode,p->leftChild); //using recursive may cause stack overflow
}
void BinarySearchTree::add(std::string word) {
    node *newNode = new node();
    newNode->context=word;
    add(newNode,root);
}

void BinarySearchTree::del(std::string word) {
    del(word,root);
}
void BinarySearchTree::del(node* &p) {
    if(!p)
        return;
    if (p->rightChild)
        p->context = findMinNodeChild(p->rightChild);
    else if (p->leftChild)
        p=p->leftChild;
    else
        p=0;
}
void BinarySearchTree::del(std::string word,node* &p){
    if(!p)
        return;
    if(p->context==word) {
        del(p);
    }
    else if(p->context < word)
        del(word,p->rightChild); //using recursive may cause stack overflow
    else
        del(word,p->leftChild); //using recursive may cause stack overflow
}
void BinarySearchTree::inorderTraverse(node *p) {
    if(!p)
        return;
    inorderTraverse(p->leftChild);
    if(p->isFull()){
        Terminal::getInstance().writeWord(p->context);
    }
    else
        return;
    inorderTraverse(p->rightChild);
}

std::string BinarySearchTree::findMinNodeChild(node * &p){
    if(!p)
        return nullptr;
    if (p->leftChild)
        return findMinNodeChild(p->leftChild);
    else if (p->isLeaf()) {
        node *q=p;
        p=0;
        return q->context;
    }
    else
        return findMinNodeChild(p->rightChild);
}
int BinarySearchTree::search(node* p,std::string context){
    if(!p)
        return 0;
    if(p->context==context)
        return 1;
    if(context<p->context)
        return search(p->leftChild,context);
    if(context>p->context)
        return search(p->rightChild,context);
}
node* BinarySearchTree::searchN(node* p,std::string context){
    if(!p)
        return p;
    if(p->context==context)
        return p;
    if(context<p->context)
        return searchN(p->leftChild,context);
    if(context>p->context)
        return searchN(p->rightChild,context);
}
int BinarySearchTree::search(std::string context){
    return search(root,context);
}

/*...........*/

//avl tree methods

int BinarySearchTree::height(node *p){
    if(!p)
        return 0;
    return std::max(height(p->rightChild), height(p->leftChild))+1;
}

int BinarySearchTree::avlValue(node *p){
    return height(p->rightChild)-height(p->leftChild);
}

void BinarySearchTree::avlAdd(std::string text){
    root=avlAdd(root,text);
}

node* BinarySearchTree::avlAdd(node* p,std::string text){
    if(!p) {
        node *p = new node();
        p->context = text;
        return p;
    }
    else if(text < p->context)
        p->leftChild=avlAdd(p->leftChild,text);
    else if(text > p->context)
        p->rightChild=avlAdd(p->rightChild,text);
    else
        return p;
    if (avlValue(p) < -1 && avlValue(p->leftChild)<=0)
        return rRotation(p);

    if (avlValue(p) > 1 && avlValue(p->rightChild)>0)
        return lRotation(p);

    if (avlValue(p) < -1 && avlValue(p->leftChild)>0)
    {
        p->leftChild =  lRotation(p->leftChild);
        return rRotation(p);
    }

    if (avlValue(p) > 1 && avlValue(p->rightChild)<=0)
    {
        p->rightChild = rRotation(p->rightChild);
        return lRotation(p);
    }
    return p;

}
node* BinarySearchTree::avlDel(node* &p,std::string text){
    if(!p)
            return p;
        if(text < p->context)
            p->leftChild=avlDel(p->leftChild,text);
        else if(text > p->context)
            p->rightChild=avlDel(p->rightChild,text);
        else{
            if (p->rightChild)
                p->context = findMinNodeChild(p->rightChild);
            else if (p->leftChild)
                p=p->leftChild;
            else
                p=0;
            return p;
        }
    if (avlValue(p) < -1 && avlValue(p->leftChild)<=0)
        return rRotation(p);

    if (avlValue(p) > 1 && avlValue(p->rightChild)>0)
        return lRotation(p);

    if (avlValue(p) < -1 && avlValue(p->leftChild)>0)
    {
        p->leftChild =  lRotation(p->leftChild);
        return rRotation(p);
    }

    if (avlValue(p) > 1 && avlValue(p->rightChild)<=0)
    {
        p->rightChild = rRotation(p->rightChild);
        return lRotation(p);
    }
    return p;

}

node* BinarySearchTree::rRotation(node *p){
    node *q=p->leftChild;
    node *r=q->rightChild;
    q->rightChild=p;
    p->leftChild=r;
    return q;
}
node* BinarySearchTree::lRotation(node *p){
    node *q=p->rightChild;
    node *r=q->leftChild;
    q->leftChild=p;
    p->rightChild=r;
    return q;
}
/*...............*/
