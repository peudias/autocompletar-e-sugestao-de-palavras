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

void printInOrder2(TreeNode* root) {
    if (root) {
        cout << "Nó: " << root->word << " ";
        
        if (root->left) {
            cout << "FE: " << root->left->word << " ";
        } else {
            cout << "FE: Nenhum ";
        }

        if (root->right) {
            cout << "FD: " << root->right->word << " ";
        } else {
            cout << "FD: Nenhum ";
        }

        cout << endl;

        printInOrder2(root->left);
        printInOrder2(root->right);
    }
}
