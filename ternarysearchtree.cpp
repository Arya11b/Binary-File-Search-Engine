//
// Created by Arya on 12/9/2016.
//

#include "ternarysearchtree.h"
#include <string>
#include <iostream>
#include "terminal.h"
#define MAX 100

tstNode::tstNode(char context){
    this->context=context;
};
tstNode::~tstNode(){
    context=0;
    leftChild=0;
    rightChild=0;
    equalChild=0;
};
void TernarySearchTree::add(std::string text){
    const char *word=text.c_str();
    add(root,word);
}
void TernarySearchTree::del(std::string text){
    const char *word=text.c_str();
    del(root,word);
}
void TernarySearchTree::add(tstNode*& p,const char *word) {
    if(!p) {
        if (*word)
            p = new tstNode(*word);
        else return;
    }
    if(*word==p->context){
        if(!*(word+1)) {
            p->isComplete = 1;
            return;
        }
        else
            add(p->equalChild,word+1);
    }
    else if(*word<p->context)
        add(p->leftChild,word);
    else
        add(p->rightChild,word);
}
void TernarySearchTree::add(tstNode *&p,tstNode* q) {
    if(!p)
        p=q;
    else if(q->context<p->context)
        add(p->leftChild,q);
    else if(q->context>p->context)
        add(p->rightChild,q);
    else
        return;
}
//void TernarySearchTree::inorderTraverse(tstNode *p,char* buffer,int depth)
void TernarySearchTree::del(tstNode *&p,const char* word){
    if(!p)
        return;
    else if(*word==p->context){
        if(!*(word+1))
            p->isComplete=0;
        else
            del(p->equalChild,word+1);
    }
    else if(*word<p->context)
        del(p->leftChild,word);
    else
        del(p->rightChild,word);
    if(!p->isComplete)
        if (!p->equalChild) {
            tstNode *q = findMinNodeChild(p->rightChild);
            tstNode *r = p->rightChild;
            tstNode *s = p->leftChild;
            if (r)
                add(q, r);
            if (s)
                add(q, s);
            p = q;
        }
}


tstNode* TernarySearchTree::findMinNodeChild(tstNode * &p){
    if(!p)
        return p;
    if (p->leftChild)
        return findMinNodeChild(p->leftChild);
    else if (!p->leftChild && !p->rightChild) {
        tstNode *q=p;
        p=0;
        return q;
    }
    else
        return findMinNodeChild(p->rightChild);
}

void TernarySearchTree::traverseTSTUtil(tstNode *p, char* buffer, int depth){
    if (!p)
        return;
        traverseTSTUtil(p->leftChild, buffer, depth);
        buffer[depth] = p->context;
        if (p->isComplete) {
            buffer[depth+1] = '\0';
            std::string fWord(buffer);
            Terminal::getInstance().writeWord(fWord);
        }
        traverseTSTUtil(p->equalChild, buffer, depth + 1);
        traverseTSTUtil(p->rightChild, buffer, depth);
}
void TernarySearchTree::inorderTraverse(tstNode *p){
   char buffer[MAX];
    traverseTSTUtil(p,buffer,0);
}
int TernarySearchTree::search(tstNode *p,const char* word){
    if(!p)
        return false;
    else if(*word==p->context)
        return *(word+1)==0?p->isComplete:search(p->equalChild,word+1);
    else if(*word<p->context)
        return search(p->leftChild,word);
    else
        return search(p->rightChild,word);
}
tstNode* TernarySearchTree::searchN(tstNode *p,std::string text){
    const char *word=text.c_str();
    if(!p)
        return false;
    else if(*word==p->context)
        return *(word+1)==0?p:searchN(p->equalChild,word+1);
    else if(*word<p->context)
        return searchN(p->leftChild,word);
    else
        return searchN(p->rightChild,word);
}

int TernarySearchTree::search(std::string text){
    const char *word=text.c_str();
    return search(root,word);
}

int TernarySearchTree::height(tstNode *p){
    if(!p)
        return 0;
    return std::max(height(p->rightChild), height(p->leftChild))+1;
}

int TernarySearchTree::avlValue(tstNode *p){
    return height(p->rightChild)-height(p->leftChild);
}

void TernarySearchTree::avlAdd(std::string text){
    const char *word=text.c_str();
    root=avlAdd(root,word );
}
void TernarySearchTree::avlDel(std::string text){
    const char *word=text.c_str();
    root=avlDel(root,word );
}

tstNode* TernarySearchTree::avlAdd(tstNode* p,const char* word){
    if(!p) {
        if (*word)
            p = new tstNode(*word);
        else return p;
    }
    if(*word==p->context){
        if(!*(word+1)) {
            p->isComplete = 1;
            return p;
        }
        else
            p->equalChild=avlAdd(p->equalChild,word+1);
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
tstNode* TernarySearchTree::avlDel(tstNode* p,const char* word){
    if(!p)
        return p;
    else if(*word==p->context){
        if(!*(word+1)){
                p->isComplete=0;
        }
        else
            del(p->equalChild,word+1 );
    }
    else if(*word<p->context)
        del(p->leftChild,word );
    else
        del(p->rightChild,word );
    if(!p->isComplete)
        if (!p->equalChild) {
            tstNode *q = findMinNodeChild(p->rightChild);
            tstNode *r = p->rightChild;
            tstNode *s = p->leftChild;
            if (r)
                add(q, r);
            if (s)
                add(q, s);
            p = q;
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

tstNode* TernarySearchTree::rRotation(tstNode *p){
    tstNode *q=p->leftChild;
    tstNode *r=q->rightChild;
    q->rightChild=p;
    p->leftChild=r;
    return q;
}
tstNode* TernarySearchTree::lRotation(tstNode *p){
    tstNode *q=p->rightChild;
    tstNode *r=q->leftChild;
    q->leftChild=p;
    p->rightChild=r;
    return q;
}
