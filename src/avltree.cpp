#include "include/avltree.hpp"

AVLTree::AVLTree() : root(nullptr) {}

avlNode::avlNode(const pair<string, int>& item) : data(item), left(nullptr), right(nullptr), height(1) {}

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

void AVLTree::insert(const pair<string, int>& data) {
    root = insert(root, data);
}

void fillAvlTree(AVLTree &tree, const vector<pair<string, int>> &topKWords) {
    for (const auto& wordCount : topKWords) {
        tree.insert(wordCount);
    }
}

void printInOrder(avlNode* node) {
    if (node == nullptr) {
        return;
    }
    
    printInOrder(node->left);
    cout << node->data.first << " (" << node->data.second << ")" << endl;
    printInOrder(node->right);
}

void printAvlTreeInOrder(AVLTree &tree) {
    printInOrder(tree.getRoot());
}

avlNode* AVLTree::getRoot() {
    return root;
}
