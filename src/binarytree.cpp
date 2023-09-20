#include "include/binarytree.hpp"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

void BinaryTree::insert(const pair<string, int>& item) {
    root = insert(root, item);
}

TreeNode* BinaryTree::insert(TreeNode* root, const pair<string, int>& item) {
    if (root == nullptr) {
        return new TreeNode(item);
    }

    if (item.second < root->data.second) {
        root->left = insert(root->left, item);
    } else {
        root->right = insert(root->right, item);
    }

    return root;
}

void BinaryTree::printInOrder() const {
    printInOrder(root);
}

void BinaryTree::printInOrder(TreeNode* root) const {
    if (root == nullptr) {
        return;
    }

    printInOrder(root->left);
    cout << root->data.first << " (" << root->data.second << "), ";
    printInOrder(root->right);
}

void fillBinaryTree(BinaryTree& binaryTree, const std::vector<std::pair<std::string, int>>& topKWords) {
    for (const auto& wordPair : topKWords) {
        binaryTree.insert(wordPair);
    }
}

void printBinaryTreeInOrder(const BinaryTree& binaryTree) {
    cout << "Árvore binária em ordem:" << endl;
    binaryTree.printInOrder();
    cout << endl;
}

void printBinaryTreeInOrderToFile(const BinaryTree& binaryTrees, ostream &outputStream) {
    outputStream << "Árvore binária em ordem:" << endl;
    // binaryTree.printInOrder(outputFile); // Direciona a saída para o arquivo
    outputStream << endl;

    // outputFile.close(); // Fecha o arquivo
}