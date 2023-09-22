#include "include/avltree.hpp"

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::getHeight(avlNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVLTree::getBalanceFactor(avlNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void AVLTree::updateHeight(avlNode* node) {
    if (node != nullptr)
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

avlNode* AVLTree::rotateRight(avlNode* y) {
    avlNode* x = y->left;
    avlNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

avlNode* AVLTree::rotateLeft(avlNode* x) {
    avlNode* y = x->right;
    avlNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

void AVLTree::insert(const pair<string, int>& data) {
    root = insert(root, data);
}

avlNode* AVLTree::insert(avlNode* node, const pair<string, int>& data) {
    if (node == nullptr)
        return new avlNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    updateHeight(node);

    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (data < node->left->data)
            return rotateRight(node);
        else if (data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (balance < -1) {
        if (data > node->right->data)
            return rotateLeft(node);
        else if (data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

void AVLTree::printInOrderToFile(ofstream& outputFile) const {
    printInOrderToFile(root, outputFile);
}

void AVLTree::printInOrderToFile(avlNode* root, ofstream& outputFile) const {
    if (root == nullptr) {
        return;
    }

    printInOrderToFile(root->left, outputFile);
    outputFile << root->data.first << " (" << root->data.second << "); ";
    printInOrderToFile(root->right, outputFile);
}

void fillAvlTree(AVLTree &avlTree, const vector<pair<string, int>> &topKWords) {
    for (const auto& wordCount : topKWords) {
        avlTree.insert(wordCount);
    }
}

void printAvlTreeInOrderToFile(const AVLTree& avlTree, const string& fileName) {
    ofstream outputFile(fileName, ios::app);

    if (!outputFile.is_open()) {
        cout << "Erro ao abrir o arquivo de saída." << endl;
        return;
    }

    outputFile << endl << "Árvore AVL:" << endl;
    avlTree.printInOrderToFile(outputFile);
    outputFile << endl;

    outputFile.close();
}