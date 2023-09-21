#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "util.hpp"

struct Node {
    std::string word;
    int count;
    Node* left;
    Node* right;
    int height;

    Node(const std::string& w, int c);
};

class avltree {
private:
    Node* root;

    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    void updateHeight(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, const std::string& word, int count);

public:
    avltree();
    void insert(const std::string& word, int count);
    Node* getRoot(); // Adicione este método público
};




void fillAvlTree(avltree &tree, const vector<pair<string, int>> &topKWords);
void printInOrder(Node* node);
void printAvlTreeInOrder(avltree &tree);
#endif
