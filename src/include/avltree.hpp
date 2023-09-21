#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "util.hpp"

struct avlNode {
    // string word;
    // int count;
    pair<string, int> data;
    avlNode* left;
    avlNode* right;
    int height;

    // avlNode(const string& w, int c);
    avlNode(const pair<string, int>& item);
    //  : data(item), left(nullptr), right(nullptr) {}
};

class AVLTree {
public:
    AVLTree();
    void insert(const pair<string, int>& item);
    avlNode* getRoot();

private:
    avlNode* root;
    int getHeight(avlNode* node);
    int getBalanceFactor(avlNode* node);
    void updateHeight(avlNode* node);
    avlNode* rotateRight(avlNode* y);
    avlNode* rotateLeft(avlNode* x);
    avlNode* insert(avlNode* node, const pair<string, int>& item);
};

void fillAvlTree(AVLTree &tree, const vector<pair<string, int>> &topKWords);
void printInOrder(avlNode* node);
void printAvlTreeInOrder(AVLTree &tree);

#endif
