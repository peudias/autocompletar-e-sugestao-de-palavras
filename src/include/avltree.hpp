#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "util.hpp"

struct avlNode {
    pair<string, int> data;
    avlNode* left;
    avlNode* right;
    int height;

    avlNode(const pair<string, int>& item) : data(item), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLTree();
    void insert(const pair<string, int>& item);
    avlNode* getRoot();
    void printInOrderToFile(ofstream& outputFile) const;

private:
    avlNode* root;
    int getHeight(avlNode* node);
    int getBalanceFactor(avlNode* node);
    void updateHeight(avlNode* node);
    avlNode* rotateRight(avlNode* y);
    avlNode* rotateLeft(avlNode* x);
    avlNode* insert(avlNode* node, const pair<string, int>& item);
    void printInOrderToFile(avlNode* root, ofstream& outputFile) const;
};

void fillAvlTree(AVLTree &avlTree, const vector<pair<string, int>> &topKWords);
void printAvlTreeInOrderToFile(const AVLTree& avlTree, const string& fileName);

#endif
