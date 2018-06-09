#include "hash.h"
#include <iostream>
#include "terminal.h"


HashNode::HashNode(std::string text){
    this->text=text;
}

Hash::Hash() {
    for (int i = 0; i <23 ; ++i)
        for (int j = 0; j <23 ; ++j)
            hashTable[i][j]=0;
}

int Hash::__1stCode(std::string text) {
    int hc=0;
    for (int i = 0; i < text.length(); ++i)
        hc+=i*(text[i]-97);
    hc%=23;
    return hc;
}
int Hash::__2stCode(std::string text) {
    int hc=0;
    for (int i = 0; i < text.length(); ++i)
        hc+=i*(122-text[i]);
    hc%=23;
    return hc;
}
bool Hash::search(std::string text,HashNode* p) {
    if (!p)
        return false;
    return p->text==text? true:search(text,p->link);
}
void Hash::add(std::string text) {
    HashNode* p=new HashNode(text);
    add(p,hashTable[__1stCode(text)][__2stCode(text)]);
}
void Hash::del(std::string text) {
    del(text,hashTable[__1stCode(text)][__2stCode(text)]);
}
bool Hash::search(std::string text) {
    return search(text,hashTable[__1stCode(text)][__2stCode(text)]);
}
void Hash::add(HashNode* q,HashNode* &p) {
    if (!p)
        p=q;
    else if(p->text!=q->text)
        add(q,p->link);
}
void Hash::del(std::string text,HashNode* &p) {
    if (!p)
        return;
    if (p->text!=text)
        del(text,p->link);
    else
        p=p->link;
}
void Hash::printNode(HashNode* hn) {
    if(!hn)
        return;
Terminal::getInstance().writeWord(hn->text);
    if(hn->link)
        printNode(hn->link);

}
void Hash::printList() {
    for (int i = 0; i <23 ; ++i)
        for (int j = 0; j <23 ; ++j)
                printNode(hashTable[i][j]);

}
