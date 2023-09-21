#include "include/avltree.hpp"


avlNode::avlNode(const std::string& w, int c) : word(w), count(c), left(nullptr), right(nullptr), height(1) {}

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
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
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

avlNode* AVLTree::insert(avlNode* node, const std::string& word, int count) {
    if (node == nullptr)
        return new avlNode(word, count);

    if (word < node->word)
        node->left = insert(node->left, word, count);
    else if (word > node->word)
        node->right = insert(node->right, word, count);
    else
        return node; // Duplicates not allowed

    updateHeight(node);

    int balance = getBalanceFactor(node);

    // Left Heavy
    if (balance > 1) {
        if (word < node->left->word)
            return rotateRight(node);
        else if (word > node->left->word) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (word > node->right->word)
            return rotateLeft(node);
        else if (word < node->right->word) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

void AVLTree::insert(const std::string& word, int count) {
    root = insert(root, word, count);
}

void fillAvlTree(AVLTree &tree, const vector<pair<string, int>> &topKWords) {
    for (const auto& wordCount : topKWords) {
        tree.insert(wordCount.first, wordCount.second);
    }
}

// Função auxiliar recursiva para imprimir a árvore AVL em ordem in-order
void printInOrder(avlNode* node) {
    if (node == nullptr) {
        return;
    }
    
    printInOrder(node->left);
    std::cout << node->word << " (" << node->count << ")" << std::endl;
    printInOrder(node->right);
}

// Função pública para imprimir a árvore AVL em ordem in-order
void printAvlTreeInOrder(AVLTree &tree) {
    printInOrder(tree.getRoot()); // Use getRoot para acessar a raiz da árvore
}


avlNode* AVLTree::getRoot() {
    return root;
}
