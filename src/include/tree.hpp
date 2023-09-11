#ifndef TREE_HPP
#define TREE_HPP
#include "util.hpp"

struct TreeNode {
    string word;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string word) : word(word), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, const string& word);
void printInOrder(TreeNode* root);
void printInOrder2(TreeNode* root);

#endif