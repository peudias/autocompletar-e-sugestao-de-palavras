#include "include/tree.hpp"

void insert(TreeNode*& root, const string& word) {
    if(!root){
        root = new TreeNode(word);
        return;
    }

    if(word < root->word){
        insert(root->left, word);
    }else if(word > root->word) {
        insert(root->right, word);
    }
}

void printInOrder(TreeNode* root) {
    if(root) {
    printInOrder(root->left);
        cout << root->word << " ";
        printInOrder(root->right);
    }
}
