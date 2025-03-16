#include <iostream>
#include <memory>
#define NIL nullptr

class Node {
public:
    int key;
    int priority;
    Node *right, *left;

    Node(int x, int y) : key(x), priority(y), right(NIL), left(NIL) {}
};

Node* Delete(Node** t, int key);
Node* deleteNode(Node** t, int key);

// This function searches for a key in the tree. Returns true if found, otherwise false.
bool find(Node* p, int x) {
    while (p != NIL) {
        if (p->key == x) return true;
        else if (p->key > x) p = p->left;
        else p = p->right;
    }
    return false;
}

// This function performs an inorder traversal of the tree and prints the keys.
void inorder(Node* a) {
    if (a->left != NIL) inorder(a->left);
    std::cout << " " << a->key;
    if (a->right != NIL) inorder(a->right);
}

// This function performs a preorder traversal of the tree and prints the keys.
void preorder(Node* p) {
    std::cout << " " << p->key;
    if (p->left != NIL) preorder(p->left);
    if (p->right != NIL) preorder(p->right);
}

// This function prints the tree in both inorder and preorder traversal formats.
void print(Node* p) {
    inorder(p);
    std::cout << "\n";
    preorder(p);
    std::cout << "\n";
}

// This function performs a right rotation on the given node.
Node* rightRotate(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
}

// This function performs a left rotation on the given node.
Node* leftRotate(Node* p) {
    Node* q = p->right;
    p->right = q->left;
    q->left = p;
    return q;
}

// This function inserts a new node into the tree while maintaining the heap property using rotations.
Node* insert(Node** t, int key, int priority) {
    if ((*t) == NIL)
        return new Node(key, priority); // Create new node if leaf is reached
    if ((*t)->key == key)
        return *t;  // Ignore duplicate keys

    if (key < (*t)->key) { // Move to left child
        (*t)->left = insert(&(*t)->left, key, priority); // Update left child pointer
        if ((*t)->priority < (*t)->left->priority) // Right rotate if left child has higher priority
            (*t) = rightRotate(*t);
    } else { // Move to right child
        (*t)->right = insert(&(*t)->right, key, priority); // Update right child pointer
        if ((*t)->priority < (*t)->right->priority) // Left rotate if right child has higher priority
            (*t) = leftRotate((*t));
    }
    return *t;
}

// This function initiates the deletion process and calls `deleteNode` for actual deletion.
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

// This function handles the actual deletion of nodes, including cases where the node has one or two children.
Node* deleteNode(Node** t, int key) {
    if ((*t)->left == NIL && (*t)->right == NIL) {  // Case for leaf node
        return NIL;
    } else if ((*t)->left == NIL) { // Case for node with only right child
        (*t) = leftRotate(*t);
    } else if ((*t)->right == NIL) { // Case for node with only left child
        (*t) = rightRotate(*t);
    } else { // Case for node with both left and right children
        if ((*t)->left->priority > (*t)->right->priority) // Rotate based on higher priority child
            (*t) = rightRotate(*t);
        else
            (*t) = leftRotate(*t);
    }
    return Delete(t, key);
}

// Entry point of the program. Reads commands to insert, delete, find, or print the tree.
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
