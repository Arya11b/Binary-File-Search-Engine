//
// Created by arya11 on 12/13/16.
//

#include "trie.h"

#include "terminal.h"
#define MAX 100
TrieNode::TrieNode(char context) {
    this->context=context;
}
Trie::Trie() {
    root=new TrieNode(0);
}
void Trie::inorderTraverse(TrieNode *p){
    char buffer[MAX];
    traverseUtil(p,buffer,0);

}
void Trie::traverseUtil(TrieNode *p, char* buffer, int depth){
    for (int i = 0; i < ALPHABET_NUMBERS; ++i) {
        if(!p->child[i])
            continue;
        if (p->child[i]->isComplete) {
            buffer[depth] = p->child[i]->context;
            buffer[depth+1] = '\0';
            std::string fWord(buffer);
            Terminal::getInstance().writeWord(fWord);
        } else {
            buffer[depth]=p->child[i]->context;
            traverseUtil(p->child[i], buffer, depth + 1);
        }
    }
}
void Trie::add(std::string text) {
    const char *word=text.c_str();
    add(root,word);
}
void Trie::del(std::string text) {
    const char *word=text.c_str();
    del(root,word);
}
int Trie::search(std::string text) {
    const char *word=text.c_str();
    return search(root,word);
}
void Trie::add(TrieNode *&p, const char *word) {
    if(*word-97>=ALPHABET_NUMBERS)
        return;
    if(!p->child[*word-97])
        p->child[*word-97]=new TrieNode(*word);
    if (!*(word + 1)) {
        p->child[*word - 97]->isComplete = 1;
        return;
    }
        add(p->child[*word-97], word + 1);
}

void Trie::del(TrieNode *&p, const char *word) {
    if(!p->child[*word-97])
        return;
    if (!*(word + 1)) {
        p->child[*word - 97]->isComplete=0;
    }
    del(p->child[*word-97], word + 1);
}
int Trie::search(TrieNode *&p, const char *word) {
    if(!p->child[*word-97])
        return false;
    if (!*(word + 1)) {
        return (p->child[*word - 97]->isComplete);
    }
    search(p->child[*word-97], word + 1);
}
TrieNode* Trie::searchN(TrieNode *&p, std::string text) {
    const char *word=text.c_str();
    if(!p->child[*word-97])
        return p;
    if (!*(word + 1)) {
        return (p->child[*word - 97]);
    }
    return searchN(p->child[*word-97], word + 1);
}

