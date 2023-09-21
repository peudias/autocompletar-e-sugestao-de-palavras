#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "util.hpp"

struct avlNode {
    std::string word;
    int count;
    avlNode* left;
    avlNode* right;
    int height;

    avlNode(const std::string& w, int c);
};

class AVLTree {
private:
    avlNode* root;

    int getHeight(avlNode* node);
    int getBalanceFactor(avlNode* node);
    void updateHeight(avlNode* node);
    avlNode* rotateRight(avlNode* y);
    avlNode* rotateLeft(avlNode* x);
    avlNode* insert(avlNode* node, const std::string& word, int count);

public:
    AVLTree();
    void insert(const std::string& word, int count);
    avlNode* getRoot(); // Adicione este método público
};




void fillAvlTree(AVLTree &tree, const vector<pair<string, int>> &topKWords);
void printInOrder(avlNode* node);
void printAvlTreeInOrder(AVLTree &tree);
#endif
