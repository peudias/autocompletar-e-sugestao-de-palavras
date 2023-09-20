#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include "util.hpp"

struct TreeNode {
    pair<string, int> data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const pair<string, int>& item) : data(item), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insert(const pair<string, int>& item);
    void printInOrder() const;

private:
    TreeNode* root;
    void destroyTree(TreeNode* node);
    TreeNode* insert(TreeNode* root, const pair<string, int>& item);
    void printInOrder(TreeNode* root) const;
};

void fillBinaryTree(BinaryTree& binaryTree, const vector<pair<string, int>>& topKWords);
void printBinaryTreeInOrder(const BinaryTree& binaryTree);

#endif