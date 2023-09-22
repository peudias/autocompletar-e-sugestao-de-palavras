#include "include/binarytree.hpp"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(binaryNode* node) {
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

binaryNode* BinaryTree::insert(binaryNode* root, const pair<string, int>& item) {
    if (root == nullptr) {
        return new binaryNode(item);
    }

    if (item.second < root->data.second) {
        root->left = insert(root->left, item);
    } else {
        root->right = insert(root->right, item);
    }

    return root;
}

void BinaryTree::printInOrderToFile(ofstream& outputFile) const {
    printInOrderToFile(root, outputFile);
}

void BinaryTree::printInOrderToFile(binaryNode* root, ofstream& outputFile) const {
    if (root == nullptr) {
        return;
    }

    printInOrderToFile(root->left, outputFile);
    outputFile << root->data.first << " (" << root->data.second << "); ";
    printInOrderToFile(root->right, outputFile);
}

void fillBinaryTree(BinaryTree& binaryTree, const vector<pair<string, int>>& topKWords) {
    for (const auto& wordPair : topKWords) {
        binaryTree.insert(wordPair);
    }
}

void printBinaryTreeInOrderToFile(const BinaryTree& binaryTree, const string& fileName) {
    ofstream outputFile(fileName, ios::app);

    if (!outputFile.is_open()) {
        cout << "Erro ao abrir o arquivo de saída." << endl;
        return;
    }

    outputFile << endl << "Árvore binária em ordem:" << endl;
    binaryTree.printInOrderToFile(outputFile);
    outputFile << endl;

    outputFile.close();
}
