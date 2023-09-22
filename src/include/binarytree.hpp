#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include "util.hpp"

struct binaryNode {
    pair<string, int> data;
    binaryNode* left;
    binaryNode* right;

    binaryNode(const pair<string, int>& item) : data(item), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insert(const pair<string, int>& item);
    void printInOrderToFile(ofstream& outputFile) const;

private:
    binaryNode* root;
    void destroyTree(binaryNode* node);
    binaryNode* insert(binaryNode* root, const pair<string, int>& item);
    void printInOrderToFile(binaryNode* root, ofstream& outputFile) const;
};

void fillBinaryTree(BinaryTree& binaryTree, const vector<pair<string, int>>& topKWords);
void printBinaryTreeInOrderToFile(const BinaryTree& binaryTree, const string& fileName);

#endif