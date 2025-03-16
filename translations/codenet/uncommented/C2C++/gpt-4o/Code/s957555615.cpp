#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> right;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> parent;
    int key;

    Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

std::shared_ptr<Node> root = nullptr;

std::shared_ptr<Node> treeMinimum(std::shared_ptr<Node> x) {
    while (x->left != nullptr) x = x->left;
    return x;
}

std::shared_ptr<Node> treeMaximum(std::shared_ptr<Node> x) {
    while (x->right != nullptr) x = x->right;
    return x;
}

std::shared_ptr<Node> treeSearch(std::shared_ptr<Node> u, int k) {
    if (u == nullptr || k == u->key) return u;

    if (k < u->key) return treeSearch(u->left, k);
    else return treeSearch(u->right, k);
}

std::shared_ptr<Node> treeSuccessor(std::shared_ptr<Node> x) {
    std::shared_ptr<Node> y;
    if (x->right != nullptr) return treeMinimum(x->right);

    y = x->parent;
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

void treeDelete(std::shared_ptr<Node> z) {
    std::shared_ptr<Node> y; // node to be deleted
    std::shared_ptr<Node> x; // child of y

    if (z->left == nullptr || z->right == nullptr) y = z;
    else y = treeSuccessor(z);

    if (y->left != nullptr) x = y->left;
    else x = y->right;

    if (x != nullptr) x->parent = y->parent;

    if (y->parent == nullptr) root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;

    if (y != z) z->key = y->key;
}

void insert(int k) {
    std::shared_ptr<Node> y = nullptr;
    std::shared_ptr<Node> x = root;
    std::shared_ptr<Node> z = std::make_shared<Node>(k);

    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}

void inorder(std::shared_ptr<Node> u) {
    if (u == nullptr) return;
    inorder(u->left);
    std::cout << " " << u->key;
    inorder(u->right);
}

void preorder(std::shared_ptr<Node> u) {
    if (u == nullptr) return;
    std::cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

int main() {
    int n, x;
    std::string com;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> com;
        if (com[0] == 'f') {
            std::cin >> x;
            std::shared_ptr<Node> t = treeSearch(root, x);
            if (t != nullptr) std::cout << "yes\n";
            else std::cout << "no\n";
        } else if (com[0] == 'i') {
            std::cin >> x;
            insert(x);
        } else if (com[0] == 'p') {
            inorder(root);
            std::cout << "\n";
            preorder(root);
            std::cout << "\n";
        } else if (com[0] == 'd') {
            std::cin >> x;
            treeDelete(treeSearch(root, x));
        }
    }

    return 0;
}

// <END-OF-CODE>
