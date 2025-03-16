#include <iostream>
#include <memory>
#define NIL nullptr

class Node {
public:
    int key;
    int priority;
    Node* right;
    Node* left;

    Node(int x, int y) : key(x), priority(y), right(NIL), left(NIL) {}
};

Node* Delete(Node** t, int key);
Node* deleteNode(Node** t, int key);

int find(Node* p, int x) {
    while (p != NIL) {
        if (p->key == x) return 1;
        else if (p->key > x) p = p->left;
        else p = p->right;
    }
    return 0;
}

void inorder(Node* a) {
    if (a->left != NIL) inorder(a->left);
    std::cout << " " << a->key;
    if (a->right != NIL) inorder(a->right);
}

void preorder(Node* p) {
    std::cout << " " << p->key;
    if (p->left != NIL) preorder(p->left);
    if (p->right != NIL) preorder(p->right);
}

void print(Node* p) {
    inorder(p);
    std::cout << "\n";
    preorder(p);
    std::cout << "\n";
}

Node* rightRotate(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
}

Node* leftRotate(Node* p) {
    Node* q = p->right;
    p->right = q->left;
    q->left = p;
    return q;
}

Node* insert(Node** t, int key, int priority) {
    if ((*t) == NIL)
        return new Node(key, priority); // Create a new node if leaf is reached

    if ((*t)->key == key)
        return *t;  // Ignore duplicate keys

    if (key < (*t)->key) { // Move to the left child
        (*t)->left = insert(&(*t)->left, key, priority); // Update left child pointer
        if ((*t)->priority < (*t)->left->priority) // Right rotate if left child has higher priority
            (*t) = rightRotate(*t);
    } else { // Move to the right child
        (*t)->right = insert(&(*t)->right, key, priority); // Update right child pointer
        if ((*t)->priority < (*t)->right->priority) // Left rotate if right child has higher priority
            (*t) = leftRotate((*t));
    }
    return *t;
}

Node* Delete(Node** t, int key) {
    if ((*t) == NIL)
        return NIL;

    if (key < (*t)->key) // Search for the node to delete
        (*t)->left = Delete(&((*t)->left), key);
    else if (key > (*t)->key)
        (*t)->right = Delete(&((*t)->right), key);
    else
        return deleteNode(t, key);
    
    return *t;
}

Node* deleteNode(Node** t, int key) {
    if ((*t)->left == NIL && (*t)->right == NIL) { // If it's a leaf
        return NIL;
    } else if ((*t)->left == NIL) { // If it has only a right child
        (*t) = leftRotate(*t);
    } else if ((*t)->right == NIL) { // If it has only a left child
        (*t) = rightRotate(*t);
    } else { // If it has both children
        if ((*t)->left->priority > (*t)->right->priority) // Promote the child with higher priority
            (*t) = rightRotate(*t);
        else
            (*t) = leftRotate(*t);
    }
    return Delete(t, key);
}

int main() {
    int num, x, y;
    char com[8];
    Node* root = NIL;
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        std::cin >> com;
        switch (com[0]) {
            case 'i':
                std::cin >> x >> y;
                root = insert(&root, x, y);
                break;
            case 'd':
                std::cin >> x;
                root = Delete(&root, x);
                break;
            case 'f':
                std::cin >> x;
                if (find(root, x)) std::cout << "yes\n";
                else std::cout << "no\n";
                break;
            case 'p':
                print(root);
                break;
        }
    }
    return 0;
}

// <END-OF-CODE>
